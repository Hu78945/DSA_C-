#include <iostream>
using namespace std;

// Structure and functions
struct Rectangle
{
    int length;
    int bredth;
};

// Pass by value

int area(struct Rectangle g)
{
    return g.length * g.bredth;
}

// Pass by address

void initilaze(struct Rectangle *g, int l, int b)
{
    g->length = l;
    g->bredth = b;
}

// Pass by reference

void changeLength(struct Rectangle &g, int l)
{
    g.length = l;
};

class Rectangle1
{
private:
    int length1;
    int brdeth1;

public:
    Rectangle1(int l, int b)
    {
        length1 = l;
        brdeth1 = b;
    }
    int area()
    {
        return length1 * brdeth1;
    }
    void changeLength(int l)
    {
        length1 = l;
    }
};

int main()
{
    struct Rectangle r;
    initilaze(&r, 10, 20);
    int i = area(r);
    changeLength(r, 45);
    int j = r.length;
    cout << i << " " << j;

    return 0;
}