#include "DoublyLinkedList.h"
#include <iostream>

// �����������, �������� ��������� �� nullptr
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// ����������, ������� �� ����� ������
DoublyLinkedList::~DoublyLinkedList() {

    while (!isEmpty()) {
        removeFromFront();  // ��������� ����� � �������, ���� ������ �� ����� ������
    }
}

// ������� ����� � ������� ��������� �� ������� ������
void DoublyLinkedList::insertAtFront(const std::string& value) {
    NodeList* newNode = new NodeList(value);  // ��������� ������ �����

    if (isEmpty()) {
        head = newNode;      // ���� ������ ������, ������������ ������
        tail = newNode;      // ������������ ����
    }
    else {
        newNode->next = head; // ����� ����� ����� �� ������� ������
        head->prev = newNode;  // ������� ������ ����� �� ����� ����� �� �� ���������
        head = newNode;        // ����� ����� ��� �������
    }
}

// ������� ����� � ������� ��������� � ����� ������
void DoublyLinkedList::insertAtEnd(const std::string& value) {
    NodeList* newNode = new NodeList(value); // ��������� ������ �����

    if (isEmpty()) {
        head = newNode;  // ���� ������ ������, ������������ ������
        tail = newNode;   // ������������ ����
    }
    else {
        tail->next = newNode; // �������� ���� ����� �� ����� �����
        newNode->prev = tail;  // ����� ����� ����� �� �������� ���� �� �� ���������
        tail = newNode;        // ����� ����� ��� �������
    }
}

// ������� ������ �������� ���� ��������
bool DoublyLinkedList::insertAfter(const std::string& target, const std::string& newValue) {
    NodeList* current = head; // �������� � ������

    while (current) {

        if (current->data == target) { // ���� ������� �������� �����
            NodeList* newNode = new NodeList(newValue); // ��������� ����� �����
            newNode->next = current->next; // ����� ����� ����� �� ���������
            newNode->prev = current;       // ����� ����� ����� �� ��������

            if (current->next) {
                current->next->prev = newNode; // ��������� ����� ����� �� �����
            }
            current->next = newNode; // �������� ����� ����� �� �����

            if (current == tail) {
                tail = newNode; // ���� �� ������� �����, ��������� ����
            }
            return true; // ������ ���������
        }
        current = current->next; // ���������� �� ���������� �����
    }
    return false; // ֳ�� �� ��������
}

// ��������� ����� �� ���������
bool DoublyLinkedList::removeFromList(const std::string& value) {
    NodeList* current = head; // �������� � ������

    while (current) {

        if (current->data == value) { // ���� ������� ����� ��� ���������
            if (current->prev) {
                current->prev->next = current->next; // ��������� ��������� �����
            }
            else {
                head = current->next; // ���� ��������� ������, ��������� ������
            }

            if (current->next) {
                current->next->prev = current->prev; // ��������� ��������� �����
            }
            else {
                tail = current->prev; // ���� ��������� ����, ��������� ����
            }
            delete current; // ��������� �����
            return true; // ������ ��������
        }
        current = current->next; // ���������� �� ���������� �����
    }
    return false; // ����� �� ��������
}

// ϳ�������� ������� ����� � ������
int DoublyLinkedList::numberOfNodes() const {
    int count = 0; // ˳������� �����
    NodeList* current = head; // �������� � ������

    while (current) {
        count++; // �������� ��������
        current = current->next; // ���������� �� ���������� �����
    }
    return count; // ��������� ������� �����
}

// ��������� ���������� �����
void DoublyLinkedList::removeFromBack() {

    if (isEmpty()) return; // ���� ������ ������, ����� �� ������

    NodeList* toDelete = tail; // �����'������� ������� �����

    if (tail->prev) {
        tail = tail->prev; // ��������� ����
        tail->next = nullptr; // ��������� �������� �� ��������� �����
    }
    else {
        head = nullptr; // ���� ������ ���� ������
        tail = nullptr; // ���� ������ ���� ������
    }
    delete toDelete; // ��������� �����
}

// ��������� ������� �����
void DoublyLinkedList::removeFromFront() {

    if (isEmpty()) return; // ���� ������ ������, ����� �� ������

    NodeList* toDelete = head; // �����'������� ������ �����
    head = head->next; // ��������� ������

    if (head) {
        head->prev = nullptr; // ��������� �������� �� ��������� �����
    }
    else {
        tail = nullptr; // ���� ������ ���� ������
    }
    delete toDelete; // ��������� �����
}

// ��������, �� ������ ������
bool DoublyLinkedList::isEmpty() const {
    return head == nullptr; // ��������� true, ���� ������ ���� nullptr
}

// ��������� ������
void DoublyLinkedList::display() const {
    NodeList* current = head; // �������� � ������
    while (current) {
        std::cout << current->data << " "; // �������� ��� �����
        current = current->next; // ���������� �� ���������� �����
    }
    std::cout << std::endl; // ������� �� ����� �����
}
