#include <iostream>
#include <vector> // Додано для використання std::vector
#include "Stack.h"
#include "List.h"

// Додає елемент на верх стека
void Stack::push(const std::string& value) {
    list.insertAtHead(value); // Додаємо новий елемент на початок списку
}

// Видаляє верхній елемент стека
void Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Стеки порожній.");
    }
    list.removeFromHead(); // Видаляємо верхній елемент зі списку
}

// Повертає верхній елемент стека
std::string Stack::top() const {
    if (isEmpty()) {
        throw std::runtime_error("Стеки порожній.");
    }
    return list.getHead()->value; // Отримуємо верхній елемент
}

// Повертає кількість елементів у стеці
int Stack::size() const {
    return list.size(); // Використовуємо метод size() списку
}

// Дублює верхній елемент
void Stack::duplicate() {
    if (isEmpty()) {
        throw std::runtime_error("Стеки порожній.");
    }
    std::string topValue = top();
    push(topValue); // Додаємо його назад на верх
}

// Обмінює верхні два елементи
void Stack::swap() {
    if (size() < 2) {
        throw std::runtime_error("Недостатньо елементів для обміну.");
    }

    std::string first = top();
    pop(); // Видаляємо перший
    std::string second = top();
    pop(); // Видаляємо другий
    push(first); // Додаємо перший назад
    push(second); // Додаємо другий назад
}

// Повертає true, якщо стек порожній
bool Stack::isEmpty() const {
    return list.isEmpty(); // Перевіряємо, чи порожній список
}

void Stack::rotate(int n) {
    if (isEmpty() || size() < 2) {
        return; // Нічого не робимо, якщо стек порожній або містить менше 2 елементів
    }

    std::vector<std::string> elements; // Вектор для зберігання елементів
    while (!isEmpty()) {
        elements.push_back(top()); // Додаємо верхній елемент в вектор
        pop(); // Видаляємо верхній елемент
    }

    // Обчислюємо нову позицію для верхнього елемента
    n = n % elements.size(); // Беремо залишок від ділення, щоб уникнути перевищення
    for (int i = elements.size() - n; i < elements.size(); i++) {
        push(elements[i]); // Додаємо нові верхні елементи
    }
    for (int i = 0; i < elements.size() - n; i++) {
        push(elements[i]); // Додаємо решту елементів
    }
}