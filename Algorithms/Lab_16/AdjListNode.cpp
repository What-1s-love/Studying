#include "AdjListNode.h"

AdjListNode::AdjListNode(Vertex* v)
{
    vertex = v;
    nextPtr = nullptr;
}

AdjListNode::~AdjListNode()
{
    // Nothing to clean here; memory cleanup is handled by Graph.
}
