#include <iostream>

using namespace std;

#include "Node.h"

Node::Node() {

}

Node::Node(Point p) {
    point = p;
    passed = false;
    numOfNeighbors = 4;
    validNode = true;
}

Node::~Node() {

}

void Node::deleteNeighbors() {
    for (int i = 0; i < numOfNeighbors; i++) {
        delete neighbors[i];
    }
}

Point Node::getPoint() {
    return point;
}

bool Node::getPassed() {
    return passed;
}

void Node::setPassed(bool psd) {
    passed = psd;
}

int Node::getNodePx() {
    return point.getX();
}

int Node::getNodePy() {
    return point.getY();
}

void Node::setValid(bool flag) {
    validNode = flag;
}

bool Node::getValid() {
    return validNode;
}

int Node::getNumOfNeighbors() {
    return numOfNeighbors;
}

bool Node::isEqual(Node n) {
    if (point.getX() == n.getNodePx() && point.getY() == n.getNodePy()) {
        return true;
    }
    return false;
}

void Node::validateNeighbors(int width, int height) {

    for (int i = 0; i < numOfNeighbors; ++i) {
        if (neighbors[i]->getNodePx() < 0 || neighbors[i]->getNodePy() < 0 ||
            neighbors[i]->getNodePx() >= width ||
            neighbors[i]->getNodePy() >= height) {
            neighbors[i]->setValid(false);
        } else {
            neighbors[i]->setValid(true);
        }
    }
}

Node Node::getNeighbor(int i) {
    return *(neighbors[i]);
}

ostream &operator<<(ostream &output, const Node &n) {
    output << n.point;
}

void Node::calcNeighbors() {
    neighbors[0] = new Node(Point(point.getX() - 1, point.getY()));
    neighbors[1] = new Node(Point(point.getX(), point.getY() + 1));
    neighbors[2] = new Node(Point(point.getX() + 1, point.getY()));
    neighbors[3] = new Node(Point(point.getX(), point.getY() - 1));
}