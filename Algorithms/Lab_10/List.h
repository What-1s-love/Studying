#ifndef LIST_H
#define LIST_H

#include <string>

struct Node {
    std::string value;
    Node* next;
};

class List {
private:
    Node* head;
    int count;
public:
    List();
    ~List();
    void insertAtHead(const std::string& value);
    void removeFromHead();
    Node* getHead() const;
    bool isEmpty() const;
    int size() const;
};

#endif
