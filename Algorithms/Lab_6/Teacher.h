#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher {
protected:
    std::string name;
    int age;
    std::string subject;
    int yearsOfExperience;

public:
    // ���������
    Teacher(std::string name, int age, std::string subject, int experience);

    // ���� � ���
    std::string getName() const;
    void setName(std::string name);

    int getAge() const;
    void setAge(int age);

    std::string getSubject() const;
    void setSubject(std::string subject);

    int getYearsOfExperience() const;
    void setYearsOfExperience(int experience);

    // ��⮤ ��� ��������� ?��ଠ�?�
    virtual void displayInfo() const;
};

#endif
