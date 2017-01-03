#ifndef EX1_MAINFLOW_H
#define EX1_MAINFLOW_H


#include "TaxiCenter.h"
#include "sockets/Socket.h"

class MainFlow {
private:
    TaxiCenter taxiCenter;
    Graph *graph;

public:
    /*
     * The MainFlow constructor.
     */
    MainFlow();

    /*
     * The MainFlow constructor.
     * Gets a Taxi-Center.
     */
    MainFlow(TaxiCenter t);

    /*
     * Function that parses the driver's details and creates a driver.
     */
    void parseDriver(string str) throw(exception);

    /*
     * Function that parses the trip's details and creates a trip.
     */
    void parseTrip(string str) throw(exception);

    /*
     * Function that parses the vehicle's details and creates a vehicle.
     */
    void parseVehicle(string str) throw(exception);

    /*
     * Function that gets a driver id from the user, and prints the
     * driver's location.
     */
    void printDriverLocation(string str) throw(exception);

    /*
     * Function that validates the number of obstacles given from the user.
     */
    bool validateNumOfObstacles(int numOfObstacles);

    /*
     * Function that validates the grid's parameters given from the user.
     */
    bool validateGridParameters(int x, int y);

    /*
     * The function that runs the program - there are 7 choices, every number
     * between 1-7 calls another mission.
     */
    void startFlow();

    /*
     * Function that recive driver from the socket.
     */
    void recieveDriver(Socket *socket);

};


#endif
