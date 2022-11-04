#include <iostream>
#include "DiagonalMatrix.h"
#include "LowerTriangularMatrix.h"
using namespace std;

int main()
{

    // DiagonalMatrix M = {4};
    // M.set(1, 1, 3);
    // M.set(2, 2, 5);
    // M.set(3, 3, 6);
    // M.set(4, 4, 9);
    // int val = M.get(1, 1);
    // M.Display();

    int d;
    cout << "Enter the dimension " << endl;
    cin >> d;
    LowerTriangularMatrix lm(d);
    int x;
    cout << "Enter all the elements : " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lm.set(i, j, x);
        }
    }

    lm.Display();

    return 0;
}
