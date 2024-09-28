#ifndef HEADTEACHER_H
#define HEADTEACHER_H

#include "Teacher.h"

class HeadTeacher : public Teacher {
private:
    int adminExperience; // Адміністративний досвід

public:
    // Конструктор
    HeadTeacher(std::string name, int age, std::string subject, int experience, int adminExperience);

    // Гетер та сетер для адміністративного досвіду
    int getAdminExperience() const;
    void setAdminExperience(int adminExperience);

    // Перевизначений метод для виведення інформації
    void displayInfo() const override;
};

#endif
