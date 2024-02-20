#pragma once
#include "Show_rooms.h"
#include "Garages.h"
#include "Car.h"
#include "Service.h"
#include "buy_rent_process.h"
#include "Service_Process.h"

#include <iostream>
#include<string>
#include <queue>
#include <vector>


using namespace std;

class Customer
{
public:
	string ID;
	string Username;
	string Password;
	int no_of_customers;

	/*stack<Service>history;*/
	/*vector<Customer>customersss;*/
	//vector<Customer>customers;

	Service_Process ProcessOBJ;


public:
	Customer();
	//~Customer();

	/*bool readData(vector<Customer>& customersss);*/
	void displayVector(vector<Customer>& customersss);

	void viewShow_rooms(vector<Show_rooms>& Show_roomsss, Show_rooms& Show_room);
	void viewGarages(vector<Garages>& garagesss, Garages& garage);
	/*void viewprocess(vector<buy_rent_process>& pro, buy_rent_process& var); */

	void searchShow_rooms(vector<Show_rooms>& Show_roomsss, Show_rooms& Show_room);
	void searchGarages(vector<Garages>& garagesss, Garages& garage);
	void searchCar(vector<Car>& carsss, Car& car);
	void searchService(vector<Service>& servicesss, Service& service);

	void buyCar(vector<Car>& carsss, Car& car);
	void rentCar(vector<Car>& carsss, Car& car);
	void bookGarage(vector<Garages>&garagesss, Garages& garage);

	bool readDataSignUp(vector<Customer>& customersss);
	bool readDataSignIn(vector<Customer>& customersss);
	bool SignUp(vector<Customer>& customersss, int size, bool IsFound, Customer& customerOBJJJ);
	bool SignIn(vector<Customer>& customersss, int size, bool IsFound, Customer& customerOBJJJ);

	void readProcess(vector<Service>& servicesss, queue<Service_Process>& ServiceProcesss);
	void viewProcess(queue<Service_Process>& ServiceProcesss);
};

