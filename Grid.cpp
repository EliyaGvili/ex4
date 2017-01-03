//
// Created by eliyagvili on 23/11/16.
//

#include "Grid.h"


Grid::Grid() {

}

Grid::Grid(int width, int height) {
    sizeX = width;
    sizeY = height;
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            grid[i][j].setPassed(false);
            grid[i][j].setValid(true);
        }
    }
}

void Grid::setSource(Node node, Node sourceNode) {
    grid[node.getNodePx()][node.getNodePy()] = sourceNode;
}

Node Grid::getSource(Node node) {
    return grid[node.getNodePx()][node.getNodePy()];
}

void Grid::validateNeighbors(Node node) {
    node.validateNeighbors(sizeX, sizeY);
}

BOOST_CLASS_EXPORT(Grid);

