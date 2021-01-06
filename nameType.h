#pragma once
#include <iomanip>
#include <cstring>

using namespace std;

class nameType
{
	private:
		char firstName[9];
		char middleName[15];
		char lastName[9];
		char fullName[30];
		void move(char[], int);

	public:
		char* getFirstName();
		char* getMiddleName();
		char* getLastName();
		char* getFullName();
		bool convertToName(char[]);
};

// delete 1 charactor in position p
void nameType::move(char arr[], int p)
{
	int length = strlen(arr);
	for (int i = p; i < length - 1; ++i)
		arr[i] = arr[i+1];
	arr[length-1] = '\0';
}

// getter function
char* nameType::getFirstName()
{
	return firstName;
}
char* nameType::getMiddleName()
{
	return middleName;
}
char* nameType::getLastName()
{
	return lastName;
}
char* nameType::getFullName()
{
	return fullName;
}

// function to format the student's name
bool nameType::convertToName(char arr[])
{
	fullName[0] = firstName[0] = lastName[0] = middleName[0] = '\0';
	for (int i = 0; i < (int)strlen(arr); ++i)
	{

		// name has character special, return false
		if((arr[i] < 65 || arr[i] >90) && (arr[i] <97 || arr[i] > 122) && arr[i] != ' ')
			return false;

		// if name has two ' ' consecutive, delete 1 ' '
		else if(arr[i] == ' ' && arr[i+1] == ' ')
		{	
			move(arr,i+1);
			i--;
		}

		// if after ' ' is lower alphabet, to_upper character
		else if(arr[i] == ' ' && (arr[i+1] >= 97 && arr[i+1] <= 122)) arr[i+1] -= 32;
	}

	// if the end of name is ' ', delete its.
	if(arr[strlen(arr)-1] == ' ') arr[strlen(arr)-1] = '\0';
	
	// if the begin of name is lower alphabet -> to_upper character
	if(arr[0] >= 97 && arr[0] <= 122)
		arr[0] -= 32;

	// if the begin of name is ' ' -> delete
	else if(arr[0] == ' ')
		move(arr,0);

	// assign fullname = arr (after format)
	for (int i = 0; i < 30; ++i)
		fullName[i] = arr[i];

	// indexs tick position ' '
	int index1 = 0, index2 = 0;

	// tick the first position
	for (int i = 0; i < (int)strlen(arr); ++i)
		if(fullName[i] == ' ' )
		{
			index1 = index2 = i;
			break;
		}

	// tick the 2nd position
	for (int i = index1; i < (int)strlen(arr); ++i)
	{
		if(fullName[i] == ' ' )
			index2 = i;
	}

	// assign lastname (ho)
	for (int i = 0; i < index1; ++i)
		lastName[i] = fullName[i];
	lastName[index1] = '\0';

	// assign middle name (ten dem)
	for (int i = index1 + 1; i < index2; ++i)
		middleName[i-(index1+1)] = fullName[i];
	middleName[index2-(index1+1)] = '\0';

	// assign first name (ten goi)
	for (int i = index2 + 1; i < (int)strlen(fullName); ++i)
		firstName[i - (index2 + 1)] = fullName[i];
	firstName[(int)strlen(fullName) - (index2 + 1)] = '\0';
	return true;
}