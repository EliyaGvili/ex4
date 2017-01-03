
#include <gtest/gtest.h>
#include "../MainFlow.h"

/*
 * Test for the MainFlow class.
 */

namespace {
    class MainFlowTest : public testing::Test {
    public:
        MainFlow obj;

        MainFlowTest() {
            obj;
        }
    };
}

/*
 * test that checks the validation of the grid's parameter input.
 */
TEST_F(MainFlowTest, validateGridParametersTest) {
    TaxiCenter tc(2);
    MainFlow mf(tc);

    EXPECT_FALSE(mf.validateGridParameters(-3, 4));
    EXPECT_FALSE(mf.validateGridParameters(3, -4));
    EXPECT_FALSE(mf.validateGridParameters(-3, -4));
    EXPECT_TRUE(mf.validateGridParameters(3, 4));
}

/*
 * test that checks the validation of the number of obstacles input.
 */
TEST_F(MainFlowTest, valiadateNumOfObstaclesTest) {
    TaxiCenter tc(3);
    MainFlow mf(tc);

    EXPECT_FALSE(mf.validateNumOfObstacles(-3));
    EXPECT_TRUE(mf.validateNumOfObstacles(7));
}

/*
 * test that checks the validation of the driver's parameters input.
 */
TEST_F(MainFlowTest, parseDriverTest) {
    TaxiCenter tc(3);
    MainFlow mf(tc);

    EXPECT_ANY_THROW(mf.parseDriver("-2,30,M,1,0"));
    EXPECT_ANY_THROW(mf.parseDriver("2,-30,M,1,0"));
    EXPECT_ANY_THROW(mf.parseDriver("2,30,J,1,0"));
    EXPECT_ANY_THROW(mf.parseDriver("2,30,M,-1,0"));
    EXPECT_ANY_THROW(mf.parseDriver("2,30,M,1,-3"));
    EXPECT_NO_THROW(mf.parseDriver("2,30,M,1,0"));
}

/*
 * test that checks the validation of the trip's parameters input.
 */
TEST_F (MainFlowTest, parseTripInformationTest) {
    TaxiCenter tc(3);
    MainFlow mf(tc);

    EXPECT_ANY_THROW(mf.parseTrip("-2,0,0,2,3,4,50"));
    EXPECT_ANY_THROW(mf.parseTrip("2,-3,0,3,4,2,5"));
    EXPECT_ANY_THROW(mf.parseTrip("2,3,-5,3,4,5,3"));
    EXPECT_ANY_THROW(mf.parseTrip("2,3,4,-5,4,2,4"));
    EXPECT_ANY_THROW(mf.parseTrip("2,3,4,5,-5,2,3"));
    EXPECT_ANY_THROW(mf.parseTrip("2,3,4,5,6,-2,4"));
    EXPECT_ANY_THROW(mf.parseTrip("2,3,4,5,6,2,-5"));
    EXPECT_NO_THROW(mf.parseTrip("2,3,4,5,2,4,2"));
}

/*
 * test that checks the validation of the vehicle's parameters input.
 */
TEST_F(MainFlowTest, parseVehicleTest) {
    TaxiCenter tc(3);
    MainFlow mf(tc);

    EXPECT_ANY_THROW(mf.parseVehicle("-1,1,H,G"));
    EXPECT_ANY_THROW(mf.parseVehicle("1,5,H,G"));
    EXPECT_ANY_THROW(mf.parseVehicle("1,5,J,G"));
    EXPECT_ANY_THROW(mf.parseVehicle("1,5,H,O"));
    EXPECT_NO_THROW(mf.parseVehicle("1,2,H,G"));
}

/*
 * test that checks the validation of a driver's id input.
 */
TEST_F(MainFlowTest, printDriverTest) {
    TaxiCenter tc(3);
    MainFlow mf(tc);

    EXPECT_ANY_THROW(mf.printDriverLocation("-4"));
}
