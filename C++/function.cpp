#include "pch.h"
#include "function.h"

// �������� �����
int LinearSearch(int array[], int size, int key) 
{
	for (int i = 0; i < size; i++)
		if (array[i] == key)
			return i;
	return -1;
}
// �������� ����� ��� �������������� �������
int BinarySearch(int A[], int size, int Key)
{
	int M, Lb = 0;
	while (1) {
		M = (Lb + size) / 2;
		if (Key < A[M])
			size = M - 1;
		else if (Key > A[M])
			Lb = M + 1;
		else
			return M;

		if (Lb > size)
			return -1;
	}
}

long int Fact(long int N)
{
	if (N == 1 || N == 0) return 1;
	else return N * Fact(N - 1);
}

// �������� ���������� �� �������� ����� ��������� (��� ������ ������� ������ ���������� swap_ptr(&x, &y))
void swap_ptr(int*px, int*py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

// �������� ���������� �� ������ (��� ������ ������� ���� ���������� swap_ref(x, y))
void swap_ref(int&rx, int&ry)
{
	int temp = rx;
	rx = ry;
	ry = temp;
}

// ������� ���������� ������ �� ������� ������� � ������������ ���������.
int &rmax(int d[], int n)
{
	int im = 0;
	for (int i = 1; i < n; i++)
		im = d[im] > d[i] ? im : i;
	return d[im];
}
/*
int x[]={10, 20, 30, 14};
cout << rmax(x, 4) << "\n";  // ����� �������� ������������� �������� 
rmax(x, 4) = 0; // ������ ������������� �������� �� ����
*/

// ��������� �� �������
/*
���_�������   (*���_���������)(������������_����������);
int (*func1Ptr) (char); - ����������� ��������� func1Ptr �� ������� � ���������� ���� char, ������������ �������� ���� int
char * (*func2Ptr) (char * ,int); - ����������� ��������� func2Ptr �� ������� � ����������� ���� ��������� �� char � ���� int, 
������������ �������� ���� ��������� �� char

void f1(void)        // ����������� f1.
{
	cout << "Load f1()\n";
}
void f2(void)        // ����������� f2.
{
	 cout << "Load f2()\n";
}
void main()
{
	void (*ptr)(void);  // ptr - ��������� �� �������.
	ptr = f2;		// ������������� ����� f2().
	(*ptr)();		// ����� f2() �� �� ������.
	ptr = f1;		// ������������� ����� f1().
	(*ptr)();		// ����� f1() �� �� ������.
	ptr();			// ����� ������������ (*ptr)();
}
��������� ���������� ���������:

	Load f2()
	Load f1()
	Load f1()
	Press any key to continue

************************************************************
char f1(char) {...}       // ����������� �������.
char f2(int) {...}        // ����������� �������.
void f3(float) {...}      // ����������� �������.
int* f4(char *){...}     // ����������� �������.
char (*pt1)(int);        // ��������� �� �������.
char (*pt2)(int);         // ��������� �� �������.
void (*ptr3)(float) = f3; // ������������������ ���������.
void main()
{
	pt1 = f1;  // ������ - �������������� ��������.
	pt2 = f3;  // ������ - �������������� ����� (�������� � ��������).
	pt1 = f4;  // ������ - �������������� �����.
	pt1 = f2;  // ���������.
	pt2 = pt1; // ���������.
	char � = (*pt1)(44); // ���������.
	� = (*pt2)('\t');    // ���������.
}

***********************************************************
#include <iostream>
using namespace std;
// ������� ������ ���� � ����������� �����������:
int add(int n, int m) { return n + m; }
int division(int n, int m) { return n/m; }
int mult(int n, int m) { return n * m; }
int subt(int n, int m) { return n - m; }
void main()
{
	int (*par)(int, int); // ��������� �� �������.
	int a =  6, b = 2;
	char c = '+';
	while   (c != ' ')
	{
		cout << "\n Arguments: a = " << a <<", b = " << b;
		cout << ". Result for c = \'" << c << "\':";

		switch (c)
		{
		case '+':
			par = add;
			c = '/';
			break;
		case '-':
			par = subt;
			c = ' ';
			break;
		case '*':
			par = mult;
			c = '-';
			break;
		case '/':
			par = division;
			c = '*';
			break;
		}
		cout << (a = (*par)(a,b))<<"\n"; //�����  ��  ������.
	}
}
���������� ���������� ���������:
	Arguments: a = 6, b = 2. Result for c = '+':8
	Arguments: a = 8, b = 2. Result for c = '/':4
	Arguments: a = 4, b = 2. Result for c = '*':8
	Arguments: a = 8, b = 2. Result for c = '-':6
	Press any key to continue
*/

// ������� ���������� �� �������
/*
float (*ptrArray[4]) (char) ; - �������� ������� � ������ ptrArray �� ������� ���������� �� �������, 
������ �� ������� ����� �������� ���� char � ���������� �������� ���� float

float � = (*ptrArray[2])('f'); - ��������� � ������� �� ���� �������

**************************************************************************
#include <iostream>
using namespace std;

// ����������� ������� ��� ��������� ���� (������� �������� �. �. �������� �������� �� ���������):

void act1(char* name)
{
	cout << "Create file..." << name;
}
void act2(char* name)
{
	cout << "Delete file... " << name;
}
void act3(char* name)
{
	cout << "Read file... " << name;
}
void act4(char* name)
{
	cout << "Mode file... " << name;
}
void act5(char* name)
{
	cout << "Close file... " << name;
}

void main()
{
	// �������� � ������������� ������� ���������� 
	void(*MenuAct[5])(char*) = { act1, act2, act3, act4, act5 };

	int number;  // ����� ���������� ������ ����.
	char FileName[30];  // ������ ��� ����� �����.

	// ���������� ����
	cout << "\n 1 - Create";
	cout << "\n 2 - Delete";
	cout << "\n 3 - Read";
	cout << "\n 4 - Mode";
	cout << "\n 5 - Close";

	while (1)  // ����������� ����.
	{
		while (1)
		{ // ���� ������������ �� ����� ����������� ������. 
			cout << "\n\nSelect action: ";
			cin >> number;
			if (number >= 1 && number <= 5) break;

			cout << "\nError number!";
		}
		if (number != 5)
		{
			cout << "Enter file name: ";
			cin >> FileName; // ������ ��� �����. 
		}
		else break;
		// ����� ������� �� ��������� �� ���:
		(*MenuAct[number - 1])(FileName);
	} // ����� ������������ �����.
}
*/

