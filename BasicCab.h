
#ifndef EX3_BASICCAB_H
#define EX3_BASICCAB_H


#include "Point.h"
#include "Node.h"

/*
 * The BasicCab class.
 * This is an abstract class with abstruct methodes, (like interface).
 * It makes the program more generic in order that we could use it with every cab.
 */
enum Manufacturer {
    HONDA = 0, SUBARO = 1, TESLA = 2, FIAT = 3
};
enum Color {
    RED = 0, BLUE = 1, GREEN = 2, PINK = 3, WHITE = 4
};

class BasicCab {
protected:
    int id;
    double totalMeters;
    double tarrif;
    int speed;
    Manufacturer carKind;
    Color color;
    Node location;
public:

    BasicCab();

    /*
     * Function that return the car kind (manufacturer).
     */
    Manufacturer getCarKind() const;

    /*
     *  Function that returns the cab color.
     */
    Color getColor() const;

    /*
     *  Function that returns the cab id.
     */
    int getId() const;

    /*
     *  Function that returns the tarrif.
     */
    double getTarrif() const;

    /*
     *  Function that returns the cab speed.
     */
    int getSpeed() const;

    /*
     *  Function that returns the total meters.
     */
    double getTotalMeters() const;

    /*
     * function that gets total meters and updates it.
     */
    void updateTotalMeters(double meters);

    /*
     * Function that returns the location.
     */
    Node getLocation() const;

    /*
     * Function that gets point and updates the cab location.
     */
    void setLocation(Node givenLoaction);

    /*
     * Function that return true if two cabs are equal,
     * false otherwise.
     */
    bool isEqual(BasicCab bc);

    /*
     * Function that equals two cabs with the operator ==.
     */
    bool operator==(const BasicCab &rhs) const;

    /*
     * Function that equals two cabs with the operator !=.
     */
    bool operator!=(const BasicCab &rhs) const;

    /*
     * Function that prints cab with <<.
     */
    friend ostream &operator<<(ostream &output, const BasicCab &c);

    /*
     * Function that serialize
     */
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & id;
        ar & totalMeters;
        ar & tarrif;
        ar & speed;
        ar & carKind;
        ar & color;
        ar & location;
    }
};

#endif //EX3_BASICCAB_H