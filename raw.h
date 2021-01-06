// draw function and input password

#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

#define account "admin"                  
#define password "admin"                                                                                                                                                                                                                                                                                                                                             
#define clearScreen "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                "

// ******** COPY **************
// turn off cursor
void noCursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// turn on cursor
void cursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// set text color
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// move the cursor to (x,y)
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {short(x-1),short(y-1)};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}


// **********BY MYSELF ******************
// print string at (x,y)
void printLabel(string buff, int x, int y)
{
	gotoxy(x,y);
	cout << buff;
}

// draw single line from (x1,y1) to (x2,y2)
void singleLine(int x1, int y1, int x2, int y2)
{
	// with horizontal line
 	if (y1 == y2)	
 	{
 		gotoxy(x1,y1);
 		for (int i = x1; i <= x2 ; ++i)
 			cout << (char)196;
 	}

 	// ưith vertical lines
 	if (x1 == x2)	
 		for (int i = y1; i <= y2; ++i)
 		{
 			gotoxy(x1,i);
 			cout << (char)179;
 		}
}

 // draw double line from (x1,y1) to (x2,y2)
void doubleLine(int x1, int y1, int x2, int y2)
{
	// with horizontal line
 	if (y1 == y2)	
 	{
 		gotoxy(x1,y1);
 		for (int i = x1; i <= x2 ; ++i)
 			cout << (char)205;
 	}

 	// ưith vertical lines
 	if (x1 == x2)	
 		for (int i = y1; i <= y2; ++i)
 		{
 			gotoxy(x1,i);
 			cout << (char)186;
 		}
}

// draw table is used to printlist
void tableOfPrintList()
{
	textcolor(9);

	// draw 4 border
	doubleLine(11,3,110,3);
	doubleLine(11,3,11,27);
	doubleLine(11,27,110,27);
	doubleLine(110,3,110,27);

	// draw vertical lines
	singleLine(17,3,17,27);
	singleLine(32,3,32,27);
	singleLine(65,3,65,27);
	singleLine(82,3,82,27);
	singleLine(100,3,100,27);

	// draw horizontal lines
	for (int i = 7; i <= 25; i += 2)
		singleLine(11,i,110,i);

	// complete points in 4 corner
	gotoxy(11,3); cout << (char)201;
	gotoxy(110,3); cout << (char)187;
	gotoxy(11,27); cout << (char)200;
	gotoxy(110,27); cout << (char)188;


	// complete points in border
		// horizontal border
	gotoxy(17,3); cout << (char)209;
	gotoxy(32,3); cout << (char)209;
	gotoxy(65,3); cout << (char)209;
	gotoxy(82,3); cout << (char)209;
	gotoxy(100,3); cout << (char)209;
	gotoxy(17,27); cout << (char)207;
	gotoxy(32,27); cout << (char)207;
	gotoxy(65,27); cout << (char)207;
	gotoxy(82,27); cout << (char)207;
	gotoxy(100,27); cout << (char)207;

		// vertical border
	for (int i = 7; i <= 25; i += 2)
	{
		gotoxy(11,i); cout << (char)199;
		gotoxy(110,i); cout << (char)182;
	}

    // complete intersect points
    for (int i = 7; i <= 25; i += 2)
    {
    	gotoxy(17,i); cout << (char)197;
    	gotoxy(32,i); cout << (char)197;
    	gotoxy(65,i); cout << (char)197;
    	gotoxy(82,i); cout << (char)197;
    	gotoxy(100,i); cout << (char)197;
    }

	// print tittle "STT", "họ tên", "mã sv",.....
	textcolor(6);
	printLabel("STT",13,5);
	printLabel("Student ID",20,5);
	printLabel("Name",47,5);
	printLabel("Class ID",70,5);
	printLabel("Date Of Birth",85,5);
	printLabel("Score",103,5);

	textcolor(7);
	printLabel("Page ",57,28);
	cout <<  endl << endl;
}

