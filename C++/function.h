#pragma once
#include<iostream>
using namespace std;

template <typename T> T Max(T A, T B)
{
	return A > B ? A : B;
}
template <typename T1, typename T2> T2 Max(T1 A, T2 B)
{
	return A > B ? A : B;
}
// �������� �����
int LinearSearch(int array[], int size, int key);  
// �������� ����� ��� �������������� �������
int BinarySearch(int A[], int size, int Key);
// ���������� �������
template <typename T>
void selectSort(T a[], long size)
{
	long i, j, k;
	T x;
	for (i = 0; i < size; i++) 
	{
		k = i;
		x = a[i];
		for (j = i + 1; j < size; j++)
			if (a[j] < x) 
			{
				k = j;
				x = a[j];
			}
		a[k] = a[i];
		a[i] = x;
	}
}
// "�����������" c���������
template <typename T>
void bubbleSort(T a[], long size) 
{
	long i, j;
	T x;
	for (i = 0; i < size; i++) 
	{
		for (j = size - 1; j > i; j--) 
		{ 
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
	}
}
// ������-����������
template <typename T>
void shakerSort(T a[], long size) 
{
	long j, k = size - 1;
	long lb = 1, ub = size - 1; // ������� ����������������� ����� �������
	T x;

	do {
		// ������ ����� ����� 
		for (j = ub; j > 0; j--) {
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				k = j;
			}
		}
		lb = k + 1;

		// ������ ������ ���� 
		for (j = 1; j <= ub; j++) {
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				k = j;
			}
		}
		ub = k - 1;

	} while (lb < ub);
}
// ���������� ���������
template <typename T>
void insertSort(T a[], long size) {
	T x;
	long i, j;

	for (i = 0; i < size; i++) 
	{  // ���� ��������, i - ����� �������
		x = a[i];

		// ����� ����� �������� � ������� ������������������ 
		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];  	// �������� ������� �������, ���� �� �����

	// ����� �������, �������� �������
		a[j + 1] = x;
	}
}
template <typename T>
void setMin(T a[], long size) {
	T min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	a[0] = min;
}
// ���������� ���������2
template <class T>
void insertSortGuarded(T a[], long size) 
{
	T x;
	long i, j;
	T backup = a[0];			// ��������� ������ ������ �������
	setMin(a, size);				// �������� �� �����������

	// ������������� ������
	for (i = 1; i < size; i++) {
		x = a[i];

		for (j = i - 1; a[j] > x; j--)
			a[j + 1] = a[j];

		a[j + 1] = x;
	}

	// �������� backup �� ���������� �����
	for (j = 1; j < size&&a[j] < backup; j++)
		a[j - 1] = a[j];

	// ������� �������� 
	a[j - 1] = backup;
}
// ���������
long int Fact(long int N);
