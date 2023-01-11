#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
    AVL tree = {};
    tree.RInsert(tree.root, 10);
    tree.RInsert(tree.root, 20);
    tree.RInsert(tree.root, 30);

    return 0;
}