#include "TaxiCenter.h"
#include "BFS.h"

TaxiCenter::TaxiCenter() {

}

TaxiCenter::TaxiCenter(int x) {
    x = 4;
    counter = 0;
}

void TaxiCenter::answerCall() {
    for (int j = 0; j < drivers.size(); ++j) {

        for (int i = 0; i < trips.size(); ++i) {
            if (trips.at(i).getStartPoint().isEqual(drivers.at(j).getCabInfo
                    ().getLocation())) {
                drivers.at(j).calculateWayToCostumer(trips.at(i).getEndPoint());
                trips.at(i).setDriver(drivers.at(j));
                continue;
            }
        }
    }
}

void TaxiCenter::sendCab() {
    counter++;
    reachedToDest = false;
    toSend = false;
    if (trips.empty()) {
        return;
    }
    if (trips.at(0).getCounter() == counter) {
        answerCall();
        return;
    } else if (trips.at(0).getCounter() < counter) {
        toSend = true;
        Driver d = trips.at(0).getDriver();

        list <Node> nodeList = d.getWayToCostumer();
        bool sendLocation = true;
        Node node;
        if (d.getCabInfo().getSpeed() != 1) {
            node = nodeList.front();
            nodeList.pop_front();
            if (node.isEqual(trips.at(0).getEndPoint())) {
                sendLocation = false;
            }
        }
        if (sendLocation) {
            node = nodeList.front();
            nodeList.pop_front();
        }

        d.updateCabLocation(node);
        d.setWayToCostumer(nodeList);
        trips.at(0).setDriver(d);
        int place = findDriverPlace(d);
        drivers.at(place) = d;
        if (node.isEqual(trips.at(0).getEndPoint())) {
            removeDriver(d);
            addDriver(d);
            reachedToDest = true;
            return;
        }
    }
}


void TaxiCenter::addDriver(Driver driver) {
    drivers.push_back(driver);
}

void TaxiCenter::removeDriver(Driver driver) {
    for (int i = 0; i < drivers.size(); i++) {
        if (drivers.at(i) == driver) {
            drivers.erase(drivers.begin() + i);
            return;
        }
    }
}

void TaxiCenter::addCab(BasicCab cab) {
    cabs.push_back(cab);
}

void TaxiCenter::removeCab(BasicCab cab) {
    for (int i = 0; i < cabs.size(); i++) {
        if (cabs.at(i) == cab) {
            cabs.erase(cabs.begin() + i);
            return;
        }
    }
}

void TaxiCenter::addTrip(TripInformation trip) {
    trips.push_back(trip);
}

void TaxiCenter::removeTrip(TripInformation trip) {
    for (int i = 0; i < trips.size(); i++) {
        if (trips.at(i) == trip) {
            trips.erase(trips.begin() + i);
            return;
        }
    }
}

vector<Driver> TaxiCenter::getDrivers() {
    return drivers;
}

vector<BasicCab> TaxiCenter::getCabs() {
    return cabs;
}

vector<TripInformation> TaxiCenter::getTrips() {
    return trips;
}


BasicCab TaxiCenter::findCabByID(int id) {
    for (int i = 0; i < cabs.size(); i++) {
        if (cabs.at(i).getId() == id) {
            return cabs.at(i);
        }
    }
}

Driver TaxiCenter::findDriverByID(int id) {
    for (int i = 0; i < drivers.size(); ++i) {
        if (drivers.at(i).getId() == id) {
            return drivers.at(i);
        }
    }
}

int TaxiCenter::findDriverPlace(Driver d) {
    for (int i = 0; i < drivers.size(); ++i) {
        if (d.isEqual(drivers.at(i))) {
            return i;
        }
    }
}

void TaxiCenter::updateGraph(Graph *g) {
    for (int i = 0; i < drivers.size(); ++i) {
        drivers.at(i).setGraph(g);
    }
}

bool TaxiCenter::isToSend() const {
    return toSend;
}


