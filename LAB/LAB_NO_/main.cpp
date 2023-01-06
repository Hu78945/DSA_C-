#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree t = {};
    t.create();
    t.levelOrder(t.root);
    return 0;
}