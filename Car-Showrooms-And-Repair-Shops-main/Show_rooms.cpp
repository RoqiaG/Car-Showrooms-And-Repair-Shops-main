#include "Show_rooms.h"
#include "Car.h"

#include<fstream>
#include<iomanip>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<Car>cars;
Car carOBJ;

Show_rooms::Show_rooms() {
	this->ID = "";
	this->Name = "";
	this->Location = "";
	this->PhoneNumber = "";

	/*List_Of_Car = new Car[no_cars];*/
}

Show_rooms::~Show_rooms(void) {

}




void Show_rooms:: readData(vector<Show_rooms>& Show_roomsss) {

	char exitFlag = '+';

	while (exitFlag == '+')
	{
		Show_rooms Show_roomsOBJJJ;

		fstream fout("Show_rooms", ios::app);
		fout << setw(14) << "ID:" << setw(14) 
			<< "Name:" << setw(14) 
			<< "Location:" << setw(14) 
			<< "PhoneNumber:" << setw(14) 
			<< "ListOfCars:" << endl;

		cout << "Enter your ID :" << endl;
		cin >> Show_roomsOBJJJ.ID;
		fout << setw(14) << Show_roomsOBJJJ.ID;

		cout << "Enter your Name :" << endl;
		cin >> Show_roomsOBJJJ.Name;
		fout << setw(14) << Show_roomsOBJJJ.Name;

		cout << "Enter your Location :" << endl;
		cin >> Show_roomsOBJJJ.Location;
		fout << setw(14) << Show_roomsOBJJJ.Location;

		cout << "Enter your PhoneNumber :" << endl;
		cin >> Show_roomsOBJJJ.PhoneNumber;
		fout << setw(14) << Show_roomsOBJJJ.PhoneNumber;

		fout << endl;

		cout << "Enter your list of cars :" << endl;   
		carOBJ.readList(cars, Show_roomsOBJJJ.ID);     
		

		Show_roomsss.push_back(Show_roomsOBJJJ);
		fout.close();

		cout << "-----------------------------------------------" << endl;
		cout << "to add new Showroom press + :" << endl;
		cout << "to exit press any key :" << endl;
		cin >> exitFlag;
	}
}

void Show_rooms::displayVector(vector<Show_rooms>& Show_roomsss) {

	int size = int(Show_roomsss.size());
	if (size == 0) { cout << "Empty !" << endl; }
	for (int i = 0; i < size; i++)
	{
		cout << " your ID :" << endl;
		cout << Show_roomsss[i].ID << endl;
		cout << " your Name :" << endl;
		cout << Show_roomsss[i].Name << endl;
		cout << " your Location :" << endl;
		cout << Show_roomsss[i].Location << endl;
		cout << " your PhoneNumber :" << endl;
		cout << Show_roomsss[i].PhoneNumber << endl;
		cout << " your list of cars :" << endl;			
		carOBJ.displayList(cars, Show_roomsss[i].ID);    
		cout << "-----------------------------------------------" << endl;
	}
}



void Show_rooms::displayData(vector<Show_rooms>& Show_roomsss,int index) {

		cout << " your ID :" << endl;
		cout << Show_roomsss[index].ID << endl;
		cout << " your Name :" << endl;
		cout << Show_roomsss[index].Name << endl;
		cout << " your Location :" << endl;
		cout << Show_roomsss[index].Location << endl;
		cout << " your PhoneNumber :" << endl;
		cout << Show_roomsss[index].PhoneNumber << endl;
		cout << " your list of cars :" << endl;
		cout << Show_roomsss[index].PhoneNumber << endl;
		cout << " your list of cars :" << endl;		
		carOBJ.displayList(cars, Show_roomsss[index].ID);    
		cout << "-----------------------------------------------" << endl;
	
}

void Show_rooms::searchVector(vector<Show_rooms>& Show_roomsss, Show_rooms &show_rooms) {

	string userID;
	bool IsFound=false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(Show_roomsss.size());

	for ( i = 0; i < size; i++)
	{
		if (Show_roomsss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else{ IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		show_rooms.displayData(Show_roomsss, i);
	}
	else { cout << "not found!" << endl; }
	
}



void Show_rooms::updateVector(vector<Show_rooms>& Show_roomsss, Show_rooms& show_rooms) {

	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(Show_roomsss.size());

	for (i = 0; i < size; i++)
	{
		if (Show_roomsss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		show_rooms.updateData(Show_roomsss, i);
	}
	else { cout << "not found!" << endl; }

}

void Show_rooms::updateData(vector<Show_rooms>& Show_roomsss, int index) {

	int updateDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to update all press 1" << endl;
	/*cout << "to update ID press 2" << endl;*/
	cout << "to update Name press 2" << endl;
	cout << "to update Location press 3" << endl;
	cout << "to update PhoneNumber press 4" << endl;
	cout << "to update list of cars press 5" << endl;

	cin >> updateDataChoice;

	switch (updateDataChoice)
	{
		case 1: {
			/*cout << "Enter your new ID :" << endl;
			cin >> Show_roomsss[index].ID;*/
			cout << "Enter your new Name :" << endl;
			cin >> Show_roomsss[index].Name;
			cout << "Enter your new Location :" << endl;
			cin >> Show_roomsss[index].Location;
			cout << "Enter your new PhoneNumber :" << endl;
			cin >> Show_roomsss[index].PhoneNumber;
			cout << "Enter your list of cars  :" << endl;  
			/*carOBJ.updateList(cars, Show_roomsss[index].ID, index);*/
			carOBJ.updateList(cars, Show_roomsss[index].ID);
			cout << "Updated !" << endl;
			cout << "-----------------------------------------------" << endl;
			break;
		}
		//case 2: {
		//	cout << "-----------------------------------------------" << endl;
		//	/*cout << "Enter your new ID :" << endl;
		//	cin >> Show_roomsss[index].ID;
		//	cout << "Updated !" << endl;*/
		//
		//	break;
		//}
		case 2: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new Name :" << endl;
			cin >> Show_roomsss[index].Name;
			cout << "Updated !" << endl;
			break;
		}
		case 3: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new Location :" << endl;
			cin >> Show_roomsss[index].Location; 
			cout << "Updated !" << endl;
			break;
		}
		case 4: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new PhoneNumber :" << endl;
			cin >> Show_roomsss[index].PhoneNumber; 
			cout << "Updated !" << endl;
			break;
		}
		case 5: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your list of cars  :" << endl;   
			/*carOBJ.updateList(cars, Show_roomsss[index].ID, index);*/
			carOBJ.updateList(cars, Show_roomsss[index].ID);
			cout << "Updated !" << endl;
			break;
		}
		default: {
			cout << "INCORRECT !!" << endl;
		}
	}
}



void Show_rooms::deleteObject(vector<Show_rooms>& Show_roomsss)
{
	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(Show_roomsss.size());

	for (i = 0; i < size; i++)
	{
		if (Show_roomsss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}
	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		Show_roomsss.erase(Show_roomsss.begin() + i);
	}
	else { cout << "not found!" << endl; }
}

void Show_rooms::deleteVector(vector<Show_rooms>& Show_roomsss) {
	Show_roomsss.clear();
}