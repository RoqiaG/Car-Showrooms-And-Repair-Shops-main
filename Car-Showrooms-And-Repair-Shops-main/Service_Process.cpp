#include "Service_Process.h"
#include "Service.h"

#include <iostream>
#include <string>
#include <queue>
using namespace std;

static unsigned int process_ID = 0;

Service_Process::Service_Process()
{
    ID = 0;
    CustomerID = "";
    Date = "";
    AmountOfMoney = "";
}

Service_Process::Service_Process(unsigned int ID, string CustomerID, string Date, string AmountOfMoney, Service ChosenService)
{

    this->ID = ID;
    this->CustomerID = CustomerID;
    this->Date = Date;
    this->AmountOfMoney = AmountOfMoney;
    this->ChosenService = ChosenService;
}


string Service_Process::getCurrentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];

#pragma warning(disable : 4996)
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}



void Service_Process::readData(vector<Service>& servicesss, queue<Service_Process>& ServiceProcesss)
{

    string id;
    cout << "Enter your customer id \n";
    cin >> id;

    string userID;
    bool IsFound = false;
    int i;

    int size = int(servicesss.size());

    if (size != 0) {
        cout << "Enter ID: " << endl;
        cin >> userID;

        for (i = 0; i < size; i++)
        {
            if (servicesss[i].ID == userID) {
                IsFound = true;
                break;
            }
            else { IsFound = false; }
        }

        if (IsFound == true) {
            process_ID++;

            Service chosen_service(servicesss[i]);
            Service_Process chosenServiceObj
                = Service_Process(process_ID, id, getCurrentDateTime(), chosen_service.Price, chosen_service);
            ServiceProcesss.push(chosenServiceObj);

            cout << " operation done successfully ! \n";
        }
    }
}


void  Service_Process::displayQueue(queue<Service_Process>& ServiceProcesss)
{
    string id;
    cout << " enter your customer id \n";
    cin >> id;

    queue<Service_Process>  q = ServiceProcesss;

    while (q.size() != 0)
    {
        if (ServiceProcesss.front().CustomerID == id) {
          
            cout << "Service Process ID " << q.front().ID << endl;
            cout << "Service Process Customer ID " << q.front().CustomerID << endl;
            cout << "Service Process Price " << q.front().AmountOfMoney << endl;
            cout << "Service Process Date " << q.front().Date << endl;

            cout << " Chosen Service  Garage ID " << q.front().ChosenService.gID << endl;
            cout << " Chosen Service  ID " << q.front().ChosenService.ID << endl;
            cout << " Chosen Service  Name " << q.front().ChosenService.Name << endl;
            cout << " Chosen Service  Price " << q.front().ChosenService.Price << endl;
            q.pop();

            cout << '\n';
        }
        else
            cout << "Enter Correct Customer id \n";
    }

}



Service_Process::~Service_Process(void)
{
}