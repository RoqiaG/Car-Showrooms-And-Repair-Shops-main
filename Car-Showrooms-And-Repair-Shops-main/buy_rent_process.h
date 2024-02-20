#pragma once

#include"Customer.h"
#include "Car.h"

#include <iostream>
#include<string>
#include <vector>

using namespace std;

class buy_rent_process
{
	int ProcessID;
	string CustomerID;
	string Date;
	string AmountOfMoney;
	Car ChosenCar;
	
	/*int compare();*/

public:
	buy_rent_process();
	buy_rent_process(int ProcessID, string CustomerID, string Date, string AmountOfMoney, Car ChosenCar);

	string getCurrentDateTime();

	void rentCar(vector<Car>& carsss, Car& car);
	void buyCar(vector<Car>& carsss, Car& car);

	~buy_rent_process(void);
};





