#include <iostream>
#include "string.h"
#include "Stack.h"
using namespace std;

// Infix to postfix conversion program

// program to check wether a symbol is oprand or not
int isOpren(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Check the prcedancec of the oprand
int pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

char *convert(char *infix)
{
    Stack st = {};
    st.push('#');
    char *postfix = new char[strlen(infix) + 1];
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (isOpren(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre(infix[i]) > pre(st.stackTop()))
            {
                st.push(infix[i++]);
            }
            else
            {
                postfix[j++] = st.pop();
            }
        }
    }
    while (!st.IsEmpty())
    {
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *arr = "a+b*c-d/e";
    char *res = convert(arr);
    printf("%s ", res);
    return 0;
}