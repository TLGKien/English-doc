#pragma once
#include "list.h"

// select and call to delete student or edit student
void list::delOrEdit(int index)
{
	char a;
	int choose = 1;

	// creat box allow user select delete or edit or exit
	textcolor(16);
	box(30,10,90,20);
	for (int i = 11; i < 20; ++i)
	{
		gotoxy(31,i);
		cout << "                                                           ";
	}
	printLabel("Enter your choose?",40,13);
	while(true)
	{
		if(choose == 1)
			textcolor(64);
		else 
			textcolor(16);
		box(35,16,48,18);
		gotoxy(36,17); cout << "   DELETE   ";

		if(choose == 2)
			textcolor(64);
		else 
			textcolor(16);
		box(53,16,66,18);	
		gotoxy(54,17); cout << "    EDIT    ";

		if(choose == 3)
			textcolor(64);
		else 
			textcolor(16);
		box(71,16,84,18);	
		gotoxy(72,17); cout << "    EXIT    ";

		// allow input only arrow key and "enter" key
		while(true)
		{
			a = getch();
			if(a == -32 || a == 13)
				break;
		}

		// if input arrow key, -> move button selected
		if(a == -32)
		{
			a = getch();
			if(a == 75 && choose > 1)
				choose --;
			if(a == 77 && choose < 3)
				choose ++;
		}
		// if input enter key, -> break and call to function delete or edit or return printList
		else
			break;
	}
	if(choose == 1)
		deleteStudent(index);
	else if(choose == 2)
		editProfile(index);
	else 
		return;
}

// function to print all student of list
int list::printList(bool check, int &index)
{
	char a;
	int page = 1;
	index = 0;
	// print 1 page = 10 student

	while(true)
	{
		int count = studentList.size();
		// draw table
		textcolor(7); gotoxy(1,3); cout << clearScreen;
		tableOfPrintList();	

		// print student - output data of students to table
		for (int i = (page-1)*10; i < count && i < page*10; ++i)	
		{
			if(i == index)
				studentList[i].display(i,true);
			else
				studentList[i].display(i,false);
		}
		

		// print next page or previous page 			//eg: draw "<- Trang 2/3 ->"
		gotoxy(62,28); cout << page << "/" << ceil((float)count/10);	
		if (page < ceil((float)count/10)) cout << " ->";
		if (page != 1) 
			printLabel("<-",54,28);


		// print List without search function
		if(check == false)
		{
			cout << endl << "Press esc to back main menu..."; 
			while(true)	
			{	
				a = getch();
				// esc to exit
				if (a == 27) 
					return a;
				// enter to select delete student or edit profile
				else if (a == 13)
				{
					delOrEdit(index);
					break;
				}
				// if press "<-", return to the previous page 
				else if ((a == 75) && page > 1) 
				{
					page--;
					index = (page-1)*10;
					break;
				}
				// press up arrow key to select student above
				else if (a == 72)
				{
					if(index == 0) 
						continue;
					else if (index == (page-1)*10)
					{
						page--;
						index--;
						break;
					}
					else
					{
						studentList[index].display(index,false);
						index--;
						studentList[index].display(index,true);
					}
				}
				// if press "->", go to the next page
				else if ((a == 77) && page < ceil((float)count/10)) 
				{
					page++;
					index = (page-1)*10;
					break;
				}
				// down arrow key to select student below
				else if (a == 80)
				{
					if(index == count-1) 
						continue;
					else if (index == page*10-1)
					{
						page++;
						index++;
						break;
					}
					else
					{
						studentList[index].display(index,false);
						index++;
						studentList[index].display(index,true);
					}
				}
			}
		}

		// print List with search function
		else
		{	
			noCursorType();
			printLabel("Press esc to back main menu...",1,29);
			gotoxy(38,2);
			while(true)
			{
				a = getch();
				// if press arrow key, check what is it?
				if (a == -32)
				{
					a = getch();
					// "<-" page previous
					if ((a == 75) && page > 1)
					{
						page--;
						index = (page-1)*10;
						break;
					}	
					// up key, student above
					else if (a == 72)
					{
						if(index == 0) 
							continue;
						else if (index == (page-1)*10)
						{
							index--;
							page--;
							break;
						}
						else
						{
							studentList[index].display(index,false);
							index--;
							studentList[index].display(index,true);
						}
					}
					// "->" page next
					else if ((a == 77) && page < ceil((float)count/10))
					{
						page++;
						index = (page-1)*10;
						break;
					}
					// down key, student below
					else if (a == 80)
					{
						if(index == count-1) 
							continue;
						else if (index == page*10-1)
						{
							index++;
							page++;
							break;
						}
						else
						{
							studentList[index].display(index,false);
							index++;
							studentList[index].display(index,true);
						}
					}
				}
				// another key, return its;
				else if (a == 27 || a == 8 || a == ' ' || a == 13) return a;
				else if (a >= 46 && a <= 57) return a;
				else if (a >= 65 && a <= 90) return a;
				else if (a >= 97 && a <= 122) return a;
			}
		}
	}
	return a;
}