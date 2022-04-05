#include <string>
#include <iostream>
#include "user.h"
#include "payment.h"
using namespace std;

void User::setUserName(string _name)
{
    name = _name;
}

void User::setUserAge(int _age)
{
    age = _age;
}

string User::getUserName()
{
    return name;
}

int User::getUserAge()
{
    return age;
}
