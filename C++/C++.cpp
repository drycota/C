#include "pch.h"
#include <iostream>
#include "array.h"
#include "function.h"
#include "string.h"
#include "classList.h"
typedef unsigned int uint;

struct Test
{
	char c;
	int i;
};

class Point
{
	double x, y;
public:
	// конструктор с параметрами
	// по умолчанию
	Point(double iX = 1, double iY = 1) {
		x = iX;
		y = iY;
		cout << "\nWhis arguments!!!\n";
	}
	void Show() {
		cout << x << " " << y << "\n";
	}
};


int main()
{
	//int const size = 50;
	//int arr[size], key;
	//initRand(arr, size);
	//printArray1(arr, size);
	//insertSort(arr, size);
	//printArray1(arr, size);
	//cin >> key;
	//cout<<"\n"<<BinarySearch(arr, 50, key);


	int a[] = { 1,2,3 };
	cout << sizeof(a) / sizeof(int) << endl;
	cout << sizeof(a) / sizeof(a[0]);
}