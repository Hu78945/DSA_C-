#include <iostream>
class Array
{
private:
    /* data */
    int length, size;
    int *arr;

public:
    Array();
    Array(int size);
    void push(int element);
    bool SizeFull();
    void ExtendSize();
    void PrintArray();
    ~Array();
};
