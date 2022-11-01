#include "Header.h"

void initStudent(Student& p) { //Khoi tao SV
	p.iD = new char[10];
	p.fullName = new Fullname[200];
	p.batchYearOfAdmission;
	p.dePartment= new char[100];
	p.eMail = new char[100];
	p.phoneNumber=new char[20];
	p.yearOfBirth;
	p.homeTown= new char[300] ;
	p.mailingAddress = new char[300];
	p.residentialAddress = new char[300];
}

void inputStudent(Student& p, ifstream& fp) { //Nhap SV
	initStudent(p);
	fp.getline(p.iD, 11);
	char* name = new char[200];
	fp.getline(name, 50);
	standardiseName(name, p.fullName);
	fp >> p.batchYearOfAdmission;
	fp.ignore();
	fp.getline(p.dePartment, 101);
	fp.getline(p.eMail, 101);
	fp.getline(p.phoneNumber, 21);
	fp >> p.yearOfBirth;
	fp.ignore();
	fp.getline(p.homeTown, 301);
	fp.getline(p.mailingAddress, 301);
	fp.getline(p.residentialAddress, 301);
}
void outputStudent(Student& p, ofstream& fp) { //Xuat SV
	fp << "Student Id: " << p.iD << endl;
	fp << "Full Name: " << p.fullName->Full << endl;
	fp << "Batch (Year Of Admission): " << p.batchYearOfAdmission << endl;
	fp << "Department: " << p.dePartment << endl;
	fp << "Email: " << p.eMail << endl;
	fp << "Phone Number: " << p.phoneNumber << endl;
	fp << "Year Of Birth: " << p.yearOfBirth << endl;
	fp << "Hometown (city/province): " << p.homeTown << endl;
	fp << "Mailing Address: " << p.mailingAddress << endl;
	fp << "Residential Address: " << p.residentialAddress << endl;
}

void initList(List& l, int n) {			// Khoi tao danh sach SV
	l.sz = n;
	l.svPtr = new Student[n];
}
void inputList(List& l, int& n, ifstream& fp) {		//Nhap DS
	fp >> n;
	initList(l, n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			fp.ignore();
		}
		inputStudent(l.svPtr[i], fp);
		
	}
}
void outputList(List& l, ofstream& fp) {		//Xuat DS
	for (int i = 0; i < l.sz; i++) {
		fp << i + 1 << "\n";
		outputStudent(l.svPtr[i], fp);
	}
}

void addStudent(Student& p) {
	initStudent(p);
	cout << "Student Id: ";
	cin.getline(p.iD, 11);
	cout << "Full Name: ";
	char* name = new char[200];
	cin.getline(name, 50);
	standardiseName(name, p.fullName);
	cout << "Batch (Year Of Admission): ";
	cin >> p.batchYearOfAdmission;
	while (p.batchYearOfAdmission < 1900 || p.batchYearOfAdmission > 2022)
	{
		cout << "Wrong data, please try again: ";
		cin >> p.batchYearOfAdmission;
	}
	cin.ignore();
	cout << "Department: ";
	cin.getline(p.dePartment, 101);
	standardiseString(p.dePartment);
	cout << "Email: ";
	cin.getline(p.eMail, 101);
	cout << "Phone Number: ";
	cin.getline(p.phoneNumber, 21);
	cout << "Year Of Birth: ";
	cin >> p.yearOfBirth;
	while (p.yearOfBirth < 1500 || p.yearOfBirth > 2004)
	{
		cout << "Wrong data, please try again: ";
		cin >> p.yearOfBirth;
	}
	cin.ignore();
	cout << "Hometown(city / province): ";
	cin.getline(p.homeTown, 301);
	standardiseString(p.homeTown);
	cout << "Mailing Address: ";
	cin.getline(p.mailingAddress, 301);
	cout << "Residential Address: ";
	cin.getline(p.residentialAddress, 301);
}
void addStudentToList(List& l) {
	int n = 0;
	cout << "Number of students: ";
	cin >> n;
	l.sz += n;
	for (int i = l.sz - n; i < l.sz; i++) {
		if (i == l.sz - n) {
			cin.ignore();
		}
		addStudent(l.svPtr[i]);
	}
}

