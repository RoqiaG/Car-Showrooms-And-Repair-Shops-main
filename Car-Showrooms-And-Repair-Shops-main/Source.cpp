#include "Admin.h"
#include "Customer.h"
#include "Show_rooms.h"
#include "Car.h"
#include "Service_Process.h"
#include "Service.h"
#include "Garages.h"
#include "buy_rent_process.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Admin admin1;

vector<Customer>customers;
Customer customer1;

queue<Service_Process> ServiceProcesses;

void adminCorrectUser() {
	bool endAdmin = false;
	while (!endAdmin) 
	{
		int Adminchoice;
		cout << "-----------------------------------------------" << endl;
		cout << "to add press 1" << endl;
		cout << "to update press 2" << endl;
		cout << "to delete press 3" << endl;
		cout << "to get back press 4" << endl;
		cout << "to Exit press 5" << endl;

		cin >> Adminchoice;

		switch (Adminchoice)
		{
			case 1://add
			{ 
				bool endAddAdmin = false;

				while (!endAddAdmin) {
					
						int AddTaskAdminchoice;

						cout << "-----------------------------------------------" << endl;
						cout << "to add showrooms press 1" << endl;
						cout << "to add garages press 2" << endl;
						cout << "to add cars press 3" << endl;
						cout << "to add services press 4" << endl;
						cout << "to go back press 5" << endl;
						cout << "to Exit press 6" << endl;
						


						cin >> AddTaskAdminchoice;

						switch (AddTaskAdminchoice)
						{
						case 1://add showrooms
						{
							admin1.addShow_rooms();

							break;
						}
						case 2://add garages
						{
							admin1.addGarages();
							break;
						}
						case 3://add cars
						{
							admin1.addcar();
							break;
						}
						case 4://add services
						{
							admin1.addService();

							break;
						}
						case 5://back add
						{
							//adminCorrectUser();
							endAddAdmin = true;
							break;
						}
						case 6://Exit add
						{
							endAdmin = true;
							endAddAdmin = true;
							//cout << "Admin logged out from ADD!" << endl;
							break;
						}
						


						default:
						{
							cout << "INCORRECT !!" << endl;
						}

						}

					
				}
						break;
			}
			case 2://update
			{
				bool endupdateAdmin = false;
				while (!endupdateAdmin) {
				
					int updateTaskAdminchoice;

					cout << "-----------------------------------------------" << endl;
					cout << "to update showrooms press 1" << endl;
					cout << "to update garages press 2" << endl;
					cout << "to update cars press 3" << endl;
					cout << "to update services press 4" << endl;
					cout << "to go back press 5" << endl;
					cout << "to Exit press 6" << endl;
				


					cin >> updateTaskAdminchoice;

					switch (updateTaskAdminchoice)
					{
					case 1://update showrooms 
					{
						admin1.updateShow_rooms();
						break;
					}
					case 2://update garages
					{
						admin1.updateGarages();
						break;
					}
					case 3://update cars
					{
						admin1.updateCars();
						break;
					}
					case 4://update services
					{
						admin1.updateServices();
						break;
					}
					case 5://back update
					{
						//adminCorrectUser();
						endupdateAdmin = true;
						break;
					}
					case 6://Exit update
					{
						endupdateAdmin = true;
						endAdmin = true;
						break;
					}
				

					default:
					{
						cout << "INCORRECT !!" << endl;
					}
					}
					/*}*/
				}
				break;
			}
			case 3://delete
			{
				bool endDeleteAdmin = false;
				while (!endDeleteAdmin) {
				
					int deleteTaskAdminchoice;
					cout << "-----------------------------------------------" << endl;
					cout << "to delete showrooms press 1" << endl;
					cout << "to delete garages press 2" << endl;
					cout << "to delete cars press 3" << endl;
					cout << "to delete services press 4" << endl;
					cout << "to go back press 5" << endl;
					cout << "to Exit press 6" << endl;
					

					cin >> deleteTaskAdminchoice;

					switch (deleteTaskAdminchoice)
					{
					case 1://delete showrooms 
					{
						admin1.deleteShow_rooms();
						break; }
					case 2://delete garages
					{
						admin1.deleteGarage();
						break;
					}
					case 3://delete cars
					{
						admin1.deleteCar();
						break;
					}
					case 4://delete services
					{
						admin1.deleteService();
						break;
					}
					case 5://back delete
					{
						//adminCorrectUser();
						endDeleteAdmin = true;
						break;
					}
					case 6://Exit delete
					{
						endAdmin = true;
						endDeleteAdmin = true;
						/*enddeleteAdmin = true;*/
						break;
					}
					
					default:
					{
						cout << "INCORRECT !!" << endl;
					}
					}

				}
				break;
			}
			case 4://back admin
			{
				endAdmin = true;
				cout << "Admin logged out!" << endl;
				break;
			}
			case 5://Exit admin
			{
				endAdmin = true;
				cout << "Admin logged out!" << endl;
				break;
			}
			default:
			{
				cout << "INCORRECT !!" << endl;
			}
		}

	}
}

