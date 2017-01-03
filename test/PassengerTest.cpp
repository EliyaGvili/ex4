
#include <gtest/gtest.h>
#include "../Passenger.h"


/*
 * Test for the Passenger class.
 */
namespace {
    class PassengerTest : public testing::Test {
    public:
        Passenger obj;

        PassengerTest() {
            obj;
        }
    };
}

/*
 * Test that checks if the start point and the destination point were connected
 * to the passenger successfully.
 */
TEST_F(PassengerTest, getPoints) {
    Node n1(Point(2, 3));
    Node n2(Point(3, 4));
    Passenger passenger(n1, n2);
    EXPECT_TRUE(n1.isEqual(passenger.getStartPoint()));
    EXPECT_TRUE(n2.isEqual(passenger.getEndPoint()));
}

/*
 * Test that checks the satisfaction update - the value of satisfaction should
 * be between 1 to 5 (that means that: 1<=satisfaction<=5).
 */
TEST_F(PassengerTest, satisfactionTest) {
    Point p1(2, 3);
    Point p2(3, 4);
    Passenger passenger(p1, p2);
    int x = passenger.calcSatisfaction();
    EXPECT_GE(x, 1);
    EXPECT_LE(x, 5);
}

/*
 * Test that checks the equally of 2 passengers.
 */
TEST_F(PassengerTest, isEqualTest) {
    Passenger p1(Point(3, 4), Point(6, 7));
    Passenger p2(Point(3, 4), Point(6, 7));
    EXPECT_TRUE(p1.isEqual(p2));
}
