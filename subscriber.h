#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include "user.h"
#include "payment.h"
using namespace std;

class Subscriber : public User
{
public:
    int subscriberId;
    string name;
    int age;
    bool active;
    string address;
    bool paymentPending;
    int amountPending;
    int paymentPendingForNumberOfMonths;
    vector<int>subcriptions; // stores the id of the magazine or the newspapers
    vector<string> systemMessage;
    map<int,string> magazineName;
    map<int,int> magazinePrice;

    Subscriber(int _id, string _name,int _age,string _address);
    void generateMagazines();
    void printSubscriptions();
    void viewAllAvailableSubscriptions();
    bool requestChangeOfSubscriptions(int _id);
    double generateMonthlyBill();
    void viewSystemMessage();
    bool requestHaltOfSubscriptions();
    bool payDues();
    bool stopService();
};



#endif // SUBSCRIBER_H