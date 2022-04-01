#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "subscriber.h"
#include "agent.h"
#include "manager.h"
using namespace std;

/*
Features to implement


*/
int main()
{
    cout << "Welcome to Newspaper Agency Automation Software" << endl;
    cout << "Please login as a\n";
    cout << "0 -> subscriber of Newspaper and magazines\n";
    cout << "1 -> delivery agent\n";
    cout << "2 -> manager of this Newspaper Agency\n";
    int choice;
    cin >> choice;

    if(choice == 0)
    {
        cout << "Logged into the system as a Subcriber\n";
    }   
    else if(choice == 1)
    {
        cout << "Logged into the system as a Delivery Agent\n";
    } 
    else if(choice == 3)
    {
        cout << "Logged into the system as Manger of the Delivery Agency\n";
    }
    else
    {
        cout << "Invalid input to the system\n Restart the system\n";
    }
    return 0;
}