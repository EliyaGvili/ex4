#include <iostream>
#include <queue>
#include "Point.h"
#include "MainFlow.h"
#include "sockets/Udp.h"
#include <unistd.h>

using namespace std;
/**
 * The main function.
 * Responsible for running the program.
 */

using namespace std;

Driver *parseDriver(string str) throw(exception);

int main(int argc, char *argv[]) {
    string str;

    const char *ip_address = argv[1];
    const int port_num = atoi(argv[2]);


    std::cout << "Hello, from client" << std::endl;

    Socket *socket = new Udp(0, port_num);
    socket->initialize();

    getline(cin, str);
    Driver *driver = parseDriver(str);

    //attaching the driver "fake" parameters just for the serialization
    Cab c(0, HONDA, GREEN);
    c.setLocation(Node(Point(0, 0)));
    driver->setCab(c);
    Graph * graph;
    Grid grid(1, 1);
    graph = &grid;
    driver->setGraph(graph);

    //**Serialize**//
    std::string serial_str;
    boost::iostreams::back_insert_device <std::string> inserter(serial_str);
    boost::iostreams::stream <boost::iostreams::back_insert_device<std::string>> s(
            inserter);
    boost::archive::binary_oarchive oa(s);
    oa << driver;
    s.flush();

    cout << serial_str << endl;

    //send the driver to the server
    socket->sendData(serial_str);
    char buffer[2048];

    //recievng the relevant cab
    socket->reciveData(buffer, sizeof(buffer));

    //**DeSerialize**//
    BasicCab *basicCab;
    boost::iostreams::basic_array_source<char> device(buffer, sizeof(buffer));
    boost::iostreams::stream <boost::iostreams::basic_array_source<char>> s2
            (device);
    boost::archive::binary_iarchive ia(s2);

    ia >> basicCab;

    //attaching the relevant cab to the driver
    driver->setCab(*basicCab);
    bool reciveData = true;
    while (reciveData) {
        socket->reciveData(buffer, sizeof(buffer));
        string str = buffer;
        if (str == "close") {
            reciveData = false;
            continue;
        }
        socket->reciveData(buffer, sizeof(buffer));
        Node *node;
        boost::iostreams::basic_array_source<char> device(buffer,
                                                          sizeof(buffer));
        boost::iostreams::stream <boost::iostreams::basic_array_source<char>> s3
                (device);
        boost::archive::binary_iarchive ia(s3);

        ia >> node;

        driver->updateCabLocation(*node);
        cout << *node << endl;
        delete node;


    }
    delete driver;
    delete basicCab;
    delete socket;
    return 0;
}

Driver *parseDriver(string str) throw(exception) {
    int saperatorP, driverId, driverAge, driverExp, vehiclId;
    char driverStatus;
    MartialStatus driverStatusStr;
    saperatorP = str.find(",");
    driverId = atoi(str.substr(0, (str.length() - saperatorP - 1)).c_str());
    if (driverId < 0) {
        throw exception();
    }
    str = str.substr(saperatorP + 1);
    saperatorP = str.find(",");
    driverAge = atoi(str.substr(0, (str.length() - saperatorP - 1)).c_str());
    if (driverAge < 0) {
        throw exception();
    }
    str = str.substr(saperatorP + 1);
    saperatorP = str.find(",");
    driverStatus = (str.substr(0, 1))[0];
    switch (driverStatus) {
        case 'S':
            driverStatusStr = SINGLE;
            break;
        case 'M':
            driverStatusStr = MARRIED;
            break;
        case 'D':
            driverStatusStr = DIVORCED;
            break;
        case 'W':
            driverStatusStr = WIDOWED;
            break;
        default:
            throw exception();
    }

    str = str.substr(saperatorP + 1);
    if (str[0] == '-') {
        throw exception();
    }
    saperatorP = str.find(",");
    driverExp = atoi(str.substr(0, (str.length() - saperatorP - 1)).c_str());
    str = str.substr(saperatorP + 1);
    vehiclId = atoi((str.substr(0)).c_str());
    if (vehiclId < 0) {
        throw exception();
    }
    //creating the driver
    Driver *driver = new Driver(driverId, driverAge, driverStatusStr,
                                driverExp);
    driver->setRequestedCabID(vehiclId);
    return driver;
}