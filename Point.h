//
// Created by eliyagvili on 18/11/16.
//

#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

using namespace boost::archive;
using namespace std;

/*
 * The Point class.
 * The class represents a point on the axis.
 */
class Point {
private:
    int x;
    int y;
public:
    /*
     * The Point constructor.
     */
    Point();

    /*
     * The Point constructor.
     * Receives a value and b value.
     */
    Point(int a, int b);

    /*
     * getX function, return the x value.
     */
    int getX();

    /*
     * getY function, return the y value.
     */
    int getY();

    /*
     * isEqual function, gets a Point and return true if the x values and the
     * y values are equal to the values of our point.
     */
    bool isEqual(Point p);

    /*
     * The printing function, this function prints the point.
     */
    friend ostream &operator<<(ostream &output, const Point &p);

    /*
     * Function that serialize point.
     */
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & x;
        ar & y;
    }
};


#endif //EX1_POINT_H
