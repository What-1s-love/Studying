#include "NodeList.h"

// �����������, �������� ��� �� ��������� �� nullptr
NodeList::NodeList(const std::string& val) : data(val), next(nullptr), prev(nullptr) {}