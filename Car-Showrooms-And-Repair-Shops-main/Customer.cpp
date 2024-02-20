#include "Customer.h"
#include "Admin.h"
#include "Show_rooms.h"
#include "Car.h"
#include "Service_Process.h"
#include "Service.h"
#include "Garages.h"
#include "buy_rent_process.h"

#include<fstream>
#include<iomanip>

#include <iostream>
#include <vector>
#include <queue>
#include<string>

using namespace std;


Customer customerOBJ;


Customer::Customer()
{
	this->ID = "";
	this->Username = "";
	this->Password = "";
}

//Customer::~Customer()
//{
//	
//}

//bool Customer::readData(vector<Customer>& customersss) {
//	
//	
//		Customer customerOBJJJ;
//		bool IsFound = false;
//		int size = int(customersss.size());
//
//		fstream fout("Customer", ios::app);
//		fout << setw(14) << "ID:" 
//			<< setw(14) << "Username:" << setw(14) 
//			<< "Password:" << endl;
//
//		cout << "Enter ID :" << endl;
//		cin >> customerOBJJJ.ID;
//		fout << setw(14) << customerOBJJJ.ID;
//
//		cout << "Enter Username :" << endl;
//		cin >> customerOBJJJ.Username;
//		fout << setw(14) << customerOBJJJ.Username;
//
//		cout << "Enter Password :" << endl;
//		cin >> customerOBJJJ.Password;
//		fout << setw(14) << customerOBJJJ.Password;
//		fout << endl;
//
//		fout.close();
//	
//		if (size != 0) {
//
//			for (int i = 0; i < size; i++)
//			{
//				if (customersss[i].ID == customerOBJJJ.ID 
//					|| customersss[i].Username == customerOBJJJ.Username) {
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
//				customersss.push_back(customerOBJJJ);
//				return false;
//			}
//		
//		}
//		else {
//			customersss.push_back(customerOBJJJ);
//			return false;
//		}
//		//customerOBJJJ.displayVector(customersss);
//}


bool Customer::readDataSignUp(vector<Customer>& customersss) {

	Customer customerOBJJJ;
	bool IsFound = false;
	int size = int(customersss.size());

	fstream fout("Customer", ios::app);
	fout << setw(14) << "ID:"
		<< setw(14) << "Username:" << setw(14)
		<< "Password:" << endl;

	cout << "Enter ID :" << endl;
	cin >> customerOBJJJ.ID;
	fout << setw(14) << customerOBJJJ.ID;

	cout << "Enter Username :" << endl;
	cin >> customerOBJJJ.Username;
	fout << setw(14) << customerOBJJJ.Username;

	cout << "Enter Password :" << endl;
	cin >> customerOBJJJ.Password;
	fout << setw(14) << customerOBJJJ.Password;
	fout << endl;

	return SignUp(customersss,size,IsFound,  customerOBJJJ);


	fout.close();

	
}
bool Customer::readDataSignIn(vector<Customer>& customersss) {

	Customer customerOBJJJ;
	bool IsFound = false;
	int size = int(customersss.size());

	fstream fout("Customer", ios::app);
	fout << setw(14) << "ID:"
		<< setw(14) << "Username:" << setw(14)
		<< "Password:" << endl;

	cout << "Enter ID :" << endl;
	cin >> customerOBJJJ.ID;
	fout << setw(14) << customerOBJJJ.ID;

	cout << "Enter Username :" << endl;
	cin >> customerOBJJJ.Username;
	fout << setw(14) << customerOBJJJ.Username;

	cout << "Enter Password :" << endl;
	cin >> customerOBJJJ.Password;
	fout << setw(14) << customerOBJJJ.Password;
	fout << endl;

	return SignIn(customersss, size, IsFound, customerOBJJJ);


	fout.close();


}
bool Customer::SignUp(vector<Customer>& customersss,int size,bool IsFound, Customer& customerOBJJJ) {
	if (size != 0) {

		for (int i = 0; i < size; i++)
		{
			if (customersss[i].ID == customerOBJJJ.ID
				|| customersss[i].Username == customerOBJJJ.Username) {
				IsFound = true;
				break;
			}
			else { IsFound = false; }
		}

		if (IsFound == true) {

			return true;

		}
		else {
			customersss.push_back(customerOBJJJ);
			return false;
		}

	}
	else {
		customersss.push_back(customerOBJJJ);
		return false;
	}
	//customerOBJJJ.displayVector(customersss);
}

bool Customer::SignIn(vector<Customer>& customersss, int size, bool IsFound, Customer& customerOBJJJ) {
	if (size != 0) {

		for (int i = 0; i < size; i++)
		{
			if (customersss[i].ID == customerOBJJJ.ID
				|| customersss[i].Username == customerOBJJJ.Username
				|| customersss[i].Password == customerOBJJJ.Password
				) {
				IsFound = true;
				break;
			}
			else { IsFound = false; }
		}

		if (IsFound == true) {

			return true;

		}
		else {
			customersss.push_back(customerOBJJJ);
			return false;
		}

	}
	else {
		customersss.push_back(customerOBJJJ);
		return false;
	}
	//customerOBJJJ.displayVector(customersss);
}


void Customer::displayVector(vector<Customer>& customersss) {

	int size = int(customersss.size());
	if (size == 0) { cout << "empty!" << endl; }
	for (int i = 0; i < size; i++)
	{
		cout << " your ID :" << endl;
		cout << customersss[i].ID << endl;
		cout << " your username :" << endl;
		cout << customersss[i].Username << endl;
		cout << " your password :" << endl;
		cout << customersss[i].Password << endl;
		cout << "-----------------------------------------------" << endl;
	}
}






void Customer::viewShow_rooms(vector<Show_rooms>& Show_roomsss, Show_rooms& Show_room) {
	
	Show_room.displayVector(Show_roomsss);
}

void Customer::viewGarages(vector<Garages>& garagesss, Garages& garage) {
	garage.displayVector(garagesss);
}



void Customer::searchShow_rooms(vector<Show_rooms>& Show_roomsss, Show_rooms& Show_room) {
	
	Show_room.searchVector(Show_roomsss, Show_room);
}

void Customer::searchGarages(vector<Garages>& garagesss, Garages& garage) {

	garage.searchVector(garagesss, garage);
}

void Customer::searchCar(vector<Car>& carsss, Car& car) {

	car.searchVector(carsss, car);
}

void Customer::searchService(vector<Service>& servicesss, Service& service) {

	service.searchVector(servicesss, service);
}



void Customer::buyCar(vector<Car>& carsss, Car& car) {
	/*car.displayVector(carsss);
	car.deleteObject(carsss);*/

	buy_rent_process buy;
	buy.buyCar(carsss, car);
}

void Customer::rentCar(vector<Car>& carsss, Car& car)
{
	/*car.displayVector(carsss);
	car.deleteObject(carsss);*/

	buy_rent_process rent;
	rent.rentCar(carsss, car);
}

void Customer::bookGarage(vector<Garages>& garagesss, Garages& garage) {
	garage.displayVector(garagesss);
	garage.deleteObject(garagesss);
}


//void Customer::viewShow_rooms() {
//	Admin adminnn;
//	adminnn.viewShow_rooms();
//}

void Customer::readProcess(vector<Service>& servicesss, queue<Service_Process>& ServiceProcesss) {

	ProcessOBJ.readData(servicesss, ServiceProcesss);
}
void Customer::viewProcess(queue<Service_Process>& ServiceProcesss) {

	ProcessOBJ.displayQueue(ServiceProcesss);
}