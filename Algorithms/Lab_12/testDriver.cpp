// Бєл?ков В.В.
// ОПП на мов? С++
// Лабораторна робота 12
// К?нцевий строк подання: 5 листопада
// Використано часу приблизно 60 хв
// Це моя власна робота. Не було використано сторонньої допомоги
//
// Завдання: Взяти за основу б?нарне дерево та реал?зувати гру.
//

#include <iostream>
#include "Set.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void displayRandomNumbers(Set& set) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 10 + 1;
        set.add(num);
        cout << num << " ";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl;
}

int main() {
    Set mySet;

    cout << "Generated random numbers:" << endl;
    displayRandomNumbers(mySet);

    cout << "Enter your guess for the number of unique values shown: ";
    int guess;
    cin >> guess;

    int actualCount = mySet.getSize(); // Використовуємо метод для отримання к?лькост? ун?кальних значень
    if (guess == actualCount) {
        cout << "Correct! There were " << actualCount << " unique values." << endl;
    }
    else {
        cout << "Incorrect. There were " << actualCount << " unique values." << endl;
    }

    return 0;
}
