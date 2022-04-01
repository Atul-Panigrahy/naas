#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include "agent.h"
using namespace std;



Agent::Agent(int _id, string _name,int _age)
{
    agentId = _id;
    name = _name;
    age = _age;
    active = true;
    salaryOfMonth = 0;
    generateMagazines();
}


void Agent::generateMagazines()
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


void Agent::addSubscriber(int _id)
{
    if(!active)
    {
        cout << "Service not available for this agent!! Join agency first\n";
        cout << "\n--------------------------------------------------------------\n";
        return;
    }

    if(find(subscriberList.begin(),subscriberList.end(),_id) != subscriberList.end())
    {
        cout << "Subscirber is already registered for the delivery service\n";
        cout << "\n--------------------------------------------------------------\n";
        return;
    }

    subscriberList.push_back(_id);
    cout << "Agent " << agentId << " Will deliver the magazines to the subscirber " << _id << "\n";
    cout << "\n--------------------------------------------------------------\n";
    
}


void Agent::removeSubscriber(int _id)
{
    if(!active)
    {
        cout << "Service not available for this agent!! Join agency first\n";
        cout << "\n--------------------------------------------------------------\n";
        return;
    }

    if(find(subscriberList.begin(),subscriberList.end(),_id) != subscriberList.end())
    {
        cout << "Subscirber is Not registered for the delivery service\n";
        cout << "\n--------------------------------------------------------------\n";
        return;
    }

    vector<int>updatedList;
    for(auto id:subscriberList)
    {
        if(id != _id)
        {
            updatedList.push_back(id);
        }
    }
    subscriberList = updatedList;
    cout << "Agent " << agentId << " Will no longer deliver the magazines to the subscirber " << _id << "\n";
    cout << "\n--------------------------------------------------------------\n";
}


void Agent::viewSystemMessage()
{
    if(!active)
    {
        cout << "Service not available for this agent!! Join agency first\n";
        cout << "\n--------------------------------------------------------------\n";
        return;
    }

    cout << "System generated message for the agent " << name << " ->";
    int count = 0 ;
    for(auto it:systemMessage)
    {
        cout << count++ << "  => " << it << endl;
    }
    cout << "\n--------------------------------------------------------------\n";
}
