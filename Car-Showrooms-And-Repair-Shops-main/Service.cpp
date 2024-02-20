#include "Service.h"

#include<fstream>
#include<iomanip>

#include <iostream>
#include <string>
#include <vector>
using namespace std;


Service::Service()
{
	this->ID = "";
	this->Name = "";
	this->Price = "";
	this->gID = "";
}

Service::Service(const  Service& s)
{
	this->ID = s.ID;
	this->Name = s.Name;
	this->Price = s.Price;
	this->gID = s.gID;


}
Service::~Service(void)
{
}



bool Service::readData(vector<Service>& servicesss)
{
	char exitFlag = '+';

	while (exitFlag == '+')
	{
		Service ServiceOBJJJ;
		bool IsFound = false;
		int size = int(servicesss.size());

		fstream fout("Service", ios::app);
		fout << setw(14) << "ID:" << setw(14) <<
			"Name:" << setw(14) << "Price:" << endl;

		cout << "Enter Service ID :" << endl;
		cin >> ServiceOBJJJ.ID;
		fout << setw(14) << ServiceOBJJJ.ID;

		cout << "Enter Service Name :" << endl;
		cin >> ServiceOBJJJ.Name;
		fout << setw(14) << ServiceOBJJJ.Name;

		cout << "Enter Service Price :" << endl;
		cin >> ServiceOBJJJ.Price;
		fout << setw(14) << ServiceOBJJJ.Price;
		fout << endl;
		if (size != 0) {

			for (int i = 0; i < size; i++)
			{
				if (servicesss[i].ID == ServiceOBJJJ.ID) {
					IsFound = true;
					break;
				}
				else { IsFound = false; }
			}

			if (IsFound == true) {

				return true;

			}
			else {
				servicesss.push_back(ServiceOBJJJ);
				return false;
			}

		}
		else {
			servicesss.push_back(ServiceOBJJJ);
			return false;
		}

		//servicesss.push_back(ServiceOBJJJ);
		fout.close();
		
	
		cout << "-----------------------------------------------" << endl;
		cout << "to add new Service press + :" << endl;
		cout << "to exit press any key :" << endl;
		cin >> exitFlag;
		
	}

	return false;
}

void Service::displayVector(vector<Service>& servicesss)
{
	int size = int(servicesss.size());
	for (int i = 0; i < size; i++)
	{
		cout << " Service ID :" << endl;
		cout << servicesss[i].ID << endl;
		cout << " Service Name :" << endl;
		cout << servicesss[i].Name << endl;
		cout << " Service Price :" << endl;
		cout << servicesss[i].Price << endl;
		cout << "-----------------------------------------------" << endl;
	}
}



void Service::searchVector(vector<Service>& servicesss, Service& service) {
	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(servicesss.size());

	for (i = 0; i < size; i++)
	{
		if (servicesss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		service.displayData(servicesss, i);
	}
	else { cout << "not found!" << endl; }

}

void Service::displayData(vector<Service>& servicesss, int index) {

	cout << " Service ID :" << endl;
	cout << servicesss[index].ID << endl;
	cout << " Service Name :" << endl;
	cout << servicesss[index].Name << endl;
	cout << " Service Price :" << endl;
	cout << servicesss[index].Price << endl;
	cout << "-----------------------------------------------" << endl;
}



void Service::updateVector(vector<Service>& servicesss, Service& services) {

	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(servicesss.size());

	for (i = 0; i < size; i++)
	{
		if (servicesss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		services.updateData(servicesss, i);
	}
	else { cout << "not found!" << endl; }
}

void Service::updateData(vector<Service>& servicesss, int index) {

	int updateDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to update all press 1" << endl;
	cout << "to update ID press 2" << endl;
	cout << "to update Name press 3" << endl;
	cout << "to update Price press 4" << endl;



	cin >> updateDataChoice;

	switch (updateDataChoice)
	{
		case 1: {
			cout << "Enter your new ID :" << endl;
			cin >> servicesss[index].ID;
			cout << "Enter your new Name :" << endl;
			cin >> servicesss[index].Name;
			cout << "Enter your new Price :" << endl;
			cin >> servicesss[index].Price;
			cout << "Updated !" << endl;
			cout << "-----------------------------------------------" << endl;
			break;
		}
		case 2: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new ID :" << endl;
			cin >> servicesss[index].ID;
			cout << "Updated !" << endl;
			break;
		}
		case 3: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new Name :" << endl;
			cin >> servicesss[index].Name;
			cout << "Updated !" << endl;
			break;
		}
		case 4: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter your new Price:" << endl;
			cin >> servicesss[index].Price;
			cout << "Updated !" << endl;
			break;
		}
		default:
		{
			cout << "INCORRECT !!" << endl;
		}
	}
}


