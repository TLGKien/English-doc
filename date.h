#pragma once
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class date
{
	private:
		int day, month, year;
		bool checkLeapYear();
		int numberOfDays();
		bool checkDate();
		
	public:
		int getDay();
		int getMonth();
		int getYear();
		void display();
		bool convertToDate(char[]);
};

// getter function
int date::getDay()
{
	return day;
}
int date::getMonth()
{
	return month;
}
int date::getYear()
{
	return year;
}

// display date
void date::display()
{	if(day < 10) cout << "0" << day;
	else cout << day;
	cout << "/";
	if(month < 10) cout << "0" << month;
	else cout << month;
	cout << "/" << year;
}

// check is date correct????
bool date::checkDate()
{
	if(month < 1 || month > 12) 
		return false;
	else
	{
		if(day < 1 || day > numberOfDays())
			return false;	
	}
	return true;
}

// how many days in month?????
int date::numberOfDays()
{
	if(month == 2 && !checkLeapYear())
		return 28;
	if(month == 4 || month == 6 || month == 9 || month == 11) 
		return 30;
	if(month == 2 && checkLeapYear()) 
		return 29;
	return 31;
}

// check is leap year?????
bool date::checkLeapYear()
{
	if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) return true;
	return false;
}

// convert string to date (char[] dd/mm/yyyy -> int dd, int mm, int yyyy)
bool date::convertToDate(char arr[])
{
	if(strlen(arr) > 10) return false;
	for(int i = 0; i < 10; i++)
	{
		if (i == 2 || i == 5) 
		{
			if (arr[i] != '/') return false;
		}
		else 
		{
			if(arr[i] < 48 || arr[i] > 57) return false;
		}
	}

	char day[2];
	day[0] = arr[0]; day[1] = arr[1];
	this->day = atoi(day);
	char month[2];
	month[0] = arr[3]; month[1] = arr[4];
	this->month = atoi(month);
	char year[4];
	year[0] = arr[6]; year[1] = arr[7]; year[2] = arr[8]; year[3] = arr[9];
	this->year = atoi(year);
	return checkDate();
}