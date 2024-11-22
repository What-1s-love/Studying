#include "Vertex.h"

Vertex::Vertex(int value) : value(value) {}

Vertex::~Vertex() {}

int Vertex::getValue() const {
    return value;
}
