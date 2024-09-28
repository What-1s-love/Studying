#include "Teacher.h"
#include <iostream>
#include <stdexcept>

Teacher::Teacher(std::string name, int age, std::string subject, int experience)
    : name(name), age(age), subject(subject), yearsOfExperience(experience) {

    if (age <= 0) throw std::invalid_argument("Вiк повинен бути додатним.");
    if (experience < 0) throw std::invalid_argument("Досвiд не може бути негативним.");
}

std::string Teacher::getName() const { return name; }
void Teacher::setName(std::string name) { this->name = name; }

int Teacher::getAge() const { return age; }
void Teacher::setAge(int age) {

    if (age > 0) this->age = age;
    else throw std::invalid_argument("Вiк повинен бути додатним.");
}

std::string Teacher::getSubject() const { return subject; }
void Teacher::setSubject(std::string subject) { this->subject = subject; }

int Teacher::getYearsOfExperience() const { return yearsOfExperience; }
void Teacher::setYearsOfExperience(int experience) {

    if (experience >= 0) this->yearsOfExperience = experience;
    else throw std::invalid_argument("Досвiд не може бути негативним.");
}

void Teacher::displayInfo() const {
    std::cout << "Iм'я: " << name << ", Вiк: " << age << ", Предмет: " << subject
        << ", Досвiд: " << yearsOfExperience << " рокiв\n";
}
