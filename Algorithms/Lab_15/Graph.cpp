#include "Graph.h"
#include <iostream>
#include <set> // ��� �������� ���������� �����

using namespace std;

Graph::Graph(void) {}

Graph::~Graph(void)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        AdjListNode* tempAdjListNodePtr = adjList[i];

        while (tempAdjListNodePtr->nextPtr)
        {
            AdjListNode* deleteAdjListNodePtr = tempAdjListNodePtr->nextPtr;
            cout << "deleting edge " << adjList[i]->vertex->getData() << " - ";
            cout << tempAdjListNodePtr->nextPtr->vertex->getData() << endl;
            tempAdjListNodePtr->nextPtr = tempAdjListNodePtr->nextPtr->nextPtr;
            delete deleteAdjListNodePtr;
        }
    }

    cout << endl;

    for (int i = 0; i < adjList.size(); i++)
    {
        AdjListNode* deleteAdjListNodePtr = adjList[i];
        Vertex* deleteVerterPtr = deleteAdjListNodePtr->vertex;

        cout << "deleting vertex" << deleteVerterPtr->getData() << endl;

        delete deleteVerterPtr;
        delete deleteAdjListNodePtr;
    }
}

// ������ �������� �� ���������� �������
void Graph::addVertex(int data)
{
    // ����������, �� ������� � ����� ��������� ��� ����
    for (const auto& node : adjList)
    {
        if (node->vertex->getData() == data)
        {
            cout << "Vertex " << data << " already exists. Skipping." << endl;
            return;
        }
    }

    // ������ ���� �������
    Vertex* newVertexPtr = new Vertex(data);
    AdjListNode* newAdjListNodePtr = new AdjListNode(newVertexPtr);
    adjList.push_back(newAdjListNodePtr);
}

// ������ �������� �� ���������� �����
void Graph::addEdge(int o, int d)
{
    AdjListNode* originAdjListNodePtr = nullptr;
    AdjListNode* destinationAdjListNodePtr = nullptr;

    // ����������, �� ������� ����� �������
    for (auto& node : adjList)
    {
        if (node->vertex->getData() == o)
            originAdjListNodePtr = node;
        if (node->vertex->getData() == d)
            destinationAdjListNodePtr = node;
    }

    if (!originAdjListNodePtr || !destinationAdjListNodePtr)
    {
        cout << "Edge cannot be created. One or both vertices do not exist." << endl;
        return;
    }

    // ����������, �� ����� ��� ����
    AdjListNode* temp = originAdjListNodePtr->nextPtr;
    while (temp)
    {
        if (temp->vertex->getData() == d)
        {
            cout << "Edge " << o << " -> " << d << " already exists. Skipping." << endl;
            return;
        }
        temp = temp->nextPtr;
    }

    // ������ ���� �����
    AdjListNode* newAdjListNodePtr = new AdjListNode(destinationAdjListNodePtr->vertex);

    AdjListNode* tempAdjListNodePtr = originAdjListNodePtr;
    while (tempAdjListNodePtr->nextPtr)
        tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;

    tempAdjListNodePtr->nextPtr = newAdjListNodePtr;
}

// ���� ������ �����
void Graph::printVertices() const
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << adjList[i]->vertex->getData() << " ";
    }
    cout << endl;
}

// ���� ����� �����
void Graph::printEdges() const
{
    for (int i = 0; i < adjList.size(); i++)
    {
        AdjListNode* tempAdjListNodePtr = adjList[i];

        while (tempAdjListNodePtr->nextPtr)
        {
            cout << adjList[i]->vertex->getData() << " - ";
            cout << tempAdjListNodePtr->nextPtr->vertex->getData() << endl;
            tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;
        }
    }
}

// ������ ����� ��� ��������� ������� ������
int Graph::numberOfVertices() const
{
    return adjList.size();
}

// ������ ����� ��� ��������, �� ���� � ������
bool Graph::isComplete() const
{
    int n = numberOfVertices();
    for (const auto& node : adjList)
    {
        int count = 0;
        AdjListNode* temp = node->nextPtr;
        while (temp)
        {
            count++;
            temp = temp->nextPtr;
        }
        if (count != n - 1)
        {
            return false;
        }
    }
    return true;
}
