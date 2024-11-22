#ifndef ADJLISTNODE_H
#define ADJLISTNODE_H

#include "Vertex.h"

class AdjListNode {
public:
    AdjListNode(Vertex* vertex);
    ~AdjListNode();

    Vertex* getVertex() const;
    AdjListNode* getNext() const;
    void setNext(AdjListNode* next);

private:
    Vertex* vertex;
    AdjListNode* next;
};

#endif
