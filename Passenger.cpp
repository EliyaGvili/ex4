#include <cstdlib>
#include "Passenger.h"

Passenger::Passenger() {

}

Passenger::Passenger(Node startP, Node endP) {
    startPoint = startP;
    endPoint = endP;
}

int Passenger::calcSatisfaction() {
    int satisfaction = rand() % 5 + 1;
    return satisfaction;
}

const Node Passenger::getStartPoint() const {
    return startPoint;
}

const Node Passenger::getEndPoint() const {
    return endPoint;
}

bool Passenger::isEqual(Passenger p) {
    if ((startPoint.isEqual(p.getStartPoint())) &&
        (endPoint.isEqual(p.getEndPoint()))) {
        return true;
    }
    return false;
}
