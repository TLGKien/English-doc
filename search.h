#pragma once
#include "list.h"

vector<student> sequentialSearch(vector<student>, char[], int, int);		// search algorithm
vector<student> binarySearch(vector<student>, char[], int, int, int, int);	

vector<student> searchInList(list, char[], int, int);			// call to search algorithms
int inBuff(char[], char[], int);								// check buff1 in buff2???
int inDate(char[], date, int);									// check buff1 in date Of Birth???
int inScore(char[], float, int);								// check buff1 in score???
int in(char[],student, int, int);								// check buff1 in student[i]?????

// function to call to search algorithms
void list::search(int choose1, int choose2)
{
	int i = 0;
	char searchKey[41];
	char a;
	int index = 0;

	// list to save result of search()
	list searchList = *this;

	while(true)
	{	
		list tmpList = *this;

		// before search, if selected binary search, we need sort list by key
		if (choose1 == 2)
		{
			switch(choose2)
			{
				case 1:
					tmpList.sort(3,1);
					break;
				case 2:
					tmpList.sort(3,2);
					break;
				case 3:
					tmpList.sort(3,6);
					break;
				case 4:
					tmpList.sort(3,7);
					break;
				case 5:
					tmpList.sort(3,5);
					break;
			}
		}

		while(true)
		{	
			if(a == 13)
				searchList.studentList = searchInList(tmpList, searchKey, choose1, choose2);
			gotoxy(1,3); cout << clearScreen;
			gotoxy(38+i,2);

			// if searchKey == '\0' print all list, else print result of search
			// argument "true" allow input char from keyboard
			if (i == 0)
				a = this->printList(true,index);
			else
				a = searchList.printList(true,index);

			// press "esc" -> exit function
			if(a == 27) break;

			// press "backspace", delete a last char in search Key, then search from (*this)
			else if(a == 8 && i >= 1) 
			{
				i--;
				searchKey[i] = '\0';
				printLabel("                                         ",38,2);
				printLabel(searchKey,38,2);
				searchList.studentList = searchInList(tmpList, searchKey, choose1, choose2);		
			}
			else if(a == 8 && i==0);

			// allow input maximum 40 characters
			else if(i >= 40) continue;

			// press "enter", -> choose delete or edit student, then search from original list
			else if(a == 13) 
			{	////////////////////////////////////can xoa them ở tmp list và search list////////////////////////////////
				for (int i = 0; i < (int)studentList.size(); ++i)
					if(in(searchList.studentList[index].getStudentID(),studentList[i],1,2))
					{
						delOrEdit(i);
						break;
					}		
				break;
			}

			// othor key, input it to searchkey, and search from search List
			else
			{
				searchKey[i] = a;
				i++;
				searchKey[i] = '\0';
				printLabel(searchKey,38,2);
				if(strlen(searchKey) == 1)
					searchList.studentList = searchInList(tmpList,searchKey,choose1,choose2);
				else
					searchList.studentList = searchInList(searchList, searchKey, choose1, choose2);		
			}
		}
		if(a == 27) break;
	}
}

// sequential Search algorithm 
vector<student> sequentialSearch(vector<student> arr, char searchKey[], int choose1, int choose2)
{
	vector<student> tmp;
	for (int i = 0; i < (int)arr.size(); ++i)
		if(in(searchKey,arr[i],choose1,choose2))
			tmp.push_back(arr[i]);
	return tmp;
}

// binary search algorithm 
vector<student> binarySearch(vector<student> arr, char searchKey[], int choose1, int choose2, int l, int r)
{
	vector<student> tmp;
	while(l <= r)
	{
		int m = (l+r) / 2;

		// if mid is student looking for
		if (in(searchKey,arr[m],choose1,choose2) == 0)
		{ 
			l = r = m;
			// search to previous until it isn't student looking for
			while(true)
			{
				if((l-1) >= 0)
				{
					if(in(searchKey,arr[l-1],choose1,choose2) == 0)
						l--;
					else break;
				}
				else break;
			}
			// search to sequent until it isn't student looking for
			while(true)
			{
				if((r+1) <= int(arr.size()-1))
				{
					if(in(searchKey,arr[r+1],choose1,choose2) == 0)
						r++;
					else break;
				}
				else break;
			}
			// add them to temp list and return to search list
			for (int i = l; i <= r; ++i)
				tmp.push_back(arr[i]);
			break;
		}
		// if search key < "mid" student, search to previous
		else if(in(searchKey,arr[m], choose1,choose2) == -1)
			r = m-1;
		// if search key > "mid" student, search to next
		else 
			l = m+1;
	}
	return tmp;
}

