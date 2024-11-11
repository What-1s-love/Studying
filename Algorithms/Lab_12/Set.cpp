#include "Set.h"

Set::Set() {}

Set::~Set() {}

void Set::add(int value) {
    if (dataSet.insert(value).second) {
        insert(value); // Додаємо значення в дерево лише якщо воно нове
    }
}

void Set::remove(int value) {
    if (dataSet.erase(value)) {
        Tree::remove(value); // Видаляємо значення з дерева лише якщо воно було в множині
    }
}

void Set::print() const {
    for (const int& value : dataSet) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int Set::getSize() const {
    return dataSet.size();
}
