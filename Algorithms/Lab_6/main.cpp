// ��?��� �.�
// ��� �� ���? �++
// ������ୠ ஡�� 6
// �?�楢�� �ப �������: 26 �����
// ������⠭� ��� 120 �
// �� ��� ���᭠ ஡��. �� ������⠭ �� ���
//
// �⢮��� ��� ���� � ॠ�?��� ��⮤�. �������� ?��ଠ�?� �� ����� ��'�� 

#include <iostream>
#include "Teacher.h"
#include "HeadTeacher.h"

int main() {
    // �⢮७�� ��'��?� ����?�

    Teacher teacher1("����ᠭ��", 40, "��⥬�⨪�", 15);
    HeadTeacher headTeacher1("���i�", 50, "�i����", 25, 10);

    // ��ᨢ ��'��?�
    Teacher* teachers[2];
    teachers[0] = &teacher1;
    teachers[1] = &headTeacher1;

    // ��������� ?��ଠ�?� �१ 横�
    for (int i = 0; i < 2; ++i) {
        teachers[i]->displayInfo();
        
        std::cout << std::endl;
    }

    return 0;
}
