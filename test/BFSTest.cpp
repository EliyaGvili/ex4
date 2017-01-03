
#include <gtest/gtest.h>
#include "../BFS.h"
#include "../Grid.h"

/*
 * Test for the BFS class.
 */
namespace {
    class BFSTest : public testing::Test {
    public:
        BFS obj;

        BFSTest() {
            obj;
        }

    };
}
/*
 * A test that checks if the right node was added to the class.
 */

TEST_F(BFSTest, getDsNodeTest) {
    Point p(2, 2);
    Node n(p);
    BFS bfs(n);
    EXPECT_TRUE(n.isEqual(bfs.getDsNode()));
}

/*
 * A test that checks the correction of the stack.
 */
TEST_F(BFSTest, stackTest) {
    Node n(Point(2, 2));
    BFS bfs(n);
    EXPECT_EQ(bfs.getNodeStack().size(), 0);
    Node n2(Point(3, 3));
    bfs.addToStack(n2);
    EXPECT_EQ(bfs.getNodeStack().size(), 1);
    Node n3 = bfs.getNodeStack().top();
    EXPECT_TRUE(n2.isEqual(n3));
    bfs.getNodeStack().pop();
}

/*
 * A test that checks if the returnFasterRoad
 * function is the right road by the bfs.
 */
TEST_F(BFSTest, roadTest) {
    Node n(Point(0, 0));
    Grid grid(3, 3);
    Graph *graph = &grid;
    queue<Node> nodeQueue;
    Node dstNode(Point(2, 2));
    dstNode.setValid(true);
    Node outN(Point(-1, -1));
    outN.setValid(false);
    n.setValid(true);
    n.setPassed(true);
    outN.setPassed(true);
    graph->setSource(n, outN);
    graph->getSource(n).setPassed(true);
    nodeQueue.push(n);
    BFS bfs(dstNode);
    bfs.bfs(n, nodeQueue, *graph);
    stack<Node> stack = bfs.returnFasterRoad();
    EXPECT_TRUE(stack.top().isEqual(Node(Point(2, 2))));
    stack.pop();
    EXPECT_TRUE(stack.top().isEqual(Node(Point(1, 2))));
    stack.pop();
    EXPECT_TRUE(stack.top().isEqual(Node(Point(0, 2))));
    stack.pop();
    EXPECT_TRUE(stack.top().isEqual(Node(Point(0, 1))));
    stack.pop();
    EXPECT_TRUE(stack.top().isEqual(Node(Point(0, 0))));
    stack.pop();
}