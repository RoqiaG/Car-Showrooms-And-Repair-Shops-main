#pragma once
#include "Car.h"

#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Show_rooms
{
	public:

		string ID;
		string Name;
		string Location;
		string PhoneNumber;
		vector<Car>List_Of_Car;

		/*vector<Car>List_Of_Cars;*/
	
		//int no_cars;

		/*vector<Show_rooms>Show_roomsss;*/


	public:
		Show_rooms();
		~Show_rooms(void);

		void readData(vector<Show_rooms>& Show_roomsss);
		void displayVector(vector<Show_rooms>& Show_roomsss);

		void searchVector(vector<Show_rooms>& Show_roomsss, Show_rooms& show_rooms);
		void displayData(vector<Show_rooms>& Show_roomsss, int index);
	

		void updateVector(vector<Show_rooms>& Show_roomsss, Show_rooms& show_rooms);
		void updateData(vector<Show_rooms>& Show_roomsss, int index);

		void deleteObject(vector<Show_rooms>& Show_roomsss);
		void deleteVector(vector<Show_rooms>& Show_roomsss);




};

 






