#ifndef EX1_TRIPINFORMATION_H
#define EX1_TRIPINFORMATION_H


#include "Point.h"
#include "Driver.h"

class TripInformation {
private:

    int id;
    double totalMeters;
    Node startPoint;
    Node endPoint;
    int passengersNum;
    double tarrif;
    Driver driver;
    int counter;

public:
    /*
     * The TripInformation constructor.
     */
    TripInformation();

    /*
     * The TripInformation constructor.
     * Gets a trip id, start point, end point, num of passengers and tarrif.
     */
    TripInformation(int tripId, Node startP, Node endP, int pNum,
                    double tarrif, int givenCounter);

    /*
     * Function that gets a driver and sets the driver the
     * tripInformation holds.
     */
    void setDriver(Driver d);

    /*
     * The function gets meters and updates the total meters number.
     */
    void updateTotalMeters(double meters);

    /*
     * Function that updates the satisfaction and the costumers of the driver.
     */
    void updateDriverSatisfactionAndCostumers();

    /*
     * Function that returns the id.
     */
    int getId() const;

    /*
     * Function that returns the total meters number.
     */
    double getTotalMeters() const;

    /*
     * Function that returns the start point.
     */
    Node getStartPoint() const;

    /*
     * Function that returns the start point.
     */
    Node getEndPoint() const;

    /*
     * Function that returns the passengers number.
     */
    int getPassengersNum() const;

    /*
     * Function that returns the tarrif.
     */
    double getTarrif() const;

    /*
     * Function that returns the driver.
     */
    Driver getDriver();

    /*
     * function that update the driver location.
     * get a node.
     */
    void updateDriverLocation(Node n);

    /*
     * Function that equals two trips with the operator ==.
     */
    bool operator==(const TripInformation &rhs) const;

    /*
     * Function that equals two trips with the operator !=.
     */
    bool operator!=(const TripInformation &rhs) const;

    /*
     * Function that return the trip counter.
     */
    int getCounter();
};


#endif //EX1_TRIPINFORMATION_H