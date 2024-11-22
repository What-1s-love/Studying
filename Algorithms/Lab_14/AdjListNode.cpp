#include "AdjListNode.h"

AdjListNode::AdjListNode(Vertex* vertex) : vertex(vertex), next(nullptr) {}

AdjListNode::~AdjListNode() {}

Vertex* AdjListNode::getVertex() const {
    return vertex;
}

AdjListNode* AdjListNode::getNext() const {
    return next;
}

void AdjListNode::setNext(AdjListNode* next) {
    this->next = next;
}
