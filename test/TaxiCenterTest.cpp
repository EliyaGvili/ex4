
#include <gtest/gtest.h>
#include "../TaxiCenter.h"

/*
 * Test for the TaxiCenter Class.
 */
namespace {
    class TaxiCenterTest : public testing::Test {
    public:
        TaxiCenter obj;

        TaxiCenterTest() {
            obj;
        }

    };
}

/*
 * Test that checks the list of drives.
 * By default, when we create a TaxiCenter instance, the size of the drivers'
 * list should be 0. When we add one driver - it should be 1. Then, when we
 * remove the same driver - it should be 0 again.
 * the test also checks the findDriverByID function.
 */
TEST_F(TaxiCenterTest, driversTest) {
    TaxiCenter t(4);
    Driver d(2, 3, SINGLE, 0);
    int size1 = t.getDrivers().size();
    EXPECT_EQ(size1, 0);
    t.addDriver(d);
    int size2 = t.getDrivers().size();
    EXPECT_FALSE(size1 == size2);
    EXPECT_TRUE(d.isEqual(t.findDriverByID(2)));
    t.removeDriver(d);
    int size3 = t.getDrivers().size();
    EXPECT_FALSE(size3 == size2);
}

/*
 * Test that checks the list of cabs.
 * By default, when we create a TaxiCenter instance, the size of the cabs' list
 * should be 0. When we add one cab - it should be 1. Then, when we remove the
 * same cab - it should be 0 again.
 * the test also checks the findCabById function.
 */
TEST_F(TaxiCenterTest, cabsTest) {
    TaxiCenter t(4);
    Cab c(1, 0, TESLA, BLUE, 2, 0);
    int size1 = t.getCabs().size();
    EXPECT_EQ(size1, 0);
    t.addCab(c);
    int size2 = t.getCabs().size();
    EXPECT_FALSE(size1 == size2);
    EXPECT_TRUE(c.isEqual(t.findCabByID(1)));
    t.removeCab(c);
    int size3 = t.getCabs().size();
    EXPECT_FALSE(size2 == size3);
}

/*
 * Test that checks the list of tripInformations.
 * By default, when we create a TaxiCenter instance, the size of the trips'
 * list should be 0. When we add one tripInformation - it should be 1. Then,
 * when we remove the same trip - it should be 0 again.
 */
TEST_F(TaxiCenterTest, tripsTest) {
    TaxiCenter t(3);
    TripInformation ti(1, Point(0, 0), Point(1, 1), 3, 2.3);
    int size1 = t.getTrips().size();
    EXPECT_EQ(size1, 0);
    t.addTrip(ti);
    int size2 = t.getTrips().size();
    EXPECT_FALSE(size1 == size2);
    t.removeTrip(ti);
    int size3 = t.getTrips().size();
    EXPECT_FALSE(size2 == size3);
}

/*
 * Test that check the answerCall function and the sendCab function.
 * first we attach a cab to the driver, then by the answerCall we attach a
 * trip to the driver.
 * from that function, call the sendCab fucntion that should update the
 * driver's location.
 */
TEST_F(TaxiCenterTest, answeCallandSendCabTest) {
    TaxiCenter tc(3);
    Grid g(6, 6);
    Graph *graph = &g;
    Driver d(3, 4, SINGLE, 5);
    Node n(Point(2, 3));
    Cab c(2, 4, HONDA, GREEN, 4, 5);
    c.setLocation(n);
    d.setCab(c);
    d.setGraph(graph);
    tc.addDriver(d);
    tc.addCab(c);
    TripInformation ti(4, Node(Point(2, 3)), Node(Point(5, 4)), 5, 3);
    tc.addTrip(ti);
    //we attach the trip to the driver and we check if the right driver was
    // added. we also check if the location of the driver was updated correctly.
    tc.answerCall();
    EXPECT_TRUE(tc.getDrivers().at(0).getCabInfo().getLocation().isEqual
            (Node(Point(5, 4))));
    EXPECT_EQ(tc.getTrips().size(), 0);

}
