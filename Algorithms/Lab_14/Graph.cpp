#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int vertices) : numVertices(vertices) 
{
    // ����������� ������� ��������
    adjMatrix.resize(numVertices, vector<int>(numVertices, 0));

    // ����������� ������ ��������
    adjList = new AdjListNode * [numVertices];

    for (int i = 0; i < numVertices; ++i) 
    {
        adjList[i] = nullptr;
    }
}

Graph::~Graph() 
{
    // ��������� ������ ��������
    for (int i = 0; i < numVertices; ++i) 
    {
        AdjListNode* current = adjList[i];

        while (current) 
        {
            AdjListNode* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
    delete[] adjList;
}

void Graph::addEdge(int u, int v) 
{
    // ��������� ������� ��������
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;

    // ��������: �� ��� ���� ����� � ������ ��������
    AdjListNode* current = adjList[u];

    while (current) 
    {
        if (current->getVertex()->getValue() == v) 
        {
            return; // ����� ��� ����, �����
        }
        current = current->getNext();
    }

    // ��������� ������� v �� ������ ������� u
    Vertex* vertexV = new Vertex(v);
    AdjListNode* nodeV = new AdjListNode(vertexV);
    nodeV->setNext(adjList[u]);
    adjList[u] = nodeV;

    // ��������� ������� u �� ������ ������� v
    Vertex* vertexU = new Vertex(u);
    AdjListNode* nodeU = new AdjListNode(vertexU);
    nodeU->setNext(adjList[v]);
    adjList[v] = nodeU;
}


void Graph::printAdjMatrix() const 
{
    cout << "Adjacency Matrix:" << endl;

    for (int i = 0; i < numVertices; ++i) 
    {
        for (int j = 0; j < numVertices; ++j) 
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::printAdjList() const 
{
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < numVertices; ++i) 
    {
        cout << i << ": ";
        AdjListNode* current = adjList[i];

        while (current) 
        {
            cout << current->getVertex()->getValue() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
}
    