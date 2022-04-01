#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include <map>
using namespace std;

class Manager
{
public:
    int managerId;
    string name;
    int age;
    map<int,string> magazineName;
    map<int,int> magazinePrice;
    vector<int>subscriberList;
    vector<int>AgentList;
    
    Manager(int _id,string _name,int age);
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