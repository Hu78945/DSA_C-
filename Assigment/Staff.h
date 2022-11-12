#include <iostream>
using namespace std;
class Staff
{
private:
    /* Data members */
    string Name;
    int ID;
    string Role;
    int Salary;

public:
    Staff();
    Staff(string name, int ID, string Role, int Salary);
    // setter function
    void setName(string name);
    void setID(int ID);
    void setRole(string Role);
    void setSalary(int Salary);

    // getter function
    string getName();
    int getID();
    string getRole();
    int getSalary();
};
