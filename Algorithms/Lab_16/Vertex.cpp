#include "Vertex.h"

Vertex::Vertex(int data, STATUS s)
{
    this->data = data;
    this->status = s;
}

Vertex::~Vertex()
{}

int Vertex::getData() const
{
    return data;
}

void Vertex::setData(int d)
{
    data = d;
}

STATUS Vertex::getStatus() const
{
    return status;
}

void Vertex::setStatus(STATUS s)
{
    status = s;
}
