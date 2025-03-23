#include "Graph.h"
#include <iostream>
#include <fstream>
#include <set>
#include <stack>
#include <queue>
#include <limits.h>
#include <functional>

using namespace std;

Graph::Graph() {}

Graph::~Graph()
{
    for (auto node : adjList)
    {
        AdjListNode* current = node->nextPtr;

        while (current)
        {
            AdjListNode* temp = current;
            current = current->nextPtr;
            delete temp;
        }
        delete node->vertex;
        delete node;
    }
}

void Graph::addVertex(int data)
{
    for (const auto& node : adjList)
    {
        if (node->vertex->getData() == data)
        {
            cout << "Vertex " << data << " already exists. Skipping." << endl;
            return;
        }
    }

    Vertex* newVertexPtr = new Vertex(data, NOT_VISITED);
    AdjListNode* newAdjListNodePtr = new AdjListNode(newVertexPtr);
    adjList.push_back(newAdjListNodePtr);
}

void Graph::addEdge(int o, int d, int weight)
{
    AdjListNode* originAdjListNodePtr = nullptr;
    AdjListNode* destinationAdjListNodePtr = nullptr;

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

    AdjListNode* newAdjListNodePtr = new AdjListNode(destinationAdjListNodePtr->vertex);

    if (!originAdjListNodePtr->nextPtr)
    {
        originAdjListNodePtr->nextPtr = newAdjListNodePtr;
    }
    else
    {
        AdjListNode* tempAdjListNodePtr = originAdjListNodePtr->nextPtr;
        while (tempAdjListNodePtr->nextPtr)
            tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;

        tempAdjListNodePtr->nextPtr = newAdjListNodePtr;
    }

    // Store the weight for the edge
    edgeWeights[o][d] = weight;
    edgeWeights[d][o] = weight; // If it's an undirected graph
}

void Graph::loadFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int origin, destination, weight;
    while (file >> origin >> destination >> weight)
    {
        addVertex(origin);
        addVertex(destination);
        addEdge(origin, destination, weight);
    }
    file.close();
}

void Graph::dijkstra(int startVertex) const
{
    unordered_map<int, int> dist;
    unordered_map<int, int> prev;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (const auto& node : adjList)
    {
        dist[node->vertex->getData()] = INT_MAX;
    }

    dist[startVertex] = 0;
    pq.push({ 0, startVertex });

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (const auto& node : adjList)
        {
            if (node->vertex->getData() == u)
            {
                AdjListNode* tempAdjListNodePtr = node->nextPtr;
                while (tempAdjListNodePtr)
                {
                    int v = tempAdjListNodePtr->vertex->getData();
                    int weight = edgeWeights.at(u).at(v);

                    if (dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        prev[v] = u;
                        pq.push({ dist[v], v });
                    }

                    tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;
                }
            }
        }
    }

    for (const auto& pair : dist)
    {
        cout << "Vertex " << pair.first << " Distance: " << pair.second << endl;
    }
}

void Graph::findCriticalRoads() const {
    // Масиви для збереження часу відкриття та найменшого часу доступу
    unordered_map<int, int> disc, low, parent;
    unordered_map<int, bool> visited;
    int time = 0;

    // DFS допоміжна функція для пошуку мостів
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (const auto& node : adjList) {
            if (node->vertex->getData() == u) {
                AdjListNode* tempAdjListNodePtr = node->nextPtr;
                while (tempAdjListNodePtr) {
                    int v = tempAdjListNodePtr->vertex->getData();

                    if (!visited[v]) { // Якщо вершина не відвідана
                        parent[v] = u;
                        dfs(v);

                        low[u] = min(low[u], low[v]);

                        // Перевірка на критичний міст
                        if (low[v] > disc[u]) {
                            cout << "Critical road: " << u << " - " << v << endl;
                        }
                    }
                    else if (v != parent[u]) {
                        low[u] = min(low[u], disc[v]);
                    }

                    tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;
                }
            }
        }
        };

    // Виконати DFS для кожної невідвіданої вершини
    for (const auto& node : adjList) {
        int u = node->vertex->getData();
        if (!visited[u]) {
            dfs(u);
        }
    }
}


