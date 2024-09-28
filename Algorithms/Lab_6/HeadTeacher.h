#ifndef HEADTEACHER_H
#define HEADTEACHER_H

#include "Teacher.h"

class HeadTeacher : public Teacher {
private:
    int adminExperience; // ���������������� ������

public:
    // �����������
    HeadTeacher(std::string name, int age, std::string subject, int experience, int adminExperience);

    // ����� �� ����� ��� ����������������� �������
    int getAdminExperience() const;
    void setAdminExperience(int adminExperience);

    // �������������� ����� ��� ��������� ����������
    void displayInfo() const override;
};

#endif
