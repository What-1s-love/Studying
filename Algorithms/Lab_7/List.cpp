#include "List.h"
#include <iostream>

List::List() : head(nullptr) {}

List::~List() {
    while (head) {

        NodeList* temp = head;
        head = head->next;
        delete temp;

    }
}

void List::insertAtFront(int value) {

    NodeList* newNode = new NodeList(value);
    newNode->next = head;
    head = newNode;

}

void List::insertAtEnd(int value) {
    NodeList* newNode = new NodeList(value);

    if (!head) {

        head = newNode;
    }

    else {
        NodeList* temp = head;
        while (temp->next) {

            temp = temp->next;

        }

        temp->next = newNode;
    }
}

bool List::insertAfter(int target, int newValue) {
    NodeList* temp = head;

    while (temp && temp->value != target) {

        temp = temp->next;

    }

    if (temp) {
        NodeList* newNode = new NodeList(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
        return true;
    }

    return false;
}

bool List::removeFromList(int value) {
    if (!head) return false;

    if (head->value == value) {
        NodeList* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    NodeList* temp = head;
    while (temp->next && temp->next->value != value) {
        temp = temp->next;
    }

    if (temp->next) {

        NodeList* toDelete = temp->next;
        temp->next = temp->next->next;


        delete toDelete;
        return true;
    }

    return false;
}

int List::numberOfNodes() {
    int count = 0;

    NodeList* temp = head;

    while (temp) {

        ++count;

        temp = temp->next;
    }
    return count;
}

void List::removeFromBack() {
    if (!head) return;

    if (!head->next) {

        delete head;

        head = nullptr;

        return;
    }

    NodeList* temp = head;
    while (temp->next && temp->next->next) {

        temp = temp->next;

    }

    delete temp->next;

    temp->next = nullptr;
}

void List::display() const {

    NodeList* temp = head;

    while (temp) {

        std::cout << temp->value << " ";
        temp = temp->next;

    }

    std::cout << std::endl;
}
