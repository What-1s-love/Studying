#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "NodeList.h"

// Клас для представлення двозв'язного списку
class DoublyLinkedList {
private:
    NodeList* head;  // Вказівник на перший вузол
    NodeList* tail;  // Вказівник на останній вузол

public:
    DoublyLinkedList();  // Конструктор
    ~DoublyLinkedList(); // Деструктор

    // Методи для роботи з двозв'язним списком
    void insertAtFront(const std::string& value);
    void insertAtEnd(const std::string& value);
    bool insertAfter(const std::string& target, const std::string& newValue);
    bool removeFromList(const std::string& value);
    int numberOfNodes() const;  // Підрахунок вузлів
    void removeFromBack();       // Видалення останнього вузла
    void removeFromFront();      // Видалення першого вузла
    bool isEmpty() const;        // Перевірка, чи пустий список
    void display() const;        // Виведення списку
};

#endif
