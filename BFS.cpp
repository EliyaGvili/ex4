#include <iostream>
#include <stack>
#include "BFS.h"

using namespace std;

BFS::BFS() {

}

BFS::BFS(Node n) {
    dsNode = n;
}

void BFS::addToStack(Node n) {
    nodeStack.push(n);
}


Node BFS::bfs(Node node, queue<Node> nodeQueue, Graph &graph) {
    int i;
    int numOfNeighbors = node.getNumOfNeighbors();
    //calc the node neighbors.
    node.calcNeighbors();
    graph.validateNeighbors(node);
    //run on every neighber.
    for (i = 0; i < numOfNeighbors; i++) {
        if (node.getNeighbor(i).getValid()) {
            if (node.getNeighbor(i).isEqual(dsNode)) {
                graph.setSource(node.getNeighbor(i), node);
                addToStack(node.getNeighbor(i));
                Node n = node.getNeighbor(i);
                //delete the neighbors before return.
                node.deleteNeighbors();
                return n;
            } else if (!(graph.getSource(node.getNeighbor(i)).getPassed())) {
                nodeQueue.push(node.getNeighbor(i));
                node.setPassed(true);
                graph.setSource(node.getNeighbor(i), node);
                addToStack(node.getNeighbor(i));
            }
        }
    }
    //delete the neighbors before return.
    node.deleteNeighbors();
    nodeQueue.pop();
    Node returnNode = bfs(nodeQueue.front(), nodeQueue, graph);
    if (graph.getSource(returnNode).getValid()) {
        addToStack(graph.getSource(returnNode));
        return graph.getSource(returnNode);
    } else {
        return returnNode;
    }
}

stack<Node> BFS::returnFasterRoad() {
    stack<Node> stack;
    for (int i = 0; i < nodeStack.size(); i++) {
        stack.push(nodeStack.top());
        if (nodeStack.top().isEqual(dsNode)) {
            return stack;
        }
        nodeStack.pop();
    }
}

void BFS::printRoad() {
    bool found = false;
    for (int i = 0; i < nodeStack.size(); i++) {
        Node node = nodeStack.top();
        if (!found) {
            cout << node << endl;
            if (nodeStack.top().isEqual(dsNode)) {
                found = true;
            }
        }
        nodeStack.pop();
    }
}

stack<Node> BFS::getNodeStack() const {
    return nodeStack;
}

Node BFS::getDsNode() const {
    return dsNode;
}