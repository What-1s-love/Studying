// Бєл?ков В.В
// ОПП на мов? С++
// Лабораторна робота 6
// К?нцевий срок подання: 26 вересня
// Використано часу 120 хв
// Це моя власна робота. Був використан чат гпт
//
// Створюємо два класи та реал?зуємо методи. Виводимо ?нформац?ю про кожен об'єкт 

#include <iostream>
#include "Teacher.h"
#include "HeadTeacher.h"

int main() {
    // Створення об'єкт?в клас?в

    Teacher teacher1("Олександр", 40, "Математика", 15);
    HeadTeacher headTeacher1("Марiя", 50, "Фiзика", 25, 10);

    // Масив об'єкт?в
    Teacher* teachers[2];
    teachers[0] = &teacher1;
    teachers[1] = &headTeacher1;

    // Виведення ?нформац?ї через цикл
    for (int i = 0; i < 2; ++i) {
        teachers[i]->displayInfo();
        
        std::cout << std::endl;
    }

    return 0;
}
