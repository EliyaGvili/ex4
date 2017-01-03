
#include <gtest/gtest.h>
#include "../BasicCab.h"
#include "../Cab.h"
#include "../LuxuryCab.h"

/*
 * tests for Basic-Cab Class
 * all of the test are checked on Cab and Luxury-Cab.
 */

namespace {
    class BasicCabTest : public testing::Test {
    public:
        BasicCab obj;

        BasicCabTest() {
            obj;
        }
    };
}

/*
 * Test that checks the Manufacturer update.
 */
TEST_F(BasicCabTest, ManufacturerTest) {
    Cab c(0, 0, TESLA, BLUE, 0, 0);
    EXPECT_EQ(TESLA, c.getCarKind());
    Cab c2(2, HONDA, GREEN);
    EXPECT_EQ(HONDA, c2.getCarKind());

    LuxuryCab lc(0, 0, HONDA, GREEN, 2, 3);
    EXPECT_EQ(HONDA, lc.getCarKind());
    LuxuryCab lc2(3, TESLA, GREEN);
    EXPECT_EQ(TESLA, lc2.getCarKind());
}

/*
 * Test that checks the color update.
 */
TEST_F(BasicCabTest, ColorTest) {
    Cab c(0, 0, HONDA, BLUE, 0, 0);
    EXPECT_EQ(BLUE, c.getColor());
    Cab c2(2, HONDA, GREEN);
    EXPECT_EQ(GREEN, c2.getColor());

    LuxuryCab lc(0, 0, HONDA, GREEN, 0, 0);
    EXPECT_EQ(GREEN, lc.getColor());
    LuxuryCab lc2(1, HONDA, GREEN);
    EXPECT_EQ(GREEN, lc2.getColor());
}

/*
 * Test that checks the id update.
 */
TEST_F(BasicCabTest, idTest) {
    Cab c(2, 0, HONDA, BLUE, 0, 0);
    EXPECT_EQ(c.getId(), 2);
    Cab c2(3, HONDA, GREEN);
    EXPECT_EQ(c2.getId(), 3);

    LuxuryCab lc(7, 3, HONDA, GREEN, 3, 4);
    EXPECT_EQ(lc.getId(), 7);
    LuxuryCab lc2(5, HONDA, GREEN);
    EXPECT_EQ(lc2.getId(), 5);
}

/*
 * Test that checks the tarrif update.
 */
TEST_F(BasicCabTest, tarrifTest) {
    Cab c(0, 0, HONDA, BLUE, 2, 0);
    EXPECT_EQ(c.getTarrif(), 2);
    Cab c2(2, HONDA, GREEN);
    EXPECT_EQ(c2.getTarrif(), 1);

    LuxuryCab lc(2, 3, HONDA, GREEN, 5, 7);
    EXPECT_EQ(lc.getTarrif(), 5);
    LuxuryCab lc2(5, HONDA, GREEN);
    EXPECT_EQ(lc2.getTarrif(), 2);

}

/*
 * Test that check the speed update.
 */
TEST_F(BasicCabTest, speedTest) {
    Cab c(0, 0, HONDA, BLUE, 0, 7);
    EXPECT_EQ(c.getSpeed(), 7);
    Cab c2(3, HONDA, GREEN);
    EXPECT_EQ(c2.getSpeed(), 1);

    LuxuryCab lc(3, 3, HONDA, GREEN, 3, 4);
    EXPECT_EQ(lc.getSpeed(), 4);
    LuxuryCab lc2(2, HONDA, GREEN);
    EXPECT_EQ(lc2.getSpeed(), 2);


}

/*
 * Test that checks the meters update.
 */
TEST_F(BasicCabTest, metersTest) {
    Cab c(0, 2, HONDA, BLUE, 0, 0);
    EXPECT_EQ(c.getTotalMeters(), 2);
    c.updateTotalMeters(5);
    EXPECT_EQ(c.getTotalMeters(), 7);
    Cab c2(3, HONDA, GREEN);
    EXPECT_EQ(c2.getTotalMeters(), 0);
    c2.updateTotalMeters(4);
    EXPECT_EQ(c2.getTotalMeters(), 4);

    LuxuryCab lc(2, 3, HONDA, GREEN, 3, 4);
    EXPECT_EQ(lc.getTotalMeters(), 3);
    lc.updateTotalMeters(4);
    EXPECT_EQ(lc.getTotalMeters(), 7);
    LuxuryCab lc2(4, HONDA, GREEN);
    EXPECT_EQ(lc2.getTotalMeters(), 0);
    lc2.updateTotalMeters(6);
    EXPECT_EQ(lc2.getTotalMeters(), 6);

}

