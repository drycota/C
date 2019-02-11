#pragma once
#include <iostream>
using namespace std;

struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element * Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element * Head;
	// ����� ���������� �������� ������
	Element * Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};