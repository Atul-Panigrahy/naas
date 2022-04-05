#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class User
{
public:
    string name;
    int age;
    bool active;

    string getUserName();
    int getUserAge();

    void setUserName(string _name);
    void setUserAge(int _age);
};



#endif // USER_H