#ifndef GRAPH_H
#define GRAPH_H

#include "AdjListNode.h"
#include <vector>

class Graph {
public:
    Graph(int vertices);
    ~Graph();

    void addEdge(int u, int v);
    void printAdjMatrix() const;
    void printAdjList() const;

private:
    int numVertices;                // ʳ������ ������
    std::vector<std::vector<int>> adjMatrix; // ������� ��������
    AdjListNode** adjList;          // ������ ��������
};

#endif
