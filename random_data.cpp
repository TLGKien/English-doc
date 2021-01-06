#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "student.h"
#include "list.h"
#include "date.h"
#include "nameType.h"

using namespace std;

const char* firstName[] = {"Thuy","Kien","Hung","Linh","Tuan","Anh","Dai","Quynh","Khanh","Nga",
						"Thang","Ta","Tu","An","Duc","Nhu","Lien","Phuc","Hai","Dat",
						"Phieu","Duy","Dung","Tien","Duat","Dien","Dai","Anh","Hoang","Nam",
						"Micheal","John","Edward","Jane","Bella","Charlie","Jacob","James","Messi","Emilly"};
const char* middleName[] = {"Van","Ngoc","Duy","Viet","Thi Kim","Van","Dinh","Thi","Thanh","Quoc",
							"Van","Hoc","Tuan","Manh","Pham Trung","Thi Thanh","Quang","Thuy","Viet","Trung"};
const char* lastName[] = {"Huynh","Nguyen","Nguyen","Pham","Ho","Duong","Nong","Trinh","Cullen","Mayer",
						"Phan","Quach","Ha","Ma","Le","Dau","Ngo","Tran","Nguyen","Eyer"};
const char* className[] = {"CNTT1","CNTT2","BDATTT","ANHTTT","DTH"};

int main()
{
	list aList;
	srand(time(NULL));

	int TL;
	char *classID, *studentID, *nametmp, *datetmp, *tmp;
	date dateOfBirth;
	nameType name;
	int a,n;
	float score;
	cout << "enter number of students: "; cin >> n;
	
	for (int i = 0; i < n; ++i)
	{	
		// random for class ID
		a = rand()%5;
		classID = new char[10];
		classID[0] = '\0';
		strcat(classID,className[a]);

		tmp = new char[6];
		tmp[0] = '\0';
		studentID = new char[10];
		studentID[0] = '\0';
		strcpy(studentID,classID);
		studentID[3] = '\0';
		itoa(i+1,tmp,10);
		strrev(tmp);
		for (int i = strlen(tmp); i < 5; ++i)
			tmp[i] = '0';
		tmp[5] = '\0';
		strrev(tmp);
		strcat(studentID,tmp);


		// random for name
		while(true)
		{
			nametmp = new char[30];
			nametmp[0] = '\0';
			// last Name
			a = rand()%20;
			strcat(nametmp,lastName[a]);
			nametmp[strlen(nametmp)+1] = '\0';
			nametmp[strlen(nametmp)] = ' ';
			// middle name
			a = rand()%20;
			strcat(nametmp,middleName[a]);
			nametmp[strlen(nametmp)+1] = '\0';
			nametmp[strlen(nametmp)] = ' ';
			// first name
			a = rand()%40;
			strcat(nametmp,firstName[a]);
			// convert from name char[] to nameType.h
			if(name.convertToName(nametmp))
				break;
		}
		
		
		// random for date of birth
		while(true)
		{
			datetmp = new char[10];
			datetmp[0] = '\0';
			// day
			a = rand()%31+1;
			if(a < 10)
			{
				datetmp[strlen(datetmp)+1] = '\0';
				datetmp[strlen(datetmp)] = '0';
			}
			strcat(datetmp,itoa(a,tmp,10));
			datetmp[strlen(datetmp)+1] = '\0';
			datetmp[strlen(datetmp)] = '/';
			// month
			a = rand()%12+1;
			if(a < 10)
			{
				datetmp[strlen(datetmp)+1] = '\0';
				datetmp[strlen(datetmp)] = '0';
			}
			strcat(datetmp,itoa(a,tmp,10));
			datetmp[strlen(datetmp)+1] = '\0';
			datetmp[strlen(datetmp)] = '/';
			// year
			a = rand()%5+1996;
			strcat(datetmp,itoa(a,tmp,10));
			// convert from date char[] to date.h
			if(dateOfBirth.convertToDate(datetmp))
				break;
		}
		
		TL = rand()%100;
		if(TL <= 4)	// ti le ra xuat sac = 5%
			score = float(360 + rand()%41)/100;
		else if(TL > 4 && TL <= 19)	// ti le ra gioi = 15%
			score = float(320 + rand()%40)/100;
		else if(TL > 19 && TL <= 69)	// ti le ra kha = 50%
			score = float(250 + rand()%70)/100;
		else if(TL > 69 && TL <= 94)	// ti le ra trung binh = 25%
			score = float(200 + rand()%50)/100;
		else if(TL > 94)	// ti le ra yeu = 5%
			score = float(rand()%200)/100;
	
		student student(classID,studentID,name,dateOfBirth,score);
		aList.getList()->push_back(student);		
	}
	aList.outputToFile();

}	