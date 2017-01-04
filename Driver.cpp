#include "Driver.h"
#include "BFS.h"

Driver::Driver() {

}

Driver::Driver(int id2, int age2, MartialStatus status, int experiance2) {
    id = id2;
    age = age2;
    mStatus = status;
    experiance = experiance2;
    numOfCostumers = 0;
    avgSatisfaction = 0;
}

Driver::~Driver() {

}

void Driver::setCab(BasicCab cab) {
    cabInfo = cab;
}

void Driver::setGraph(Graph *grid) {
    cityGrid = grid;
}

void Driver::updateCostumers(int costumers) {
    numOfCostumers += costumers;
}

void Driver::updateSatisfaction(int satisNum) {
    avgSatisfaction = (avgSatisfaction + satisNum);
    if (numOfCostumers != 0) {
        avgSatisfaction = avgSatisfaction / numOfCostumers;
    }
}

int Driver::getExperiance() const {
    return experiance;
}

BasicCab Driver::getCabInfo() {
    return cabInfo;
}

int Driver::getId() const {
    return id;
}

int Driver::getAge() const {
    return age;
}

MartialStatus Driver::getMStatus() const {
    return mStatus;
}

double Driver::getAvgSatisfaction() const {
    return avgSatisfaction;
}


int Driver::getNumOfCostumers() const {
    return numOfCostumers;
}

Graph *Driver::getCityGraph() {
    // Grid g (5,6);
    return cityGrid;
}

bool Driver::isEqual(Driver d2) {
    if (id = d2.getId()) {
        return true;
    }
    return false;
}

void Driver::addPassenger(Passenger p) {
    currentPassengers.push_back(p);
}

void Driver::clearCurrentPassengers() {
    currentPassengers.clear();
}

list <Passenger> Driver::getCurrentPassengers() {
    return currentPassengers;
}

void Driver::updateCabLocation(Node n) {
    cabInfo.setLocation(n);

}

stack <Node> Driver::calculateWayToCostumer(Node dstNode) {
    stack <Node> nodeStack;
    Node startNode = cabInfo.getLocation();
    queue <Node> nodeQueue;
    dstNode.setValid(true);
    Node oNode(Point(-1, -1));
    oNode.setValid(false);
    startNode.setValid(true);
    startNode.setPassed(true);
    oNode.setPassed(true);
    cityGrid->setSource(startNode, oNode);
    cityGrid->getSource(startNode).setPassed(true);
    nodeQueue.push(startNode);
    BFS bfs(dstNode);
    Node n = bfs.bfs(startNode, nodeQueue, *cityGrid);
    nodeStack = bfs.returnFasterRoad();
    int size = nodeStack.size();
    int j;
    for (int i = 0; i < size; ++i) {
        if (nodeStack.top().isEqual(startNode)) {
            nodeStack.pop();
            continue;
        }
        wayToCostumer.push_front(nodeStack.top());
        nodeStack.pop();
    }
    return nodeStack;
}

list <Node> Driver::getWayToCostumer() {
    return wayToCostumer;
}

ostream &operator<<(ostream &output, Driver const &d) {
    output << d.cabInfo.getLocation();
}

bool Driver::operator==(const Driver &d) const {
    return id == d.id;
}

bool Driver::operator!=(const Driver &d) const {
    return !(d == *this);
}

int Driver::getRequestedCabID() {
    return requestedCabID;
}

void Driver::setRequestedCabID(int requestedCabID) {
    Driver::requestedCabID = requestedCabID;
}

void Driver::setWayToCostumer(list <Node> givenWayToCostumer) {
    wayToCostumer = givenWayToCostumer;
}

void Driver::deleteGraph() {
    delete cityGrid;
}