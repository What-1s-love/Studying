#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include "AdjListNode.h"
#include "Vertex.h"
#include <string>

using namespace std;

class Graph
{
public:
    Graph();
    ~Graph();

    void addVertex(int data);
    void addEdge(int origin, int destination, int weight);
    void printVertices() const;
    void printEdges() const;
    void dfs() const;
    void bfs() const;

    void loadFromFile(const string& filename);
    void dijkstra(int startVertex) const;
    void findCriticalRoads() const;
    void removeEdge(int origin, int destination);
    void addNewEdge(int origin, int destination, int weight);
    void simulateTrafficCongestion(int origin, int destination, int newWeight);

private:
    void resetStatuses() const; // Helper to reset statuses for all vertices
    vector<AdjListNode*> adjList;
    unordered_map<int, unordered_map<int, int>> edgeWeights;
};

#endif
