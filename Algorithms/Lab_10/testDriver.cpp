// ��?��� �.�.
// ��� �� ���? �++
// ������ୠ ஡�� 10
// �?�楢�� ��ப �������: 22 �����
// ������⠭� ��� �ਡ����� 100 �
// �� ��� ���᭠ ஡��. �� �㫮 ������⠭� ��஭��� ��������
//
// ��������: ॠ�?�㢠� c⥪ � ��⮤� �� �쮣�.
// 

#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stack; // �⢮��� ����� �⥪

    // ����� ������� �� �⥪�
    cout << "����� ������� �� �⥪�:" << endl;
    stack.push("����");
    stack.push("��㣥");
    stack.push("����");
    stack.push("��⢥��");

    // �������� ?��ଠ�?� ��। ��������� ?��� �����?�
    cout << "�i��i��� �������i� � ���i: " << stack.size() << endl;
    cout << "����i� �������: " << stack.top() << endl;

    // ������� pop
    cout << "������� pop()..." << endl;
    stack.pop(); // ������� ����?� �������
    cout << "�i�� ���������:" << endl;
    cout << "�i��i��� �������i� � ���i: " << stack.size() << endl;
    cout << "����i� �������: " << stack.top() << endl;

    // ���?��� ����? ��� �������
    cout << "���i��� ����i ��� �������..." << endl;
    stack.swap();
    cout << "�i�� ���i��:" << endl;
    cout << "����i� �������: " << stack.top() << endl;

    // �㡫�� ����?� �������
    cout << "�㡫�� ����i� �������..." << endl;
    stack.duplicate();
    cout << "�i�� �㡫���:" << endl;
    cout << "����i� �������: " << stack.top() << endl;

    // ������� rotate
    cout << "������� rotate(1)..." << endl;
    stack.rotate(1);
    cout << "�i�� ���i�:" << endl;
    cout << "����i� �������: " << stack.top() << endl;

    // ������� ��? �������
    cout << "������� �������:" << endl;
    while (!stack.isEmpty()) {
        string topElement = stack.top();
        cout << "�������: " << topElement << endl;
        stack.pop(); // ������� ����?� �������
    }

    // ��ॢ?���, � �⥪ ��஦�?�
    if (stack.isEmpty()) {
        cout << "�⥪ ��஦�i�." << endl;
    }

    return 0;
}

