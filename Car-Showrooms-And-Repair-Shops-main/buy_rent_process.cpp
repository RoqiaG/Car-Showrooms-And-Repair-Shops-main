#include "buy_rent_process.h"
#include "Car.h"
#include"Customer.h"

#include <iostream>
#include <string>
#include<vector>

#include<fstream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <time.h>
#include <ctime>

using namespace std;

static unsigned int process_ID = 0;

buy_rent_process::buy_rent_process() {

    ProcessID = 0;
    CustomerID = "";
    Date = "";
    AmountOfMoney = "";
}

buy_rent_process::buy_rent_process(int ProcessID, string CustomerID, string Date, string AmountOfMoney, Car ChosenCar) {
    this->ProcessID = ProcessID;
    this->CustomerID = CustomerID;
    this->Date = Date;
    this->AmountOfMoney = AmountOfMoney;
    this->ChosenCar = ChosenCar;
}


//Get current date/time, format is YYYY-MM-DD.HH:mm:ss
string buy_rent_process::getCurrentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];

#pragma warning(disable : 4996)
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void buy_rent_process::rentCar(vector<Car>& carsss, Car& car) {

    string id;
    cout << "Enter your customer id \n";
    cin >> id;

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

            Car chosen_car(carsss[i]);
            process_ID++;

            buy_rent_process rent =
                buy_rent_process(process_ID, id, getCurrentDateTime(), chosen_car.Price, chosen_car);

            cout << "Number process_ID :  "
                << rent.ProcessID << endl;
            cout << "date :  "
                << rent.Date << endl;
            //car.deleteObject(carsss);
            carsss.erase(carsss.begin() + i);

           /* _sleep(10000);*/
            this_thread::sleep_for(chrono::milliseconds(10000));
          /*   cout << "time's up no more rent \n";*/

            carsss.push_back(chosen_car);
        }
    }
}

void buy_rent_process::buyCar(vector<Car>& carsss, Car& car)
{
    string id;
    cout << "Enter your customer id \n";
    cin >> id;

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

            Car chosen_car(carsss[i]);
            process_ID++;

            buy_rent_process buyOBJ =
                buy_rent_process(process_ID, id, getCurrentDateTime(), carsss[i].Price, chosen_car);

            cout << "Number process_ID :  "
                << buyOBJ.ProcessID << endl;
            cout << "date :  " <<
                buyOBJ.Date << endl;

            //car.deleteObject(carsss);
            carsss.erase(carsss.begin() + i);
        }
    }
}


buy_rent_process::~buy_rent_process(void)
{
}