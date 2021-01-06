#pragma once
#include "list.h"
#include "raw.h"

void swap(student*, student*);						// swap value of two students

void selectionSort(vector<student>&, int);			// sort algorithm
void insertionSort(vector<student>&, int);
void quickSort(vector<student>&, int, int, int);
void merge(vector<student>&, int, int, int,int);
void mergeSort(vector<student>&, int, int, int);

bool dateOfBirthStringCompare(student, student);	// compare two birthdat (string form)
bool dateOfBirthCompare(student, student);			// compare two birthday (date form)
bool scoreCompare(student, student);				// compare two score
bool classIDCompare(student, student);				// compare two class id
bool studentIDCompare(student, student);			// compare two student id
bool fullNameCompare(student, student);				// compare two full name
bool nameCompare(student, student);					// compare two name
bool studentCompare(student, student, int);			// compare two students,


// function to sort list
void list::sort(int choose1, int choose2)
{
	switch(choose1)
	{
		// case 1 is selection sort
		case 1:
			selectionSort(studentList,choose2);
			break;

		// case 2 is insertion sort
		case 2:
			insertionSort(studentList,choose2);
			break;

		// case 3 is quick sort
		case 3:
			quickSort(studentList,0,studentList.size()-1,choose2);
			break;

		//case 4 is merge sort
		case 4:
			mergeSort(studentList,0, studentList.size()-1,choose2);
			break;
	}
}

// function to swap value of two students
void swap(student *st1, student *st2)
{
	student tmp = *st1;
	*st1 = *st2;
	*st2 = tmp;
}

void selectionSort(vector<student> &arr, int choose2)
{
	int i_min;
	for (int i = 0; i < (int)arr.size()-1; ++i)
	{
		i_min = i;
		for (int j = i+1; j < (int)arr.size(); ++j)
			if(studentCompare(arr[i_min], arr[j],choose2))
				i_min = j;
		if (i != i_min)
			swap(&arr[i],&arr[i_min]);
	}
}

void insertionSort(vector<student> &arr, int choose2)
{
	for (int i = 1; i < (int)arr.size(); ++i)
	{
		int index = i;
		while(studentCompare(arr[index-1], arr[index],choose2) && index > 0)
		{
			swap(&arr[index-1], &arr[index]);
			index--;
		}
	}
}

void quickSort (vector<student> &arr, int l, int r, int choose2)
{
	
	if (l < r)
	{
		// chia mảng thành 2 vùng: 	+ vùng 1 gồm các phần tử nhỏ hơn key đang xét, 
		//							+ một vùng gồm các phần tử lớn hơn key đang xét
		student key;
		int i;
		key = arr[r]; //chọn key là phần tử ở cuối cùng của mảng
		i = l - 1;
		for (int j = l; j < r; j++)
			if (studentCompare(key, arr[j],choose2))
			{
				i++;
				if(i != j)
					swap(&arr[i],&arr[j]);
			}
		i++;
		swap(&arr[i],&arr[r]);

		//gọi đệ quy với 2 vùng được phân
		quickSort(arr,l,i-1,choose2);
		quickSort(arr,i+1,r,choose2);
	}
}

void merge(vector<student> &arr, int l, int m, int r, int choose2)
{
	
	vector<student> left;
	for (int i = l; i <= m; ++i)
	{
		left.push_back(arr[l]);
		arr.erase(arr.begin()+l);
	}

	vector<student> right;
	for (int i = m+1; i <= r; ++i)
	{
		right.push_back(arr[l]);
		arr.erase(arr.begin()+l);
	}

	while(left.size() != 0 && right.size() != 0)
	{
		if(studentCompare(left.back(),right.back(),choose2))
		{ 
			arr.insert(arr.begin()+l, left.back());
			left.pop_back();
		}
		else
		{	
			arr.insert(arr.begin()+l, right.back());
			right.pop_back();
		}
	}

	while(left.size() != 0)
	{
		arr.insert(arr.begin()+l, left.back());
		left.pop_back();
	}

	while(right.size() != 0)
	{
		arr.insert(arr.begin()+l, right.back());
		right.pop_back();
	}	
}

void mergeSort(vector<student> &arr, int l, int r, int choose2)
{
	if(r > l)
	{
		int m = (l+r)/2;
		mergeSort(arr,l,m,choose2);
		mergeSort(arr,m+1,r,choose2);
		merge(arr,l,m,r,choose2);
	}
}

// function to compare two students, if student 1 > student 2 return true, else false
bool studentCompare(student st1, student st2,int choose2)
{
	switch(choose2)
	{
		case 1:
			return classIDCompare(st1,st2);
		case 2:
			return studentIDCompare(st1,st2);
		case 3:
			return nameCompare(st1,st2);
		case 4:
			return dateOfBirthCompare(st1,st2);
		case 5:
			return scoreCompare(st1,st2);
		case 6:
			return fullNameCompare(st1,st2);			// sort for binary search by name
		case 7: 
			return dateOfBirthStringCompare(st1,st2); 	// sort for binary search by birthday
	}
	return true;
}

