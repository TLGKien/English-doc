#include <time.h>
#include <ctype.h>
#include "list.h"
#include "menu.h"

// Account = Password = "admin" 

// Function to allow user log in  to the system
bool signIn()
{
	textcolor(7);
	system("cls");
	textcolor(96);
	box(29,4,91,22);

	char acc[30], pass[30];

	// draw the login's screen
	textcolor(9);
	printLabel("LOG IN TO SEE MORE",52,7); 
	textcolor(7);
	printLabel("Account*:",40,11); 
	printLabel("Password*: ",40,15); 

	textcolor(112);
	printLabel("                             ",51,10);
	printLabel("                             ",51,11);
	printLabel("                             ",51,12);
	printLabel("                             ",51,14);
	printLabel("                             ",51,15);
	printLabel("                             ",51,16);


	// enter account and password

	gotoxy(52,11); cin >> acc;								
	enterPass(pass,52,15);		

	// if account, password entered are equal account, password of system, return true
	if (strcmp(acc,account) == 0 && strcmp(pass,password) == 0)	
		return true;
	return false;
}

int main()
{	
	// sign in until acc and pass are correct
	while(!signIn())	
	{
		textcolor(7);
		system("cls");
		textcolor(4);
		printLabel("Account and passwork are incorrect!",43,19);
	}

	// create list students, menu and display main menu
	list list;	
	list.inputFromFile();
	menu menu;	
	noCursorType(); // Turn of cursor
	menu.mainMenu(&list);

	return 0;
}