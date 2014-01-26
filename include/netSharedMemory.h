#ifndef NETSHAREDMEMORY_H
#define NETSHAREDMEMORY_H


class netSharedMemory
{
    public:
        netSharedMemory();

        virtual int sizeInBytes() = 0;
        virtual void writeToClient(int socketHandle) = 0;

        virtual ~netSharedMemory();
    protected:
    private:
};

#endif // NETSHAREDMEMORY_H
