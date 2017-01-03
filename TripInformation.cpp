#include "TripInformation.h"

TripInformation::TripInformation() {

}

TripInformation::TripInformation(int tripId, Node startP, Node endP, int pNum,
                                 double tarrif2, int givenCounter) {
    id = tripId;
    startPoint = startP;
    endPoint = endP;
    passengersNum = pNum;
    tarrif = tarrif2;
    totalMeters = 0;
    counter = givenCounter;
}


int TripInformation::getId() const {
    return id;
}

double TripInformation::getTotalMeters() const {
    return totalMeters;
}

Node TripInformation::getStartPoint() const {
    return startPoint;
}

Node TripInformation::getEndPoint() const {
    return endPoint;
}

int TripInformation::getPassengersNum() const {
    return passengersNum;
}

double TripInformation::getTarrif() const {
    return tarrif;
}

Driver TripInformation::getDriver() {
    return driver;
}

void TripInformation::setDriver(Driver d) {
    driver = d;
}


void TripInformation::updateTotalMeters(double meters) {
    totalMeters += meters;
}

void TripInformation::updateDriverSatisfactionAndCostumers() {
    driver.updateCostumers(passengersNum);
    int satisfaction = 0;
    for (int i = 0; i < passengersNum; i++) {
        satisfaction +=
                driver.getCurrentPassengers().front().calcSatisfaction();
        driver.getCurrentPassengers().pop_front();
    }
    satisfaction = satisfaction / passengersNum;
    driver.updateSatisfaction(satisfaction);
}

void TripInformation::updateDriverLocation(Node n) {
    driver.updateCabLocation(n);
}

int TripInformation::getCounter() {
    return counter;
}

bool TripInformation::operator==(const TripInformation &t) const {
    return id == t.id;
}

bool TripInformation::operator!=(const TripInformation &t) const {
    return !(t == *this);
}
