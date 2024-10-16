#ifndef LIST_H
#define LIST_H

#include "NodeList.h"

class List {

private:
    NodeList* head;

public:
    List();
    ~List();

    void insertAtFront(int value);
    void insertAtEnd(int value);
    bool insertAfter(int target, int newValue);
    bool removeFromList(int value);
    int numberOfNodes();
    void removeFromBack();
    void display() const;
};

#endif
