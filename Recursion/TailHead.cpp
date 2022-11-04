#include <stdio.h>

// Tail Recursion
void fun(int x)
{
    if (x > 0)
    {
        printf("%d ", x);
        fun(x - 1);
    }
}

// Head Recursion
void fun2(int x)
{
    if (x > 0)
    {
        fun(x - 1);
        printf("%d ", x);
    }
}

int main()
{
    int x = 3;
    fun(x);
    return 0;
}