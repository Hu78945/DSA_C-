class BSTTNode
{
private:
    BSTTNode *leftChild;
    int data;
    BSTTNode *rightChild;

public:
    // constructor
    BSTTNode();
    BSTTNode(int data);

    // getter methode
    BSTTNode *getLeftChild();
    int getData();
    BSTTNode *getRightChild();
    // setter methode
    void setRightChild(BSTTNode *data);
    void setLeftChild(BSTTNode *data);
    void setData(int data);
    friend class BStree;
};

#include <iostream>
using namespace std;

class BinarySearchTree
{

public:
    BSTTNode *root;
    BinarySearchTree(/* args */);

    void Inorder(BSTTNode *n);
    BSTTNode *RInsert(BSTTNode *p, int key);
    BSTTNode *Delete(BSTTNode *p, int key);
    int Height(BSTTNode *p);
    BSTTNode *Inpre(BSTTNode *p);
    BSTTNode *InSucc(BSTTNode *p);
};
