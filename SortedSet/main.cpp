#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node();
    Node(int data);
};

class SortedSet
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    SortedSet();
    void insert(int const data);
    void Delete(int const index);
    void Union(SortedSet &set2);
    void rotate(int val);
    void Display();
};

Node::Node()
{
    next = NULL;
}

Node::Node(int data)
{
    this->data = data;
    next = NULL;
}
SortedSet::SortedSet()
{
    head = NULL;
    tail = NULL;
}

void SortedSet::insert(int const data)
{
    // make a node object
    Node *obj = new Node(data);
    if (head == NULL && tail == NULL)
    {
        head = obj;
        tail = obj;
        length = 1;
    }
    else
    {
        int counter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                cout << "Duplication is not allowed" << endl;
                temp = NULL;
            }
            else if (data < temp->data)
            {
                break;
            }
            else
            {
                counter++;
                temp = temp->next;
            }
        }
        if (temp == head)
        {
            Node *temphEAD = head;
            head = obj;
            head->next = temphEAD;
            length++;
        }
        else if (temp != NULL)
        {
            Node *temp1 = head;
            int i = 0;
            while (i != counter - 1)
            {
                temp1 = temp1->next;
                i++;
            }

            Node *tempNode = temp1->next;
            temp1->next = obj;
            obj->next = tempNode;
            length++;
        }
        else
        {
            tail->next = obj;
            tail = obj;
            length++;
        }
    }
}

void SortedSet::Union(SortedSet &set2)
{
    bool con = true;
    Node *p = head;
    Node *q = set2.head;
    while (q != NULL)
    {
        p = head;
        while (p != NULL)
        {
            if (p->data == q->data)
            {
                con = false;
                break;
            }
            else
            {
                p = p->next;
            }
        }
        if (con)
        {
            insert(q->data);
        }
        q = q->next;
    }
    Display();
}

void SortedSet::Delete(int const index)
{
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else if (index == length - 1)
    {
        Node *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        cout << "Length is " << length << endl;
        cout << "This is the tail data " << p->data << endl;
        p->next = NULL;
        tail = p;
    }
    else
    {
        Node *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        p->next = p->next->next;
    }
}

void SortedSet::rotate(int val)
{
    if (val < 0 || val >= length)
    {
        cout << "Enter a valid Index" << endl;
    }
    else
    {
        Node *p = head;
        int i = 0;
        while (i != val)
        {
            p = p->next;
            i++;
        }
        }
}

void SortedSet::Display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    SortedSet set = {};
    set.insert(10);
    set.insert(20);
    set.insert(30);
    set.insert(9);
    // set.insert(25);
    // set.Display();
    // set.Delete(4);
    // set.Display();
    // SortedSet set2 = {};
    // set2.insert(40);
    // set2.insert(90);
    // set2.insert(15);
    // set2.insert(22);
    // set.Union(set2);
    set.rotate(1);
    set.Display();
}