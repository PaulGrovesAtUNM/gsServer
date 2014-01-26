#include <string.h>
#include <stdio.h>
#include "../include/shareInt.h"

shareInt::shareInt()
{
    //ctor
}

int shareInt::sizeInBytes()
{
    return sizeof(int);
}

void shareInt::writeToClient(int socketHandle)
{
    char buffer[100];

    sprintf(buffer, "%i", myValue);

    write(socketHandle, buffer, strlen(buffer));
}

void shareInt::setInt(int val)
{
    myValue = val;
}
shareInt::~shareInt()
{
    //dtor
}
