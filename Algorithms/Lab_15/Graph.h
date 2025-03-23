#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "AdjListNode.h"

using namespace std;

class Graph
{
public:
    Graph();
    ~Graph();

    void addVertex(int data);
    void addEdge(int origin, int destination);
    int numberOfVertices() const;
    bool isComplete() const;

    void printVertices() const;
    void printEdges() const;

private:
    bool vertexExists(int data) const;
    bool edgeExists(int origin, int destination) const;

    vector<AdjListNode*> adjList;
};

#endif
