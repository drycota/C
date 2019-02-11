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
// Указатель на массив
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
// Динамический массив
void dArrPrint() {
	srand(time(NULL));
	int size;
	int * dar;
	// запрос размера массива с клавиатуры
	cout << "Enter size:\n";
	cin >> size;
	//выделение памяти под массив с количеством элементов size
	dar = new int[size];
	if (!dar) {
		cout << "Sorry, error!!!";
		exit(0);// функция организует выход из программы
	}
	// заполнение массива и показ на экран
	for (int i = 0; i < size; i++) {
		dar[i] = rand() % 100;
		cout << dar[i] << "\t";
	}
	cout << "\n\n";
	// освобождение памяти
	delete[]dar;
}
/*
delete ip; // Удаляет динамический объект типа int, если было ip = new int; 
delete[] mas; // удаляет динамический массив длиной 50, если было double *mas = new double[50]; 
*/

// Двумерный динамический массив
void dArr2()
{
	// Переменные для описания характеристик массивов.
	int m1 = 5, m2 = 5;
	/*
	Организация двумерного динамического массива производится в два этапа.
	Сначала создаётся одномерный массив указателей, а затем каждому элементу
	этого массива присваивается адрес одномерного массива. Для характеристик
	размеров массивов не требуется константных выражений.
	*/
	int **pArr = new int*[m1];
	for (int i = 0; i < m1; i++)
		pArr[i] = new int[m2];

	pArr[3][3] = 100;
	cout << pArr[3][3] << "\n";

	//Последовательное уничтожение двумерного массива…
	for (int i = 0; i < m1; i++)
		delete[]pArr[i];
	delete[]pArr;
}

//Двумерный "треугольный" динамический массив
/*
Сначала создаётся одномерный массив указателей, а затем каждому элементу этого массива присваивается адрес одномерного массива. 
При этом размер (количество элементов) каждого нового массива на единицу меньше размера предыдущего
*/
void dArr2Triangle()
{
	// Переменные для описания характеристик массивов.
	int m1 = 5, wm = 5;
	int **pXArr = new int*[m1];

	for (int i = 0; i < m1; i++, wm--)
		pXArr[i] = new int[m1];

	//Заполнение массива нулями и показ его на экран
	for (int i = m1 - 1; i >= 0; i--, wm++) {
		for (int j = 0; j < wm; j++) {
			pXArr[i][j] = 0;
			cout << pXArr[i][j] << "\t";
		}
		cout << "\n\n";
	}

	//Последовательное уничтожение двумерного массива треугольной конфигурации…
	for (int i = 0; i < m1; i++)
		delete[]pXArr[i];
	delete[]pXArr;

}

// Трехмерный динамический массив
void dArr3()
{
	// Переменные для описания характеристик массивов.
	int m1 = 5, m2 = 5, m3 = 2;
	// указатель на указатель на указатель :)
	int ***ppArr;

	// Создание массива
	ppArr = new int**[m1];
	for (int i = 0; i < m1; i++)
		ppArr[i] = new int*[m2];

	for (int i = 0; i < m1; i++)
		for (int j = 0; j < m2; j++)
			ppArr[i][j] = new int[m3];

	ppArr[1][2][3] = 750;
	cout << ppArr[1][2][3] << "\n";

	// Удаление в последовательности, обратной созданию
	for (int i = 0; i < m1; i++)
		for (int j = 0; j < m2; j++)
			delete[]ppArr[i][j];

	for (int i = 0; i < m1; i++)
		delete[]ppArr[i];
	
	delete[] ppArr;
}

// Перечислимые типы
/*
enum Months {JAN = 1, FEB, MAR, APR, MAY, YUN, YUL AUG, SEP, OCT, NOV, DEC};
Основные моменты использования перечислений.
1. Использование перечислений вместо целых констант облегчает чтение программы.
2. Идентификаторы в enum должны быть уникальными, но отдельные константы перечисления могут иметь одинаковые целые значения.
3. Набор идентификаторов перечислимого типа — собственный уникальный тип, отличающийся от других целочисленных типов.
4. Перечислимые константы могут определяться и инициализироваться произвольными целочисленными константами, а также константными выражениями:
enum ages (milton = 47, ira, harold = 56, philip = harold + 7};  // ira = 48
5. Каждое перечисление является отдельным типом. Типом элемента перечисления является само перечисление. Например, в
enum Keyword {ASM, AUTO, BREAK};
AUTO имеет тип Keyword.
6. Перечислимая константа может быть объявлена анонимно, то есть без имени типа.
enum {FALSE, TRUE};
enum {lazy, hazy, crazy} why;
Первое объявление — распространенный способ объявления мнемонических целочисленных констант. Второе объявление объявляет переменную перечислимого типа why, с допустимыми значениями этой переменной lazy,hazy и crazy.
7. Перечисления могут неявно преобразовываться в обычные целочисленные типы, но не наоборот.
enum boolean {FALSE, TRUE} q;
enum signal {off, on} a = on;  //а инициализируется в on
enum answer {no, yes, maybe = -1} b;
int i, j = true;  //верно true преобразуется в 1
a = off;  //верно
і = а;  //верно i становится 1
q = а;  //неверно два различных типа
q = (boolean)а;  //верно явное преобразование приведением
*/

// Структуры
/*
struct date
{
   int day; // День.
   char month[10]; // Месяц.
   int year; // Год.
};

struct person
{
   char name[namesize]; // Имя, фамилия, отчество.
   char address[adrsize]; // Домашний адрес.
   int zipcode[2]; // Почтовый индекс.
   int s_number [2]; // Код соц.обеспечения.
   int salary[4]; // Зарплата.
   date birthdate; // Дата рождения.
   date hiredate; // Дата поступления на работу.
};

//Создание и инициализация объекта структуры.
date d = { 2,5,1776,"July" }; //d - переменная типа date.
// Указатель p указывает на структуру типа date.
	struct date *p;

	// Показ содержимого структуры на экран
	//(обращение через объект)
	cout<< d.day << " ";
	cout<< d.year << " ";
	cout<< d.month << " ";
	cout<< d.mon_name << "\n\n";

	// запись адреса объкта структуры в указатель
	p = &d;

	// Показ содержимого структуры на экран
	//(обращение через указатель)
	cout << p->day << " ";
	cout << p->month << " ";
	cout << p->year << " ";
	cout << p->mon_name << "\n\n";
*/

// Объединения
/*
Объединения в языке C подобны структурам, однако в каждый момент времени может использоваться (является активным) только один из его компонентов
Поля структуры размещаются в оперативной памяти одно за другим в той последовательности, в которой перечислены в описании. 
В отличие же от структуры, все атрибуты объединения располагаются по одному адресу. 
Таким образом, под объединение выделяется столько памяти, сколько нужно для хранения наибольшего его атрибута.
union Test
{
   int a;
   char b;

}kkk;

void main ()
{
  kkk.a = 65;
  cout<<kkk.a<<" "; // число 65
  cout<<kkk.b;// символ А (соответствующий этому числу)
}
Объединения применяются для:
-минимизации используемого объема памяти, если в каждый момент времени только один объект из многих является активным;
-интерпретации основного представления объекта одного типа, как если бы этому объекту был присвоен другой тип.
*/
