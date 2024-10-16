#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "NodeList.h"

// ���� ��� ������������� �����'������ ������
class DoublyLinkedList {
private:
    NodeList* head;  // �������� �� ������ �����
    NodeList* tail;  // �������� �� ������� �����

public:
    DoublyLinkedList();  // �����������
    ~DoublyLinkedList(); // ����������

    // ������ ��� ������ � �����'����� �������
    void insertAtFront(const std::string& value);
    void insertAtEnd(const std::string& value);
    bool insertAfter(const std::string& target, const std::string& newValue);
    bool removeFromList(const std::string& value);
    int numberOfNodes() const;  // ϳ�������� �����
    void removeFromBack();       // ��������� ���������� �����
    void removeFromFront();      // ��������� ������� �����
    bool isEmpty() const;        // ��������, �� ������ ������
    void display() const;        // ��������� ������
};

#endif