void Service::deleteObject(vector<Service>& Servicesss)
{
	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(Servicesss.size());

	for (i = 0; i < size; i++)
	{
		if (Servicesss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}
	if (IsFound == true) {
		//cout << "found! at " << i << endl; 
		Servicesss.erase(Servicesss.begin() + i);

	}
	else { cout << "not found!" << endl; }
}

void Service::deleteVector(vector<Service>& Servicesss) {
	Servicesss.clear();
}

void Service::readList(vector<Service>& servicesss, string id){

	char exitFlag = '+';

	while (exitFlag == '+')
	{
		//vector<Service> serviceList;
		Service service;
		service.gID = id;   
		
	
		fstream fout("Garages", ios::app);
		fout << setw(14) << "ID:" << setw(14) <<
			"Name:" << setw(14) << "Price:" << endl;

		cout << "Enter Service ID :" << endl;
		cin >> service.ID;
		fout << setw(14) << service.ID;

		cout << "Enter Service Name :" << endl;
		cin >> service.Name;
		fout << setw(14) << service.Name;

		cout << "Enter Service Price :" << endl;
		cin >> service.Price;
		fout << setw(14) << service.Price;
		fout << endl;

		servicesss.push_back(service);
		fout.close();

		cout << "------------" << endl;
		cout << "to add new Service press + :" << endl;
		cout << "to exit press any key :" << endl;
		cin >> exitFlag;
		

	}
}

void Service::displayList(vector<Service>& servicesss, string id)
{
	int size = int(servicesss.size());
	
	for (int i = 0; i < size; i++)
	{
		if (id == servicesss[i].gID) {   
		cout << " Service ID :" << endl;
		cout << servicesss[i].ID << endl;
		cout << " Service Name :" << endl;
		cout << servicesss[i].Name << endl;
		cout << " Service Price :" << endl;
		cout << servicesss[i].Price << endl;
		cout << "-----------------------------------------------" << endl;
		}
	}
}

//void Service::updateList(vector<Service>& servicesss, string id, int index) {
//	/*if (id == servicesss[index].gID) {*/
//	    servicesss[index].gID = id;
//		cout << "Enter your new ID :" << endl;
//		cin >> servicesss[index].ID;
//		cout << "Enter your new Name :" << endl;
//		cin >> servicesss[index].Name;
//		cout << "Enter your new Price :" << endl;
//		cin >> servicesss[index].Price;
//		cout << "-----------------------------------------------" << endl;
//	/*}*/
//}

void Service::updateList(vector<Service>& servicesss, string id) {
	int size = int(servicesss.size());
	for (int index = 0; index < size; index++) {
		if (id == servicesss[index].gID) {
			servicesss[index].gID = id;
			cout << "Enter your new ID :" << endl;
			cin >> servicesss[index].ID;
			cout << "Enter your new Name :" << endl;
			cin >> servicesss[index].Name;
			cout << "Enter your new Price :" << endl;
			cin >> servicesss[index].Price;
			cout << "-----------------------------------------------" << endl;
		}
	}
}


//bool Service::readListss(vector<Service>& servicesss, string id){
//
//	char exitFlag = '+';
//	bool IsFound = false;
//	int size = int(servicesss.size());
//
//	while (exitFlag == '+')
//	{
//		//vector<Service> serviceList;
//		Service service;
//		service.gID = id;   //NEW
//		
//	
//		fstream fout("Garages", ios::app);
//		fout << setw(14) << "ID:" << setw(14) <<
//			"Name:" << setw(14) << "Price:" << endl;
//
//		cout << "Enter Service ID :" << endl;
//		cin >> service.ID;
//		fout << setw(14) << service.ID;
//
//		cout << "Enter Service Name :" << endl;
//		cin >> service.Name;
//		fout << setw(14) << service.Name;
//
//		cout << "Enter Service Price :" << endl;
//		cin >> service.Price;
//		fout << setw(14) << service.Price;
//		fout << endl;
//
//		if (size != 0) {
//
//			for (int i = 0; i < size; i++)
//			{
//				if (servicesss[i].ID == service.ID) {
//					IsFound = true;
//					break;
//				}
//				else { IsFound = false; }
//			}
//
//			if (IsFound == true) {
//
//				return true;
//
//			}
//			else {
//				servicesss.push_back(service);
//				return false;
//			}
//
//		}
//		else {
//			servicesss.push_back(service);
//			return false;
//		}
//
//		//servicesss.push_back(service);
//		fout.close();
//
//		cout << "------------" << endl;
//		cout << "to add new Service press + :" << endl;
//		cout << "to exit press any key :" << endl;
//		cin >> exitFlag;
//		
//
//	}
//	return false;
//}