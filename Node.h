#ifndef EX1_NODE_H
#define EX1_NODE_H


#include <vector>
#include "Point.h"

/*
 * The Node class.
 * This class represents a Node.
 */
class Node {
private:
    Point point;
    bool passed;
    Node *neighbors[4];
    int numOfNeighbors;
    bool validNode;
public:
    /*
     * The Node constructor.
     */
    Node();

    /*
     * The Node constructor, gets a Point and creates a node.
     */
    Node(Point p);

    /*
     * The Node destructor.
     */
    ~Node();

    /*
     * getPoint function, returns the point.
     */
    Point getPoint();

    /*
     * getPassed function, returns passed.
     */
    bool getPassed();

    /*
     * setPassed function, sets the passed to the value given.
     */
    void setPassed(bool psd);

    /*
     * getNodePx function returns the x value of the point.
     */
    int getNodePx();

    /*
     * getNodePy function returns the y value of the point.
     */
    int getNodePy();

    /*
     * setValid function gets flag and sets the validNode.
     */
    void setValid(bool flag);

    /*
     * getValid function returns the validNode value.
     */
    bool getValid();

    /*
     * calcNeighbors function calculates the neighbors to the current node.
     */
    void calcNeighbors();

    /*
     * getNumOfNeighbors function returns numOfNeighbors value.
     */
    int getNumOfNeighbors();

    /*
     * Returns true if the given node is equal to the current node.
     */
    bool isEqual(Node n);

    /*
     * validateNeighbors function sets the validNode value of each neighbor.
     */
    void validateNeighbors(int width, int height);

    /*
     * getNeighbor function returns the i neighbor of the given node.
     */
    Node getNeighbor(int i);

    /*
     * The printing function, this function prints the point.
     */
    friend ostream &operator<<(ostream &output, const Node &N);

    /*
     * deleteNeighbors function that frees the memory that was allocated for
     * each neighbor.
     */
    void deleteNeighbors();

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & point;
        ar & passed;
        //ar & neighbors;
       // for (int i=0; i<4; i++){
        //    ar & neighbors[i];
       // }
        ar & numOfNeighbors;
        ar & validNode;
    }
};


#endif //EX1_NODE_H
