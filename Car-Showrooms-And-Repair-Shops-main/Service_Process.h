#pragma once

#include "Service.h"

#include <iostream>
#include<string>
#include<queue>
using namespace std;


class Service_Process
{
	//int ID;
	unsigned int ID;
	string CustomerID;
	string Date;
	string AmountOfMoney;
	Service ChosenService;

public:
	Service_Process();
	Service_Process(unsigned int ID, string CustomerID, string Date, string AmountOfMoney, Service ChosenService);
	~Service_Process(void);

	string getCurrentDateTime();

	void readData(vector<Service>& servicesss, queue<Service_Process>& ServiceProcesss);
	void displayQueue(queue<Service_Process>& ServiceProcesss);


};