void adminUser() {
	//sign in
	
	/*vector<Admin>admins;*/
	//Admin admin1;
	cout << "***********************************************" << endl;
	admin1.readData(admin1);

	/*admins.push_back(admin1);*/

	if (admin1.ID != "1" || admin1.Username != "admin1" || admin1.Password != "123") {
		cout << "Incorrect username ,or password ,or ID!" << endl;
		adminUser();
	}
	else {
		adminCorrectUser();
	}
}

void customerCorrectUser() {
	bool endCustomer = false;
	while (!endCustomer) {
		int Customerchoice;
		cout << "-----------------------------------------------" << endl;
		cout << "to search press 1" << endl;
		cout << "to view press 2" << endl;
		cout << "to buy/rent/book press 3" << endl;
		cout << "to select service process 4" << endl;
		cout << "to get back press 5" << endl;
		cout << "to exit press 6" << endl;

		cin >> Customerchoice;

		switch (Customerchoice)
		{
			case 1://search
			{	
				bool endSearchCustomer = false;
				while (!endSearchCustomer) {

					int searchTaskCustomerchoice;
					cout << "-----------------------------------------------" << endl;
					cout << "to search car press 1" << endl;
					cout << "to search service press 2" << endl;
					cout << "to search showrooms press 3" << endl;
					cout << "to search garages press 4" << endl;
					cout << "to go back press 5" << endl;
					cout << "to Exit press 6" << endl;
				

					cin >> searchTaskCustomerchoice;

					switch (searchTaskCustomerchoice)
					{
					case 1://search car
					{
						customer1.searchCar(admin1.cars, admin1.carOBJ);
						break;
					}
					case 2://search service
					{
						customer1.searchService(admin1.services, admin1.ServiceOBJ);
						break;
					}
					case 3://search showrooms
					{
						customer1.searchShow_rooms(admin1.show_rooms, admin1.show_roomOBJ);
						break;
					}
					case 4://search garages
					{
						customer1.searchGarages(admin1.garages, admin1.garagesOBJ);
						break;
					}
					case 5://back search
					{
						endSearchCustomer = true;
						//customerCorrectUser();
						break;
					}
					case 6://Exit search
					{
						endSearchCustomer = true;
						endCustomer = true;
						break;
					}
				
					default:
					{
						cout << "INCORRECT !!" << endl;
					}
					}


				}
				break;
			}
			case 2://view
			{	
				bool endViewCustomer = false;
				while (!endViewCustomer) {
					int viewTaskCustomerchoice;
					cout << "-----------------------------------------------" << endl;
					cout << "to view showrooms press 1" << endl;
					cout << "to view garages press 2" << endl;
					cout << "to view service process press 3" << endl;
					cout << "to go back press 4" << endl;
					cout << "to Exit press 5" << endl;
				

					cin >> viewTaskCustomerchoice;

					switch (viewTaskCustomerchoice)
					{
					case 1://view showrooms
					{
						customer1.viewShow_rooms(admin1.show_rooms, admin1.show_roomOBJ);
						break;
					}
					case 2://view garages
					{	customer1.viewGarages(admin1.garages, admin1.garagesOBJ);
					break;
					}
					case 3://view service process
					{	customer1.viewProcess(ServiceProcesses);
					break;
					}
					case 4://back view
					{
						endViewCustomer = true;
						//customerCorrectUser();
						break;
					}
					case 5://Exit view
					{
						endViewCustomer = true;
						endCustomer = true;
						break;
					}
					
					default:
					{
						cout << "INCORRECT !!" << endl;
					}
					}
				}
				break;
			}
			case 3://buy/rent/book
			{
				bool endBuyCustomer = false;
				while (!endBuyCustomer) {

					int buyTaskCustomerchoice;
					cout << "-----------------------------------------------" << endl;
					cout << "to buy car press 1" << endl;
					cout << "to rent car press 2" << endl;
					cout << "to book garage press 3" << endl;
					cout << "to go back press 4" << endl;
					cout << "to Exit press 5" << endl;
				

					cin >> buyTaskCustomerchoice;

					switch (buyTaskCustomerchoice)
					{
					case 1://buy car
					{
						customer1.buyCar(admin1.cars, admin1.carOBJ);
						break;
					}
					case 2://rent car
					{
						customer1.rentCar(admin1.cars, admin1.carOBJ);
						break;
					}
					case 3://book garage
					{
						customer1.bookGarage(admin1.garages, admin1.garagesOBJ);
						break;
					}
					case 4://back buy
					{
						endBuyCustomer = true;
						//customerCorrectUser();
						break;
					}

					case 5://Exit buy
					{
						endBuyCustomer = true;
						endCustomer = true;
						break;
					}
				
					default:
					{
						cout << "INCORRECT !!" << endl;
					}
					}

				}
				break;
			}
			case 4: //service process
			{
				customer1.readProcess(admin1.services, ServiceProcesses);
				break;
			}
			case 5://back
			{
				endCustomer = true;
				break;
			}
			case 6://exit
			{
				endCustomer = true;
				break;
			}
			
			default:
			{
				cout << "INCORRECT !!" << endl;
			}

		}
	}
}

