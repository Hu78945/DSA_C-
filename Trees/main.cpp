#include <iostream>
#include "Trees.h"
using namespace std;

int main()
{
    Tree T = {};
    T.create();
    T.preorder(T.root);
    cout << "\n";
    T.postorder(T.root);
    return 0;
}