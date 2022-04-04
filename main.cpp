#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "subscriber.h"
#include "agent.h"
#include "manager.h"
using namespace std;
#include <unistd.h>
/*
Features to implement


*/

vector<Subscriber *> subs;
vector<Manager *> mag;
vector<Agent *> ag;
void manager()
{
}
void init()
{
    subs.push_back(new Subscriber(0, "ritesh nayak", 24, "b312 Mv Hall NIT,rourkela"));
    subs.back()->subcriptions.push_back(9);
    subs.push_back(new Subscriber(1, "atish ranna", 24, "a33 koelnagar A block,rourkela"));
    subs.back()->subcriptions.push_back(1);
    subs.push_back(new Subscriber(2, "arnab parkey", 24, "b23 koelnagar B block,rourkela"));
    subs.back()->subcriptions.push_back(2);
    subs.back()->subcriptions.push_back(3);
    subs.push_back(new Subscriber(3, "aman singh", 24, "g34 civil township,rourkela"));
    subs.back()->subcriptions.push_back(2);
    subs.back()->subcriptions.push_back(1);
    subs.push_back(new Subscriber(4, "niraj sharma", 24, "g103 sector 19,rourkela"));
    subs.back()->subcriptions.push_back(2);
    subs.back()->subcriptions.push_back(3);
    subs.back()->subcriptions.push_back(9);

    ag.push_back(new Agent(0, "tikklu raj", 19, subs));
    ag.back()->addSubscriber(0);
    ag.back()->addSubscriber(1);
    ag.back()->addSubscriber(2);
    ag.push_back(new Agent(1, "anwesh kapoor", 22, subs));
    ag.back()->addSubscriber(3);
    ag.back()->addSubscriber(4);
}

void agent()
{
    cout << "Welcome Agent" << endl;
    cout << "Please select a option\n";
    cout << "0 ->  30 day simulation \n";
    cout << "1 -> print deleveries today\n";
    cout << "2 -> generate bill\n";
    int choice;
    cin >> choice;

    if (choice == 0)
    {
        cout << "1 month Simulation\n ";
        cout << " 1 day ~ 1sec in simulation! \n";
        cout << "start...\n";
        for (int i = 0; i < 30; i++)
        {
            cout << "____________\n";
            cout << "|| Day:" << i + 1 << " ||\n";
            cout << "------------\n";
            for (auto i : ag)
            {
                i->printDeliveriesToday();
            }
            sleep(1);
        }
        cout<<"generating monthly bill...";
        sleep(2);
        for (auto i : ag)
        {
            i->generateMonthlyBill();
        }
        cout << "end...\n";
    }
    else if (choice == 1)
    {
        cout << "Deleveries Today...\n";
        for (auto i : ag)
        {
            i->printDeliveriesToday();
        }
    }
    else if (choice == 2)
    {
        cout << "Monthly Bill...\n";
        for (auto i : ag)
        {
            i->generateMonthlyBill();
        }
    }
    else
    {
        cout << "Invalid input to the system\n Restart the system\n";
    }
}
int main()
{
    init();
    cout << "Welcome to Newspaper Agency Automation Software" << endl;
    cout << "Please login as a\n";
    cout << "0 -> subscriber of Newspaper and magazines\n";
    cout << "1 -> delivery agent\n";
    cout << "2 -> manager of this Newspaper Agency\n";
    int choice;
    cin >> choice;

    if (choice == 0)
    {
        cout << "Logged into the system as a Subcriber\n";
    }
    else if (choice == 1)
    {
        cout << "Logged into the system as a Delivery Agent\n";
        agent();
    }
    else if (choice == 2)
    {
        cout << "Logged into the system as Manger of the Delivery Agency\n";
        Manager *s = new Manager(0, "john smith", 34);
    }
    else
    {
        cout << "Invalid input to the system\n Restart the system\n";
    }
    return 0;
}
