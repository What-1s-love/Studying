#include "DoublyLinkedList.h"
#include <iostream>

// Конструктор, ініціалізує вказівники на nullptr
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Деструктор, видаляє всі вузли списку
DoublyLinkedList::~DoublyLinkedList() {

    while (!isEmpty()) {
        removeFromFront();  // Видалення вузлів з початку, поки список не стане пустим
    }
}

// Вставка вузла з заданим значенням на початок списку
void DoublyLinkedList::insertAtFront(const std::string& value) {
    NodeList* newNode = new NodeList(value);  // Створення нового вузла

    if (isEmpty()) {
        head = newNode;      // Якщо список пустий, встановлюємо голову
        tail = newNode;      // Встановлюємо хвіст
    }
    else {
        newNode->next = head; // Новий вузол вказує на поточну голову
        head->prev = newNode;  // Поточна голова вказує на новий вузол як на попередній
        head = newNode;        // Новий вузол стає головою
    }
}

// Вставка вузла з заданим значенням в кінець списку
void DoublyLinkedList::insertAtEnd(const std::string& value) {
    NodeList* newNode = new NodeList(value); // Створення нового вузла

    if (isEmpty()) {
        head = newNode;  // Якщо список пустий, встановлюємо голову
        tail = newNode;   // Встановлюємо хвіст
    }
    else {
        tail->next = newNode; // Поточний хвіст вказує на новий вузол
        newNode->prev = tail;  // Новий вузол вказує на поточний хвіст як на попередній
        tail = newNode;        // Новий вузол стає хвостом
    }
}

// Вставка нового значення після заданого
bool DoublyLinkedList::insertAfter(const std::string& target, const std::string& newValue) {
    NodeList* current = head; // Починаємо з голови

    while (current) {

        if (current->data == target) { // Якщо знайшли цільовий вузол
            NodeList* newNode = new NodeList(newValue); // Створюємо новий вузол
            newNode->next = current->next; // Новий вузол вказує на наступний
            newNode->prev = current;       // Новий вузол вказує на поточний

            if (current->next) {
                current->next->prev = newNode; // Наступний вузол вказує на новий
            }
            current->next = newNode; // Поточний вузол вказує на новий

            if (current == tail) {
                tail = newNode; // Якщо це останній вузол, оновлюємо хвіст
            }
            return true; // Успішно вставлено
        }
        current = current->next; // Переходимо до наступного вузла
    }
    return false; // Ціль не знайдена
}

// Видалення вузла за значенням
bool DoublyLinkedList::removeFromList(const std::string& value) {
    NodeList* current = head; // Починаємо з голови

    while (current) {

        if (current->data == value) { // Якщо знайшли вузол для видалення
            if (current->prev) {
                current->prev->next = current->next; // Оновлюємо попередній вузол
            }
            else {
                head = current->next; // Якщо видаляємо голову, оновлюємо голову
            }

            if (current->next) {
                current->next->prev = current->prev; // Оновлюємо наступний вузол
            }
            else {
                tail = current->prev; // Якщо видаляємо хвіст, оновлюємо хвіст
            }
            delete current; // Видаляємо вузол
            return true; // Успішно видалено
        }
        current = current->next; // Переходимо до наступного вузла
    }
    return false; // Вузол не знайдено
}

// Підрахунок кількості вузлів у списку
int DoublyLinkedList::numberOfNodes() const {
    int count = 0; // Лічильник вузлів
    NodeList* current = head; // Починаємо з голови

    while (current) {
        count++; // Збільшуємо лічильник
        current = current->next; // Переходимо до наступного вузла
    }
    return count; // Повертаємо кількість вузлів
}

// Видалення останнього вузла
void DoublyLinkedList::removeFromBack() {

    if (isEmpty()) return; // Якщо список пустий, нічого не робимо

    NodeList* toDelete = tail; // Запам'ятовуємо останній вузол

    if (tail->prev) {
        tail = tail->prev; // Оновлюємо хвіст
        tail->next = nullptr; // Оновлюємо вказівник на наступний вузол
    }
    else {
        head = nullptr; // Якщо список став пустим
        tail = nullptr; // Якщо список став пустим
    }
    delete toDelete; // Видаляємо вузол
}

// Видалення першого вузла
void DoublyLinkedList::removeFromFront() {

    if (isEmpty()) return; // Якщо список пустий, нічого не робимо

    NodeList* toDelete = head; // Запам'ятовуємо перший вузол
    head = head->next; // Оновлюємо голову

    if (head) {
        head->prev = nullptr; // Оновлюємо вказівник на попередній вузол
    }
    else {
        tail = nullptr; // Якщо список став пустим
    }
    delete toDelete; // Видаляємо вузол
}

// Перевірка, чи список пустий
bool DoublyLinkedList::isEmpty() const {
    return head == nullptr; // Повертаємо true, якщо голова рівна nullptr
}

// Виведення списку
void DoublyLinkedList::display() const {
    NodeList* current = head; // Починаємо з голови
    while (current) {
        std::cout << current->data << " "; // Виводимо дані вузла
        current = current->next; // Переходимо до наступного вузла
    }
    std::cout << std::endl; // Перехід на новий рядок
}
