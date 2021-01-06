#include <math.h>
#include <string.h>
#pragma once
#include "list.h"

float convertToFloat(char tmp[])
{
	char tmp1[4];
	// lấy phần số trong tmp, chuyển sang int rồi chia cho 10^x
	int index = 4;
	for (int i = 0; i < 4; ++i)
		if(tmp[i] == '.') 
			index = i;
	for (int i = 0; i < index; ++i)
		tmp1[i] = tmp[i];
	for (int i = index+1; i < 4; ++i)
		tmp1[i-1] = tmp[i];
	int result = atoi(tmp1);
	if(index == 4) 
		return result;
	else
		return float(result/(pow(10,strlen(tmp)-1-index)));
}

// function to check classID is true/ false
bool list::checkClassID(char classID[])
{
	strupr(classID);
	if (strcmp(classID,CNTT1) == 0 || strcmp(classID,CNTT2) == 0 
		|| strcmp(classID,BDATTT) == 0 || strcmp(classID,ANHTTT) == 0 || strcmp(classID,DTH) == 0) 
		return true;
	return false;
}

// check student ID
bool list::checkStudentID(char studentID[])
{
	if(strlen(studentID) == 8) 
	{
		strupr(studentID);
		for (int i = 0; i < (int)studentList.size(); ++i)
			if(strcmp(studentID,studentList[i].getStudentID()) == 0)
				return false;
		return true;
	}
	return false;
}

// function to verify "do you want add student to list?"
bool list::verify(student tmp)
{
	char a;
	system("cls");
	next(6,11);
	back(106,11);
	
	textcolor(3);
	printLabel("----ADD STUDENT----",51,2);
	//////////////////////////////
	textcolor(7);
	printLabel("Verify:",30,5);
	printLabel("Student:           ",50,5); cout << tmp.getName().getFullName();
	printLabel("Date Of Birth:     ",50,8); tmp.getDateOfBirth().display();
	printLabel("Student ID:        ",50,11); cout << tmp.getStudentID();
	printLabel("Class ID:          ",50,14); cout << tmp.getClassID();
	printLabel("Score:             ",50,17); cout << tmp.getScore();
	printLabel("Continue? (y/n) >> ",30,20);
	while(true)
	{
		a = getch();
		if (a == 'y' || a == 'n') break;
	}
	cout << a;
	if (a == 'n') return false;
	else return true;
}

