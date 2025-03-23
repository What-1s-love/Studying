#ifndef VERTEX_H
#define VERTEX_H

typedef enum
{
    NOT_VISITED,
    VISITED
} STATUS;

class Vertex
{
public:
    Vertex(int data, STATUS s);
    ~Vertex();

    int getData() const;
    void setData(int data);
    STATUS getStatus() const;
    void setStatus(STATUS status);

private:
    int data;
    STATUS status;
};

#endif
