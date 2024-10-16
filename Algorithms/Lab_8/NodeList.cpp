#include "NodeList.h"

// Конструктор, ініціалізує дані та вказівники на nullptr
NodeList::NodeList(const std::string& val) : data(val), next(nullptr), prev(nullptr) {}