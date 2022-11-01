#include "Header.h"

int main()
{
	List l;
	List sort;
	Student* p = new Student;
	int n = 0;
	char Continue = 'y';

	ifstream fileIn;
	ofstream fileOut;
	ofstream fileSort;

	fileIn.open("Student.txt", ios_base::in);
	if (!fileIn.is_open())
	{
		cout << "\nFile does not exist!";
		system("pause");
		return 0;
	}
	inputList(l, n, fileIn);
	fileIn.close();

	fileOut.open("List.txt", ios_base::out);
	if (!fileOut.is_open())
	{
		cout << "\nFile does not exist!";
		system("pause");
		return 0;
	}
	fileOut << "STUDENT DATA\n";
	outputList(l, fileOut);
	fileOut.close();

	fileSort.open("Sort.txt", ios_base::out);
	if (!fileSort.is_open())
	{
		cout << "\nFile does not exist!";
		system("pause");
		return 0;
	}
	menuFindStudent(Continue, l, n, sort, fileSort, fileOut);
	fileSort.close();
	delete p;
	return 0;
}