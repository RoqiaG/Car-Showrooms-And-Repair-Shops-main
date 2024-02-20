#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car
{
public:
	string ID;
	string sID;   
	string Make;
	string Model;
	int Year;
	string Price;
	string Installment;
	/*int no_cars;*/
	
	/*vector<Car>carsss;*/
public:
	Car();
	Car(const Car& c);
	~Car(void);

	bool readData(vector<Car>& carsss);
	void displayVector(vector<Car>& carsss);
	
	void searchVector(vector<Car>& carsss, Car& car);
	void displayData(vector<Car>& carsss, int index);

	void updateVector(vector<Car>& carsss, Car& car);
	void updateData(vector<Car>& carsss, int index);

	void deleteObject(vector<Car>& carsss);
	void deleteVector(vector<Car>& carsss);

	void readList(vector<Car>& carsss, string id);      
	void displayList(vector<Car>& carsss, string id);   
	//void updateList(vector<Car>& carsss, string id, int index);
	void updateList(vector<Car>& carsss, string id);
	
};

	
	

 
