#include <iostream>
#include <vector> // ������ ��� ������������ std::vector
#include "Stack.h"
#include "List.h"

// ���� ������� �� ���� �����
void Stack::push(const std::string& value) {
    list.insertAtHead(value); // ������ ����� ������� �� ������� ������
}

// ������� ������ ������� �����
void Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("����� �������.");
    }
    list.removeFromHead(); // ��������� ������ ������� � ������
}

// ������� ������ ������� �����
std::string Stack::top() const {
    if (isEmpty()) {
        throw std::runtime_error("����� �������.");
    }
    return list.getHead()->value; // �������� ������ �������
}

// ������� ������� �������� � �����
int Stack::size() const {
    return list.size(); // ������������� ����� size() ������
}

// ������ ������ �������
void Stack::duplicate() {
    if (isEmpty()) {
        throw std::runtime_error("����� �������.");
    }
    std::string topValue = top();
    push(topValue); // ������ ���� ����� �� ����
}

// ������ ����� ��� ��������
void Stack::swap() {
    if (size() < 2) {
        throw std::runtime_error("����������� �������� ��� �����.");
    }

    std::string first = top();
    pop(); // ��������� ������
    std::string second = top();
    pop(); // ��������� ������
    push(first); // ������ ������ �����
    push(second); // ������ ������ �����
}

// ������� true, ���� ���� �������
bool Stack::isEmpty() const {
    return list.isEmpty(); // ����������, �� ������� ������
}

void Stack::rotate(int n) {
    if (isEmpty() || size() < 2) {
        return; // ͳ���� �� ������, ���� ���� ������� ��� ������ ����� 2 ��������
    }

    std::vector<std::string> elements; // ������ ��� ��������� ��������
    while (!isEmpty()) {
        elements.push_back(top()); // ������ ������ ������� � ������
        pop(); // ��������� ������ �������
    }

    // ���������� ���� ������� ��� ��������� ��������
    n = n % elements.size(); // ������ ������� �� ������, ��� �������� �����������
    for (int i = elements.size() - n; i < elements.size(); i++) {
        push(elements[i]); // ������ ��� ����� ��������
    }
    for (int i = 0; i < elements.size() - n; i++) {
        push(elements[i]); // ������ ����� ��������
    }
}