#include "Point.h"
#include <iostream>

using namespace std;

Point::Point() {
}

Point::Point(int a, int b) {
    x = a;
    y = b;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

bool Point::isEqual(Point p) {
    if (x == p.getX() && y == p.getY()) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &output, Point const &p) {
    Point p2 = p;
    output << '(' << p2.getX() << ',' << p2.getY() << ')';
}