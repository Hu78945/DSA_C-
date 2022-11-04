#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int *A;
    int n;

public:
    DiagonalMatrix(int size);
    ~DiagonalMatrix();
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
};
