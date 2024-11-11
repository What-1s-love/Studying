#ifndef NODELIST_H
#define NODELIST_H

#include <string>

// ��������� �����
struct Node {
    std::string data; // ��� �����
    Node* next;       // �������� �� ��������� �����

    // ����������� �����
    Node(const std::string& value) : data(value), next(nullptr) {}
};

#endif // NODELIST_H
