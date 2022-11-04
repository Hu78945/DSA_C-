#include <iostream>
using namespace std;

int SumOfN(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x += n;
        SumOfN(n - 1);
    }
    return x;
}

int Sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return Sum(n - 1) + n;
    }
}

int Factoriol(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return Factoriol(n - 1) * n;
    }
}

int Power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return Power(m, n - 1) * m;
    }
}

int Pow2(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return Pow2(m * m, n / 2);
    else
        return m * Pow2(m * m, (n - 1) / 2);
}

// Power using iteeration

int pow3(int m, int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= m;
    }
    return res;
}

// Tailer Series
int e(int x, int n)
{
    static int p = 1, f = 1;
    int r;
    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

// Tailer iterative
int e2(int x, int n)
{
    int S = 1;
    for (n > 0; n--;)
    {
        S = 1 + x / n * S;
    }
    return S;
}

// Tailer using the static variable
int e3(int x, int n)
{
    static int S = 1;
    if (n == 0)
        return S;
    S = 1 + x / n * S;
    return e3(x, n - 1);
}

int main()
{
    cout << e(2, 4);
    return 0;
}