void conversion(Student& a, Student& b) {
	Student temp;
	temp = a;
	a = b;
	b = temp;
}

void findStudentByIDOrFullNameOrPhoneNumber(List& l, int n, ofstream& fp) {
	char* tmp = new char[200];
	int count = 0;
	cin.ignore();
	cout << "Input imformation that you want to find (ID/FullName/Phone Number): ";
	cin.getline(tmp, 200);
	standardiseString(tmp);
	fp << "Students that have the information: " << tmp << "\n";
	for (int i = 0; i < n; ++i) {
		if (strcmp(l.svPtr[i].iD, tmp) == 0 || strcmp(l.svPtr[i].phoneNumber, tmp) == 0 || strcmp(l.svPtr[i].fullName->Full, tmp) == 0){
			count++;
			outputStudent(l.svPtr[i], fp);
		}
	}
	if (count == 0) {
		fp << "There're no student has this ID";
	}
}
void findStudentByBatchOrDepartmen(List& l, int n, List& sort, ofstream& fp) {
	char* tmp = new char[200];
	initList(sort, n);
	int k = 0;
	cout << "Input imformation that you want to find (Batch/Department) : ";
	cin.ignore();
	cin.getline(tmp, 200);
	int x = atoi(tmp);
	standardiseString(tmp);
	fp << "Students that have the information: " << tmp << " and sorted by ID here:\n";
	for (int i = 0; i < n; ++i) {
		if (strcmp(l.svPtr[i].dePartment, tmp) == 0 || l.svPtr[i].batchYearOfAdmission == x){
			sort.svPtr[k] = l.svPtr[i];
			k++;
		}
	}
	sort.sz = k;
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (strcmp(sort.svPtr[i].iD, sort.svPtr[j].iD) > 0) {
				conversion(sort.svPtr[i], sort.svPtr[j]);
			}
		}
	}
	
}

void standardiseName(char* name, Fullname* Name)		//Chuan hoa va chia ten thanh tung phan: ho, ten dem, ten 
{
	char* strStd = new char[100];
	int j = 0;
	while (name[j] == 32)
		++j;
	int m = 1;
	if (islower(name[j]))
		strStd[0] = name[j] - 32;
	else
		strStd[0] = name[j];
	for (int k = j + 1; k < strlen(name); ++k)
	{
		if (isalpha(name[k - 1]) || isalpha(name[k]))
		{
			if (!isalpha(name[k - 1]))
			{
				if (islower(name[k]))
					name[k] -= 32;
			}
			else
			{
				if (isupper(name[k]))
					name[k] += 32;
			}
			strStd[m] = name[k];
			++m;
		}
	}
	strStd[m] = '\0';
	Name->Full = new char[200];
	Name->FirstName = new char[100];
	Name->MiddleName = new char[100];
	Name->LastName = new char[100];
	for (int i = 0; i <= m; ++i)
		Name->Full[i] = strStd[i];
	int i = 0;
	while (strStd[i] != 32)
	{
		Name->FirstName[i] = strStd[i];
		++i;
	}
	Name->FirstName[i] = '\0';
	j = m - 1;
	while (strStd[j] != 32)
	{
		--j;
	}
	for (int k = i; k <= j; ++k)
	{
		Name->MiddleName[k - i] = strStd[k];
	}
	Name->MiddleName[j - i + 1] = '\0';
	for (int k = j + 1; k < m; ++k)
	{
		Name->LastName[k - j - 1] = strStd[k];
	}
	Name->LastName[m - j - 1] = '\0';
}

