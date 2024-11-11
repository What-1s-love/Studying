#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "List.h"

class Stack {
private:
    List list; // Використовуємо список для реалізації стека
public:
    Stack() {}

    void push(const std::string& value);
    void pop();
    std::string top() const;
    int size() const;
    void duplicate();
    void swap();
    void rotate(int n);
    bool isEmpty() const;
};

#endif
