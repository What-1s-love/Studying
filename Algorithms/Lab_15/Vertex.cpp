#include "Vertex.h"

Vertex::Vertex(int data) : data(data) {}

Vertex::~Vertex()
{}

int Vertex::getData() const
{
    return data;
}

void Vertex::setData(int data)
{
    this->data = data;
}
