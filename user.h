#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class User
{
public:
    int id;
    string name;
    int age;
    bool active;

    string getUserName();
    int getUserId();
    int getUserAge();

    void setUserName(string _name);
    void setUserId(int _id);
    void setUserAge(int _age);
};



#endif // USER_H