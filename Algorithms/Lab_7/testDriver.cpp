// Бєл?ков В.В
// ОПП на мов? С++
// Лабораторна робота 7
// К?нцевий срок подання: 3 жовтня
// Використано часу приблизно 80 хв
// Це моя власна робота. Не було використано сторонньої допомоги
//
// Завдання: ми створюємо linked list(переписуємо з лекц?ї) та додаємо три нових метода
// Метод видалення, метод п?драхування елемент?в та метод вставлення п?сля елементу

#include "List.h"
#include <iostream>

int main() {
    List list;

    std::cout << "Створення списку: порожнiй" << std::endl;
    list.display();

    std::cout << "Вставка 3 на початок" << std::endl;
    list.insertAtFront(3);
    list.display();

    std::cout << "Вставка 1 на початок" << std::endl;
    list.insertAtFront(1);
    list.display();

    std::cout << "Вставка 7 в кiнець" << std::endl;
    list.insertAtEnd(7);
    list.display();

    std::cout << "Спроба вставки 5 пiсля 4" << std::endl;

    if (!list.insertAfter(4, 5)) {

        std::cout << "Немає елемента 4. Список не змiнився." << std::endl;

    }
    list.display();

    std::cout << "Вставка 5 пiсля 3" << std::endl;
    list.insertAfter(3, 5);
    list.display();

    std::cout << "Видалення 1" << std::endl;
    list.removeFromList(1);
    list.display();

    std::cout << "Видалення з кiнця" << std::endl;
    list.removeFromBack();
    list.display();

    std::cout << "Кiлькiсть вузлiв: " << list.numberOfNodes() << std::endl;

    return 0;
}
