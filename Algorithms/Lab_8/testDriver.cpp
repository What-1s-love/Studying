// ��?��� �.�.
// ��� �� ���? �++
// ������ୠ ஡�� 8
// �?�楢�� ��ப �������: 8 �����
// ������⠭� ��� �ਡ����� 92 �
// �� ��� ���᭠ ஡��. �� �㫮 ������⠭� ��஭��� ��������
//
// ��������: ॠ�?�㢠� ����?��� ���?易��� ᯨ᮪ �?� (doubly linked list of strings).
// ��? ��⮤� � �������� 7 ������ ��� �����?��.
// 
#include "DoublyLinkedList.h"
#include <iostream>

int main() {
    DoublyLinkedList list; // �⢮��� ����� �����'吝�� ᯨ᮪

    // ��⠢�� �������?�
    list.insertAtFront("apple");
    list.insertAtEnd("banana");
    list.insertAtFront("cherry");
    list.insertAtEnd("date");

    std::cout << "���᮪ �i�� ��⠢��: ";
    list.display(); // �������� ᯨ᮪

    // ��ॢ?ઠ �����? �㧫�
    list.insertAfter("banana", "elderberry");
    std::cout << "���᮪ �i�� ��⠢�� �i�� 'banana': ";
    list.display(); // �������� ᯨ᮪

    // ��������� �㧫�
    list.removeFromList("cherry");
    std::cout << "���᮪ �i�� ��������� 'cherry': ";
    list.display(); // �������� ᯨ᮪

    // �?��?��� �㧫?�
    std::cout << "�i��i��� �㧫i�: " << list.numberOfNodes() << std::endl;

    // ��������� � ����� � � �?���
    list.removeFromFront();
    std::cout << "���᮪ �i�� ��������� � �����: ";
    list.display(); // �������� ᯨ᮪
    list.removeFromBack();
    std::cout << "���᮪ �i�� ��������� � �i���: ";
    list.display(); // �������� ᯨ᮪

    return 0; // �����襭�� �ணࠬ�
}
