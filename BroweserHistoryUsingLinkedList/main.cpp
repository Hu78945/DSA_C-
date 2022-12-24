#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *prev;
    Node *next;
    Node()
    {
        prev = NULL;
        next = NULL;
    }
    Node(string data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

int getLength(Node *node)
{
    Node *temp = node;
    int counter = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

class BrowserHistory
{
public:
    Node *head;
    Node *curretTab;
    BrowserHistory(string homepage)
    {
        head = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        if (head->next == NULL)
        {
            head->next = newNode;
            newNode->prev = head;
            curretTab = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            curretTab = newNode;
        }
    }

    string back(int steps)
    {
        int len = getLength(head);
        if (steps <= 0 || steps >= len)
        {
            cout << "Invalid steps" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            while (steps > 0)
            {
                temp = temp->prev;
                steps--;
            }
            if (!temp->data.empty())
            {
                curretTab = temp;
                return temp->data;
            }
        }
    }

    void printHistory()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "||";
            temp = temp->next;
        }
    }

    string forward(int steps)
    {
        int len = getLength(head);
        if (steps <= 0 || steps >= len)
        {
            cout << "Invalid steps" << endl;
            return "";
        }
        else
        {
            while (steps > 0)
            {
                steps--;
                curretTab = curretTab->next;
            }
            if (!curretTab->data.empty())
            {
                return curretTab->data;
            }
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main()
{
    BrowserHistory *obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    obj->back(1);
    obj->back(1);
    obj->forward(1);
    obj->visit("linkden.com");
}