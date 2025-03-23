#include "AdjListNode.h"

AdjListNode::AdjListNode(Vertex* v)
{
	vertex = v;
	nextPtr = nullptr;
}

AdjListNode::~AdjListNode()
{

}