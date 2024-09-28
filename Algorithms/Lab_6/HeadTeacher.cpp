#include "HeadTeacher.h"
#include <iostream>
#include <stdexcept>

HeadTeacher::HeadTeacher(std::string name, int age, std::string subject, int experience, int adminExperience)
    : Teacher(name, age, subject, experience), adminExperience(adminExperience) {
    if (adminExperience < 0) throw std::invalid_argument("���i�i���⨢��� ���i� �� ���� ��� ����⨢���.");
}

int HeadTeacher::getAdminExperience() const { return adminExperience; }
void HeadTeacher::setAdminExperience(int adminExperience) {
    if (adminExperience >= 0) this->adminExperience = adminExperience;
    else throw std::invalid_argument("���i�i���⨢��� ���i� �� ���� ��� ����⨢���.");
}

void HeadTeacher::displayInfo() const {
    Teacher::displayInfo();
    std::cout << "���i�i���⨢��� ���i�: " << adminExperience << " பi�\n";
}
