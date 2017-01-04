#ifndef EX1_BFS_H
#define EX1_BFS_H


#include <queue>
#include <stack>
#include "Node.h"
#include "Graph.h"

/*
 * The BFA class.
 * run the bfs algoritem.
 */
class BFS {
private:
    std::stack <Node> nodeStack;
    Node dsNode;
public:
    BFS();

    /*
     * The BFS constructor.
     * Gets node.
     */
    BFS(Node n);

    /*
     * bfs function, get node, destination node, queue of nodes and pointer to
     * graph. It returns a node after calculating the shortest path between
     * the 2 nodes.
     */
    Node bfs(Node node, queue <Node> nodeQueue, Graph &graph);

    /*
     * addToStack function - adds to the stack the node it gets.
     */
    void addToStack(Node n);

    /*
     * printRoad function - prints the path that we saved in the stack.
     */
    void printRoad();

    /*
    * Function that returns a stack of Node that represent the fastest road.
    */
    stack <Node> returnFasterRoad();

    /*
     * Function that return stack of Nodes.
     */
    stack <Node> getNodeStack() const;

    /*
     * Function that return the destination node.
     */
    Node getDsNode() const;

};


#endif
