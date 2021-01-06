#pragma once
#include <vector>
#include <fstream>
#include "student.h"

#define CNTT1 "CNTT1"
#define CNTT2 "CNTT2"
#define BDATTT "BDATTT"
#define ANHTTT "ANHTTT"
#define DTH "DTH"

//definition of class "list"
class list 	
{
	private:
		vector<student> studentList;
		bool checkClassID(char[]);
		bool checkStudentID(char[]);
		bool verify(student);
		void delOrEdit(int);

	public:
		void outputToFile();
		void inputFromFile();
		list();
		void addStudent();
		void editProfile(int);
		void deleteStudent(int);
		int printList(bool,int&);
		void sort(int, int);
		void search(int, int);
		void statistic();
		vector<student>* getList(){return &studentList;};
};

list::list()
{}

// function to update structure data from binary file
void list::inputFromFile()
{
	student tmp;
	ifstream ifs("data.dat",ios::binary);
	while(true)
	{
		ifs.read((char*)&tmp,sizeof(student));
		if(ifs.eof()) break;
		studentList.push_back(tmp);
	}
	ifs.close();
}

// function to output structure data to binary file
void list::outputToFile()
{
	ofstream ofs("data.dat",ios::binary);
	for (int i = 0; i < (int)studentList.size(); ++i)
		ofs.write((char*)&studentList[i],sizeof(student));
	ofs.close();
}
