#include <iostream>
#include "Trees.h"
using namespace std;

int main()
{
    Tree T = {};
    T.create();
    cout << "Recursive: ";
    T.Inorder(T.root);
    cout << "\n";
    cout << "Itertaive: ";
    T.Tinorder(T.root);
    cout << "\n";
    return 0;
}