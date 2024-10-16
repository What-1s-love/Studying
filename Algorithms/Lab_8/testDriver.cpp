// Бєл?ков В.В.
// ОПП на мов? С++
// Лабораторна робота 8
// К?нцевий строк подання: 8 жовтня
// Використано часу приблизно 92 хв
// Це моя власна робота. Не було використано сторонньої допомоги
//
// Завдання: реал?зувати подв?йно пов?язаний список сл?в (doubly linked list of strings).
// Ус? методи з завдання 7 мусять бути присутн?ми.
// 
#include "DoublyLinkedList.h"
#include <iostream>

int main() {
    DoublyLinkedList list; // Створюємо новий двозв'язний список

    // Вставка елемент?в
    list.insertAtFront("apple");
    list.insertAtEnd("banana");
    list.insertAtFront("cherry");
    list.insertAtEnd("date");

    std::cout << "Список пiсля вставки: ";
    list.display(); // Виводимо список

    // Перев?рка наявност? вузла
    list.insertAfter("banana", "elderberry");
    std::cout << "Список пiсля вставки пiсля 'banana': ";
    list.display(); // Виводимо список

    // Видалення вузла
    list.removeFromList("cherry");
    std::cout << "Список пiсля видалення 'cherry': ";
    list.display(); // Виводимо список

    // К?льк?сть вузл?в
    std::cout << "Кiлькiсть вузлiв: " << list.numberOfNodes() << std::endl;

    // Видалення з початку та з к?нця
    list.removeFromFront();
    std::cout << "Список пiсля видалення з початку: ";
    list.display(); // Виводимо список
    list.removeFromBack();
    std::cout << "Список пiсля видалення з кiнця: ";
    list.display(); // Виводимо список

    return 0; // Завершення програми
}
