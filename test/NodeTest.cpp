
#include <gtest/gtest.h>
#include "../Node.h"


/*
 * Test for the Node class.
 */

namespace {
    class NodeTests : public testing::Test {
    public:
        Node obj;

        NodeTests() {
            obj;
        }

    };
}

/*
 * Test that checks the point update.
 */
TEST_F(NodeTests, pointTest) {
    Point p(5, 7);
    Node n(p);
    EXPECT_TRUE(p.isEqual(n.getPoint()));
    EXPECT_EQ(n.getNodePx(), 5);
    EXPECT_EQ(n.getNodePy(), 7);

}

/*
 * Test that checks the passed update.
 */
TEST_F(NodeTests, boolTest) {
    Point p(3, 4);
    Node n(p);
    EXPECT_FALSE(n.getPassed());
    n.setPassed(true);
    EXPECT_TRUE(n.getPassed());
}

/*
 * Test that checks the valid update of the node.
 */
TEST_F(NodeTests, validTest) {
    Point p(3, 4);
    Node n(p);
    n.setValid(true);
    EXPECT_TRUE(n.getValid());

}

/*
 * Test that checks the numOfNeighbors - by default, when we create a Node
 * instance, it should be 4.
 */
TEST_F(NodeTests, numOfNeighborsTest) {
    Point p(2, 2);
    Node n(p);
    EXPECT_EQ(n.getNumOfNeighbors(), 4);

}

/*
 * Test that checks the equality of two nodes.
 */
TEST_F(NodeTests, isEqualTest) {
    Point p1(3, 4);
    Point p2(3, 4);
    Node n1(p1);
    Node n2(p2);
    EXPECT_TRUE(n1.isEqual(n2));
    EXPECT_TRUE(n2.isEqual(n1));
}

/*
 * test that checks the neighbors update - if they were created and added
 * successfully. afterwards, we call the deleteNeighbours function that frees
 * the memory we allocated for each neighbor.
 */
TEST_F(NodeTests, neighborsTest) {
    Point p(5, 3);
    Node n1(p);
    n1.calcNeighbors();
    Node n2(p);
    n2 = n1.getNeighbor(0);
    EXPECT_EQ(n2.getNodePx(), 4);
    EXPECT_EQ(n2.getNodePy(), 3);
    n2 = n1.getNeighbor(1);
    EXPECT_EQ(n2.getNodePx(), 5);
    EXPECT_EQ(n2.getNodePy(), 4);
    n2 = n1.getNeighbor(2);
    EXPECT_EQ(n2.getNodePx(), 6);
    EXPECT_EQ(n2.getNodePy(), 3);
    n2 = n1.getNeighbor(3);
    EXPECT_EQ(n2.getNodePx(), 5);
    EXPECT_EQ(n2.getNodePy(), 2);
    n1.deleteNeighbors();

}

/*
 * Test that checks the validation of each neighbour in a specified point.
 */
TEST_F(NodeTests, validateNeighborsTest) {
    Point p(0, 2);
    Node n(p);
    n.calcNeighbors();
    n.validateNeighbors(10, 10);
    EXPECT_FALSE(n.getNeighbor(0).getValid());
    EXPECT_TRUE(n.getNeighbor(1).getValid());
    EXPECT_TRUE(n.getNeighbor(2).getValid());
    EXPECT_TRUE(n.getNeighbor(3).getValid());
    n.deleteNeighbors();
}

/*
 * Test that checks the print function.
 */
TEST_F(NodeTests, printTest) {
    std::ostringstream out;
    Point p(6, 7);
    Node n(p);
    out << n;
    EXPECT_EQ("(6,7)", out.str());
}
