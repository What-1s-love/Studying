#include "Graph.h"
#include <iostream>
#include <set> // Для перевірки унікальності ребер

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

// Додано перевірку на унікальність вершини
void Graph::addVertex(int data)
{
    // Перевіряємо, чи вершина з таким значенням уже існує
    for (const auto& node : adjList)
    {
        if (node->vertex->getData() == data)
        {
            cout << "Vertex " << data << " already exists. Skipping." << endl;
            return;
        }
    }

    // Додаємо нову вершину
    Vertex* newVertexPtr = new Vertex(data);
    AdjListNode* newAdjListNodePtr = new AdjListNode(newVertexPtr);
    adjList.push_back(newAdjListNodePtr);
}

// Додано перевірку на унікальність ребра
void Graph::addEdge(int o, int d)
{
    AdjListNode* originAdjListNodePtr = nullptr;
    AdjListNode* destinationAdjListNodePtr = nullptr;

    // Перевіряємо, чи існують обидві вершини
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

    // Перевіряємо, чи ребро вже існує
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

    // Додаємо нове ребро
    AdjListNode* newAdjListNodePtr = new AdjListNode(destinationAdjListNodePtr->vertex);

    AdjListNode* tempAdjListNodePtr = originAdjListNodePtr;
    while (tempAdjListNodePtr->nextPtr)
        tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;

    tempAdjListNodePtr->nextPtr = newAdjListNodePtr;
}

// Вивід вершин графу
void Graph::printVertices() const
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << adjList[i]->vertex->getData() << " ";
    }
    cout << endl;
}

// Вивід ребер графу
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

// Додано метод для підрахунку кількості вершин
int Graph::numberOfVertices() const
{
    return adjList.size();
}

// Додано метод для перевірки, чи граф є повним
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
