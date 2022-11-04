#include <iostream>
using namespace std;

void fun2(int x)
{
    if (x > 0)
    {
        fun2(x - 1);
        printf("%d ", x);
    }
}

// Static variable in a recursive function
/*
    Static variable are created in code section or there is a sub section in code section for static and golobal variable.
 */
int func(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return func(n - 1) + x; // ---> x will be added at the returning time of the function.
    }
    return 0;
}
int main()
{
    int x = 5;
    cout << func(x);

    return 0;
}