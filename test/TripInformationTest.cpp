
#include <gtest/gtest.h>
#include "../TripInformation.h"

/*
 * Test for the TripInformation class.
 */
namespace {
    class TripInformationTest : public testing::Test {
    public:
        TripInformation obj;

        TripInformationTest() {
            obj;
        }
    };
}

/*
 * Test that checks the id update.
 */
TEST_F(TripInformationTest, idTest) {
    TripInformation t(2, Point(0, 0), Point(1, 0), 1, 0);
    EXPECT_EQ(t.getId(), 2);
}

/*
 * Test that checks the start point update.
 */
TEST_F(TripInformationTest, startPointTest) {
    Node n1(Point(0, 0));
    Node n2(Point(1, 0));
    TripInformation t(2, n1, n2, 1, 0);
    EXPECT_TRUE(n1.isEqual(t.getStartPoint()));
}

/*
 * Test that checks the end point update.
 */
TEST_F(TripInformationTest, endPointTest) {
    Node n1(Point(0, 0));
    Node n2(Point(1, 0));
    TripInformation t(2, Point(0, 0), Point(1, 0), 1, 0);
    EXPECT_TRUE(n2.isEqual(t.getEndPoint()));
}

/*
 * Test that checks the passenger number update.
 */
TEST_F(TripInformationTest, passengersNumTest) {
    TripInformation t(2, Point(0, 0), Point(1, 0), 5, 0);
    EXPECT_EQ(t.getPassengersNum(), 5);
}

/*
 * Test that checks the tarrif update.
 */
TEST_F(TripInformationTest, tarrifTest) {
    TripInformation t(2, Point(0, 0), Point(1, 0), 1, 33.3);
    EXPECT_EQ(t.getTarrif(), 33.3);
}

/*
 * Test that checks the total meters update.
 */
TEST_F(TripInformationTest, totalMetersTest) {
    TripInformation t(2, Point(0, 0), Point(1, 0), 1, 3);
    EXPECT_EQ(t.getTotalMeters(), 0);
    t.updateTotalMeters(22);
    EXPECT_EQ(t.getTotalMeters(), 22);
}

/*
 * Test that checks the driver update.
 */
TEST_F(TripInformationTest, driverTest) {
    TripInformation t(2, Point(0, 0), Point(1, 0), 1, 3);
    Driver d(2, 10, SINGLE, 3);
    t.setDriver(d);
    EXPECT_TRUE(d.isEqual(t.getDriver()));
}

/*
 * Test that checks the updateDriverSatisfactionAndCostumers function.
 */
TEST_F(TripInformationTest, satAndCostTest) {
    Driver d(54, 10, SINGLE, 3);
    Passenger p(Point(3, 4), Point(5, 6));
    d.addPassenger(p);
    TripInformation t(2, Point(0, 0), Point(3, 5), 1, 3);
    t.setDriver(d);
    int satisfaction = t.getDriver().getAvgSatisfaction();
    int costumers = t.getDriver().getNumOfCostumers();


    t.updateDriverSatisfactionAndCostumers();
    /*we called in the updateDriverSatisfactionAndCostumers to the
    driver's 2 function: updateSatisfaction and uptadeCostumers.
    so, the members of the Driver - aveSaticfaction and numOfCostumers
    should not be the same as satisfaction and costumers.*/
    EXPECT_FALSE(satisfaction == t.getDriver().getAvgSatisfaction());
    EXPECT_FALSE(costumers == t.getDriver().getNumOfCostumers());
}

/*/
 * test that checks the equality of 2 trips by the "==" operator.
 */
TEST_F(TripInformationTest, boolEqualTest) {
    TripInformation t1(46, Point(4, 5), Point(6, 7), 3, 5);
    TripInformation t2(46, Point(4, 5), Point(6, 7), 3, 5);
    EXPECT_EQ(t1, t2);
    TripInformation t3(21, Point(4, 5), Point(3, 4), 2, 4);
    EXPECT_NE(t1, t3);
    EXPECT_NE(t2, t3);
}
