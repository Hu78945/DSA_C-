#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree t = {};
    t.create();
    t.Inorder(t.root);
    cout << "\n";
    cout << "No of nodes  is : " << t.length << endl;
    return 0;
}