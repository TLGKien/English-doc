#pragma once
#include <math.h>
#include "addStudent.h"
#include "editProfile.h"
#include "deleteStudent.h"
#include "printList.h"
#include "sort.h"
#include "search.h"
#include "statistic.h"
#include "raw.h"

using namespace std;

class menu
{
	private:
		// variable is used to choose
		int choose1, choose2;
		char a;	
	public:
		// the menu is displayed
		void mainMenu(list *list);
		void addStudent(list*);
		void printList(list);
		void sort(list*);
		void search(list);
		void statistic(list);
};


// draw main menu screen-------------------------------------------------------------------------
void menu::mainMenu(list *list)
{
	textcolor(7);
	choose1 = 1;	// choose "Them Ho So" is default 
	system("cls");	// clear the screen
	while(true)
	{
		//draw the menu's screen
		textcolor(26);
		box(40,4,80,26);
		textcolor(3);
		printLabel("----MENU----",55,6);

		// The selected item is in bold		// else is normal
		if(choose1 == 1) textcolor(31);						
		else textcolor(6);									
		printLabel("      Add Student     ",50,10);		
		if(choose1 == 2) textcolor(31);
		else textcolor(6);
		printLabel("       Print List     ",50,12);
		if(choose1 == 3) textcolor(31);
		else textcolor(6);
		printLabel("       Sort List      ",50,14);
		if(choose1 == 4) textcolor(31);
		else textcolor(6);
		printLabel("    Search Student    ",50,16);
		if(choose1 == 5) textcolor(31);
		else textcolor(6);
		printLabel("       Statistic      ",50,18);
		if(choose1 == 6) textcolor(31);
		else textcolor(6);
		printLabel("         Exit         ",50,20);
		textcolor(7);
		printLabel("-----------------------------",46,23);
		printLabel("Copyright 2019 @ TLG_Kien",48,24);

		// enter the key to control
		a = getch();				  					
		if (a == 13) break;								// if key = "enter" -> item is selected and continue
		else if (a == 72 && choose1 > 1) choose1--;		// up	
		else if (a == 80 && choose1 < 6) choose1++;		// down
	}

	// the selected item is corresponding to a choose1's value (corresponding = (adj) "tuong ung")
	// and it call to the function corresponding.
	switch (choose1)	
	{					
		case 1:
			addStudent(list);		
			break;
		case 2:
			printList(*list);
			break;
		case 3:
			sort(list);
			break;
		case 4:
			search(*list);
			break;
		case 5:
			statistic(*list);
			break;
		case 6:
			textcolor(4);
			printLabel("See you again...",53,28);
			textcolor(7);
			exit(0);
	}
}

//Function to add students----------------------------------------------------------------------------
void menu::addStudent(list *list)
{
	system("cls");
	list->addStudent();	// call to "addStudent" function
	mainMenu(list);	// then back to the main menu
}

//function to show student list ---------------------------------------------------------------
void menu::printList(list list)
{
	int index = 0;
	system("cls");
	textcolor(3);
	printLabel("----PRINT LIST----",51,2);
	list.printList(false,index);	// call to "printList" Function
	mainMenu(&list);	// then back to the main menu
}

