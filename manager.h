#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include "agent.h"
#include "subscriber.h"
using namespace std;

class Manager : public User
{
public:
    int managerId;
    string name;
    int age;
    map<int,string> magazineName;
    map<int,int> magazinePrice;
    vector<Subscriber*> &subs;
    vector<Agent *> &ag;
    vector<int>subscriberList;
    vector<int>AgentList;
    
    Manager(int _id,string _name,int age,vector<Subscriber *> &v,vector<Agent *> &a);
    void generateMagazines();
    void getSubscriberList();
    void addSubscriber(int _id);
    void removeSubscriber(int _id);
    void getDeliveryAgentList();
    void addDeliveryAgent(int _id);
    void removeDeliveryAgent(int _id);
    void viewAllAvailableSubscriptions();
    void getPayCollection();
};

#endif // MANAGER_H