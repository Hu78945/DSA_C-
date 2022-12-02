#include <iostream>
#include <stack>
using namespace std;

bool isOprend(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
    {
        return false;
    }
    return true;
}

int outStackPre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '(')
        return 100;
    else if (x == ')')
        return 0;
    return -1;
}

int inStackPre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '(')
        return 0;
    return -1;
}

string convert(string Infix)
{
    //(a+b)*c/d ===> ab+cd/*
    stack<char> st;
    string postfix = "";
    st.push('#');
    int j = 0;
    int i = 0;
    while (Infix[i] != '\0')
    {
        if (isOprend(Infix[i]))
        {
            postfix += Infix[i++];
        }
        else
        {
            if (outStackPre(Infix[i]) > inStackPre(st.top()))
            {
                st.push(Infix[i++]);
            }
            else
            {
                if (Infix[i] == ')')
                {
                    while (st.top() != '(')
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    st.pop();
                    i++;
                }
                else
                {
                    postfix += st.top();
                    st.pop();
                }
            }
        }
    }

    return postfix;
}

int main()
{
    string Infix = "(3*5)+(6/2)-4";
    string postfix = convert(Infix);
    cout << postfix << endl;
    return 0;
}
