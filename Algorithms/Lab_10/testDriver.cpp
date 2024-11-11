// Бєл?ков В.В.
// ОПП на мов? С++
// Лабораторна робота 10
// К?нцевий строк подання: 22 жовтня
// Використано часу приблизно 100 хв
// Це моя власна робота. Не було використано сторонньої допомоги
//
// Завдання: реал?зувати cтек та методи до нього.
// 

#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stack; // Створюємо новий стек

    // Додаємо елементи до стека
    cout << "Додаємо елементи до стека:" << endl;
    stack.push("Перше");
    stack.push("Друге");
    stack.push("Третє");
    stack.push("Четверте");

    // Виводимо ?нформац?ю перед виконанням ?нших операц?й
    cout << "Кiлькiсть елементiв у стецi: " << stack.size() << endl;
    cout << "Верхнiй елемент: " << stack.top() << endl;

    // Виконуємо pop
    cout << "Виконую pop()..." << endl;
    stack.pop(); // Видаляємо верхн?й елемент
    cout << "Пiсля видалення:" << endl;
    cout << "Кiлькiсть елементiв у стецi: " << stack.size() << endl;
    cout << "Верхнiй елемент: " << stack.top() << endl;

    // Обм?нюємо верхн? два елементи
    cout << "Обмiнюю верхнi два елементи..." << endl;
    stack.swap();
    cout << "Пiсля обмiну:" << endl;
    cout << "Верхнiй елемент: " << stack.top() << endl;

    // Дублюємо верхн?й елемент
    cout << "Дублюю верхнiй елемент..." << endl;
    stack.duplicate();
    cout << "Пiсля дублювання:" << endl;
    cout << "Верхнiй елемент: " << stack.top() << endl;

    // Виконуємо rotate
    cout << "Виконую rotate(1)..." << endl;
    stack.rotate(1);
    cout << "Пiсля ротацiї:" << endl;
    cout << "Верхнiй елемент: " << stack.top() << endl;

    // Видаляємо вс? елементи
    cout << "Видаляю елементи:" << endl;
    while (!stack.isEmpty()) {
        string topElement = stack.top();
        cout << "Видаляю: " << topElement << endl;
        stack.pop(); // Видаляємо верхн?й елемент
    }

    // Перев?ряємо, чи стек порожн?й
    if (stack.isEmpty()) {
        cout << "Стек порожнiй." << endl;
    }

    return 0;
}

