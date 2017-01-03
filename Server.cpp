//
// Created by may on 28/12/16.
//

#include <iostream>
#include "sockets/Udp.h"
#include "TaxiCenter.h"
#include "MainFlow.h"
#include <unistd.h>

int main() {

    Driver driver (2,3,MARRIED,4);

    //attaching the driver "fake" parameters just for the serialization
    Cab c (0,HONDA,GREEN);
    c.setLocation(Node(Point(0,0)));
    driver.setCab(c);
    Graph *graph;
    Grid grid (3,3);
    graph = &grid;
    driver.setGraph(graph);

    driver.calculateWayToCostumer(Node(Point(0,1)));


    TaxiCenter taxiCenter(4);
    MainFlow mainFlow (taxiCenter);
    mainFlow.startFlow();
    return 0;
}