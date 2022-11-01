#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;
struct Fullname {
	char* FirstName;
	char* LastName;
	char* MiddleName;
	char* Full;
};
struct Student {
	char* iD;
	Fullname* fullName;
	int batchYearOfAdmission;
	char* dePartment;
	char* eMail;
	char* phoneNumber;
	int yearOfBirth;
	char* homeTown;
	char* mailingAddress;
	char* residentialAddress;
};

struct List {
	int sz;
	Student* svPtr;
};
void initStudent(Student& p);
void inputStudent(Student& p, ifstream& fp);
void outputStudent(Student& p, ofstream& fp);

void initList(List& l, int n);
void inputList(List& l, int& n, ifstream& fp);
void outputList(List& l, ofstream& fp);

void addStudent(Student& p);
void addStudentToList(List& l);

void standardiseString(char s[]);
void findStudentByIDOrFullNameOrPhoneNumber(List& l, int n, ofstream& fp);

void conversion(Student& a, Student& b);

void findStudentByBatchOrDepartmen(List& l, int n, List& sort, ofstream& fp);

void standardiseName(char* name, Fullname* Name);
void findStudentByBatchAndDepartMent(List& l, int n, List& sort, ofstream& fp);

void menuFindStudent(char Continue, List& l, int n, List& sort, ofstream& fileSort, ofstream& fileOut);
#endif // !_HEADER_H_