// function to draw sort menu, choose and sort the list ---------------------------------------
void menu::sort(list *list)
{
	choose1 = 1;
	system("cls");
	while(true)
	{
		textcolor(3);
		printLabel("----SORT LIST----",52,5);

		textcolor(3);
		printLabel("SELECT ALGORITHM",23,7);
		if(choose1 == 1) textcolor(31);
		else textcolor(6);
		printLabel("    Selection Sort    ",20,11);
		if(choose1 == 2) textcolor(31);
		else textcolor(6);
		printLabel("    Insertion Sort    ",20,13);
		if(choose1 == 3) textcolor(31);
		else textcolor(6);
		printLabel("       QuickSort      ",20,15);
		if(choose1 == 4) textcolor(31);
		else textcolor(6);
		printLabel("      Merge Sort      ",20,17);

		a = getch();
		if (a == 13) break;
		else if (a == 72 && choose1 > 1) choose1--;
		else if (a == 80 && choose1 < 4) choose1++;
	}
	
	next(55,13);
	choose2 = 1;
	while(true)
	{
		textcolor(3);
		printLabel("SELECT KEY",86,7);

		if(choose2 == 1) textcolor(31);
		else textcolor(6);
		printLabel("       Class ID       ",80,11);
		if(choose2 == 2) textcolor(31);
		else textcolor(6);
		printLabel("      Student ID      ",80,13);
		if(choose2 == 3) textcolor(31);
		else textcolor(6);
		printLabel("         Name         ",80,15);
		if(choose2 == 4) textcolor(31);
		else textcolor(6);
		printLabel("     Date Of Birth    ",80,17);
		if(choose2 == 5) textcolor(31);
		else textcolor(6);
		printLabel("         Score        ",80,19);
		if(choose2 == 6) textcolor(31);
		else textcolor(6);
		printLabel("         Exit         ",80,21);

		a = getch();
		if (a == 13) break;
		else if (a == 72 && choose2 > 1) choose2--;
		else if (a == 80 && choose2 < 6) choose2++;
	}
	
	if(choose2 == 6)
	{
		textcolor(7);
		mainMenu(list);
	}
	else
	{
		int index = 0;
		list->sort(choose1,choose2);
		textcolor(12); 
		printLabel("----SUCCESSFUL----",54,24);
		cout << endl << endl; 
		textcolor(7);
		cout << "Press any key to print list after sort..." << endl;
		a = getch();
		textcolor(3);
		printLabel("----LIST AFTER SORT----",49,2);
		list->printList(false,index);
		mainMenu(list);
	}	
}

// function to draw search menu, choose and search the list ---------------------------------------
void menu::search(list list)
{
	choose1 = 1;
	system("cls");
	while(true)
	{
		textcolor(3);
		printLabel("----SEARCH STUDENT----",50,5);

		textcolor(3);
		printLabel("SELECT ALGORITHM",23,7);
		if(choose1 == 1) textcolor(31);
		else textcolor(6);
		printLabel("   Sequential Search   ",20,11);
		if(choose1 == 2) textcolor(31);
		else textcolor(6);
		printLabel("     Binary Search    ",20,13);
		a = getch();
		if (a == 13) break;
		else if (a == 72 && choose1 > 1) choose1--;
		else if (a == 80 && choose1 < 2) choose1++;
	}

	next(55,13);
	choose2 = 1;
	while(true)
	{
		textcolor(3);
		printLabel("SELECT KEY",86,7);

		if(choose2 == 1) textcolor(31);
		else textcolor(6);
		printLabel("       Class ID       ",80,11);
		if(choose2 == 2) textcolor(31);
		else textcolor(6);
		printLabel("      Student ID      ",80,13);
		if(choose2 == 3) textcolor(31);
		else textcolor(6);
		printLabel("         Name         ",80,15);
		if(choose2 == 4) textcolor(31);
		else textcolor(6);
		printLabel("     Date Of Birth    ",80,17);
		if(choose2 == 5) textcolor(31);
		else textcolor(6);
		printLabel("         Score        ",80,19);
		if(choose2 == 6) textcolor(31);
		else textcolor(6);
		printLabel("         Exit         ",80,21);

		a = getch();
		if (a == 13) break;
		else if (a == 72 && choose2 > 1) choose2--;
		else if (a == 80 && choose2 < 6) choose2++;
	}

	if(choose2 == 6)
	{
		textcolor(7);
		mainMenu(&list);
	}
	else
	{
		system("cls");
		printLabel("SEARCH >> ",20,1); 
		switch (choose1)
		{
			case 1:
				cout << "Sequential Search >> ";
				break;
			case 2:
				cout << "Binary Search >> ";
				break;
		}
		switch (choose2)
		{
			case 1:
				cout << "Class ID >> ";
				break;
			case 2:
				cout << "Student ID >> "; 
				break;
			case 3:
				cout << "Name >> ";
				break;
			case 4:
				cout << "Date Of Birth >> ";
				break;
			case 5:
				cout << "Score >> ";
				break;
		}
		printLabel("Enter search key: ",20,2);
		list.search(choose1,choose2);
		mainMenu(&list);
	}		
}

// function to draw statistic menu, choose and statistic student list ---------------------------------------
void menu::statistic(list list)
{
	list.statistic();
	mainMenu(&list);
}