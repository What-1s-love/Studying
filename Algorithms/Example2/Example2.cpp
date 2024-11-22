#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Структура для оператора з кодом та поштовим індексом
struct Operator {
    string code;
    int postalCode;
};

// Генерація випадкового номера телефону
string generatePhoneNumber(string operatorCode) {
    string number = operatorCode;
    for (int i = 0; i < 7; i++) {
        number += '0' + rand() % 10;
    }
    return number;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел

    // Масив операторів з кодами та поштовими індексами
    Operator operators[] = {
        {"067", 40000}, {"068", 40000}, {"096", 40000}, {"097", 40000}, {"098", 40000},
        {"050", 40000}, {"066", 40000}, {"095", 40000}, {"099", 40000}, {"063", 40000},
        {"067", 40100}, {"068", 40100}, {"096", 40100}, {"097", 40100}, {"098", 40100},
        {"050", 40100}, {"066", 40100}, {"095", 40100}, {"099", 40100}, {"063", 40100},
        {"067", 40200}, {"068", 40200}, {"096", 40200}, {"097", 40200}, {"098", 40200},
        {"050", 40200}, {"066", 40300}, {"095", 40300}, {"099", 40300}, {"063", 40300},
        {"067", 40300}, {"068", 40300}, {"096", 40400}, {"097", 40400}, {"098", 40400},
        {"050", 40400}, {"066", 40400}, {"095", 40500}, {"099", 40500}, {"063", 40500},
        {"067", 40500}, {"068", 40500}, {"096", 40600}, {"097", 40600}, {"098", 40600},
        {"050", 40600}, {"066", 40600}, {"095", 40600}, {"099", 40600}, {"063", 40600}
    };

    int numOperators = sizeof(operators) / sizeof(operators[0]); // Кількість операторів

    // Відкриваємо файл для запису
    ofstream outFile("PhoneNumbers.txt");
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Генерація 10000 номерів
    for (int i = 0; i < 10000; i++) {
        // Вибір випадкового оператора
        Operator selectedOperator = operators[rand() % numOperators];

        // Генерація випадкового номера з кодом оператора
        string phoneNumber = generatePhoneNumber(selectedOperator.code);

        // Запис номера телефону та поштового індексу в файл
        outFile << phoneNumber << " " << selectedOperator.postalCode << endl;
    }

    outFile.close(); // Закриття файлу
    cout << "10000 phone numbers generated and saved to PhoneNumbers.txt" << endl;

    return 0;
}
