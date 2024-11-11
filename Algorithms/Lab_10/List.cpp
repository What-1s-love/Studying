#include "List.h"
#include <iostream>

List::List() : head(nullptr), count(0) {}

List::~List() {
    while (!isEmpty()) {
        removeFromHead();
    }
}

void List::insertAtHead(const std::string& value) {
    Node* newNode = new Node{ value, head }; // ��������� ����� �����
    head = newNode; // ����� ����� ��� �������
    count++; // �������� ��������
}

void List::removeFromHead() {
    if (isEmpty()) {
        throw std::runtime_error("������ �������."); // ���� ������ �������, �������� �������
    }

    Node* temp = head; // �������� ������
    head = head->next; // ������� ������ �� ��������� �������
    delete temp; // ��������� ����� ������
    count--; // �������� ��������
}

Node* List::getHead() const {
    return head; // ��������� ������ ������
}

bool List::isEmpty() const {
    return head == nullptr; // ���� ������ �������, ������ �������
}

int List::size() const {
    return count; // ��������� ������� �������� � ������
}
