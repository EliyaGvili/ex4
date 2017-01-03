
#include <gtest/gtest.h>
#include "../Grid.h"

/*
 * Test for the Grid class.
 */
namespace {
    class GridTests : public testing::Test {
    public:
        Grid obj;

        GridTests() {
            obj;
        }
    };
}

/*
 * Test that checks the x and y update.
 */
TEST_F(GridTests, getXandYTests) {
    Grid grid(3, 4);
    int x = grid.getWidth();
    EXPECT_EQ(x, 3);
    int y = grid.getHeight();
    EXPECT_EQ(y, 4);
}

/*
 * Test that checks the source point update.
 */
TEST_F(GridTests, sourceTest) {
    Grid grid(10, 10);
    Point p(2, 2);
    Node node(p);
    Point sourcePoint(1, 2);
    Node sourceNode(sourcePoint);
    grid.setSource(node, sourceNode);
    EXPECT_TRUE(sourceNode.isEqual(grid.getSource(node)));
}

/*
 * Test that check the validation of the neighbors update.
 */
TEST_F(GridTests, validateNeighborsTest) {
    Grid grid(10, 10);
    Point p(0, 1);
    Node n(p);
    n.calcNeighbors();
    grid.validateNeighbors(n);
    EXPECT_FALSE(n.getNeighbor(0).getValid());
    EXPECT_TRUE(n.getNeighbor(1).getValid());
    EXPECT_TRUE(n.getNeighbor(2).getValid());
    EXPECT_TRUE(n.getNeighbor(3).getValid());
    n.deleteNeighbors();

}

/*
 * Test that check the equality of two grids.
 */
TEST_F(GridTests, isEqualTest) {
    Grid g1(4, 6);
    Grid g2(4, 6);
    EXPECT_TRUE(g1.isEqual(g2));
}
