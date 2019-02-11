#pragma once
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void printArray1(int *arr, int length);
template <int row, int col>
void printArray2(char(&arr)[row][col]);
void printRand();
template <typename T> 
void initRand(T *arr, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % 100;
}
void printFig1();
void printFig2();
void printFig3();
void printFig4();
void printFig5();
void printFig6();
void printFig7();
void printFig8();
void printFigAll();
void pointerArray();