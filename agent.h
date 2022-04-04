#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include "subscriber.h"
using namespace std;

class Agent
{
public:
    int agentId;
    string name;
    int age;
    bool active;
    int salaryOfMonth;
    vector<Subscriber*> &subs;
    vector<int>subscriberList;
    vector<string> systemMessage;
    map<int,string> magazineName;
    map<int,int> magazinePrice;
    
    Agent(int _id, string _name,int _age,vector<Subscriber*> &v);
    void generateMagazines();
    void addSubscriber(int _id);
    void removeSubscriber(int _id);
    void printDeliveriesToday();
    void generateMonthlyBill();
    void viewSystemMessage();
    bool collectDues();
};




#endif // AGENT_H