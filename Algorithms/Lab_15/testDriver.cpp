// Бєліков В.В.
// ОПП на мові С++
// Лабораторна робота 11
// Кінцевий строк подання: 26 листопада
// Використано часу приблизно 130 хв
// Це моя власна робота. Не було використано сторонньої допомоги
//
// Завдання: Потрібно реалізувати орієнтований граф.
// Додати перевірки на унікальність у певних функціях та додати нові функції.
//

#include <iostream>
#include "Graph.h"

using namespace std;

void printMenu() {
    cout << "\nGraph Operations:\n";
    cout << "1. Add Vertex\n";
    cout << "2. Add Edge\n";
    cout << "3. Print Vertices\n";
    cout << "4. Print Edges\n";
    cout << "5. Number of Vertices\n";
    cout << "6. Check if Complete\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Graph graph;
    int choice, data, origin, destination;

    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter vertex value: ";
            cin >> data;
            graph.addVertex(data);
            break;
        case 2:
            cout << "Enter origin and destination: ";
            cin >> origin >> destination;
            graph.addEdge(origin, destination);
            break;
        case 3:
            cout << "Vertices:\n";
            graph.printVertices();
            break;
        case 4:
            cout << "Edges:\n";
            graph.printEdges();
            break;
        case 5:
            cout << "Number of vertices: " << graph.numberOfVertices() << endl;
            break;
        case 6:
            cout << (graph.isComplete() ? "Graph is complete.\n" : "Graph is not complete.\n");
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
