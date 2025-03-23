// Бєл?ков В.В.
// ОПП на мов? С++
// Лабораторна робота 16
// К?нцевий строк подання: 29 листопада
// Використано часу приблизно 240 хв
// Це моя власна робота. Але мен? допом?г чат гпт
//
// Завдання: Потр?бно реал?зувати мережу м?ста(графом) та додати нов? методи
// 
//

#include <iostream>
#include "Graph.h"

using namespace std;

void printMenu()
{
    cout << "----- Menu -----" << endl;
    cout << "1. Load graph from file" << endl;
    cout << "2. Print all vertices" << endl;
    cout << "3. Print all edges" << endl;
    cout << "4. Run Dijkstra's Algorithm" << endl;
    cout << "5. Find critical roads (bridges)" << endl;
    cout << "6. Remove an edge" << endl;
    cout << "7. Add a new edge" << endl;
    cout << "8. Simulate traffic congestion" << endl;
    cout << "9. Exit" << endl;
    cout << "-----------------" << endl;
}

int main()
{
    Graph cityGraph;
    bool running = true;
    int choice;

    while (running)
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string filename;
            cout << "Enter the filename to load the graph from: ";
            cin >> filename;
            cityGraph.loadFromFile(filename);
            break;
        }
        case 2:
        {
            cityGraph.printVertices();
            break;
        }
        case 3:
        {
            cityGraph.printEdges();
            break;
        }
        case 4:
        {
            int startVertex;
            cout << "Enter the start vertex for Dijkstra's algorithm: ";
            cin >> startVertex;
            cityGraph.dijkstra(startVertex);
            break;
        }
        case 5:
        {
            cityGraph.findCriticalRoads();
            break;
        }
        case 6:
        {
            int origin, destination;
            cout << "Enter the origin vertex of the edge to remove: ";
            cin >> origin;
            cout << "Enter the destination vertex of the edge to remove: ";
            cin >> destination;
            cityGraph.removeEdge(origin, destination);
            break;
        }
        case 7:
        {
            int origin, destination, weight;
            cout << "Enter the origin vertex of the new edge: ";
            cin >> origin;
            cout << "Enter the destination vertex of the new edge: ";
            cin >> destination;
            cout << "Enter the weight of the new edge: ";
            cin >> weight;
            cityGraph.addNewEdge(origin, destination, weight);
            break;
        }
        case 8:
        {
            int origin, destination, newWeight;
            cout << "Enter the origin vertex for traffic congestion: ";
            cin >> origin;
            cout << "Enter the destination vertex for traffic congestion: ";
            cin >> destination;
            cout << "Enter the new weight for the congested road: ";
            cin >> newWeight;
            cityGraph.simulateTrafficCongestion(origin, destination, newWeight);
            break;
        }
        case 9:
        {
            cout << "Exiting the program..." << endl;
            running = false;
            break;
        }
        default:
        {
            cout << "Invalid choice, please try again." << endl;
            break;
        }
        }
    }

    return 0;
}