void findStudentByBatchAndDepartMent(List &l, int n, List& sort, ofstream& fp) {
	char* department = new char[200];
	int batch = 0;
	initList(sort, n);
	int k = 0;
	cout << "Input Batch: ";
	cin >> batch;
	cin.ignore();
	cout << "Input Department: ";
	cin.getline(department, 200);
	standardiseString(department);
	fp << "Students that have the information: " << batch << " and " << department << " and sorted by Name here:\n";
	for (int i = 0; i < n; ++i) {
		if (strcmp(l.svPtr[i].dePartment, department) == 0 && l.svPtr[i].batchYearOfAdmission == batch) {
			sort.svPtr[k] = l.svPtr[i];
			k++;
		}
	}
	sort.sz = k;
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (strcmp(sort.svPtr[i].fullName->LastName, sort.svPtr[j].fullName->LastName) > 0 || strcmp(sort.svPtr[i].fullName->LastName, sort.svPtr[j].fullName->LastName) == 0 && strcmp(sort.svPtr[i].fullName->FirstName, sort.svPtr[j].fullName->FirstName) > 0 || strcmp(sort.svPtr[i].fullName->LastName, sort.svPtr[j].fullName->LastName) == 0 && strcmp(sort.svPtr[i].fullName->FirstName, sort.svPtr[j].fullName->FirstName) == 0 && strcmp(sort.svPtr[i].fullName->MiddleName, sort.svPtr[j].fullName->MiddleName) > 0) {
				conversion(sort.svPtr[i], sort.svPtr[j]);
			}
		}
	}

}

void menuFindStudent(char Continue, List& l, int n, List& sort, ofstream& fileSort, ofstream& fileOut) {
	while (Continue == 'y' || Continue == 'Y')
	{
		cout << "1. Find students by ID/Full Name/Phone Number.\n";
		cout << "2. Find students by Batch/Department.\n";
		cout << "3. Find students by Batch and Department.\n";
		cout << "4. Add students to list.\n";
		cout << "5. Exit the program.\n";
		cout << "Choose a number: ";
		int Choice = 0;
		cin >> Choice;
		while (Choice <= 0 || Choice > 5) {
			cout << "Type again, please: \n";
			cin >> Choice;
		}
		cout << "Your choice: ";
		switch (Choice)
		{
		case 1:
			fileSort << "Find students by ID/Full Name/Phone Number.\n";
			findStudentByIDOrFullNameOrPhoneNumber(l, n, fileSort);
			break;
		case 2:
			fileSort << "Find students by Batch/Department.\n";
			findStudentByBatchOrDepartmen(l, n, sort, fileSort);
			if (sort.sz != 0) {
				outputList(sort, fileSort);
			}
			else fileSort << "There're no student has this information";
			break;
		case 3:
			fileSort << "Find students by Batch and Department.\n";
			findStudentByBatchAndDepartMent(l, n, sort, fileSort);
			if (sort.sz != 0) {
				outputList(sort, fileSort);
			}
			else fileSort << "There're no student has both information";
			break;
		case 4:
			fileOut.open("List.txt", ios::trunc);
			fileOut.close();
			cout << "Add students to list.\n";
			addStudentToList(l);
			fileOut.open("List.txt", ios_base::out);
			fileOut << "STUDENT LIST AFTER BEING ADDED\n";
			outputList(l, fileOut);
			fileOut.close();
			break;
		case 5:
			cout << "Exit the program.\nType randomly a key to exit.\n";
			return;
			break;
		}
		cout << "\nDo you want to continue(Y: Yes, N: No): ";
		cin >> Continue;
		while (Continue != 'y' && Continue != 'n' && Continue != 'N' && Continue != 'Y') {
			cout << "Wrong! Please type again: ";
			cin >> Continue;
		}
		if (Continue == 'n' || Continue == 'N') {
			cout << "Exit the program!";
		}

	}
}

void standardiseString(char* name) {
	char* strStd = new char[100];
	if (islower(name[0]))
		name[0] = name[0] - 32;
	int j = 0;
	while (name[j] == 32) {
		++j;
	}
	int m = 1;
	if (islower(name[j]))
		strStd[0] = name[j] - 32;
	else
		strStd[0] = name[j];
	for (int k = j + 1; k < strlen(name); ++k)
	{
		if (isalpha(name[k - 1]) || isalpha(name[k]))
		{
			if (!isalpha(name[k - 1]))
			{
				if (islower(name[k]))
					name[k] -= 32;
			}
			else
			{
				if (isupper(name[k]))
					name[k] += 32;
			}
			strStd[m] = name[k];
			++m;
		}
	}
}
