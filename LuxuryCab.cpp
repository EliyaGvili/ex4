#include "LuxuryCab.h"

LuxuryCab::LuxuryCab() {

}

LuxuryCab::~LuxuryCab() {

}

LuxuryCab::LuxuryCab(int cabId, Manufacturer carM, Color carColor) {
    id = cabId;
    totalMeters = 0;
    carKind = carM;
    color = carColor;
    tarrif = 2;
    speed = 2;
    location = Node(Point(0, 0));

}

LuxuryCab::LuxuryCab(int cabId, double meters, Manufacturer carM,
                     Color carColor, double carTarrif, int cabSpeed) {
    id = cabId;
    totalMeters = meters;
    carKind = carM;
    color = carColor;
    tarrif = carTarrif;
    speed = cabSpeed;
    location = Node(Point(0, 0));
}
