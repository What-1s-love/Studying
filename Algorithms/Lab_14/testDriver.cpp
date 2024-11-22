// Бєліков В.В.
// ОПП на мові С++
// Лабораторна робота 14
// Кінцевий строк подання: 20 листопада
// Використано часу приблизно 40 хв
// Це моя власна робота. Не було використано сторонньої допомоги
//
// Нам потрібно створити матриці по графу який був наданий по варіанту.
//

#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    int numVertices = 9;
    Graph g(numVertices);

    // Додати ребра (граф з картинки)
    g.addEdge(0, 5);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 7);
    g.addEdge(3, 6);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(4, 7);
    g.addEdge(5, 0);
    g.addEdge(5, 1);
    g.addEdge(5, 4);
    g.addEdge(5, 8);
    g.addEdge(6, 3);
    g.addEdge(6, 8);
    g.addEdge(7, 2);
    g.addEdge(7, 4);
    g.addEdge(8, 5);
    g.addEdge(8, 6);

    // Друк матриці суміжності
    g.printAdjMatrix();

    // Друк списку суміжності
    g.printAdjList();

    return 0;
}
