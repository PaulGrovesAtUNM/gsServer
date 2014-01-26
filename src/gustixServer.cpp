#include "../include/gustixServer.h"

#include <iostream>

void *share(void *me)
{
    gustixServer *g = (gustixServer *)me;
    int clientFD;

    while ( g->sockfd )
    {
        clientFD = accept(g->sockfd, NULL, NULL);
        g->shared->writeToClient(clientFD);
        //We have a connection with a client.
        // Share our data first, when wait for further requests.
        //Write one thing and close, forcing a new connection by the clien.
        close(clientFD);
    }
}

gustixServer::gustixServer(unsigned int portno, netSharedMemory *toShare)
{
    shared = toShare;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    // Bind to our address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error on binding!");
        exit(-1);
    }

    listen(sockfd,5); //5 clients.
    // Spin off a thread to listen.
    if ( pthread_create(&hThread, NULL, share, (void *)this) )
    {
        perror("Could not spin off thread!");
        exit(-1);
    }
}

gustixServer::~gustixServer()
{
    if (sockfd != 0)
        close(sockfd);
    sockfd = 0;

    if (hThread)
        pthread_cancel(hThread);
}


