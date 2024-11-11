#include "List.h"
#include <iostream>

List::List() : head(nullptr), count(0) {}

List::~List() {
    while (!isEmpty()) {
        removeFromHead();
    }
}

void List::insertAtHead(const std::string& value) {
    Node* newNode = new Node{ value, head }; // Створюємо новий вузол
    head = newNode; // Новий вузол стає головою
    count++; // Збільшуємо лічильник
}

void List::removeFromHead() {
    if (isEmpty()) {
        throw std::runtime_error("Список порожній."); // Якщо список порожній, викидаємо помилку
    }

    Node* temp = head; // Зберігаємо голову
    head = head->next; // Зсуваємо голову на наступний елемент
    delete temp; // Видаляємо стару голову
    count--; // Зменшуємо лічильник
}

Node* List::getHead() const {
    return head; // Повертаємо голову списку
}

bool List::isEmpty() const {
    return head == nullptr; // Якщо голова порожня, список порожній
}

int List::size() const {
    return count; // Повертаємо кількість елементів у списку
}
