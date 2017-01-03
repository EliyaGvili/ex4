
#include <gtest/gtest.h>
#include "../Point.h"


/*
 * Test for the Point class.
 */
namespace {
    class PointTests : public testing::Test {
    public:
        Point obj;

        PointTests() {
            obj;
        }
    };
}

/*
 * Test that checks the equality of two points.
 */
TEST_F(PointTests, isEqualTest) {
    Point p1(3, 5);
    Point p2(3, 5);
    EXPECT_TRUE(p1.isEqual(p2));

}

/*
 * Test that checks the x update.
 */
TEST_F(PointTests, getXTest) {
    Point p(2, 7);
    EXPECT_EQ(p.getX(), 2);
}

/*
 * Test that checks the y update.
 */
TEST_F(PointTests, getYTest) {
    Point p(2, 7);
    EXPECT_EQ(p.getY(), 7);
}

/*
 * Test that checks the print function.
 */
TEST_F(PointTests, printTest) {
    std::ostringstream out;
    Point p(3, 5);
    out << p;
    EXPECT_EQ("(3,5)", out.str());
}
