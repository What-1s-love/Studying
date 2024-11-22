#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
public:
    Vertex(int value);
    ~Vertex();

    int getValue() const;

private:
    int value; // Значення вершини
};

#endif
