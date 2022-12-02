#include <iostream>
#include <stack>
using namespace std;

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    if (x == '%')
        return 3;

    return 0;
}
string convert(string infix)
{
    int i = 0;
    string postfix = "";
    stack<int> s;

    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
            i++;
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }

        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while (!s.empty() && priority(infix[i]) <= priority(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix is : " << postfix;
    return postfix;
}
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

int main()
{
    string infix = "(3*5)+(6/2)-4"; // 35*62/+4-
    // string postfix;
    // postfix = convert(infix);
    evaluate("35*62/+4-");

    return 0;
}