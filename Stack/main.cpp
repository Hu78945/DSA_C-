#include <iostream>
#include <string.h>
#include "Stack.h"
using namespace std;

int main()
{
    string code = "";
    char arr[] = "((a+b)+f(c+d))";
    Stack My = {strlen(arr)};
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(')
        {
            My.Push(arr[i]);
        }
        else if (arr[i] == ')')
        {
            if (My.isEmpty() == 0)
            {
                My.Pop();
            }
            else
            {
                code = "Not Blanced \n";
                cout << code;
            }
        }
    }
    if (My.isEmpty() == 1)
    {
        if (code == "")
            cout << "Blanced" << endl;
    }
    else
    {
        if (code == "")
            cout << "Not Blanced";
    }

    return 0;
}