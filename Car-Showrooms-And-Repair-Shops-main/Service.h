#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Service
{
public:
    string ID;
    string gID;
    string Name;
    string Price;
    /*int no_services;*/

    /*vector<Service> servicesss;*/

public:
    Service();
    Service(const  Service& s);
    ~Service(void);

    bool readData (vector<Service>& servicesss);
    void displayVector(vector<Service>& servicesss);

    void searchVector(vector<Service>& servicesss, Service& service);
    void displayData(vector<Service>& servicesss, int index);

    void updateVector(vector<Service>& servicesss, Service& services);
    void updateData(vector<Service>& servicesss, int index);

    void deleteObject(vector<Service>& Servicesss);
    void deleteVector(vector<Service>& Servicesss);

    void readList(vector<Service>& servicesss, string id);
    /*bool readListss(vector<Service>& servicesss, string id);*/
    void displayList(vector<Service>& servicesss, string id);
    //void updateList(vector<Service>& servicesss, string id,int index);
    void updateList(vector<Service>& servicesss, string id);
};

	


	

    



