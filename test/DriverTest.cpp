#include <gtest/gtest.h>
#include <stack>
#include "../Driver.h"
#include "../LuxuryCab.h"

/*
 * test for Driver class.
 */

namespace {
    class DriverTests : public testing::Test {
    public:
        Driver obj;

        DriverTests() {
            obj;
        }
    };
}

/*
 * Test that checks the id update.
 */
TEST_F(DriverTests, idTest) {
    Driver d(2, 0, SINGLE, 0);
    EXPECT_EQ(d.getId(), 2);
}

/*
 * Test that checks the age update.
 */
TEST_F(DriverTests, ageTest) {
    Driver d(0, 2, SINGLE, 0);
    EXPECT_EQ(d.getAge(), 2);
}

/*
 * Test that checks the status update.
 */
TEST_F(DriverTests, statusTest) {
    Driver d(0, 0, MARRIED, 0);
    EXPECT_EQ(d.getMStatus(), MARRIED);
}

/*
 * Test that checks the experiance update.
 */
TEST_F(DriverTests, experianceTest) {
    Driver d(0, 0, SINGLE, 2);
    EXPECT_EQ(d.getExperiance(), 2);
}
/*
 * Test that checks the satisfaction update.
 */
TEST_F(DriverTests, satisfactionTest) {
    Driver d(0, 0, SINGLE, 0);
    EXPECT_EQ(d.getAvgSatisfaction(), 0);
    d.updateSatisfaction(4);
    EXPECT_EQ(d.getAvgSatisfaction(), 4);
}

/*
 * Test that checks the costumers update.
 */
TEST_F(DriverTests, costumersTest) {
    Driver d(0, 0, SINGLE, 2);
    EXPECT_EQ(d.getNumOfCostumers(), 0);
    d.updateCostumers(6);
    EXPECT_EQ(d.getNumOfCostumers(), 6);
}

/*
 * Test that checks the cab update.
 */
TEST_F(DriverTests, cabTest) {
    Driver d(0, 0, SINGLE, 0);
    Cab c(6, 0, HONDA, BLUE, 0, 0);
    d.setCab(c);
    //if it is a cab
    EXPECT_EQ(d.getCabInfo().getId(), 6);
    Cab c2(7, HONDA, GREEN);
    d.setCab(c2);
    EXPECT_EQ(d.getCabInfo().getId(), 7);

    //if it is a luxury cab
    LuxuryCab lc(2, 3, HONDA, GREEN, 3, 4);
    d.setCab(lc);
    EXPECT_EQ(d.getCabInfo().getId(), 2);
    LuxuryCab lc2(6, HONDA, GREEN);
    d.setCab(lc2);
    EXPECT_EQ(d.getCabInfo().getId(), 6);
}

/*
 * test that checks the equality of two drivers.
 */
TEST_F(DriverTests, isEqualTest) {
    Driver d1(2, 3, MARRIED, 5);
    Driver d2(2, 3, MARRIED, 5);
    EXPECT_TRUE(d1.isEqual(d2));
}
/*
 * Test that checks if a passenger was added
 * to the passenger's list successfully.
 */

TEST_F(DriverTests, passengersTest) {
    Passenger p(Point(2, 2), Point(3, 5));
    Driver d(2, 8, SINGLE, 5);
    //first there are no passengers, so the size should be 0.
    EXPECT_EQ(d.getCurrentPassengers().size(), 0);
    d.addPassenger(p);
    //now it should be 1.
    EXPECT_EQ(d.getCurrentPassengers().size(), 1);
    Passenger p2 = d.getCurrentPassengers().front();
    Node n = p.getStartPoint();
    //the 2 nodes should be equal
    EXPECT_TRUE(n.isEqual(p2.getStartPoint()));
    //now 0
    d.clearCurrentPassengers();
    EXPECT_EQ(d.getCurrentPassengers().size(), 0);
}

/*
 * Test that checks the cab location update.
 */
TEST_F(DriverTests, updateCabLocationTest) {
    Driver d(2, 3, SINGLE, 6);
    Cab c(2, 4.5, HONDA, GREEN, 5, 6);
    Node n(Point(3, 3));
    c.setLocation(n);
    EXPECT_TRUE(c.getLocation().isEqual(n));
    Node n2(Point(5, 5));
    d.updateCabLocation(n2);
    EXPECT_TRUE(n2.isEqual(d.getCabInfo().getLocation()));
}

/*
 * Test that checks the way to costumer function - checks if it really the
 * fastest way to the costumer according to the BFS algorithm.
 */
TEST_F(DriverTests, calculateWayToCostumerTest) {
    Driver d(3, 4, MARRIED, 6);
    Point p1(0, 0);
    Node n1(p1);
    Point p2(1, 2);
    Node dstNode(p2);
    Grid g(3, 3);
    d.setGraph(&g);
    Cab c(3, 2, HONDA, GREEN, 2, 3);
    d.setCab(c);
    d.updateCabLocation(n1);
    stack<Node> stack = d.calculateWayToCostumer(dstNode);
    Node n = stack.top();
    EXPECT_TRUE(n.isEqual(dstNode));
    stack.pop();
    n = stack.top();
    EXPECT_TRUE(n.isEqual(Node(Point(0, 2))));
    stack.pop();
    n = stack.top();
    EXPECT_TRUE(n.isEqual(Node(Point(0, 1))));
    stack.pop();
    n = stack.top();
    EXPECT_TRUE(n.isEqual(Node(Point(0, 0))));

}

/*
 * Test that checks if the driver's location was printed successfully.
 */
TEST_F(DriverTests, printTest) {
    std::ostringstream out;
    Driver d(3, 3, MARRIED, 5);
    Cab c(3, 4, HONDA, GREEN, 4, 5);
    c.setLocation(Point(4, 5));
    d.setCab(c);
    out << d;
    EXPECT_EQ("(4,5)", out.str());
}

/*
 * test that checks the equality of 2 drivers by the "==" operator
 */
TEST_F(DriverTests, boolEqualTest) {
    Driver d1(45, 3, SINGLE, 6);
    Driver d2(45, 3, SINGLE, 6);
    EXPECT_EQ(d1, d2);
    Driver d3(23, 4, SINGLE, 5);
    EXPECT_NE(d1, d3);
    EXPECT_NE(d2, d3);
}