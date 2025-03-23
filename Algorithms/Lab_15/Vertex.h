#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
public:
    Vertex(int data);
    ~Vertex();

    int getData() const;
    void setData(int data);

private:
    int data;
};

#endif