void Graph::removeEdge(int origin, int destination) {
    // Знайти вузли, що відповідають кожній з вершин
    AdjListNode* originAdjListNodePtr = nullptr;
    AdjListNode* destinationAdjListNodePtr = nullptr;

    for (auto& node : adjList) {
        if (node->vertex->getData() == origin)
            originAdjListNodePtr = node;
        if (node->vertex->getData() == destination)
            destinationAdjListNodePtr = node;
    }

    if (!originAdjListNodePtr || !destinationAdjListNodePtr) {
        cout << "One or both vertices do not exist." << endl;
        return;
    }

    // Видалення ребра з origin до destination
    AdjListNode* prev = nullptr;
    AdjListNode* temp = originAdjListNodePtr->nextPtr;
    while (temp) {
        if (temp->vertex->getData() == destination) {
            if (prev)
                prev->nextPtr = temp->nextPtr;
            else
                originAdjListNodePtr->nextPtr = temp->nextPtr;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->nextPtr;
    }

    // Видалення ребра з destination до origin (якщо граф невпорядкований)
    prev = nullptr;
    temp = destinationAdjListNodePtr->nextPtr;
    while (temp) {
        if (temp->vertex->getData() == origin) {
            if (prev)
                prev->nextPtr = temp->nextPtr;
            else
                destinationAdjListNodePtr->nextPtr = temp->nextPtr;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->nextPtr;
    }

    // Видалення ваги ребра
    edgeWeights[origin].erase(destination);
    edgeWeights[destination].erase(origin); // Якщо граф невпорядкований
}


void Graph::addNewEdge(int origin, int destination, int weight)
{
    addEdge(origin, destination, weight);
}

void Graph::simulateTrafficCongestion(int origin, int destination, int newWeight)
{
    edgeWeights[origin][destination] = newWeight;
    edgeWeights[destination][origin] = newWeight; // Assuming undirected graph
}

void Graph::printVertices() const
{
    for (const auto& node : adjList)
    {
        cout << node->vertex->getData() << " ";
    }
    cout << endl;
}

void Graph::printEdges() const
{
    for (const auto& node : adjList)
    {
        AdjListNode* tempAdjListNodePtr = node->nextPtr;
        while (tempAdjListNodePtr)
        {
            cout << node->vertex->getData() << " - ";
            cout << tempAdjListNodePtr->vertex->getData() << " Weight: " << edgeWeights.at(node->vertex->getData()).at(tempAdjListNodePtr->vertex->getData()) << endl;
            tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;
        }
    }
}

void Graph::resetStatuses() const
{
    for (const auto& node : adjList)
    {
        node->vertex->setStatus(NOT_VISITED);
    }
}

void Graph::dfs() const
{
    if (adjList.empty()) return;

    resetStatuses();

    stack<Vertex*> dfsStack;
    dfsStack.push(adjList[0]->vertex);
    adjList[0]->vertex->setStatus(VISITED);
    cout << adjList[0]->vertex->getData() << " ";

    while (!dfsStack.empty())
    {
        bool allNextVisited = true;
        Vertex* tempVertexPtr = dfsStack.top();

        for (const auto& node : adjList)
        {
            if (node->vertex == tempVertexPtr)
            {
                AdjListNode* tempAdjListNodePtr = node->nextPtr;

                while (tempAdjListNodePtr)
                {
                    Vertex* nextVertexPtr = tempAdjListNodePtr->vertex;

                    if (nextVertexPtr->getStatus() != VISITED)
                    {
                        dfsStack.push(nextVertexPtr);
                        nextVertexPtr->setStatus(VISITED);
                        cout << nextVertexPtr->getData() << " ";

                        allNextVisited = false;
                        break;
                    }
                    tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;
                }
            }
        }

        if (allNextVisited)
            dfsStack.pop();
    }
}

void Graph::bfs() const
{
    if (adjList.empty()) return;

    resetStatuses();

    queue<Vertex*> bfsQueue;
    bfsQueue.push(adjList[0]->vertex);
    adjList[0]->vertex->setStatus(VISITED);
    cout << adjList[0]->vertex->getData() << " ";

    while (!bfsQueue.empty())
    {
        Vertex* tempVertexPtr = bfsQueue.front();
        bfsQueue.pop();

        for (const auto& node : adjList)
        {
            if (node->vertex == tempVertexPtr)
            {
                AdjListNode* tempAdjListNodePtr = node->nextPtr;

                while (tempAdjListNodePtr)
                {
                    Vertex* nextVertexPtr = tempAdjListNodePtr->vertex;

                    if (nextVertexPtr->getStatus() != VISITED)
                    {
                        bfsQueue.push(nextVertexPtr);
                        nextVertexPtr->setStatus(VISITED);
                        cout << nextVertexPtr->getData() << " ";
                    }

                    tempAdjListNodePtr = tempAdjListNodePtr->nextPtr;
                }
            }
        }
    }
}
