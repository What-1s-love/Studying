#ifndef NODENODELIST_H
#define NODENODELIST_H

#include <string>

// Клас для представлення вузла двозв'язного списку
class NodeList {
public:
    std::string data;      // Значення вузла (рядок)
    NodeList* next;        // Вказівник на наступний вузол
    NodeList* prev;        // Вказівник на попередній вузол

    // Конструктор, який ініціалізує вузол з заданим значенням
    NodeList(const std::string& val);
};

#endif
