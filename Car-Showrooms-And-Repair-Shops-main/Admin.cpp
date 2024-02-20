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
#include<string>
using namespace std;


Admin::Admin()
{
	this->ID = 1;
	this->Username = "admin1";
	this->Password = "123";
	
}

Admin::~Admin()
{

}



void Admin::addShow_rooms() {
	
	show_roomOBJ.readData(show_rooms);
	//show_roomOBJ.displayVector(show_rooms);
}

void Admin::addService() {

	/*ServiceOBJ.readData(services);*/
	//ServiceOBJ.displayVector(services);

	if ((ServiceOBJ.readData(services)) == true)
	{
		cout << "please choose another ID " << endl;
		addService();
	}
	
}

void Admin::addcar(){
	
	//carOBJ.readData(cars);
	//carOBJ.displayvector(cars);

	if ((carOBJ.readData(cars)) == true)
	{
		cout << "please choose another ID " << endl;
		addcar();
	}
}

void Admin::addGarages() {
	
	garagesOBJ.readData(garages);
	//garagesOBJ.displayVector(garages);

	/*if ((garagesOBJ.readData(garages)) == true)
	{
		cout << "please choose another ID " << endl;
		garagesOBJ.readData(garages);
		//addGarages();
	}*/


}

void Admin::updateShow_rooms() {

	show_roomOBJ.updateVector(show_rooms, show_roomOBJ);
}

void Admin::updateServices() {

	ServiceOBJ.updateVector(services, ServiceOBJ);
}

void Admin::updateGarages() {

	garagesOBJ.updateVector(garages, garagesOBJ);
}

void Admin::updateCars() {

	carOBJ.updateVector(cars, carOBJ);
}



void Admin::deleteCar() 
{
	int deleteDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to delete all cars press 1" << endl;
	cout << "to delete one car press 2" << endl;

	cin >> deleteDataChoice;

	switch (deleteDataChoice)
	{
		case 1: {
			carOBJ.deleteVector(cars);
			cout << "Deleted !" << endl;
			break;
		}
		case 2: {
			carOBJ.deleteObject(cars);
			cout << "Deleted !" << endl;
			break;
		}
		default:
		{
			cout << "INCORRECT !!" << endl;
		}

	}
}

void Admin::deleteGarage()
{
	int deleteDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to delete all garages press 1" << endl;
	cout << "to delete one garage press 2" << endl;
	
	cin >> deleteDataChoice;

	switch (deleteDataChoice)
	{
		case 1: {
			garagesOBJ.deleteVector(garages);
			cout << "Deleted !" << endl;
			break;
		}
		case 2: {
			garagesOBJ.deleteObject(garages);
			cout << "Deleted !" << endl;
			break;
		}
		default:
		{
			cout << "INCORRECT !!" << endl;
		}
	
	}
}

void Admin::deleteService()
{
	int deleteDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to delete all services press 1" << endl;
	cout << "to delete one service press 2" << endl;

	cin >> deleteDataChoice;

	switch (deleteDataChoice)
	{
		case 1: {
			ServiceOBJ.deleteVector(services);
			cout << "Deleted !" << endl;
			break;
		}
		case 2: {
			ServiceOBJ.deleteObject(services);
			cout << "Deleted !" << endl;

			break;
		}
		default:
		{
			cout << "INCORRECT !!" << endl;
		}

	}
}

void Admin::deleteShow_rooms()
{
	int deleteDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to delete all  showrooms press 1" << endl;
	cout << "to delete one showroom press 2" << endl;

	cin >> deleteDataChoice;

	switch (deleteDataChoice)
	{
		case 1: {
			show_roomOBJ.deleteVector(show_rooms);
			cout << "Deleted !" << endl;

			break;
		}
		case 2: {
			show_roomOBJ.deleteObject(show_rooms);
			cout << "Deleted !" << endl;

			break;
		}
		default:
		{
			cout << "INCORRECT !!" << endl;
		}

	}

}
void Admin::readData(Admin& admin)
{
	fstream fout("Admin", ios::app);
	fout << setw(14) << "ID:" << setw(14)
		<< "Username:" << setw(14) 
		<< "Password:" << endl;

	cout << "Enter your ID :" << endl;
	cin >> admin.ID;
	fout << setw(14) << admin.ID;

	cout << "Enter your username :" << endl;
	cin >> admin.Username;
	fout << setw(14) << admin.Username ;

	cout << "Enter your password :" << endl;
	cin >> admin.Password;
	fout << setw(14) << admin.Password;
	fout << endl;

	fout.close();
	cout << "-----------------------------------------------" << endl;

	
}

void Admin::displayData(Admin admin) {
	cout << " your ID :" << endl;
	cout << admin.ID << endl;
	cout << " your username :" << endl;
	cout << admin.Username << endl;
	cout << " your password :" << endl;
	cout << admin.Password << endl;
	cout << "-----------------------------------------------" << endl;

}

//void Admin::displayVector(vector<Admin>& adminsss) {
//
//	int size = adminsss.size();
//	for (int i = 0; i < size; i++)
//	{
//		cout << " your ID :" << endl;
//		cout << adminsss[i].ID << endl;
//		cout << " your username :" << endl;
//		cout << adminsss[i].Username << endl;;
//		cout << " your password :" << endl;
//		cout << adminsss[i].Password << endl;
//	}
//}