// function to call to search algorithms
vector<student> searchInList(list aList, char searchKey[], int choose1, int choose2)
{
	// call to sequential search algorithm
	if (choose1 == 1)
	{
		vector<student> arr = *aList.getList();
		return sequentialSearch(arr,searchKey, choose1, choose2);
	}

	// call to binary search algorithm
	else
	{
		vector<student> arr = *aList.getList();
		return binarySearch(arr,searchKey, choose1,choose2,0,arr.size()-1);
	}
}

// check buff 1 in buff 2????
int inBuff(char buff1[], char buff2[], int choose1)
{	
	strlwr(buff1);
	strlwr(buff2);

	// with sequential algorithm, (buff1 in buff2) return 1, else return 0
	if(choose1 == 1)
		return (strstr(buff2,buff1) != NULL);

	// with binary algorithm, if (buff1 in buff2), return 0, 
	//if (buff1 < buff2), return -1, if (buff1 > buff2), return 1
	else 
	{
		if(strstr(buff2,buff1) != NULL)
			return strcmp(strstr(buff2,buff1),buff2);
		else 
			return strcmp(buff1,buff2);
	}
}

// check buff in date???
int inDate(char buff[], date date, int choose1)
{
	// convert date to char[] by 2 form (eg. 2/2/1999 or 02/02/1999)
	char *buff2 = new char[11];
	char *buff3 = new char[11];
	char *tmp = new char[5];

	for (int i = 0; i < 11; ++i)
		buff2[i] = buff3[i] = '\0';

	int day = date.getDay();
	int month = date.getMonth();
	int year = date.getYear();

	// form 02/02/1999
	if(day < 10) 
		strcat(buff2, "0");
	strcat(buff2, itoa(day,tmp,10));
	strcat(buff2, "/");
	if(month < 10) 
		strcat(buff2, "0");
	strcat(buff2, itoa(month,tmp,10));
	strcat(buff2, "/");
	strcat(buff2, itoa(year,tmp,10));

	// form 2/2/1999
	strcat(buff3, itoa(day,tmp,10));
	strcat(buff3, "/");
	strcat(buff3, itoa(month,tmp,10));
	strcat(buff3, "/");
	strcat(buff3, itoa(year,tmp,10));

	// with sequential algorithm, if (buff in date1 || in date2), return 1, else return  0
	if(choose1 == 1)
	{
		bool check = 1;
		if (inBuff(buff, buff2, choose1) == 0 && inBuff(buff, buff3, choose1) == 0)
			check = 0;
		return check;					
	}
	// with binary algorithm, have only form 02/02/1999
	else return inBuff(buff,buff2,choose1);
}

// check buff in score
int inScore(char buff[], float score, int choose1)
{
	char *buff2 = new char[8];
	// convert score float to string
	if(score != 0)
	{
		// score * 100000, then convert to string
		buff2 = itoa(int(score*100000),buff2,10);

		int length = strlen(buff2);
		// add '.' to string
		for (int i = length; i > length - 5; --i)
			buff2[i] = buff2[i-1];
		buff2[length - 5] = '.';
		buff2[++length] = '\0';

		// delete '0' at last
		while(buff2[length-1] == '0')
			buff2[--length] = '\0';
		// add '0' at first if first is '.'
		if(buff2[0] == '.')
		{
			for (int i = length; i > 0; --i)
				buff2[i] = buff2[i-1];
			buff2[++length] = '\0';
			buff2[0] = '0';
		}
	}
	else buff2 = (char*)"0";

	// return buff in buff2?
	return inBuff(buff, buff2, choose1);
}

// buff in student?
int in(char buff[], student st, int choose1, int choose2)
{
	switch(choose2)
	{
		// check search key in class ID
		case 1:		
			return inBuff(buff,st.getClassID(), choose1);

		// check search key in student id
		case 2:		
			return inBuff(buff,st.getStudentID(), choose1);

		// check search key full name
		case 3:	
			return inBuff(buff,st.getName().getFullName(), choose1);

		// check search key in birth day
		case 4:		
			return inDate(buff,st.getDateOfBirth(), choose1);

		// check search key in score
		case 5: 		
			return inScore(buff,st.getScore(), choose1);
	}
	return 1;
}