#include "pch.h"
#include "function.h"

// Линейный поиск
int LinearSearch(int array[], int size, int key) 
{
	for (int i = 0; i < size; i++)
		if (array[i] == key)
			return i;
	return -1;
}
// Двоичный поиск для сортированного массива
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

// Передача аргументов по значению через указатели (при вызове передаём адреса переменных swap_ptr(&x, &y))
void swap_ptr(int*px, int*py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

// Передача аргументов по ссылке (при вызове передаём сами переменные swap_ref(x, y))
void swap_ref(int&rx, int&ry)
{
	int temp = rx;
	rx = ry;
	ry = temp;
}

// Функция определяет ссылку на элемент массива с максимальным значением.
int &rmax(int d[], int n)
{
	int im = 0;
	for (int i = 1; i < n; i++)
		im = d[im] > d[i] ? im : i;
	return d[im];
}
/*
int x[]={10, 20, 30, 14};
cout << rmax(x, 4) << "\n";  // вывод значения максимального элемента 
rmax(x, 4) = 0; // замена максимального элемента на нуль
*/

// Указатели на функции
/*
тип_функции   (*имя_указателя)(спецификация_параметров);
int (*func1Ptr) (char); - определение указателя func1Ptr на функцию с параметром типа char, возвращающую значение типа int
char * (*func2Ptr) (char * ,int); - определение указателя func2Ptr на функцию с параметрами типа указатель на char и типа int, 
возвращающую значение типа указатель на char

void f1(void)        // Определение f1.
{
	cout << "Load f1()\n";
}
void f2(void)        // Определение f2.
{
	 cout << "Load f2()\n";
}
void main()
{
	void (*ptr)(void);  // ptr - указатель на функцию.
	ptr = f2;		// Присваивается адрес f2().
	(*ptr)();		// Вызов f2() по ее адресу.
	ptr = f1;		// Присваивается адрес f1().
	(*ptr)();		// Вызов f1() по ее адресу.
	ptr();			// Вызов эквивалентен (*ptr)();
}
Результат выполнения программы:

	Load f2()
	Load f1()
	Load f1()
	Press any key to continue

************************************************************
char f1(char) {...}       // Определение функции.
char f2(int) {...}        // Определение функции.
void f3(float) {...}      // Определение функции.
int* f4(char *){...}     // Определение функции.
char (*pt1)(int);        // Указатель на функцию.
char (*pt2)(int);         // Указатель на функцию.
void (*ptr3)(float) = f3; // Инициализированный указатель.
void main()
{
	pt1 = f1;  // Ошибка - несоответствие сигнатур.
	pt2 = f3;  // Ошибка - несоответствие типов (значений и сигнатур).
	pt1 = f4;  // Ошибка - несоответствие типов.
	pt1 = f2;  // Правильно.
	pt2 = pt1; // Правильно.
	char с = (*pt1)(44); // Правильно.
	с = (*pt2)('\t');    // Правильно.
}

***********************************************************
#include <iostream>
using namespace std;
// Функции одного типа с одинаковыми сигнатурами:
int add(int n, int m) { return n + m; }
int division(int n, int m) { return n/m; }
int mult(int n, int m) { return n * m; }
int subt(int n, int m) { return n - m; }
void main()
{
	int (*par)(int, int); // Указатель на функцию.
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
		cout << (a = (*par)(a,b))<<"\n"; //Вызов  по  адресу.
	}
}
Результаты выполнения программы:
	Arguments: a = 6, b = 2. Result for c = '+':8
	Arguments: a = 8, b = 2. Result for c = '/':4
	Arguments: a = 4, b = 2. Result for c = '*':8
	Arguments: a = 8, b = 2. Result for c = '-':6
	Press any key to continue
*/

// Массивы указателей на функции
/*
float (*ptrArray[4]) (char) ; - описание массива с именем ptrArray из четырех указателей на функции, 
каждая из которых имеет параметр типа char и возвращает значение типа float

float а = (*ptrArray[2])('f'); - обращение к третьей из этих функций

**************************************************************************
#include <iostream>
using namespace std;

// Определение функций для обработки меню (функции фиктивны т. е. реальных действий не выполняют):

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
	// Создание и инициализация массива указателей 
	void(*MenuAct[5])(char*) = { act1, act2, act3, act4, act5 };

	int number;  // Номер выбранного пункта меню.
	char FileName[30];  // Строка для имени файла.

	// Реализация меню
	cout << "\n 1 - Create";
	cout << "\n 2 - Delete";
	cout << "\n 3 - Read";
	cout << "\n 4 - Mode";
	cout << "\n 5 - Close";

	while (1)  // Бесконечный цикл.
	{
		while (1)
		{ // Цикл продолжается до ввода правильного номера. 
			cout << "\n\nSelect action: ";
			cin >> number;
			if (number >= 1 && number <= 5) break;

			cout << "\nError number!";
		}
		if (number != 5)
		{
			cout << "Enter file name: ";
			cin >> FileName; // Читать имя файла. 
		}
		else break;
		// Вызов функции по указателю на нее:
		(*MenuAct[number - 1])(FileName);
	} // Конец бесконечного цикла.
}
*/

