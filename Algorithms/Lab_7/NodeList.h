#ifndef NODELIST_H
#define NODELIST_H

class NodeList {
public:

    int value;

    NodeList* next;

    NodeList(int val) : value(val), next(nullptr) {}
};

#endif

