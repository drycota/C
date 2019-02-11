#include "pch.h"
#include "array.h"

const int length = 10;
int a[length];
char b[length][length];

void printArray1(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

template <int row, int col>
void cleanArray(char(&arr)[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			arr[i][j] = NULL;
	}
}

template <int row, int col>
void printArray2(char(&arr)[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void printRand()
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		a[i] = rand() % 100;
	printArray1(a, length);
}

void printFig1()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
			b[i][j] = '*';
	}
	printArray2(b);
	cleanArray(b);
}
void printFig2()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j <= i; j++)
			b[i][j] = '*';
	}
	printArray2(b);
	cleanArray(b);
}
void printFig3()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length-i; j++)
			b[i][j] = '*';
	}
	printArray2(b);
	cleanArray(b);
}
void printFig4()
{
	for (int i = length-1; i >= 0; i--)
	{
		for (int j = length-1-i; j <= i; j++)
			b[i][j] = '*';
	}
	printArray2(b);
	cleanArray(b);
}
void printFig5()
{
	for (int i = 0; i < length; i++)
	{
		if (i < length/2)
		{
			for (int j = i; j < length-i; j++)
				b[i][j] = '*';
		}
		else
		{
			for (int j = length-1-i; j <= i; j++)
				b[i][j] = '*';
		}
		
	}
	printArray2(b);
	cleanArray(b);
}
void printFig6()
{
	for (int i = 0; i < length; i++)
	{
		if (i < length / 2)
		{
			for (int j = i; j < length - i; j++)
				b[j][i] = '*';
		}
		else
		{
			for (int j = length - 1 - i; j <= i; j++)
				b[j][i] = '*';
		}

	}
	printArray2(b);
	cleanArray(b);
}
void printFig7()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length-i; j++)
			b[i][j] = '*';
	}
	printArray2(b);
	cleanArray(b);
}
void printFig8()
{
	for (int i = length-1; i >= 0; i--)
	{
		for (int j = length-i-1; j < length; j++)
			b[i][j] = '*';
	}
	printArray2(b);
	cleanArray(b);
}
void printFigAll()
{
	printFig1();
	printFig2();
	printFig3();
	printFig4();
	printFig5();
	printFig6();
	printFig7();
	printFig8();
}
// ��������� �� ������
void pointerArray()
{
	int ar[5] = { 1,2,3,4,5 };
	int ar2[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int*ptr = ar;  // int*ptr = &ar[0];
	ptr += 3;  // 4
	cout << *ptr << endl;

	int *ptr2 = ar2[0];  // int *ptr2 = &ar2[0][0];
	ptr2 += 8;
	cout << *ptr2 << endl;  // 9
	ptr2 = ar2[1]; // ptr2 = &ar2[1][0];
	ptr2 += 5;
	cout << *ptr2 << endl;  // 9
	ptr2 = &ar2[2][1];

	ptr2 ++;
	cout << *ptr2 << endl;  // 9
}
// ������������ ������
void dArrPrint() {
	srand(time(NULL));
	int size;
	int * dar;
	// ������ ������� ������� � ����������
	cout << "Enter size:\n";
	cin >> size;
	//��������� ������ ��� ������ � ����������� ��������� size
	dar = new int[size];
	if (!dar) {
		cout << "Sorry, error!!!";
		exit(0);// ������� ���������� ����� �� ���������
	}
	// ���������� ������� � ����� �� �����
	for (int i = 0; i < size; i++) {
		dar[i] = rand() % 100;
		cout << dar[i] << "\t";
	}
	cout << "\n\n";
	// ������������ ������
	delete[]dar;
}
/*
delete ip; // ������� ������������ ������ ���� int, ���� ���� ip = new int; 
delete[] mas; // ������� ������������ ������ ������ 50, ���� ���� double *mas = new double[50]; 
*/

// ��������� ������������ ������
void dArr2()
{
	// ���������� ��� �������� ������������� ��������.
	int m1 = 5, m2 = 5;
	/*
	����������� ���������� ������������� ������� ������������ � ��� �����.
	������� �������� ���������� ������ ����������, � ����� ������� ��������
	����� ������� ������������� ����� ����������� �������. ��� �������������
	�������� �������� �� ��������� ����������� ���������.
	*/
	int **pArr = new int*[m1];
	for (int i = 0; i < m1; i++)
		pArr[i] = new int[m2];

	pArr[3][3] = 100;
	cout << pArr[3][3] << "\n";

	//���������������� ����������� ���������� ��������
	for (int i = 0; i < m1; i++)
		delete[]pArr[i];
	delete[]pArr;
}

//��������� "�����������" ������������ ������
/*
������� �������� ���������� ������ ����������, � ����� ������� �������� ����� ������� ������������� ����� ����������� �������. 
��� ���� ������ (���������� ���������) ������� ������ ������� �� ������� ������ ������� �����������
*/
void dArr2Triangle()
{
	// ���������� ��� �������� ������������� ��������.
	int m1 = 5, wm = 5;
	int **pXArr = new int*[m1];

	for (int i = 0; i < m1; i++, wm--)
		pXArr[i] = new int[m1];

	//���������� ������� ������ � ����� ��� �� �����
	for (int i = m1 - 1; i >= 0; i--, wm++) {
		for (int j = 0; j < wm; j++) {
			pXArr[i][j] = 0;
			cout << pXArr[i][j] << "\t";
		}
		cout << "\n\n";
	}

	//���������������� ����������� ���������� ������� ����������� ������������
	for (int i = 0; i < m1; i++)
		delete[]pXArr[i];
	delete[]pXArr;

}

// ���������� ������������ ������
void dArr3()
{
	// ���������� ��� �������� ������������� ��������.
	int m1 = 5, m2 = 5, m3 = 2;
	// ��������� �� ��������� �� ��������� :)
	int ***ppArr;

	// �������� �������
	ppArr = new int**[m1];
	for (int i = 0; i < m1; i++)
		ppArr[i] = new int*[m2];

	for (int i = 0; i < m1; i++)
		for (int j = 0; j < m2; j++)
			ppArr[i][j] = new int[m3];

	ppArr[1][2][3] = 750;
	cout << ppArr[1][2][3] << "\n";

	// �������� � ������������������, �������� ��������
	for (int i = 0; i < m1; i++)
		for (int j = 0; j < m2; j++)
			delete[]ppArr[i][j];

	for (int i = 0; i < m1; i++)
		delete[]ppArr[i];
	
	delete[] ppArr;
}

// ������������ ����
/*
enum Months {JAN = 1, FEB, MAR, APR, MAY, YUN, YUL AUG, SEP, OCT, NOV, DEC};
�������� ������� ������������� ������������.
1. ������������� ������������ ������ ����� �������� ��������� ������ ���������.
2. �������������� � enum ������ ���� �����������, �� ��������� ��������� ������������ ����� ����� ���������� ����� ��������.
3. ����� ��������������� ������������� ���� � ����������� ���������� ���, ������������ �� ������ ������������� �����.
4. ������������ ��������� ����� ������������ � ������������������ ������������� �������������� �����������, � ����� ������������ �����������:
enum ages (milton = 47, ira, harold = 56, philip = harold + 7};  // ira = 48
5. ������ ������������ �������� ��������� �����. ����� �������� ������������ �������� ���� ������������. ��������, �
enum Keyword {ASM, AUTO, BREAK};
AUTO ����� ��� Keyword.
6. ������������ ��������� ����� ���� ��������� ��������, �� ���� ��� ����� ����.
enum {FALSE, TRUE};
enum {lazy, hazy, crazy} why;
������ ���������� � ���������������� ������ ���������� ������������� ������������� ��������. ������ ���������� ��������� ���������� ������������� ���� why, � ����������� ���������� ���� ���������� lazy,hazy � crazy.
7. ������������ ����� ������ ����������������� � ������� ������������� ����, �� �� ��������.
enum boolean {FALSE, TRUE} q;
enum signal {off, on} a = on;  //� ���������������� � on
enum answer {no, yes, maybe = -1} b;
int i, j = true;  //����� true ������������� � 1
a = off;  //�����
� = �;  //����� i ���������� 1
q = �;  //������� ��� ��������� ����
q = (boolean)�;  //����� ����� �������������� �����������
*/

// ���������
/*
struct date
{
   int day; // ����.
   char month[10]; // �����.
   int year; // ���.
};

struct person
{
   char name[namesize]; // ���, �������, ��������.
   char address[adrsize]; // �������� �����.
   int zipcode[2]; // �������� ������.
   int s_number [2]; // ��� ���.�����������.
   int salary[4]; // ��������.
   date birthdate; // ���� ��������.
   date hiredate; // ���� ����������� �� ������.
};

//�������� � ������������� ������� ���������.
date d = { 2,5,1776,"July" }; //d - ���������� ���� date.
// ��������� p ��������� �� ��������� ���� date.
	struct date *p;

	// ����� ����������� ��������� �� �����
	//(��������� ����� ������)
	cout<< d.day << " ";
	cout<< d.year << " ";
	cout<< d.month << " ";
	cout<< d.mon_name << "\n\n";

	// ������ ������ ������ ��������� � ���������
	p = &d;

	// ����� ����������� ��������� �� �����
	//(��������� ����� ���������)
	cout << p->day << " ";
	cout << p->month << " ";
	cout << p->year << " ";
	cout << p->mon_name << "\n\n";
*/

// �����������
/*
����������� � ����� C ������� ����������, ������ � ������ ������ ������� ����� �������������� (�������� ��������) ������ ���� �� ��� �����������
���� ��������� ����������� � ����������� ������ ���� �� ������ � ��� ������������������, � ������� ����������� � ��������. 
� ������� �� �� ���������, ��� �������� ����������� ������������� �� ������ ������. 
����� �������, ��� ����������� ���������� ������� ������, ������� ����� ��� �������� ����������� ��� ��������.
union Test
{
   int a;
   char b;

}kkk;

void main ()
{
  kkk.a = 65;
  cout<<kkk.a<<" "; // ����� 65
  cout<<kkk.b;// ������ � (��������������� ����� �����)
}
����������� ����������� ���:
-����������� ������������� ������ ������, ���� � ������ ������ ������� ������ ���� ������ �� ������ �������� ��������;
-������������� ��������� ������������� ������� ������ ����, ��� ���� �� ����� ������� ��� �������� ������ ���.
*/
