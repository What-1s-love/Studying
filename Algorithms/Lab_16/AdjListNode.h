#ifndef ADJLISTNODE_H
#define ADJLISTNODE_H

#include "Vertex.h"

class AdjListNode
{
    friend class Graph;

public:
    AdjListNode(Vertex* vertex);
    ~AdjListNode();

private:
    Vertex* vertex;
    AdjListNode* nextPtr;
};

#endif
