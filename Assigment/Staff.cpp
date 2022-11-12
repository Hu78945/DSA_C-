#include <iostream>
#include "Staff.h"
using namespace std;

Staff::Staff()
{
    ID = 0;
    Salary = 0;
}

Staff::Staff(string name, int ID, string Role, int Salary)
{
    this->Name = name;
    this->ID = ID;
    this->Role = Role;
    this->Salary = Salary;
}

void Staff::setName(string name)
{
    this->Name = name;
}

void Staff::setID(int ID)
{
    this->ID = ID;
}

void Staff::setRole(string Role)
{
    this->Role = Role;
}

void Staff::setSalary(int Salary)
{
    this->Salary = Salary;
}

string Staff::getName()
{
    return Name;
}

int Staff::getID()
{
    return ID;
}

string Staff::getRole()
{
    return Role;
}

int Staff::getSalary()
{
    return Salary;
}
