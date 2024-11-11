#ifndef NODELIST_H
#define NODELIST_H

#include <string>

// Структура вузла
struct Node {
    std::string data; // Дані вузла
    Node* next;       // Вказівник на наступний вузол

    // Конструктор вузла
    Node(const std::string& value) : data(value), next(nullptr) {}
};

#endif // NODELIST_H
