//
// Created by may on 28/12/16.
//

#include <iostream>
#include "sockets/Udp.h"
#include "TaxiCenter.h"
#include "MainFlow.h"
#include <unistd.h>

int main() {

    TaxiCenter taxiCenter(4);
    MainFlow mainFlow (taxiCenter);
    mainFlow.startFlow();

    std::cout << "Hello, from server" << std::endl;

   // Udp udp(1, 5555);

    const char* ip_address = "127.0.0.1";
    const int port_num=5555;

    Socket* socket = new Udp(1,port_num);
    socket->initialize();

    char buffer[1024];
    socket->reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
    socket->sendData("sup?");


//
//    usleep(5000);
    //Socket socket2 =  Udp(1, 5554);
    //socket->initialize();

    //char buffer2[1024];
    socket->reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;




    // support more than one client?
    return 0;
}