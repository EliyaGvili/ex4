#ifndef EX1_PASSENGER_H
#define EX1_PASSENGER_H


#include "Point.h"
#include "Node.h"

class Passenger {
private:
    Node startPoint;
    Node endPoint;
public:

    /*
     * The Passenger constructor.
     */
    Passenger();

    /*
     * The Passenger constructor.
     * Gets a start point and an end point.
     */
    Passenger(Node startP, Node endP);

    /*
     * Function that calculates satisfaction and returns it.
     * Should be a number between 1 to 5.
     */
    int calcSatisfaction();

    /*
     * Function that returns the start point.
     */
    const Node getStartPoint() const;

    /*
     * Function that returns the end point.
     */
    const Node getEndPoint() const;

    /*
     * Function that return true if the passenger that we get and the passenger
     * that we hold are equal, else return false.
     */
    bool isEqual(Passenger p);

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & startPoint;
        ar & endPoint;
    }


};


#endif