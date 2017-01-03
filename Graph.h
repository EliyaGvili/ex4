#ifndef EX1_GRAPH_H
#define EX1_GRAPH_H


#include "Node.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>

/*
 * The Graph class.
 * This is an abstract class with abstruct methods, (like interface).
 * It makes the program more generic in order that we could use it with
 * every Node.
 */
class Graph {

protected:
    int sizeX;
    int sizeY;

public:
    /*
     * setSource function that get 2 Nodes.
     * we implement this function in its dirived class.
     */
    virtual void setSource(Node node, Node sourceNode) = 0;

    /*
     * getSource function that get node.
     * we implement this function in its dirived class.
     */
    virtual Node getSource(Node node) = 0;

    /*
     * validateNeighbors function that get node and validate its neighbors.
     * we implement this function in its dirived class.
     */
    virtual void validateNeighbors(Node node) = 0;

    /*
     * Function that return the width.
     */
    int getWidth();

    /*
     * Function that return the height.
     */
    int getHeight();

    /*
     * Function that serialize the graph.
     */
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & sizeX;
        ar & sizeY;
    }


};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Graph);


#endif //EX1_GRAPH_H
