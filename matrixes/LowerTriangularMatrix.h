#include <iostream>
using namespace std;

class LowerTriangularMatrix
{
private:
    int *A;
    int n;

public:
    LowerTriangularMatrix(int size);
    ~LowerTriangularMatrix();
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
};
