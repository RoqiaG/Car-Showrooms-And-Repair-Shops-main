#include "Car.h"

#include<fstream>
#include<iomanip>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

Car::Car()
{
	this->ID = "";
	this->Make = "";
	this->Model = "";
	this->Year = 0;
	this->Price = "";
	this->Installment = "";
	
}

Car::Car(const Car& c)
{

	this->ID = c.ID;
	this->Make = c.Make;
	this->Model = c.Model;
	this->Price = c.Price;
	this->Year = c.Year;
	this->Installment = c.Installment;

}

Car::~Car(void)
{
}

bool Car::readData(vector<Car>& carsss) {


	char exitFlag = '+';

	while (exitFlag == '+')
	{
		Car CarOBJJJ;
		bool IsFound = false;
		int size = int(carsss.size());
		fstream fout("Car", ios::app);
		fout << setw(14) << "ID:" << setw(14)
			<< "make:" << setw(14) << "Model:" << setw(14)
			<< "Year:" << setw(14) << "Price:" << setw(14)
			<< "Installment:" << endl;
		
		cout << "Enter your ID :" << endl;
		cin >> CarOBJJJ.ID;
		fout << setw(14) << CarOBJJJ.ID;

		cout << "Enter make Of car :" << endl;
		cin >> CarOBJJJ.Make;
		fout << setw(14) << CarOBJJJ.Make;

		cout << "Enter Model Of car :" << endl;
		cin >> CarOBJJJ.Model;
		fout << setw(14) << CarOBJJJ.Model;

		cout << "Enter year Of car :" << endl;
		cin >> CarOBJJJ.Year;
		fout << setw(14) << CarOBJJJ.Year;

		cout << "Enter price Of car :" << endl;
		cin >> CarOBJJJ.Price;
		fout << setw(14) << CarOBJJJ.Price;

		cout << "Enter Installment Of car :" << endl;
		cin >> CarOBJJJ.Installment;
		fout << setw(14) << CarOBJJJ.Installment;
		fout << endl;
		if (size != 0) {

			for (int i = 0; i < size; i++)
			{
				if (carsss[i].ID == CarOBJJJ.ID) {
					IsFound = true;
					break;
				}
				else { IsFound = false; }
			}

			if (IsFound == true) {

				return true;

			}
			else {
				carsss.push_back(CarOBJJJ);
				return false;
			}

		}
		else {
			carsss.push_back(CarOBJJJ);
			return false;
		}
		//carsss.push_back(CarOBJJJ);
		fout.close();

		cout << "-----------------------------------------------" << endl;
		cout << "to add new Car press + :" << endl;
		cout << "to exit press any key :" << endl;
		cin >> exitFlag;

	}
	return false;
}

 
void Car::displayVector(vector<Car>&carsss){

	int size = int(carsss.size());
	for (int i = 0; i < size; i++)
	{
		cout << " your ID :" << endl;
		cout << carsss[i].ID << endl;
		cout << " make Of car :" << endl;
		cout << carsss[i].Make << endl;
		cout << " Model Of car :" << endl;
		cout << carsss[i].Model << endl;
		cout << " year Of car :" << endl;
		cout << carsss[i].Year << endl;
		cout << " price Of car :" << endl;
		cout << carsss[i].Price << endl;
		cout << " Installment Of car :" << endl;
		cout << carsss[i].Installment << endl;
		cout << "-----------------------------------------------" << endl;
	}
}



void Car::searchVector(vector<Car>& carsss, Car& car) {
	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(carsss.size());

	for (i = 0; i < size; i++)
	{
		if (carsss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		car.displayData(carsss, i);
	}
	else { cout << "not found!" << endl; }
}

void Car::displayData(vector<Car>& carsss, int index) {

	cout << " your ID :" << endl;
	cout << carsss[index].ID << endl;
	cout << " make Of car :" << endl;
	cout << carsss[index].Make << endl;
	cout << " Model Of car :" << endl;
	cout << carsss[index].Model << endl;
	cout << " year Of car :" << endl;
	cout << carsss[index].Year << endl;
	cout << " price Of car :" << endl;
	cout << carsss[index].Price << endl;
	cout << " Installment Of car :" << endl;
	cout << carsss[index].Installment << endl;
	cout << "-----------------------------------------------" << endl;

}



void Car::updateVector(vector<Car>& carsss, Car& car) {

	string userID;
	bool IsFound = false;
	int i;
	cout << "Enter ID: " << endl;
	cin >> userID;

	int size = int(carsss.size());

	for (i = 0; i < size; i++)
	{
		if (carsss[i].ID == userID) {
			IsFound = true;
			break;
		}
		else { IsFound = false; }
	}

	if (IsFound == true) {
		//cout << "found! at " << i << endl;
		car.updateData(carsss, i);
	}
	else { cout << "not found!" << endl; }

}

void Car::updateData(vector<Car>& carsss, int index) {

	int updateDataChoice;
	cout << "-----------------------------------------------" << endl;
	cout << "to update all press 1" << endl;
	cout << "to update ID press 2" << endl;
	cout << "to update Make press 3" << endl;
	cout << "to update Model press 4" << endl;
	cout << "to update Year press 5" << endl;
	cout << "to update price press 6" << endl;
	cout << "to update Installment press 7" << endl;

	cin >> updateDataChoice;

	switch (updateDataChoice)
	{
		case 1: {
			/*cout << "Enter your ID :" << endl;
			cin >> carsss[index].ID;*/
			cout << "Enter new make Of car :" << endl;
			cin >> carsss[index].Make;
			cout << "Enter new Model Of car :" << endl;
			cin >> carsss[index].Model;
			cout << "Enter new year Of car :" << endl;
			cin >> carsss[index].Year;
			cout << "Enter new price Of car :" << endl;
			cin >> carsss[index].Price;
			cout << "Enter new Installment Of car :" << endl;
			cin >> carsss[index].Installment;
			cout << "Updated !" << endl;
			cout << "-----------------------------------------------" << endl;
			break;
		}
		case 2: {
			cout << "-----------------------------------------------" << endl;
			/*cout << "Enter your new ID :" << endl;
			cin >> carsss[index].ID;
			cout << "Updated !" << endl;
			*/
			break;
		}
		case 3: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter new make Of car :" << endl;
			cin >> carsss[index].Make;
			cout << "Updated !" << endl;
			break;
		}
		case 4: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter new Model Of car :" << endl;
			cin >> carsss[index].Model;
			cout << "Updated !" << endl;
			break;
		}
		case 5: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter new year Of car :" << endl;
			cin >> carsss[index].Year;
			cout << "Updated !" << endl;
			break;
		}
		case 6: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter new price Of car :" << endl;
			cin >> carsss[index].Price;
			cout << "Updated !" << endl;
			break;
		}
		case 7: {
			cout << "-----------------------------------------------" << endl;
			cout << "Enter new Installment Of car :" << endl;
			cin >> carsss[index].Installment;
			cout << "Updated !" << endl;
			break;
		}
		default:
		{
			cout << "INCORRECT !!" << endl;
		}

	}
}



