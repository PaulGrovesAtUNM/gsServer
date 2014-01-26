#ifndef SHAREINT_H
#define SHAREINT_H

#include <unistd.h>

#include "netSharedMemory.h"


class shareInt : public netSharedMemory
{
    public:
        shareInt();
        virtual ~shareInt();

        int sizeInBytes();
        void writeToClient(int socketHandle);
        void setInt(int val);
    protected:
        int myValue;
    private:
};

#endif // SHAREINT_H
