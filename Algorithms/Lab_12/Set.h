#ifndef SET_H
#define SET_H

#include "Tree.h"
#include <set>
#include <iostream>

class Set : public Tree {
public:
    Set();
    ~Set();

    void add(int);
    void remove(int);
    void print() const;
    int getSize() const;

private:
    std::set<int> dataSet;
};

#endif // SET_H
