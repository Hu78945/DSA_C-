#include <iostream>
using namespace std;

void fun(int x)
{
    if (x > 0)
    {
        cout << x << " ";
        fun(x - 1);
        fun(x - 1);
    }
}
/*
    Number of call the above function will make depends upon the formula:
    2^n+1 -1 ;
    The Time Complexity of the tree recursion is 2^n;
    which is O(2^n) only applicable for aobe function.
    Space Complexity if O(n+1) ---> O(n)
 */

int main()
{
    fun(3);
    return 0;
}