// Function to create a student object and add the list
void list::addStudent()	
{
	char a;
	char *classID, *studentID, *nametmp, *datetmp, *pass, *scoretmp;
	date dateOfBirth;
	nameType name;
	float score;

	// input student's data
	while(true)
	{
		cursorType();	// turn on cursor
		system("cls");
		cout << studentList.size();

		// draw addstudent's screen
		tableOfAddStudent();

		// input class ID until it's true
		classID = new char[10];
		while(true)
		{
			fflush(stdin);
			gotoxy(62,8);
			if (enterKey(classID,8))
			{
				if(checkClassID(classID)) 
				{
					printLabel(classID,62,8);
					break;
				}	
				else		// if classID is false, notify it's false
				{	
					textcolor(4);
					printLabel("Class ID is among: CNTT1, CNTT2, BDATTT, ANHTTT, DTH",35,24);
					textcolor(7);
					printLabel("                              ",62,8);				
				}
			}
			else return;

		}
		printLabel("                                                    ",35,24);
		
		// input studentID until it's true
		studentID = new char[10];
		while(true)
		{
			gotoxy(62,11);
			if(enterKey(studentID,8))
			{
				if(checkStudentID(studentID)) 
				{
					printLabel(studentID,62,11);
					break;
				}
				else	// if false, notify
				{
					textcolor(4); 
					printLabel("Student ID has 8 characters. It's unique!",40,24);
		
					textcolor(7); 
					printLabel("                              ",62,11);
				}
			}
			else return;
		} 
		printLabel("                                         ",40,24);		

		// input name, and auto format
		nametmp = new char[31];
		while(true)
		{
			gotoxy(62,14);
			if(enterKey(nametmp,30))
			{
				if(name.convertToName(nametmp))
				{
					printLabel("                               ",62,14);
					gotoxy(62,14); cout << name.getFullName();
					break;
				}
				else	// if name has character special, notify and reenter
				{
					textcolor(4); 
					printLabel("Name doesn't have special characters!",47,24);
					textcolor(7); 
					printLabel("                               ",62,14);
				}
			}
			else return;
			
		}		
		printLabel("                                      ",47,24);

		// input date of birth until it's true
		datetmp = new char[11];
		while(true)
		{
			gotoxy(62,17);
			if(enterKey(datetmp,10))
			{
				if(dateOfBirth.convertToDate(datetmp)) break;
				else 
				{
					textcolor(4); 
					printLabel("Date Of Birth has form dd/mm/yyyy",44,24);
					textcolor(7);
					printLabel("                              ",62,17);
				}	
			}
			else return;
		}
		printLabel("                                 ",44,24);		
		
		// input score until it's true
		scoretmp = new char[5];
		while(true)
		{
			gotoxy(62,20);
			if(enterKey(scoretmp,4))
			{
				// nếu không thì xét, 
				int dem = 0;
				bool acheck = true;
				for(int i = 0; i < (int)strlen(scoretmp); i++)
				{
					if((scoretmp[i] < '0' || scoretmp[i] > '9') && scoretmp[i] != '.')
						acheck = false;
					if(scoretmp[i] == '.')
						dem++;
				}
				// nếu đúng đinh dạng thì chuyển scoretmp sang score float
				if(acheck == true && dem < 2)
				{
					score = convertToFloat(scoretmp);
				}
				// nếu có kí tự đặc biệt, hoặc có nhiều hơn 1 dấu chấm thì bắt nhập lại
				else
				{
					textcolor(4);
					printLabel("Score doesn't have special characters!",41,24);
					textcolor(7);
					printLabel("                              ",62,20);
					continue;
				}
				if(score >= 0 && score <= 4) break;   
				else
				{												  	
					textcolor(4); 								  	
					printLabel("    Score is float between 0 and 4    ",41,24);
					textcolor(7); 
					printLabel("                              ",62,20);
				}
			}
			else return;
		}		
		printLabel("                                        ",41,24);

		// create a student object
		student student(classID,studentID,name,dateOfBirth,score);	

		// verify and if say "yes", program push_back to list, else cancel
		if(verify(student))
		{
			pass = new char[30];
			printLabel("Enter you password: ",30,22);
			while(true)
			{
				enterPass(pass,50,22);
				if (strcmp(pass,password) == 0)
				{
					printLabel("               ",40,24);
					break;
				}
				else if(strcmp(pass,"cancel") == 0)
				{
					printLabel("               ",40,24);
					break;
				}
				else
				{
					printLabel("                              ",50,22);
					textcolor(4);
					printLabel("password wrong!",40,24);
					textcolor(7);
				}
			}
			if(strcmp(pass,password) == 0)
			{
				studentList.push_back(student);		// add to list
				outputToFile(); // update to fife
				textcolor(12); 
				printLabel("----SUCCESSFUL----",54,24);
				cout << endl << endl; 
				textcolor(7);	// notify "add student" is done
			}
			else 
			{
				textcolor(12); 
				printLabel("----CANCELED----",54,24);
				cout << endl << endl; 
				textcolor(7);	// notify "add student" is done
			}
			
		}
		else
		{
			textcolor(12); 
			printLabel("----CANCELED----",54,24);
			cout << endl << endl; 
			textcolor(7);	// notify "add student" is done
		}
		noCursorType();			// turrn of cursor

		// exit or continue?
		cout << "Press esc to back main menu, enter to add student anothor...";
		while (true)	// if press enter, out function
		{
			a = getch();
			if (a == 13 || a == 27) break;
		}
		if(a == 27) break;	// if press esc, exit program 
	}
}