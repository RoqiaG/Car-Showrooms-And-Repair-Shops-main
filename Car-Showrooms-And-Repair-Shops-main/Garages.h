#pragma once

#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Garages
{
public:
	string ID;
	string Name;
	string Location;
	string PhoneNumber;
	/*Service* List_Of_Service;*/
	/*int no_services;*/

public:
	Garages();
	~Garages(void);

	void readData(vector<Garages>& Garagesss);
	/*void readLists(vector<Garages>& Garagesss, Garages& garage);*/
	void displayVector(vector<Garages>& Garagesss);

	void displayData(vector<Garages>& Garagesss, int index);
	void searchVector(vector<Garages>& Garagesss, Garages& garage);

	void updateVector(vector<Garages>& Garagesss, Garages& garage);
	void updateData(vector<Garages>& Garagesss, int index);

	void deleteObject(vector<Garages>& Garagesss);
	void deleteVector(vector<Garages>& Garagesss);
	
};
