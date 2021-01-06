#pragma once
#include "date.h"
#include "nameType.h"
#include "raw.h"

// definition of class "sinh vien"
class student 		
{
	private:
		char classID[10], studentID[9];
		nameType name;
		date dateOfBirth;
		float score;
	public:
		student();
		student(char[], char[], nameType, date, float);

		void setClassID(char[]);
		void setStudentID(char[]);
		void setName(nameType);
		void setDateOfBirth(date);
		void setScore(float);

		char* getClassID();
		char* getStudentID();
		nameType getName();
		date getDateOfBirth();
		float getScore();

		void display(int, bool);
};

student::student(){}
student::student(char classID[], char studentID[], nameType name, date dateOfBirth, float score)
{
	for (int i = 0; i < 10; ++i)
	{
		this->classID[i] = classID[i];
		this->studentID[i] = studentID[i];
	}
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->score = score;
}

void student::setClassID(char classID[])
{
	for (int i = 0; i < 10; ++i)
		this->classID[i] = classID[i];
}
void student::setStudentID(char studentID[])
{
	for (int i = 0; i < 10; ++i)
		this->studentID[i] = studentID[i];
}
void student::setName(nameType name)
{
	this->name = name;
}
void student::setDateOfBirth(date dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}
void student::setScore(float score)
{
	this->score = score;
}

// getter function
char* student::getClassID()
{
	return classID;
}
char* student::getStudentID()
{
	return studentID;
}
nameType student::getName()
{
	return name;
}
date student::getDateOfBirth()
{
	return dateOfBirth;
}
float student::getScore()
{
	return score;
}

// function to display information of student
void student::display(int i, bool check)
{
	// Selected student is highlighted
	if (check == true)
		textcolor(4);
	else
		textcolor(7);

	// y la toa do duoc hien thi ung voi so thu tu i+1
	int y = 8+(i%10)*2;	
	gotoxy(13,y); cout << i+1;
	printLabel(studentID,21,y);
	gotoxy(34,y); cout << name.getLastName() << " " << name.getMiddleName();
	printLabel(name.getFirstName(),56,y);
	printLabel(classID,71,y);
	gotoxy(86,y); dateOfBirth.display();
	gotoxy(104,y); cout << score;
	textcolor(7);
}