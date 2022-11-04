#include <iostream>
using namespace std;

int main()
{
    char temp = 'A';
    char X[] = {65, 66, 67, 68, 69};
    for (int i = 0; i < 5; i++)
    {
        cout << X[i];
    }
    char name[10] = {'J', 'H', 'O', 'N', 'E', '\0'}; // now it becomes strings
    char name2[] = "Jhone";
    // string delimeter will be added automaticlly by compiler
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        if (name[i] != '\0') // string delimeter or end of string character or null characters
        {
            cout << name[i];
        }
    }
    cout << endl;

    // create string / chracter array in heap
    char *name3 = (char *)"jhone"; // type cast to remove warning
    cout << name3 << endl;

    // get the length of the the string
    char *s = (char *)"welcome";
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    cout << "Lenth of the string is " << i << endl;

    // Change case of the string
    char A[] = "WeLCoMe";
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 'A' && A[i] <= 'Z')
        {
            A[i] += 32;
        }
        else if (A[i] >= 'a' && A[i] <= 'z')
        {
            A[i] -= 32;
        }
    }

    cout << A << endl;

    // count the number of vovwels in the string
    char B[] = "How are you  y son";
    int vovels = 0;
    for (int i = 0; B[i] != '\0'; i++)
    {
        if (B[i] == 'a' || B[i] == 'e' || B[i] == 'i' || B[i] == 'o' || B[i] == 'u' || B[i] == 'A' || B[i] == 'E' || B[i] == 'I' || B[i] == 'O' || B[i] == 'U')
        {
            vovels++;
        }
    }
    cout << vovels << endl;
    // get number of word in a sentence
    int words = 0;
    for (int i = 0; B[i] != '\0'; i++)
    {
        if (B[i] == ' ' && B[i - 1] != ' ')
        {
            words++;
        }
    }
    cout << "Number of word are " << words + 1 << endl;

    return 0;
}