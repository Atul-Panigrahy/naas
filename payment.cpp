#include <iostream>
#include "payment.h"
#include "subscriber.h"
#include "cash.h"
#include "cheque.h"
using namespace std;

Payment::Payment()
{
    amount = 0;
    successStatus = false;
}

bool Payment::carryOutTransaction(int _id, string dep, string coll, string dt, int amount = 0)
{
    if (amount <= 0)
    {
        cout << "Amount involved in the transaction is not allowed!!";
        return false;
    }

    try
    {
        transactionId = _id;
        depositor = dep;
        collector = coll;
        date = dt;
        this->amount = amount;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    
}


bool Payment::payDues(Subscriber& sub)
{
    if (!sub.active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return false;
    }

    if (sub.paymentPending == false)
    {
        cout << "no pending payment\n";
        cout << "\n--------------------------------------------------------------\n\n";
        return true;
    }

    cout << "Payment due" << sub.amountPending << " INR\n";
    cout << "Payement by cash(0) or cheque(1)\n";
    int choice;
    cin >> choice;
    if (choice == 0)
    {
        cout << "Delivery agent will collect the monthly due tommorrow\n";
    }
    else if (choice == 1)
    {
        int chequeNumber;
        cout << " Enter cheque number ";
        cin >> chequeNumber;
        cout << "Payment collected successfully\n";
    }
    else
    {
        cout << "Unknown argument to the system\n";
        return false;
    }
    sub.paymentPending = false;
    sub.paymentPendingForNumberOfMonths = 0;
    sub.amountPending = 0;
    cout << "\n--------------------------------------------------------------\n\n";
    return true;
}