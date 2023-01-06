#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree t = {};
    t.RInsert(t.root, 50);
    t.RInsert(t.root, 10);
    t.RInsert(t.root, 40);
    t.RInsert(t.root, 20);
    t.RInsert(t.root, 30);
    t.Inorder(t.root);
    cout << '\n';
    t.Delete(t.root, 30);
    t.Inorder(t.root);

    return 0;
}