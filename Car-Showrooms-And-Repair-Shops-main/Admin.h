#pragma once

#include <iostream>
#include<string>
#include<vector>

#include"Garages.h"
#include "Show_rooms.h"
#include "Service.h"
#include "Car.h"
using namespace std;

class Admin
{
public:
	string ID;
	string Username ;
	string Password ;

	vector<Admin>adminsss;

	vector<Garages>garages;
	Garages garagesOBJ;

	vector<Car>cars;
	Car carOBJ;

	vector<Show_rooms>show_rooms;
	Show_rooms show_roomOBJ;

	vector<Service>services;
	Service ServiceOBJ;

public:
	Admin();
	~Admin();

	void addShow_rooms();
	void addService();
	void addcar();
	void addGarages();

	void updateShow_rooms();
	void updateServices();
	void updateGarages();
	void updateCars();

	void deleteCar();
	void deleteGarage();
	void deleteService();
	void deleteShow_rooms();

	void readData(Admin& admin);
	void displayData(Admin admin);
	/*void displayVector(vector<Admin>& Adminsss);*/


	
};