void Car::deleteObject(vector<Car>& carsss) {
	string userID;
	bool IsFound = false;
	int i;

	int size = int(carsss.size());

	if (size != 0) {
		cout << "Enter ID: " << endl;
		cin >> userID;

		for (i = 0; i < size; i++)
		{
			if (carsss[i].ID == userID) {
				IsFound = true;
				break;
			}
			else { IsFound = false; }
		}

		if (IsFound == true) {
			//cout << "found! at " << i << endl;
			carsss.erase(carsss.begin() + i);
		}
		else { cout << "not found!" << endl; }
	}
	else {
		 cout << "Empty !" << endl; 
	}
}

void Car::deleteVector(vector<Car>& carsss) {
	carsss.clear();
}

void Car::readList(vector<Car>& carsss, string id) {

	char exitFlag = '+';

	while (exitFlag == '+')
	{
		Car car;
		car.sID = id;   

		fstream fout("Show_rooms", ios::app);
		fout << setw(14) << "ID:" << setw(14)
			<< "make:" << setw(14) << "Model:" << setw(14)
			<< "Year:" << setw(14) << "Price:" << setw(14)
			<< "Installment:" << endl;
		
		cout << "Enter your ID :" << endl;
		cin >> car.ID;
		fout << setw(14) << car.ID;

		cout << "Enter make Of car :" << endl;
		cin >> car.Make;
		fout << setw(14) << car.Make;

		cout << "Enter Model Of car :" << endl;
		cin >> car.Model;
		fout << setw(14) << car.Model;

		cout << "Enter year Of car :" << endl;
		cin >> car.Year;
		fout << setw(14) << car.Year;

		cout << "Enter price Of car :" << endl;
		cin >> car.Price;
		fout << setw(14) << car.Price;

		cout << "Enter Installment Of car :" << endl;
		cin >> car.Installment;
		fout << setw(14) << car.Installment;
		fout << endl;

		carsss.push_back(car);
		fout.close();

		cout << "------------" << endl;
		cout << "to add new Car press + :" << endl;
		cout << "to exit press any key :" << endl;
		cin >> exitFlag;

	}
}

void Car::displayList(vector<Car>& carsss, string id){

	int size = int(carsss.size());
	for (int i = 0; i < size; i++)
	{
		if (id == carsss[i].sID) {   
			cout << " your ID :" << endl;
			cout << carsss[i].ID << endl;
			cout << " make Of car :" << endl;
			cout << carsss[i].Make << endl;
			cout << " Model Of car :" << endl;
			cout << carsss[i].Model << endl;
			cout << " year Of car :" << endl;
			cout << carsss[i].Year << endl;
			cout << " price Of car :" << endl;
			cout << carsss[i].Price << endl;
			cout << " Installment Of car :" << endl;
			cout << carsss[i].Installment << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}
}



//void Car::updateList(vector<Car>& carsss, int id, int index) {
//	/*if (id == carsss[index].sID) {*/
//	carsss[index].sID = id;
//	cout << "Enter your new ID :" << endl;
//	cin >> carsss[index].ID;
//	cout << "Enter new make Of car :" << endl;
//	cin >> carsss[index].Make;
//	cout << "Enter new Model Of car :" << endl;
//	cin >> carsss[index].Model;
//	cout << "Enter new year Of car :" << endl;
//	cin >> carsss[index].Year;
//	cout << "Enter new price Of car :" << endl;
//	cin >> carsss[index].Price;
//	cout << "Enter new Installment Of car :" << endl;
//	cin >> carsss[index].Installment;
//	cout << "-----------------------------------------------" << endl;
//	/*}*/
//}

void Car::updateList(vector<Car>& carsss, string id) {
	//carsss[index].sID = id;

	int size = int(carsss.size());
	for (int index = 0; index < size; index++) {
		if (id == carsss[index].sID) {
		cout << "Enter your new ID :" << endl;
		cin >> carsss[index].ID;
		cout << "Enter new make Of car :" << endl;
		cin >> carsss[index].Make;
		cout << "Enter new Model Of car :" << endl;
		cin >> carsss[index].Model;
		cout << "Enter new year Of car :" << endl;
		cin >> carsss[index].Year;
		cout << "Enter new price Of car :" << endl;
		cin >> carsss[index].Price;
		cout << "Enter new Installment Of car :" << endl;
		cin >> carsss[index].Installment;
		cout << "-----------------------------------------------" << endl;
		}
	}
}