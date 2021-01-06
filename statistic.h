#pragma once
#include <iostream>
#include "list.h"
#include "raw.h"
#include "numberOfClass.h"
#include "search.h"

void list::statistic()
{
	numberOfClass *numbers = new numberOfClass[5];
	numbers[0].setClassID(ANHTTT);
	numbers[1].setClassID(BDATTT);
	numbers[2].setClassID(CNTT1);
	numbers[3].setClassID(CNTT2);
	numbers[4].setClassID(DTH);
	textcolor(7);
	system("cls");
	int count = studentList.size();
	for (int i = 0; i < count; ++i)
	{
		for(int j = 0; j < 5; j++)
		{
			if(strcmp(studentList[i].getClassID(),numbers[j].getClassID()) == 0)
				numbers[j].update(studentList[i].getScore());
		}
	}	

	//draw head
	textcolor(3);
	printLabel("----STATISTIC----",52,3);
	drawHead();

	// draw body (statistic)
	for (int i = 0; i < 5; ++i)
	{
		numbers[i].display(i);
		drawBody(i);
	}

	// draw end (total)
	int SL_XuatSac, SL_Gioi, SL_Kha, SL_TrungBinh, SL_Yeu, tongSinhVien;
	SL_XuatSac = SL_Gioi = SL_Kha = SL_TrungBinh = SL_Yeu = tongSinhVien = 0;

	for (int i = 0; i < 5; ++i)
	{
		SL_XuatSac += numbers[i].getXuatSac();
		SL_Gioi += numbers[i].getGioi();
		SL_Kha += numbers[i].getKha();
		SL_TrungBinh += numbers[i].getTrungBinh();
		SL_Yeu += numbers[i].getYeu();
		tongSinhVien += numbers[i].getSoSinhVien();
	}

	drawEnd(5);
	textcolor(5);
	gotoxy(25,20); cout << SL_XuatSac;
	gotoxy(41,20); cout << SL_Gioi;
	gotoxy(57,20); cout << SL_Kha;
	gotoxy(73,20); cout << SL_TrungBinh;
	gotoxy(89,20); cout << SL_Yeu;
	gotoxy(32,20); printf("%.2f\n", (float)100*SL_XuatSac/tongSinhVien);
	gotoxy(48,20); printf("%.2f\n", (float)100*SL_Gioi/tongSinhVien);
	gotoxy(64,20); printf("%.2f\n", (float)100*SL_Kha/tongSinhVien);
	gotoxy(80,20); printf("%.2f\n", (float)100*SL_TrungBinh/tongSinhVien);
	gotoxy(96,20); printf("%.2f\n", (float)100*SL_Yeu/tongSinhVien);
	textcolor(4);
	gotoxy(104,20); cout << tongSinhVien;

	char a;
	int choose = 1;
	while(true)
	{
		textcolor(7);
		gotoxy(1,24); cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ";
		if(choose == 1) textcolor(31);
		else textcolor(6);
		printLabel("    Thong Ke Theo Ten    ",10,24);
		if(choose == 2) textcolor(31);
		else textcolor(6);
		printLabel("     Thong Ke Theo Ho    ",10,26);
		if(choose == 3) textcolor(31);
		else textcolor(6);
		printLabel("          Exit           ",10,28);

		a = getch();
		if (a == 13)
		{
			if(choose == 3) return;
			else
			{
				int SL = 0;
				char *key = new char[10];
				fflush(stdin);
				gotoxy(50,24); cout << "Enter key: "; 
				textcolor(7);
				cursorType();
				gets(key);
				noCursorType();
				if(choose == 1)
				{
					for (int i = 0; i < count; ++i)
					{
						if(inBuff(key,studentList[i].getName().getFirstName(),1))
						{
							SL++;
						}
					}
					textcolor(6);
					gotoxy(61,26); cout << "SL sinh vien co ten " << key << ": " << SL;
					gotoxy(61,28); cout << "TL sinh vien co ten " << key << ": ";
					printf("%.2f", (float)100*SL/tongSinhVien); 
					a = getch();
				}

				if(choose == 2)
				{
					for (int i = 0; i < count; ++i)
					{
						if(inBuff(key,studentList[i].getName().getLastName(),1))
						{
							SL++;
						}
					}
					textcolor(6);
					gotoxy(61,26); cout << "SL sinh vien co ho " << key << ": " << SL;
					gotoxy(61,28); cout << "TL sinh vien co go " << key << ": ";
					printf("%.2f", (float)100*SL/tongSinhVien); 
					a = getch();
				}
			}			
		}

		else if (a == 72 && choose > 1) choose--;
		else if (a == 80 && choose < 3) choose++;
	}


}