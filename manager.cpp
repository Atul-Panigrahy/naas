
#include "manager.h"

Manager::Manager(int _id, string _name, int _age,vector<Subscriber *> &v,vector<Agent *> &a) : subs(v),ag(a)
{
    managerId = _id;
    name = _name;
    age = _age;
    generateMagazines();
}

void Manager::generateMagazines()
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

void Manager::getSubscriberList(){
    cout<<" subscriber List \n";
    cout<<" name | age \n";
    cout<<"--------------------\n";
    for(auto i : subs){
        cout<<i->name<<" | "<<i->age<<endl;
    }
    cout<<endl;
}
void Manager::getDeliveryAgentList(){
    cout<<" Agent List \n";
    cout<<" name | age \n";
    cout<<"--------------------\n";
    for(auto i : ag){
        cout<<i->name<<" | "<<i->age<<endl;
    }
    cout<<endl;
}

void Manager::addSubscriber(int _id)
{
    if (find(subscriberList.begin(), subscriberList.end(), _id) != subscriberList.end())
    {
        return;
    }

    subscriberList.push_back(_id);
}

void Manager::removeSubscriber(int _id)
{

    if (find(subscriberList.begin(), subscriberList.end(), _id) != subscriberList.end())
    {
        return;
    }

    vector<int> updatedList;
    for (auto id : subscriberList)
    {
        if (id != _id)
        {
            updatedList.push_back(id);
        }
    }
    subscriberList = updatedList;
}

void Manager::addDeliveryAgent(int _id)
{
    if (find(AgentList.begin(), AgentList.end(), _id) != AgentList.end())
    {
        return;
    }

    AgentList.push_back(_id);
}

void Manager::removeDeliveryAgent(int _id)
{

    if (find(AgentList.begin(), AgentList.end(), _id) != AgentList.end())
    {
        return;
    }

    vector<int> updatedList;
    for (auto id : AgentList)
    {
        if (id != _id)
        {
            updatedList.push_back(id);
        }
    }
    AgentList = updatedList;
}

void Manager::viewAllAvailableSubscriptions()
{
    cout << "\n--------------------------------------------------------------\n";
    cout << "for <Manager> " << name << " listing All available subscriptions list: \n" ;
    cout << "\n--------------------------------------------------------------\n\n";

    for(auto deliverables:magazineName)
    {
        int _id = deliverables.first;
        string _name = deliverables.second;
        cout << _id << " " << name << "-> price [" << magazinePrice[_id] << "]\n";
    }
    cout << "\n--------------------------------------------------------------\n\n";
}