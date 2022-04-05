#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
#include "subscriber.h"
using namespace std;

class Payment
{
public:
    int transactionId;
    string depositor;
    string collector;
    string date;
    int amount;
    bool successStatus;

    Payment();
    bool payDues(Subscriber& sub);
    bool carryOutTransaction(int _id,string dep,string coll,string dt,int amount);
};



#endif // PAYMENT_H