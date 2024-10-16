// ��?��� �.�
// ��� �� ���? �++
// ������ୠ ஡�� 7
// �?�楢�� �ப �������: 3 �����
// ������⠭� ��� �ਡ����� 80 �
// �� ��� ���᭠ ஡��. �� �㫮 ������⠭� ��஭��� ��������
//
// ��������: �� �⢮��� linked list(��९���� � ����?�) � ����� �� ����� ��⮤�
// ��⮤ ���������, ��⮤ �?���㢠��� �������?� � ��⮤ ��⠢����� �?�� ��������

#include "List.h"
#include <iostream>

int main() {
    List list;

    std::cout << "�⢮७�� ᯨ��: ��஦�i�" << std::endl;
    list.display();

    std::cout << "��⠢�� 3 �� ���⮪" << std::endl;
    list.insertAtFront(3);
    list.display();

    std::cout << "��⠢�� 1 �� ���⮪" << std::endl;
    list.insertAtFront(1);
    list.display();

    std::cout << "��⠢�� 7 � �i����" << std::endl;
    list.insertAtEnd(7);
    list.display();

    std::cout << "��஡� ��⠢�� 5 �i�� 4" << std::endl;

    if (!list.insertAfter(4, 5)) {

        std::cout << "����� ������� 4. ���᮪ �� ��i�����." << std::endl;

    }
    list.display();

    std::cout << "��⠢�� 5 �i�� 3" << std::endl;
    list.insertAfter(3, 5);
    list.display();

    std::cout << "��������� 1" << std::endl;
    list.removeFromList(1);
    list.display();

    std::cout << "��������� � �i���" << std::endl;
    list.removeFromBack();
    list.display();

    std::cout << "�i��i��� �㧫i�: " << list.numberOfNodes() << std::endl;

    return 0;
}
