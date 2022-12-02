#include <iostream>
#include <stack>
using namespace std;

int solve(int first, int second, char operation)
{
    int res = 0;
    switch (operation)
    {
    case '+':
        res = first + second;
        break;
    case '-':
        res = first - second;
        break;
    case '*':
        res = first * second;
        break;
    case '/':
        res = first / second;
        break;
    default:
        break;
    }
    return res;
}

void evaluate(string postfix)
{
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            int res = solve(first, second, postfix[i]);
            st.push(res);
        }
        else
        {
            st.push(postfix[i] - '0');
        }
    }
    cout << "Result is " << st.top() << endl;
}