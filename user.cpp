#include <string>
#include <iostream>
#include "user.h"
#include "payment.h"
using namespace std;

void User::setUserName(string _name)
{
    name = _name;
}

void User::setUserId(int _id)
{
    id = _id;
}

void User::setUserAge(int _age)
{
    age = _age;
}

string User::getUserName()
{
    return name;
}

int User::getUserId()
{
    return id;
}

int User::getUserAge()
{
    return age;
}
