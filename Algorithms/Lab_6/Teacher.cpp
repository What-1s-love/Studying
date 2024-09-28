#include "Teacher.h"
#include <iostream>
#include <stdexcept>

Teacher::Teacher(std::string name, int age, std::string subject, int experience)
    : name(name), age(age), subject(subject), yearsOfExperience(experience) {

    if (age <= 0) throw std::invalid_argument("�i� ������� ��� ����⭨�.");
    if (experience < 0) throw std::invalid_argument("���i� �� ���� ��� ����⨢���.");
}

std::string Teacher::getName() const { return name; }
void Teacher::setName(std::string name) { this->name = name; }

int Teacher::getAge() const { return age; }
void Teacher::setAge(int age) {

    if (age > 0) this->age = age;
    else throw std::invalid_argument("�i� ������� ��� ����⭨�.");
}

std::string Teacher::getSubject() const { return subject; }
void Teacher::setSubject(std::string subject) { this->subject = subject; }

int Teacher::getYearsOfExperience() const { return yearsOfExperience; }
void Teacher::setYearsOfExperience(int experience) {

    if (experience >= 0) this->yearsOfExperience = experience;
    else throw std::invalid_argument("���i� �� ���� ��� ����⨢���.");
}

void Teacher::displayInfo() const {
    std::cout << "I�'�: " << name << ", �i�: " << age << ", �।���: " << subject
        << ", ���i�: " << yearsOfExperience << " பi�\n";
}
