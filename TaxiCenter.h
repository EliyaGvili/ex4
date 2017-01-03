#ifndef EX1_TAXICENTER_H
#define EX1_TAXICENTER_H

#include <list>
#include <map>
#include "Driver.h"
#include "Cab.h"
#include "TripInformation.h"
#include "Passenger.h"

using namespace std;

/*
 * The TaxiCenter class.
 * creates a taxi center.
 */
class TaxiCenter {
private:
    vector<Driver> drivers;
    vector<BasicCab> cabs;
    vector<TripInformation> trips;
    Graph *cleanGraph;
    vector<Node> obstacles;
    int counter;
    bool reachedToDest;
    bool toSend;
public:

    /*
     * The TaxiCenter constructor.
     */
    TaxiCenter();

    /*
     * The TaxiCenter constructor.
     * Gets  a x.
     */
    TaxiCenter(int x);

    /*
     * This function attaches a trip to a driver.
     */
    void answerCall();

    /*
     * This function calls the callculateWayToCostumer in the driver's class,
     * remove him from the Taxi-Center, then updates the driver location,
     * add add the updated driver again.
     * him from the
     */
    void sendCab();

    /*
     * Function that gets a driver and adds it to the drivers list.
     */
    void addDriver(Driver driver);

    /*
     * Function that gets driver and removes it from the drivers list.
     */
    void removeDriver(Driver driver);

    /*
     * Function that returns the drivers list.
     */
    vector<Driver> getDrivers();

    /*
     * Function that gets a cab and adds it to the cabs list.
     */
    void addCab(BasicCab cab);

    /*
     * Function that gets cab and removes it from the cabs list.
     */
    void removeCab(BasicCab cab);

    /*
     * Function that returns the cabs list.
     */
    vector<BasicCab> getCabs();

    /*
     * Function that gets a trip and adds it to the trips list.
     */
    void addTrip(TripInformation trip);

    /*
     * Function that gets trip and removes it from the trips list.
     */
    void removeTrip(TripInformation trip);

    /*
     * Function that returns the trips list.
     */
    vector<TripInformation> getTrips();

    /*
     * Function that gets a Driver, and removes it from the locations' map.
     */
    void removeLocation(Driver d);

    /*
     * Function that find a cab by its id.
     * Gets an id.
     */
    BasicCab findCabByID(int id);

    /*
     * Function that finds  driver by its id.
     * Gets an id.
     */
    Driver findDriverByID(int id);

    /*
     * Function that update the graph.
     * get a graph.
     */
    void updateGraph(Graph *g);

    /*
     * Function that get driver and return its place in the taxi center.
     */
    int findDriverPlace(Driver d);

    /*
     * Function that return is to sent true.
     */
    bool isToSend() const;

    /*
     * Function that return is reached true.
     */
    bool isReached() const;
};


#endif