// draw table for statistic
void drawHead()
{
	// ve hang ngang
	textcolor(9);
	doubleLine(11,5,109,5);
	singleLine(22,7,102,7);
	singleLine(11,9,109,9);
	// ve hang doc
	doubleLine(11,5,11,9);
	doubleLine(109,5,109,9);
	singleLine(22,5,22,9);singleLine(30,7,30,9);
	singleLine(38,5,38,9);singleLine(46,7,46,9);
	singleLine(54,5,54,9);singleLine(62,7,62,9);
	singleLine(70,5,70,9);singleLine(78,7,78,9);
	singleLine(86,5,86,9);singleLine(94,7,94,9);
	singleLine(102,5,102,9);

	// title
	textcolor(6);
	printLabel("Class ID",13,7);
	printLabel("Xuat Sac",26,6);
	printLabel("Gioi",44,6);
	printLabel("Kha",61,6);
	printLabel("Trung Binh",73,6);
	printLabel("Yeu",93,6);
	printLabel("Tong",104,7);
	printLabel("SL",25,8);
	printLabel("SL",41,8);
	printLabel("SL",57,8);
	printLabel("SL",73,8);
	printLabel("SL",89,8);
	printLabel("%",34,8);
	printLabel("%",50,8);
	printLabel("%",66,8);
	printLabel("%",82,8);
	printLabel("%",98,8);
}
void drawBody(int i)
{
	int y = 11 + i*2;
	textcolor(9);
	// ve hang ngang
	singleLine(11,y,109,y);
	// ve hang doc
	doubleLine(11,y-1,11,y);
	doubleLine(109,y-1,109,y);
	singleLine(22,y-1,22,y);singleLine(30,y-1,30,y);
	singleLine(38,y-1,38,y);singleLine(46,y-1,46,y);
	singleLine(54,y-1,54,y);singleLine(62,y-1,62,y);
	singleLine(70,y-1,70,y);singleLine(78,y-1,78,y);
	singleLine(86,y-1,86,y);singleLine(94,y-1,94,y);
	singleLine(102,y-1,102,y);
}
void drawEnd(int i)
{
	int y = 11 + i*2;
	textcolor(9);
	// ve hang ngang
	doubleLine(11,y,109,y);
	// ve hang doc
	doubleLine(11,y-1,11,y);
	doubleLine(109,y-1,109,y);
	singleLine(22,y-1,22,y);singleLine(30,y-1,30,y);
	singleLine(38,y-1,38,y);singleLine(46,y-1,46,y);
	singleLine(54,y-1,54,y);singleLine(62,y-1,62,y);
	singleLine(70,y-1,70,y);singleLine(78,y-1,78,y);
	singleLine(86,y-1,86,y);singleLine(94,y-1,94,y);
	singleLine(102,y-1,102,y);
	// title
	textcolor(6);
	printLabel("Tong",15,y-1);
}

//draw box form (x1,y1) to (x2,y2)
void box(int x1, int y1, int x2, int y2)
{
	singleLine(x1+1,y1,x2-1,y1);
	singleLine(x1+1,y2,x2-1,y2);
	singleLine(x1,y1+1,x1,y2-1);
	singleLine(x2,y1+1,x2,y2-1);

	gotoxy(x1,y1); cout << (char)218;
	gotoxy(x2,y2); cout << (char)217;
	gotoxy(x2,y1); cout << (char)191;
	gotoxy(x1,y2); cout << (char)192;
}

// draw the add student's screen
void tableOfAddStudent()
{
	textcolor(26);
	box(15,3,105,27);
	textcolor(3);
	printLabel("----ADD STUDENT----",51,5);

	textcolor(7);
	printLabel("Class ID: ",30,8);
	box(60,7,93,9);

	printLabel("Student ID (8 characters): ",30,11);
	box(60,10,93,12);

	printLabel("Name: ",30,14);
	box(60,13,93,15);

	printLabel("Date Of Birth (dd/mm/yyyy): ",30,17);
	box(60,16,93,18);

	printLabel("Score: ",30,20);
	box(60,19,93,21);
}

// cho phep nhap 1 chuoi vao mang, toi da size ki tu
bool enterKey(char buff[], int size)
{
	for (int i = 0; i <= size; ++i)
		buff[i] = '\0';
	char a;
	int index = 0;
	while(true)
	{
		a = getch();

		if(a == 13)
			break;
		else if(a == 27)
			return false;
		else if (a == 8 && index == 0);
		else if(a == 8 && index > 0)
		{
			index--;
			buff[index] = '\0';
			cout << "\b \b";
		}
		else 
		{
			if(index < size)
			{
				buff[index] = a;
				cout << (char)a;
				index++;
			}
			
		}
	}
	return true;
}

// input password at(x,y)
void enterPass(char pass[], int x, int y)
{
	gotoxy(x,y);
	int i = 0;
	char a;

	while(true)
	{
		// if "enter", end 
		a = getch();
		if(a == 13) 
			break;

		// if backspace, delete the end of string
		else if(a == 8 && i >= 1)
		{
			i--;
			printLabel(" ",x + i,y);
			gotoxy(x + i,y);
		}
		else if(a == 8 && i==0);

		// else assign password[i] = char a; 
		else
		{
			pass[i] = a;
			cout << "*";
			i++;
		}
	}
	pass[i] = '\0'; // end
}

// draw big arrow
void next(int x, int y)
{
	textcolor(26);
	gotoxy(x,y);
	for (int i = 0; i < 10; ++i)
		cout << (char)178;
	gotoxy(x+7,y-2); cout << (char)178;
	gotoxy(x+8,y-1); cout << (char)178;
	gotoxy(x+8,y+1); cout << (char)178;
	gotoxy(x+7,y+2); cout << (char)178;
	textcolor(7);
}
void back(int x, int y)
{
	textcolor(26);
	gotoxy(x,y);
	for (int i = 0; i < 10; ++i)
		cout << (char)178;
	gotoxy(x+2,y-2); cout << (char)178;
	gotoxy(x+1,y-1); cout << (char)178;
	gotoxy(x+1,y+1); cout << (char)178;
	gotoxy(x+2,y+2); cout << (char)178;
	textcolor(7);
}