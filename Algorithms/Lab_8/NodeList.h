#ifndef NODENODELIST_H
#define NODENODELIST_H

#include <string>

// ���� ��� ������������� ����� �����'������ ������
class NodeList {
public:
    std::string data;      // �������� ����� (�����)
    NodeList* next;        // �������� �� ��������� �����
    NodeList* prev;        // �������� �� ��������� �����

    // �����������, ���� �������� ����� � ������� ���������
    NodeList(const std::string& val);
};

#endif
