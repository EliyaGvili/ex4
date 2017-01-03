#include "Cab.h"

Cab::Cab() {

}

Cab::Cab(int cabId, Manufacturer carM, Color carColor) {
    id = cabId;
    totalMeters = 0;
    carKind = carM;
    color = carColor;
    tarrif = 1;
    speed = 1;
    location = Node(Point(0, 0));
}

Cab::Cab(int cabId, double meters, Manufacturer carM, Color carColor,
         double caTarrif, int cabSpeed) {
    id = cabId;
    totalMeters = meters;
    carKind = carM;
    color = carColor;
    tarrif = caTarrif;
    speed = cabSpeed;
    location = Node(Point(0, 0));
}