void customerUser() {

	int customerUserChoice;
	//Customer customer1;
	cout << "-----------------------------------------------" << endl;
	cout << "to sign up press 1" << endl;
	cout << "to sign in press 2" << endl;
	cout << "***********************************************" << endl;

	cin >> customerUserChoice;

	switch (customerUserChoice)
	{
		case 1:
		{
			if ((customer1.readDataSignUp(customers)) == true)
			{
				cout << "please choose another username, or ID " << endl;
				customerUser();
			}

			else {
				customerCorrectUser();
			}

			break;
		}
		case 2:
		{
			if ((customer1.readDataSignIn(customers)) == true)
			{
				customerCorrectUser();
			}
			else {
				cout << "Incorrect username, password or ID " << endl;
				customerUser();
			}
			break;
		}
		default: {
			cout << "INCORRECT !!" << endl;
		}

	}
}

void User() {
	bool end = false;
	while (!end) {
		int choice;
		cout << "-----------------------------------------------" << endl;
		cout << "to Sign in as Admin press 1" << endl;
		cout << "to Sign up/Sign in as Customer press 2" << endl;
		cout << "to Exit press 3" << endl;

		cin >> choice;

		switch (choice)
		{

			case 1: //Admin
			{
				adminUser();
				break;
			}
			case 2: //Customer
			{
				customerUser();
				break;
			}
			case 3: //Exit User
			{
				end = true;
				cout << "CLOSED!" << endl;
				break;
			}
			default:
			{
				cout << "INCORRECT !!" << endl;
			}

		}
	}
}

int main(){
	

	User();

	return 0;
}

