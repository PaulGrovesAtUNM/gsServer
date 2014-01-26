#include <iostream>
#include "./include/gustixServer.h"
#include "./include/shareInt.h"

using namespace std;

int main()
{
    shareInt myInt;
    gustixServer *myServer = new gustixServer(2014, &myInt);
    int anInput = 100;

    cout << "Server started..." << endl;

    while (anInput > 0)
    {
        cin >> anInput;
        cout << "Setting new integer value..." << endl;
        myInt.setInt(anInput);
    }

    delete myServer;
    return 0;
}
// i5 2.4Gh, 4GB Ram
