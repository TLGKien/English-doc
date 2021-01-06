#pragma once
#include "student.h"

class numberOfClass
{
	private:
		char classID[10];
		int soSinhVien;
		int xuatSac, gioi, kha, trungBinh, yeu;
	public:
		numberOfClass();
		void update(float);
		void display(int);
		char* getClassID();
		void setClassID(const char[]);
		int getXuatSac();
		int getGioi();
		int getKha();
		int getTrungBinh();
		int getYeu();
		int getSoSinhVien();
};
numberOfClass::numberOfClass()
{
	soSinhVien = xuatSac = gioi = kha = trungBinh = yeu = 0;
}
void numberOfClass::update(float score)
{
	soSinhVien++;
	if(score >= 3.6 && score <= 4.0) xuatSac++;
	else if (score >= 3.2 && score < 3.6) gioi++;
	else if (score >= 2.5 && score < 3.2) kha++;
	else if (score >= 2.0 && score < 2.5) trungBinh++;
	else if (score >= 0 && score < 2.0) yeu++;
}
char* numberOfClass::getClassID()
{
	return classID;
}
void numberOfClass::setClassID(const char name[])
{
	for (size_t i = 0; i <= strlen(name); ++i)
		classID[i] = name[i];
}
void numberOfClass::display(int i)
{
	int y = 10 + i*2;
	textcolor(7);
	printLabel(classID,14,y);
	gotoxy(25,y); cout << xuatSac;
	gotoxy(41,y); cout << gioi;
	gotoxy(57,y); cout << kha;
	gotoxy(73,y); cout << trungBinh;
	gotoxy(89,y); cout << yeu;
	gotoxy(32,y); printf("%.2f\n", (float)100*xuatSac/soSinhVien);
	gotoxy(48,y); printf("%.2f\n", (float)100*gioi/soSinhVien);
	gotoxy(64,y); printf("%.2f\n", (float)100*kha/soSinhVien);
	gotoxy(80,y); printf("%.2f\n", (float)100*trungBinh/soSinhVien);
	gotoxy(96,y); printf("%.2f\n", (float)100*yeu/soSinhVien);
	textcolor(5);
	gotoxy(104,y); cout << soSinhVien;
}

int numberOfClass::getXuatSac()
{
	return xuatSac;
}
int numberOfClass::getGioi()
{
	return gioi;
}
int numberOfClass::getKha()
{
	return kha;
}
int numberOfClass::getTrungBinh()
{
	return trungBinh;
}
int numberOfClass::getYeu()
{
	return yeu;
}
int numberOfClass::getSoSinhVien()
{
	return soSinhVien;
}