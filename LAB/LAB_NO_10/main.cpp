#include <iostream>
#include "BSTT.h"
using namespace std;

int main()
{
    BinarySearchTree tree = {};
    tree.RInsert(tree.root, 30);
    tree.RInsert(tree.root, 25);
    tree.RInsert(tree.root, 40);
    tree.RInsert(tree.root, 12);
    tree.Inorder(tree.root);
    cout << "\n";
    tree.Delete(tree.root, 40);
    tree.Inorder(tree.root);

    return 0;
}