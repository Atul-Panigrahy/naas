#include "subscriber.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



Subscriber::Subscriber(int _id, string _name,int _age,string _address)
{
    subscriberId = _id;
    name = _name;
    age = _age;
    active = true;
    address = _address;
    paymentPending = false;
    paymentPendingForNumberOfMonths = 0;
    amountPending = 0 ;
    generateMagazines();
}

void Subscriber::generateMagazines()
{
    // map magazine id to name
    magazineName[1] = "Science News";
    magazineName[2] = "New Scientist";
    magazineName[3] = "Cosmos";
    magazineName[4] = "Discover";
    magazineName[5] = "Ideas and Discoveries";
    magazineName[6] = "SciTech";
    magazineName[7] = "MIT Technical News";
    magazineName[8] = "Skeptic";
    magazineName[9] = "Science Reporter";
    magazineName[10] = "Astronomy";
    
    // map magazine id to price
    magazinePrice[1] = 16;
    magazinePrice[2] = 67;
    magazinePrice[3] = 3;
    magazinePrice[4] = 45;
    magazinePrice[5] = 88;
    magazinePrice[6] = 90;
    magazinePrice[7] = 5;
    magazinePrice[8] = 44;
    magazinePrice[9] = 7;
    magazinePrice[10] = 4;

}

void Subscriber::printSubscriptions()
{
    if(!active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return;
    }
    cout << "\n--------------------------------------------------------------\n";
    cout << "User " << name << " subscription list: \n" ;
    cout << "\n--------------------------------------------------------------\n\n";

    for(auto deliverables:subcriptions)
    {
        cout << "id= " << deliverables << " name = " << magazineName[deliverables] << "\n";
    }
    cout << "\n--------------------------------------------------------------\n\n";
}

void Subscriber::viewAllAvailableSubscriptions()
{
    if(!active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return;
    }

    cout << "\n--------------------------------------------------------------\n";
    cout << "For User " << name << " All available subscriptions list: \n" ;
    cout << "\n--------------------------------------------------------------\n\n";

    for(auto deliverables:magazineName)
    {
        int _id = deliverables.first;
        string _name = deliverables.second;
        string subcriptionStatus = "Not Taken";
        if(find(subcriptions.begin(),subcriptions.end(),_id)!= subcriptions.end())
        {
            subcriptionStatus = "taken";
        }
        cout << _id << " " << name << "-> price [" << magazinePrice[_id] << " ] status [" << (subcriptionStatus) << "]\n";
    }
    cout << "\n--------------------------------------------------------------\n\n";
}

bool Subscriber::requestChangeOfSubscriptions(int _id)
{
    if(!active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return false;
    }

    cout << "Request for change of subscription queued\nPlease wait....";
    try
    {
        string subcriptionStatus = "Not Taken";
        if(find(subcriptions.begin(),subcriptions.end(),_id)!= subcriptions.end())
        {
            subcriptionStatus = "taken";
        }
        if(subcriptionStatus == "taken")
        {
            cout << "User is already subscribed to the magazine\n";
            return true;
        }

        subcriptions.push_back(_id);
        cout << "subscription of " << magazineName[_id] << " successful for User " << name << "\n";
        cout << "The request will be in effect within 7 working days\n";
        return true;
    }
    catch(const std::exception& e)
    {
        cout << "Request for change of subscription unsuccessful\n";
        cout << "Please try again\n";
        std::cerr << e.what() << '\n';
        return false;
    }
}

void Subscriber::generateMonthlyBill()
{
    if(!active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return ;
    }

    cout << "\n--------------------------------------------------------------\n";
    cout << "For User " << name << " monthly bill generated: \n" ;
    cout << "Address: "<<address<<"\n--------------------------------------------------------------\n\n";

    int total = 0;
    for(auto deliverables:subcriptions)
    {
        cout << "id= " << deliverables << " name = " << magazineName[deliverables] ;
        cout << " cost = " << magazinePrice[deliverables]*30 << "\n";
        total += magazinePrice[deliverables]*30;
    }
    cout << "total cost for this month: " << total << "\n";
    paymentPending = true;
    paymentPendingForNumberOfMonths +=1;
    amountPending += total;
    systemMessage.push_back("Please deposit monthly due to continue our service");
    cout << "\n--------------------------------------------------------------\n\n";
}

void Subscriber::viewSystemMessage()
{
    if(!active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return;
    }

    cout << "\n--------------------------------------------------------------\n";
    cout << "For User " << name << " system messages are: \n" ;
    cout << "\n--------------------------------------------------------------\n\n";
    int count = 0;
    for(auto message: systemMessage)
    {
        cout << count++ << " => " << message << "\n";
    }
    cout << "\n--------------------------------------------------------------\n\n";
}

bool Subscriber::payDues()
{
    if(!active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return false;
    }

    if(paymentPending == false)
    {
        cout << "no pending payment\n";
        cout << "\n--------------------------------------------------------------\n\n";
        return true;
    }

    cout << "Payment due" << amountPending << " INR\n";
    cout << "Payement by cash(0) or cheque(1)\n";
    int choice;
    cin >> choice;
    if(choice == 0)
    {
        cout << "Delivery agent will collect the monthly due tommorrow\n";
    }
    else if(choice == 1)
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
    paymentPending = false;
    paymentPendingForNumberOfMonths = 0;
    amountPending = 0;
    cout << "\n--------------------------------------------------------------\n\n";
    return true;
}


bool Subscriber::stopService()
{
    if(!active)
    {
        cout << "Service not available for this user, please create an account to enjoy our services\n";
        return false;
    }

    if(paymentPending)
    {
        cout << "Please Clear payments before stop using the service\n";
        return false;
    }
    active = false;
    paymentPending = false;
    paymentPendingForNumberOfMonths = 0;
    amountPending = 0 ;
    cout << "Thank you for joining our service, Please create an acount to avail our service once more\n";
    return true;
}


