#ifndef GUSTIXSERVER_H
#define GUSTIXSERVER_H


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "netSharedMemory.h"



class gustixServer
{
    friend void *share(void *me);

    public:
        gustixServer(unsigned int portno, netSharedMemory *toShare);
        virtual ~gustixServer();

    protected:
        int sockfd;
        int newSocketFD; //to the client requesting info.
        struct sockaddr_in serv_addr;

        netSharedMemory *shared;


    private:
        pthread_t hThread; //Handle to the (a) server thread.
};

#endif // GUSTIXSERVER_H