// function to compare two classIDs, if classID1 > classID2 return true, else return false
bool classIDCompare (student st1, student st2)
{	
	if(strcmp(st1.getClassID(), st2.getClassID()) == 1) 
		return true;
	else if (strcmp(st1.getClassID(), st2.getClassID()) == -1) 
		return false;
	return nameCompare(st1,st2); 
}

// function to compare two studentIDs, if studentID 1 > studentID 2 return true, else return false
bool studentIDCompare(student st1, student st2)
{
	if (strcmp(st1.getStudentID(),st2.getStudentID()) == 1) 
		return true;
	return false;
}

// function to compare two names, if name 1 > name 2 return true, else return false
bool fullNameCompare(student st1, student st2)
{
	char *name1 = st1.getName().getFullName();
	char *name2 = st2.getName().getFullName();
	if(strcmp(name1,name2) == 1) return true;
	else if(strcmp(name1,name2) == -1) return false;
	else return dateOfBirthCompare(st1,st2);
}
bool nameCompare(student st1, student st2)
{	
	// get student1's name1
	char *firstName1 = st1.getName().getFirstName();
	char *middleName1 = st1.getName().getMiddleName();
	char *lastName1 = st1.getName().getLastName();
 
 	// get student1's name2
	char *firstName2 = st2.getName().getFirstName();
	char *middleName2 = st2.getName().getMiddleName();
	char *lastName2 = st2.getName().getLastName();

	// compare two firstnames
	if(strcmp(firstName1,firstName2) == 1) return true;
	else if (strcmp(firstName1,firstName2) == -1) return false;

	// if firstname 1 == firstname 2, compare two middlenames
	else
	{
		if(strcmp(middleName1,middleName2) == 1) return true;
		else if(strcmp(middleName1,middleName2) == -1) return false;

		// if middlename 1 == middlename 2, compare two lastnames
		else
		{
			if(strcmp(lastName1,lastName2) == 1) return true;
			else if(strcmp(lastName1,lastName2) == -1) return false;
		}
	}
	return dateOfBirthCompare(st1, st2);
}

// function to compare two dates, return true if date1 > date2, else return false
bool dateOfBirthStringCompare(student st1, student st2)
{
	int day1 = st1.getDateOfBirth().getDay();
	int month1 = st1.getDateOfBirth().getMonth();
	int year1 = st1.getDateOfBirth().getYear();

	int day2 = st2.getDateOfBirth().getDay();
	int month2 = st2.getDateOfBirth().getMonth();
	int year2 = st2.getDateOfBirth().getYear();

	char *date1 = new char[11];
	char *date2 = new char[11];
	char *tmp = new char[5];
	for(int i = 0; i < 11; i++)
		date1[i] = date2[i] = '\0';

	// convert date type to string type
	if(day1 < 10) 
		strcat(date1, "0");
	strcat(date1, itoa(day1,tmp,10));
	strcat(date1, "/");
	if(month1 < 10) 
		strcat(date1, "0");
	strcat(date1, itoa(month1,tmp,10));
	strcat(date1, "/");
	strcat(date1, itoa(year1,tmp,10));

	if(day2 < 10) 
		strcat(date2, "0");
	strcat(date2, itoa(day2,tmp,10));
	strcat(date2, "/");
	if(month2 < 10) 
		strcat(date2, "0");
	strcat(date2, itoa(month2,tmp,10));
	strcat(date2, "/");
	strcat(date2, itoa(year2,tmp,10));

	// compare two date string
	if (strcmp(date1,date2) == 1) return true;
	else if (strcmp(date1,date2) == -1) return false;
	else return studentIDCompare(st1,st2);
}

bool dateOfBirthCompare(student st1, student st2)
{
	// get date1
	int day1 = st1.getDateOfBirth().getDay();
	int month1 = st1.getDateOfBirth().getMonth();
	int year1 = st1.getDateOfBirth().getYear();

	//get date2
	int day2 = st2.getDateOfBirth().getDay();
	int month2 = st2.getDateOfBirth().getMonth();
	int year2 = st2.getDateOfBirth().getYear();

	// compare two year
	if(year1 > year2) return true;
	else if (year1 < year2)return false;

	// if year1 == year2, compare two month
	else
	{
		if(month1 > month2) return true;
		else if (month1 < month2) return false;

		// if month 1 == month2, compare two day.
		else
		{
			if(day1 > day2) return true;
			else if(day1 < day2) return false;
		}
	}
	return studentIDCompare(st1,st2);
}

// function to compare two scores, return true if score1 > score 2, else return false
bool scoreCompare(student st1, student st2)
{
	if (st1.getScore() > st2.getScore()) 
		return true;
	else if (st1.getScore() == st2.getScore())
		return classIDCompare(st1,st2);
	return false;
}