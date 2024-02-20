#include "Garages.h"
#include "Service.h"

#include<fstream>
#include<iomanip>

#include <iostream>
#include <string>
#include<vector>
using namespace std;

vector<Service>services;
Service ServiceOBJ;

Garages::Garages()
{
	this->ID = "";
	this->Name = "";
	this->Location = "";
	this->PhoneNumber = "";
	/*vector<Garages> Garagesss;*/
	/*List_Of_Service = new Service[no_services];*/
}

Garages::~Garages(void)
{
}



void Garages:: readData(vector<Garages>& Garagesss) {

	char exitFlag = '+';

	while (exitFlag == '+')
	{
		Garages GaragesOBJJJ;
		/*bool IsFound = false;
		int size = int(Garagesss.size());*/

		fstream fout("Garages", ios::app);
		fout << setw(14) << "ID:" << setw(14) 
			<< "Name:" << setw(14) << "Location:" << setw(14) 
			<< "PhoneNumber:" << setw(14) << "listOfServices:" << endl;

		cout << "Enter Garage ID :" << endl;
		cin >> GaragesOBJJJ.ID;
		fout << setw(14) << GaragesOBJJJ.ID;

		cout << "Enter Garage Name :" << endl;
		cin >> GaragesOBJJJ.Name;
		fout << setw(14) << GaragesOBJJJ.Name;

		cout << "Enter Garage location :" << endl;
		cin >> GaragesOBJJJ.Location;
		fout << setw(14) << GaragesOBJJJ.Location;

		cout << "Enter Garage phoneNumber :" << endl;
		cin >> GaragesOBJJJ.PhoneNumber;
		fout << setw(14) << GaragesOBJJJ.PhoneNumber;

		fout << endl;

		cout << "Enter your list of services :" << endl;
		ServiceOBJ.readList(services, GaragesOBJJJ.ID); 

		//if ((ServiceOBJ.readListss(services, GaragesOBJJJ.ID)) == true)
		//{
		//	cout << "please choose another ID " << endl;

		//	//readLists(Garagesss, GaragesOBJJJ);
		//	ServiceOBJ.readList(services, GaragesOBJJJ.ID);
		//}
		
		/*readLists(Garagesss, GaragesOBJJJ);*/
		//if (size != 0) {

		//	for (int i = 0; i < size; i++)
		//	{
		//		if (Garagesss[i].ID == GaragesOBJJJ.ID) {
		//			IsFound = true;
		//			break;
		//		}
		//		else { IsFound = false; }
		//	}

		//	if (IsFound == true) {

		//		return true;

		//	}
		//	else {
		//		Garagesss.push_back(GaragesOBJJJ);
		//		return false;
		//	}

		//}
		//else {
		//	Garagesss.push_back(GaragesOBJJJ);
		//	return false;
		//}
		Garagesss.push_back(GaragesOBJJJ);
		fout.close();

		cout << "-----------------------------------------------" << endl;
		cout << "to add new Garage press + :" << endl;
		cout << "to exit press any key :" << endl;
		cin >> exitFlag;

	}
	//return false;
}

//void Garages::readLists(vector<Garages>& Garagesss, Garages& garage){
//
//	cout << "Enter your list of services :" << endl;
//	if ((ServiceOBJ.readList(services, garage.ID)) == true)
//	{
//	    cout << "please choose another ID " << endl;
//		readLists(Garagesss, garage);
//	}
//}



void Garages::displayVector(vector<Garages>& Garagesss)
{
	int size = int(Garagesss.size());
	if (size == 0) { cout << "Empty !" << endl; }
	
		for (int i = 0; i < size; i++)
		{
			cout << " your ID:" << endl;
			cout << Garagesss[i].ID << endl;
			cout << " garage's name: " << endl;
			cout << Garagesss[i].Name << endl;
			cout << " garage's location: " << endl;
			cout << Garagesss[i].Location << endl;
			cout << " garage's phoneNumber: " << endl;
			cout << Garagesss[i].PhoneNumber << endl;
			cout << " your list of services :" << endl;         //NEW
			ServiceOBJ.displayList(services,Garagesss[i].ID);    //NEW
			/*ServiceOBJ.displayVector(services);*/

			cout << "-----------------------------------------------" << endl;
		}
	
}