/*
 * Test that checks the equality of two cars.
 */
TEST_F (BasicCabTest, isEqualTest) {
    Cab c1(1, 2, HONDA, GREEN, 3, 4);
    Cab c2(1, 2, HONDA, GREEN, 3, 4);
    EXPECT_TRUE(c1.isEqual(c2));
    Cab c3(4, HONDA, GREEN);
    Cab c4(4, HONDA, GREEN);
    EXPECT_TRUE(c3.isEqual(c4));

    LuxuryCab lc1(2, 3, HONDA, GREEN, 5, 6);
    LuxuryCab lc2(2, 3, HONDA, GREEN, 5, 6);
    EXPECT_TRUE(lc1.isEqual(lc2));
    LuxuryCab lc3(4, HONDA, GREEN);
    LuxuryCab lc4(4, HONDA, GREEN);
    EXPECT_TRUE(lc3.isEqual(lc4));
}

/*
 * Test that checks the cab location update.
 */
TEST_F(BasicCabTest, locationTest) {
    Cab c(1, 2, HONDA, GREEN, 3, 4);
    EXPECT_TRUE(c.getLocation().isEqual(Node(Point(0, 0))));
    Node n(Point(3, 3));
    c.setLocation(n);
    EXPECT_TRUE(n.isEqual(c.getLocation()));
    Cab c2(2, HONDA, GREEN);
    EXPECT_TRUE(c2.getLocation().isEqual((Node(Point(0, 0)))));
    Node n2(Point(5, 6));
    c2.setLocation(n2);
    EXPECT_TRUE(n2.isEqual(c2.getLocation()));

    LuxuryCab lc(3, 4, HONDA, GREEN, 3, 5);
    EXPECT_TRUE(lc.getLocation().isEqual(Node(Point(0, 0))));
    Node n3(Point(4, 5));
    lc.setLocation(n3);
    EXPECT_TRUE(n3.isEqual(lc.getLocation()));
    LuxuryCab lc2(3, HONDA, GREEN);
    EXPECT_TRUE(lc2.getLocation().isEqual(Node(Point(0, 0))));
    Node n4(Point(2, 5));
    lc2.setLocation(n4);
    EXPECT_TRUE(n4.isEqual(lc2.getLocation()));

}

/*
 * test that checks the equality of 2 cabs by the "==" operator
 */
TEST_F(BasicCabTest, boolEqualTest) {
    Cab c1(34, 2, HONDA, GREEN, 7, 8);
    Cab c2(34, 2, HONDA, GREEN, 7, 8);
    EXPECT_EQ(c1, c2);
    Cab c3(45, 2, HONDA, GREEN, 4, 6);
    EXPECT_NE(c1, c3);
    EXPECT_NE(c2, c3);
    Cab c4(42, HONDA, GREEN);
    Cab c5(42, HONDA, GREEN);
    EXPECT_EQ(c4, c5);
    Cab c6(23, HONDA, GREEN);
    EXPECT_NE(c4, c6);
    EXPECT_NE(c5, c6);

    LuxuryCab lc1(25, 3, HONDA, GREEN, 3, 4);
    LuxuryCab lc2(25, 3, HONDA, GREEN, 3, 4);
    EXPECT_EQ(lc1, lc2);
    LuxuryCab lc3(23, 4, HONDA, GREEN, 3, 5);
    EXPECT_NE(lc1, lc3);
    EXPECT_NE(lc2, lc3);
    LuxuryCab lc4(34, HONDA, GREEN);
    LuxuryCab lc5(34, HONDA, GREEN);
    EXPECT_EQ(lc4, lc5);
    LuxuryCab lc6(24, HONDA, GREEN);
    EXPECT_NE(lc4, lc6);
    EXPECT_NE(lc5, lc6);


}