void Garages::displayData(vector<Garages>& Garagesss, int index) {

	cout << " your ID :" << endl;
	cout << Garagesss[index].ID << endl;
	cout << " your Name :" << endl;
	cout << Garagesss[index].Name << endl;
	cout << " your Location :" << endl;
	cout << Garagesss[index].Location << endl;
	cout << " your PhoneNumber :" << endl;
	cout << Garagesss[index].PhoneNumber << endl;
	cout << " your list of services :" << endl;         
	ServiceOBJ.displayList(services, Garagesss[index].ID);    
	cout << "-----------------------------------------------" << endl;

}

void Garages::searchVector(vector<Garages>& Garagesss, Garages& garage) {

    string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(Garagesss.size());

	for (i = 0; i < size; i++)
	{
		if (Garagesss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		garage.displayData(Garagesss, i);
	}
	else { cout << "not found!" << endl; }

}



void Garages::updateVector(vector<Garages>& Garagesss, Garages& garage) {

	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(Garagesss.size());

	for (i = 0; i < size; i++)
	{
		if (Garagesss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		garage.updateData(Garagesss, i);
	}
	else { cout << "not found!" << endl; }

}

void Garages::updateData(vector<Garages>& Garagesss, int index) {

	int updateDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to update all press 1" << endl;
	/*cout << "to update ID press 2" << endl;*/
	cout << "to update Name press 2" << endl;
	cout << "to update Location press 3" << endl;
	cout << "to update PhoneNumber press 4" << endl;
	cout << "to update list of services press 5" << endl;


	cin >> updateDataChoice;

	switch (updateDataChoice)
	{
		case 1: {
			/*cout << "Enter your new ID :" << endl;
			cin >> Garagesss[index].ID;*/
			cout << "Enter your new Name :" << endl;
			cin >> Garagesss[index].Name;
			cout << "Enter your new Location :" << endl;
			cin >> Garagesss[index].Location;
			cout << "Enter your new PhoneNumber :" << endl;
			cin >> Garagesss[index].PhoneNumber;
			cout << "Enter your list of services :" << endl;   
			ServiceOBJ.updateList(services, Garagesss[index].ID);
			cout << "Updated !" << endl;
			cout << "-----------------------------------------------" << endl;
			break;
		}
		//case 2: {
		//	cout << "-----------------------------------------------" << endl;
		//	/*cout << "Enter your new ID :" << endl;
		//	cin >> Garagesss[index].ID;
		//	cout << "Updated !" << endl;*/
		//	break;
		//}
		case 2: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new Name :" << endl;
			cin >> Garagesss[index].Name;
			cout << "Updated !" << endl;
			break;
		}
		case 3: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new Location :" << endl;
			cin >> Garagesss[index].Location;
			cout << "Updated !" << endl;
			break;
		}
		case 4: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new PhoneNumber :" << endl;
			cin >> Garagesss[index].PhoneNumber;
			cout << "Updated !" << endl;
			break;
		}

		case 5: {
			cout << "-----------------------------------------------" << endl;
			  cout << "Enter your list of services :" << endl;   
			  ServiceOBJ.updateList(services, Garagesss[index].ID);
			  cout << "Updated !" << endl;
			  break;
		}
		default: {
			cout << "INCORRECT !!" << endl;
		}
	}
}



void Garages::deleteObject(vector<Garages>& Garagesss)
{
	string userID;
	bool IsFound = false;
	int i;
	
	int size = int(Garagesss.size());

	if (size != 0) {

		cout << "Enter ID: " << endl;
		cin >> userID;

		for (i = 0; i < size; i++)
		{
			if (Garagesss[i].ID == userID) {
				IsFound = true;
				break;
			}
			else { IsFound = false; }
		}
		if (IsFound == true) {
			//cout << "found! at " << i << endl; 
			Garagesss.erase(Garagesss.begin() + i);

		}
		else { cout << "not found!" << endl; }
	}
}

void Garages::deleteVector(vector<Garages>& Garagesss) {
	Garagesss.clear();
}