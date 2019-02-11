#include "pch.h"
#include "dynamic_structure.h"

// ����
/*
���� - ������������ ��������� ������, �������������� �� ���� ������������� ����� ���������, � ������� ���������� ����� ��������� 
// � �������� ������������ ������������ � ������ �����, ����������� �������� �����.
//  �������� ����������� �� ����� � �������, �������� �� ���������� � ��� ���������, �� ���� ��������� ������� LIFO (Last In First Out) 
// ��� "��������� ������ ������ ����". 
// �������� �������� ��� ������ � ��� ����������.
// 1. ���������� �������� � ����.
// 2. �������� �������� �� �����.
// 3. ��������, ���� �� ����. (���� ��������� "������", ���� ��������� ������� ��������� � ���������� ������ �������.)
// 4. �������� �������� � ������� ����� ��� ��������.
// 5. ������� �����.

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	// ������ � ������� ������� �����
	enum {EMPTY = -1, FULL = 20};

	// ������ ��� �������� ������
	char st[FULL + 1];

	// ��������� �� ������� �����
	int top;

public:
	// �����������
	Stack();

	// ���������� ��������
	void Push(char c);

	// ���������� ��������
	char Pop();

	// ������� �����
	void Clear();

	// �������� ������������� ��������� � �����
	bool IsEmpty();

	// �������� �� ������������ �����
	bool IsFull();

	// ���������� ��������� � �����
	int GetCount();
};

Stack::Stack()
{
	// ���������� ���� ����
	top = EMPTY;
}

void Stack::Clear()
{
	// ����������� "�������" �����
	// (������ � ������� ��� ��� ����������,
	// �� ������� ������, ��������������� �� ������ � �������� �����,
	// ����� �� ������������)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// ����?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// �����?
	return top == FULL;
}

int Stack::GetCount()
{
	// ���������� �������������� � ����� ���������
	return top + 1;
}

void Stack::Push(char c)
{
	// ���� � ����� ���� �����, �� ����������� ���������
	// �� ������� ����� � ��������� ����� �������
	if(!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	// ���� � ����� ���� ��������, �� ���������� ������� �
	// ��������� ��������� �� ������� �����
	if(!IsEmpty())
		return st[top--];
	else // ���� � ����� ��������� ���
		return 0;
}

void main()
{
	srand(time(0));
	Stack ST;
	char c;
	// ���� ���� �� ����������
	while(!ST.IsFull()){
		c=rand()%4+2;
		ST.Push(c);
	}
	// ���� ���� �� �����������
	while(c=ST.Pop()){
			cout<<c<<" ";
	}
	cout<<"\n\n";

}

*/

// �������
/*
// ������� � ��� ���������������� ����� ��������� � ���������� ������. ��� ����, ���������� ��������� � ������� ���������� � ����� �������, 
// � �������� � � ������ �������. ������ ����������� ������������� �� ��������� FIFO (First In � First Out), �� ���� "������ ������ � ������ �����". 
// ��� ������� ������� �������� �������� ������������������ ���������, �� ������� � ������ ������� ������ ������� ���������� ������� ������ 
// ���� ����� ���������������� ���������

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	// �������
	int * Wait;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	Queue(int m);

	//����������
	~Queue();

	// ���������� ��������
	void Add(int c);

	// ���������� ��������
	int Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};

void Queue::Show(){
	cout<<"\n-------------------------------------\n";
	//������������ �������
	for(int i=0;i<QueueLength;i++){
		cout<<Wait[i]<<" ";
	}
	cout<<"\n-------------------------------------\n";
}

Queue::~Queue()
{
	//�������� �������
	delete[]Wait;
}

Queue::Queue(int m)
{
	//�������� ������
	MaxQueueLength=m;
	//������� �������
	Wait=new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

void Queue::Clear()
{
	// ����������� "�������" �������
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

void Queue::Add(int c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if(!IsFull())
		Wait[QueueLength++] = c;
}

int Queue::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���,
	// ������� ����� ������ � �������� �������
	if(!IsEmpty()){
		//��������� ������
		int temp=Wait[0];

		//�������� ��� ��������
		for(int i=1;i<QueueLength;i++)
			Wait[i-1]=Wait[i];

		//��������� ����������
		QueueLength--;

		//������� ������(�������)
		return temp;
	}

	else // ���� � ����� ��������� ���
		return -1;
}

void main()
{
	srand(time(0));

	//�������� �������
	Queue QU(25);

	//���������� ����� ���������
	for(int i=0;i<5;i++){
		QU.Add(rand()%50);
	}
	//����� �������
	QU.Show();

	//���������� ��������
	QU.Extract();

	//����� �������
	QU.Show();
}
*/

// ��������� �������
/*
// ��������� ������� ����� ������ �� ������� �������. ��� ���� ���������� �� ��������� FIFO, ���������� - �������, ������� �������� � ������� ������, 
// ������ �� � �������. ������� ���� � ���, ��� �������, ������� ������� �� ������ �������, ����� ��������� � � �����

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class QueueRing
{
	// �������
	int * Wait;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	QueueRing(int m);

	//����������
	~QueueRing();

	// ���������� ��������
	void Add(int c);

	// ���������� ��������
	bool Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};

void QueueRing::Show(){
	cout<<"\n-------------------------------------\n";
	//������������ �������
	for(int i=0;i<QueueLength;i++){
		cout<<Wait[i]<<" ";
	}
	cout<<"\n-------------------------------------\n";
}

QueueRing::~QueueRing()
{
	//�������� �������
	delete[]Wait;
}

QueueRing::QueueRing(int m)
{
	//�������� ������
	MaxQueueLength=m;
	//������� �������
	Wait=new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

void QueueRing::Clear()
{
	// ����������� "�������" �������
	QueueLength = 0;
}

bool QueueRing::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool QueueRing::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int QueueRing::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

void QueueRing::Add(int c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if(!IsFull())
		Wait[QueueLength++] = c;
}

bool QueueRing::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���,
	// ������� ����� ������ � �������� �������
	if(!IsEmpty()){
		//��������� ������
		int temp=Wait[0];

		//�������� ��� ��������
		for(int i=1;i<QueueLength;i++)
			Wait[i-1]=Wait[i];

		//����������� ������ "����������� ������� � �����"
		Wait[QueueLength-1]=temp;
		return 1;

	}
	else return 0;
}

void main()
{
	srand(time(0));

	//�������� �������
	QueueRing QUR(25);

	//���������� ����� ���������
	for(int i=0;i<5;i++){
		QUR.Add(rand()%50);
	}
	//����� �������
	QUR.Show();

	//���������� ��������
	QUR.Extract();

	//����� �������
	QUR.Show();
}
*/

// ������� � �����������
/*
// ���������� ��������� ����� ������������ ��������: 
// 1. ������� � ������������ ���������� - ������������������ ��������� ������� �������� ������ �������������. ������� �������, ������ ������� 
// ��� ��������� � ������� ����� �� ������������� �������� ������ ����������. � � ������ ���������� �������� ������ ����������� ������� �� ������.
// 2. ������� � ������������ ����������� - ������� ����������� � ����� �������, � ��� ���������� �������������� ������ ������������� ��������, 
// ������� ������������ ��������� �� �������.

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class QueuePriority
{
	// �������
	int * Wait;
	// ���������
	int * Pri;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	QueuePriority(int m);

	//����������
	~QueuePriority();

	// ���������� ��������
	void Add(int c,int p);

	// ���������� ��������
	int Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};

void QueuePriority::Show(){
	cout<<"\n-------------------------------------\n";
	//������������ �������
	for(int i=0;i<QueueLength;i++){
		cout<<Wait[i]<<" - "<<Pri[i]<<"\n\n";
	}
	cout<<"\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	//�������� �������
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	//�������� ������
	MaxQueueLength=m;
	//������� �������
	Wait=new int[MaxQueueLength];
	Pri=new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	// ����������� "�������" �������
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

void QueuePriority::Add(int c,int p)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if(!IsFull()){
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

int QueuePriority::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���,
	// � �������� ��������� ��������� � �������� �������
	if(!IsEmpty()){


		//����� ������������ ������� - �������
		int max_pri=Pri[0];
		//� ������������ ������ = 0
		int pos_max_pri=0;

		//���� ���������
		for(int i=1;i<QueueLength;i++)
			//���� �������� ����� ������������ �������
			if(max_pri<Pri[i]){
				max_pri=Pri[i];
				pos_max_pri=i;
			}

		//����������� ������������ �������
		int temp1=Wait[pos_max_pri];
		int temp2=Pri[pos_max_pri];

		//�������� ��� ��������
		for(int i=pos_max_pri;i<QueueLength-1;i++){
			Wait[i]=Wait[i+1];
			Pri[i]=Pri[i+1];
		}
		//��������� ����������
		QueueLength--;
		// ������� ������������ ��������
		return temp1;

	}
	else return -1;
}

void main()
{
	srand(time(0));

	//�������� �������
	QueuePriority QUP(25);

	//���������� ����� ���������
	for(int i=0;i<5;i++){

		// �������� �� 0 �� 99 (������������)
		// � ��������� �� 0 �� 11 (������������)
		QUP.Add(rand()%100,rand()%12);
	}
	//����� �������
	QUP.Show();

	//���������� ��������
	QUP.Extract();

	//����� �������
	QUP.Show();
}
*/

// ����������� ������
/*
// ����������� ������ - ��� ������������ ���������� ��������, ������ �� ������� ������������ ����� ������� ������, ��������� �� ���� ������. 
// ������ ����� �������� - ��������, ������� �� ������, ������ - ���������� � ��������� �������� ������.
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

List::List()
{
   // ���������� ������ ����
   Head = Tail = NULL;
   Count = 0;
}

List::~List()
{
   // ����� ������� ��������
   DelAll();
}

int List::GetCount()
{
   // ���������� ���������� ���������
   return Count;
}

void List::Add(char data)
{
   // �������� ������ ��������
   Element * temp = new Element;

   // ���������� �������
   temp->data = data;
   // ��������� ������� �����������
   temp->Next = NULL;
   // ����� ������� ���������� ��������� ��������� ������
   // ���� �� �� ������ �����������
   if(Head!=NULL){
		Tail->Next=temp;
		Tail = temp;
   }
   // ����� ������� ���������� ������������
   // ���� �� ������ �����������
   else{
	   Head=Tail=temp;
   }
}

void List::Del()
{
   // ���������� ����� ��������� ��������
   Element * temp = Head;
   // ������������� ������ �� ��������� �������
   Head = Head->Next;
   // ������� ������ �������� �������
   delete temp;
}

void List::DelAll()
{
   // ���� ��� ���� ��������
   while(Head != 0)
	  // ������� �������� �� ������
	  Del();
}

void List::Print()
{
   // ���������� ����� ��������� ��������
   Element * temp = Head;
   // ���� ��� ���� ��������
   while(temp != 0)
   {
	  // ������� ������
	  cout << temp->data << " ";
	  // ��������� �� ��������� �������
	  temp = temp->Next;
   }

   cout << "\n\n";
}

// �������� ������
void main()
{
   // ������� ������ ������ List
   List lst;

   // �������� ������
   char s[] = "Hello, World !!!\n";
   // ������� ������
   cout << s << "\n\n";
   // ���������� ����� ������
   int len = strlen(s);
   // �������� ������ � ������
   for(int i = 0; i < len; i++)
	  lst.Add(s[i]);
   // ������������� ���������� ������
   lst.Print();
   // ������� ��� �������� ������
   lst.Del();
   lst.Del();
   lst.Del();
   //������������� ���������� ������
   lst.Print();
}
*/

// ���������� ������
/*
#include <iostream>
using namespace std;

struct Elem
{
   int data; // ������
   Elem * next, * prev;
};

class List
{
   // ������, �����
   Elem * Head, * Tail;
   // ���������� ���������
   int Count;

public:

   // �����������
   List();
   // ����������� �����������
   List(const List&);
   // ����������
   ~List();

   // �������� ����������
   int GetCount();
   // �������� ������� ������
   Elem* GetElem(int);

   // ������� ���� ������
   void DelAll();
   // �������� ��������, ���� �������� �� �����������,
   // �� ������� ��� �����������
   void Del(int pos = 0);
   // ������� ��������, ���� �������� �� �����������,
   // �� ������� ��� �����������
   void Insert(int pos = 0);

   // ���������� � ����� ������
   void AddTail(int n);

   // ���������� � ������ ������
   void AddHead(int n);

   // ������ ������
   void Print();
   // ������ ������������� ��������
   void Print(int pos);

   List& operator = (const List&);
   // �������� ���� ������� (�����������)
   List operator + (const List&);

   // ��������� �� ���������
   bool operator == (const List&);
   bool operator != (const List&);
   bool operator <= (const List&);
   bool operator >= (const List&);
   bool operator < (const List&);
   bool operator > (const List&);

   // ��������������� ������
   List operator - ();
};

List::List()
{
   // ���������� ������ ����
   Head = Tail = NULL;
   Count = 0;
}

List::List(const List & L)
{
   Head = Tail = NULL;
   Count = 0;

   // ������ ������, �� �������� ��������
   Elem * temp = L.Head;
   // ���� �� ����� ������
   while(temp != 0)
   {
	  // ���������� ������
	  AddTail(temp->data);
	  temp = temp->next;
   }
}

List::~List()
{
   // ������� ��� ��������
   DelAll();
}

void List::AddHead(int n)
{
   // ����� �������
   Elem * temp = new Elem;

   // ����������� ���
   temp->prev = 0;
   // ��������� ������
   temp->data = n;
   // ��������� - ������ ������
   temp->next = Head;

   // ���� �������� ����?
   if(Head != 0)
	  Head->prev = temp;

   // ���� ������� ������, �� �� ������������ � ������ � �����
   if(Count == 0)
	  Head = Tail = temp;
   else
	  // ����� ����� ������� - ��������
	  Head = temp;

   Count++;
}

void List::AddTail(int n)
{
   // ������� ����� �������
   Elem * temp = new Elem;
   // ���������� ���
   temp->next = 0;
   // ��������� ������
   temp->data = n;
   // ���������� - ������ �����
   temp->prev = Tail;

   // ���� �������� ����?
   if(Tail != 0)
	  Tail->next = temp;

   // ���� ������� ������, �� �� ������������ � ������ � �����
   if(Count == 0)
	  Head = Tail = temp;
   else
	  // ����� ����� ������� - ���������
   Tail = temp;

   Count++;
}

void List::Insert(int pos)
{
   // ���� �������� ����������� ��� ����� 0, �� ����������� ���
   if(pos == 0)
   {
	  cout << "Input position: ";
	  cin >> pos;
   }

  // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count + 1)
   {
	  // �������� �������
	  cout << "Incorrect position !!!\n";
	  return;
   }

   // ���� ������� � ����� ������
   if(pos == Count + 1)
   {
	  // ����������� ������
	  int data;
	  cout << "Input new number: ";
	  cin >> data;
	  // ���������� � ����� ������
	  AddTail(data);
	  return;
   }
   else if(pos == 1)
   {
	  // ����������� ������
	  int data;
	  cout << "Input new number: ";
	  cin >> data;
	  // ���������� � ������ ������
	  AddHead(data);
	  return;
   }

   // �������
   int i = 1;

   // ����������� �� ������ n - 1 ���������
   Elem * Ins = Head;

   while(i < pos)
   {
	  // ������� �� ��������,
	  // ����� ������� �����������
	  Ins = Ins->next;
	  i++;
   }

   // ������� �� ��������,
   // ������� ������������
   Elem * PrevIns = Ins->prev;

   // ������� ����� �������
   Elem * temp = new Elem;

   // ������ ������
   cout << "Input new number: ";
   cin >> temp->data;

   // ��������� ������
   if(PrevIns != 0 && Count != 1)
	  PrevIns->next = temp;

   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;

   Count++;
}

void List::Del(int pos)
{
   // ���� �������� ����������� ��� ����� 0, �� ����������� ���
   if(pos == 0)
   {
	   cout << "Input position: ";
	   cin >> pos;
   }
   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
	  // �������� �������
	  cout << "Incorrect position !!!\n";
	  return;
   }

   // �������
   int i = 1;

   Elem * Del = Head;

   while(i < pos)
   {
	  // ������� �� ��������,
	  // ������� ���������
	  Del = Del->next;
	  i++;
   }

   // ������� �� ��������,
   // ������� ������������ ����������
   Elem * PrevDel = Del->prev;
   // ������� �� ��������, ������� ������� �� ���������
   Elem * AfterDel = Del->next;

   // ���� ������� �� ������
   if(PrevDel != 0 && Count != 1)
	  PrevDel->next = AfterDel;
   // ���� ������� �� �����
	if(AfterDel != 0 && Count != 1)
	  AfterDel->prev = PrevDel;

   // ��������� �������?
   if(pos == 1)
	   Head = AfterDel;
   if(pos == Count)
	   Tail = PrevDel;

   // �������� ��������
   delete Del;

   Count--;
}

void List::Print(int pos)
{
   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
	  // �������� �������
	  cout << "Incorrect position !!!\n";
	  return;
   }

   Elem * temp;

   // ���������� � ����� �������
   // ������� ���������
   if(pos <= Count / 2)
   {
	  // ������ � ������
	  temp = Head;
	  int i = 1;

	  while(i < pos)
	  {
		 // ��������� �� ������� ��������
		 temp = temp->next;
		 i++;
	  }
   }
   else
   {
	   // ������ � ������
	  temp = Tail;
	  int i = 1;

	  while(i <= Count - pos)
	  {
		 // ��������� �� ������� ��������
		 temp = temp->prev;
		 i++;
	  }
   }
   // ����� ��������
   cout << pos << " element: ";
   cout << temp->data << endl;
}

void List::Print()
{
   // ���� � ������ ������������ ��������, �� ��������� �� ����
   // � �������� ��������, ������� � ���������
   if(Count != 0)
   {
	  Elem * temp = Head;
	  cout << "( ";
	  while(temp->next != 0)
	  {
		  cout << temp->data << ", ";
		  temp = temp->next;
	  }

	  cout << temp->data << " )\n";
   }
}

void List::DelAll()
{
   // ���� �������� ��������, ������� �� ������ � ������
   while(Count != 0)
	  Del(1);
}

int List::GetCount()
{
	return Count;
}

Elem * List::GetElem(int pos)
{
   Elem *temp = Head;

   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
	  // �������� �������
	  cout << "Incorrect position !!!\n";
	  return 0;
   }

   int i = 1;
   // ���� ������ ��� �������
   while(i < pos && temp != 0)
   {
	  temp = temp->next;
	  i++;
   }

   if(temp == 0)
	  return 0;
   else
	  return temp;
}

List & List::operator = (const List & L)
{
	// �������� ������������ �������� "������ ����"
	if(this == &L)
	   return *this;

   // �������� ������� ������
   this->~List(); // DelAll();

   Elem * temp = L.Head;

   // �������� ��������
   while(temp != 0)
   {
	  AddTail(temp->data);
	  temp = temp->next;
   }

   return *this;
}
// �������� ���� �������
List List::operator + (const List& L)
{
   // ������� �� ��������� ������ �������� ������� ������
   List Result(*this);
   // List Result = *this;

   Elem * temp = L.Head;

   // ��������� �� ��������� ������ �������� ������� ������
   while(temp != 0)
   {
	  Result.AddTail(temp->data);
	  temp = temp->next;
   }

   return Result;
}

bool List::operator == (const List& L)
{
   // ��������� �� ����������
   if(Count != L.Count)
	  return false;

   Elem *t1, *t2;

   t1 = Head;
   t2 = L.Head;

   // ��������� �� ����������
   while(t1 != 0)
   {
	  // ������� ������, �������
	  // ��������� �� ���������� ��������
	  if(t1->data != t2->data)
		 return false;

	  t1 = t1->next;
	  t2 = t2->next;
  }

   return true;
}

bool List::operator != (const List& L)
{
   // ���������� ���������� ������� ���������
   return !(*this == L);
}

bool List::operator >= (const List& L)
{
   // ��������� �� ����������
   if(Count > L.Count)
	  return true;
   // ��������� �� ����������
   if(*this == L)
	  return true;

   return false;
}

bool List::operator <= (const List& L)
{
   // ��������� �� ����������
   if(Count < L.Count)
	  return true;
   // ��������� �� ����������
   if(*this == L)
	   return true;

   return false;
}

bool List::operator > (const List& L)
{
   if(Count > L.Count)
	 return true;

   return false;
}

bool List::operator < (const List& L)
{
   if(Count < L.Count)
	   return true;

   return false;
}

// ���������
List List::operator - ()
{
   List Result;

   Elem * temp = Head;
   // �������� �������� ������, ������� � ���������,
   // � ���� ����� ���������� ��������� � ������,
   // ����� ������� ��������� ������ Result ����� ���������
   // �������� � �������� �������
   while(temp != 0)
   {
	   Result.AddHead(temp->data);
	   temp = temp->next;
   }

   return Result;
}

// �������� ������
void main()
{
   List L;

   const int n = 10;
   int a[n] = {0,1,2,3,4,5,6,7,8,9};

   // ��������� ��������, ������� �� ������ ��������, � ������,
   // �� �������� - � �����
   for(int i = 0; i < n; i++)
	  if(i % 2 == 0)
		 L.AddHead(a[i]);
	  else
		 L.AddTail(a[i]);

   // ���������� ������
   cout << "List L:\n";
   L.Print();

   cout << endl;

   // ������� �������� � ������
   L.Insert();
   // ���������� ������
   cout << "List L:\n";
   L.Print();

   // ���������� 2-�� � 8-�� ��������� ������
   L.Print(2);
   L.Print(8);

   List T;

   // �������� ������
   T = L;
   // ���������� �����
   cout << "List T:\n";
   T.Print();

   // ���������� ��� ������ (������ � ������������ ���������)
   cout << "List Sum:\n";
   List Sum = -L + T;
   // ���������� ������
   Sum.Print();
}
*/

// ��������� ���������� ������
/*
#include <iostream>
using namespace std;

template <typename T>
struct Elem
{
   // ����� ������
   T data;
   Elem * next, * prev;
};

template <typename T>
class List
{
   // ������ �����
   Elem<T> * Head, * Tail;
   int Count;

public:

   List();
   List(const List&);
   ~List();

   int GetCount();
   Elem<T>* GetElem(int);

   void DelAll();
   void Del(int);
   void Del();

   void AddTail();
   void AddTail(T);

   void AddHead(T);
   void AddHead();

   void Print();
   void Print(int pos);

   List& operator = (const List&);
   List operator + (const List&);

   bool operator == (const List&);
   bool operator != (const List&);
   bool operator <= (const List&);
   bool operator >= (const List&);
   bool operator < (const List&);
   bool operator > (const List&);

   List operator - ();
};

template <typename T>
List<T>::List()
{
   Head = Tail = 0;
   Count = 0;
}

template <typename T>
List<T>::List(const List & L)
{
   Head = Tail = 0;
   Count = 0;

   Elem<T> * temp = L.Head;
   while(temp != 0)
   {
	  AddTail(temp->data);
	  temp = temp->next;
   }
}

template <typename T>
List<T>::~List()
{
   DelAll();
}

template <typename T>
Elem<T>* List<T>::GetElem(int pos)
{
   Elem<T> *temp = Head;

   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
	  // �������� �������
	  cout << "Incorrect position !!!\n";
	  return;
   }

   int i = 1;
   while(i < pos && temp != 0)
   {
	  temp = temp->next;
	  i++;
   }

   if(temp == 0)
	  return 0;
   else
	  return temp;
}

template <typename T>
void List<T>::AddHead()
{
   Elem<T> * temp = new Elem<T>;

   temp->prev = 0;

   int n;
   cout << "Input new number: ";
   cin >> n;

   temp->data = n;

   temp->next = Head;

   if(Head != 0)
	  Head->prev = temp;

   if(Count == 0)
	  Head = Tail = temp;
   else
	  Head = temp;

   Count++;
}

template <typename T>
void List<T>::AddHead(T n)
{
   Elem<T> * temp = new Elem<T>;

   temp->prev = 0;
   temp->data = n;
   temp->next = Head;

   if(Head != 0)
	  Head->prev = temp;

   if(Count == 0)
	  Head = Tail = temp;
   else
	  Head = temp;

   Count++;
}

template <typename T>
void List<T>::AddTail()
{
   Elem<T> * temp = new Elem<T>;

   temp->next = 0;
   int n;
   cout << "Input new number: ";
   cin >> n;

   temp->data = n;
   temp->prev = Tail;

   if(Tail != 0)
	  Tail->next = temp;

   if(Count == 0)
	  Head = Tail = temp;
   else
	  Tail = temp;

   Count++;
}

template <typename T>
void List<T>::AddTail(T n)
{
   Elem<T> * temp = new Elem<T>;

   temp->next = 0;
   temp->data = n;
   temp->prev = Tail;

   if(Tail != 0)
	  Tail->next = temp;

   if(Count == 0)
	  Head = Tail = temp;
   else
	  Tail = temp;

   Count++;
}

template <typename T>
void List<T>::Del()
{
   int n;
   cout << "Input position: ";
   cin >> n;

   if(n < 1 || n > Count)
   {
	  cout << "Incorrect position !!!\n";
	  return;
   }

   int i = 1;
   Elem<T> * Del = Head;

   while(i <= n)
   {
	  // ������� �� ��������, ������� ���������
	  Del = Del->next;
	  i++;
   }

   // ������� �� ��������, ������� ������������ ����������
   Elem<T> * PrevDel = Del->prev;
   // ������� �� ��������, ������� ������� �� ���������
   Elem<T> * AfterDel = Del->next;

   if(PrevDel != 0 && Count != 1)
	  PrevDel->next = AfterDel;

   if(AfterDel != 0 && Count != 1)
	  AfterDel->prev = PrevDel;

   if(n == 1)
	  Head = AfterDel;
   if(n == Count)
	  Tail = PrevDel;

   delete Del;

   Count--;
}

template <typename T>
void List<T>::Del(int n)
{
   if(n < 1 || n > Count)
   {
	  cout << "Incorrect position !!!\n";
	  return;
   }

   int i = 1;
   Elem<T> * Del = Head;

   while(i < n)
   {
	  // ������� �� ��������, ������� ���������
	  Del = Del->next;
	  i++;
   }

   // ������� �� ��������, ������� ������������ ����������
   Elem<T> * PrevDel = Del->prev;
   // ������� �� ��������, ������� ������� �� ���������
   Elem<T> * AfterDel = Del->next;

   if(PrevDel != 0 && Count != 1)
	  PrevDel->next = AfterDel;

   if(AfterDel != 0 && Count != 1)
	  AfterDel->prev = PrevDel;

   if(n == 1)
	  Head = AfterDel;
   if(n == Count)
	  Tail = PrevDel;

   delete Del;

   Count--;
}

template <typename T>
void List<T>::Print(int pos)
{
   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
	  // �������� �������
	  cout << "Incorrect position !!!\n";
	  return;
   }

   Elem<T> * temp;

   // ���������� � ����� �������
   // ������� ���������
   if(pos <= Count / 2)
   {
	  // ������ � ������
	  temp = Head;
	  int i = 1;

	  while(i < pos)
	  {
		 // ��������� �� ������� ��������
		 temp = temp->next;
		 i++;
	  }
   }
   else
   {
	  // ������ � ������
	  temp = Tail;
	  int i = 1;

	  while(i <= Count - pos)
	  {
		 // ��������� �� ������� ��������
		 temp = temp->prev;
		 i++;
	  }
   }
   // ����� ��������
   cout << pos << " element: ";
   cout << temp->data << "\n";
}

template <typename T>
void List<T>::Print()
{
   if(Count != 0)
   {
	  Elem<T> * temp = Head;
	  while(temp != 0)
	  {
		 cout << temp->data << "\n";
		 temp = temp->next;
	  }
   }
}

template <typename T>
void List<T>::DelAll()
{
   while(Count != 0)
	  Del(1);
}

template <typename T>
int List<T>::GetCount()
{
   return Count;
}

template <typename T>
List<T>& List<T>::operator = (const List<T> & L)
{
   if(this == &L)
	  return *this;

   this->~List();

   Elem<T> * temp = L.Head;

   while(temp != 0)
   {
	  AddTail(temp->data);
	  temp = temp->next;
   }

   return *this;
}

template <typename T>
List<T> List<T>::operator + (const List<T>& L)
{
   List Result(*this);

   Elem<T> * temp = L.Head;

   while(temp != 0)
   {
	  Result.AddTail(temp->data);
	  temp = temp->next;
   }

   return Result;
}

template <typename T>
bool List<T>::operator == (const List<T>& L)
{
   if(Count != L.Count)
	  return false;

   Elem<T> *t1, *t2;

   t1 = Head;
   t2 = L.Head;

   while(t1 != 0)
   {
	  if(t1->data != t2->data)
		 return false;

	  t1 = t1->next;
	  t2 = t2->next;
   }

   return true;
}

template <typename T>
bool List<T>::operator != (const List& L)
{
   if(Count != L.Count)
	  return true;

   Elem<T> *t1, *t2;

   t1 = Head;
   t2 = L.Head;

   while(t1 != 0)
   {
	  if(t1->data != t2->data)
		 return true;

	  t1 = t1->next;
	  t2 = t2->next;
   }

   return false;
}

template <typename T>
bool List<T>::operator >= (const List& L)
{
   if(Count > L.Count)
	  return true;

   if(*this == L)
	  return true;

   return false;
}

template <typename T>
bool List<T>::operator <= (const List& L)
{
   if(Count < L.Count)
	  return true;

   if(*this == L)
	  return true;

   return false;
}

template <typename T>
bool List<T>::operator > (const List& L)
{
   if(Count > L.Count)
	  return true;

   return false;
}

template <typename T>
bool List<T>::operator < (const List& L)
{
   if(Count < L.Count)
	  return true;

   return false;
}

template <typename T>
List<T> List<T>::operator - ()
{
   List Result;
   Elem<T> * temp = Head;

   while(temp != 0)
   {
	  Result.AddHead(temp->data);
	  temp = temp->next;
   }

   return Result;
}

// �������� ������
void main()
{
   List <int> L;

   const int n = 10;
   int a[n] = {0,1,2,3,4,5,6,7,8,9};

   // ��������� ��������, ������� �� ������ ��������, � ������,
   // �� �������� - � �����
   for(int i = 0; i < n; i++)
	  if(i % 2 == 0)
		 L.AddHead(a[i]);
	  else
		 L.AddTail(a[i]);

   // ���������� ������
   cout << "List L:\n";
   L.Print();

   cout << "\n\n";

   // ���������� ������
   cout << "List L:\n";
   L.Print();

   // ���������� 2-�� � 8-�� ��������� ������
   L.Print(2);
   L.Print(8);

   List <int> T;

   // �������� ������
   T = L;
   // ���������� �����
   cout << "List T:\n";
   T.Print();

   // ���������� ��� ������ (������ � ������������ ���������)
   cout << "List Sum:\n";
   List <int> Sum = -L + T;
   // ���������� ������
   Sum.Print();
}
*/

// �������� ������
/*
// �������� ������ (binary tree) - ��� ������������� ����������� ������������ ���������. ������ ������� (����) ������ ����� �� ����� 
// ���� ��������� ��������� �� ��� (��������) � �� ����� ������ ����������� (��������)

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;
struct Elem
{
   int  OwnerPoints;		// ���� �������
   int  OppPoints;		// ���� ���������
   char Match[10];		// ����
   char Name[20];		// �������
   char Opponent[20];		// ��������

   Elem * left, * right, * parent;
};

class Tree
{
   // ������
   Elem * root;
public:
   Tree();
   ~Tree();
   // ������ �� ���������� ����
   void Print(Elem * Node);
   // ����� �� ���������� ����
   Elem * Search(Elem * Node, char * key);
   // min �� ���������� ����
   Elem * Min(Elem * Node);
   // max �� ���������� ����
   Elem * Max(Elem * Node);
   // ��������� ��� ���������� ����
   Elem * Next(Elem * Node);
   // ���������� ��� ���������� ����
   Elem * Previous(Elem * Node);
   // ������� ����
   void Insert(Elem * z);
   // �������� ����� ��� ���������� ����,
   // 0 - �������� ����� ������
   void Del(Elem * z = 0);
   // �������� ������
   Elem * GetRoot();
};

Tree::Tree()
{
   root = NULL;
}

Tree::~Tree()
{
   Del();
}

// ����������� ����� ������
void Tree::Print(Elem * Node)
{
   if(Node != 0)
   {
	  Print(Node->left);
	  cout << Node->Name
			   << Node->Match
			   << Node->Opponent
			   << endl;
	  Print(Node->right);
   }
}

Elem * Tree::Search(Elem * Node, char * k)
{
   // ���� ���� ���� � ����� �� ���������
   while(Node != 0 && strcmp(k, Node->Name) != 0)
   {
	  if(strcmp(k, Node->Name) < 0)
		 Node = Node->left;
	  else
		 Node = Node->right;
   }
   return Node;
}

Elem * Tree::Min(Elem * Node)
{
   // ����� ������ "������" ����
   if(Node != 0)
	  while(Node->left != 0)
		 Node = Node->left;

   return Node;
}

Elem * Tree::Max(Elem * Node)
{
   // ����� ������ "�������" ����
   if(Node != 0)
	  while(Node->right != 0)
		 Node = Node->right;

   return Node;
}

Elem * Tree::Next(Elem * Node)
{
   Elem * y = 0;
   if(Node != 0)
   {
	  // ���� ���� ������ �������
	  if(Node->right != 0)
		 return Min(Node->right);

	  // �������� ����
	  y = Node->parent;
	  // ���� Node �� ������ � Node ������
	  while(y != 0 && Node == y->right)
	  {
		 // �������� �����
		 Node = y;
		 y = y->parent;
	  }
   }
   return y;
}

Elem * Tree::Previous(Elem * Node)
{
   Elem * y = 0;
   if(Node != 0)
   {
	  // ���� ���� ����� �������
	  if(Node->left != 0)
		 return Max(Node->left);

	  // �������� ����
	  y = Node->parent;
	  // ���� Node �� ������ � Node �����
	  while(y != 0 && Node == y->left)
	  {
		 // �������� �����
		 Node = y;
		 y = y->parent;
	  }
   }
   return y;
}

Elem * Tree::GetRoot()
{
   return root;
}

void Tree::Insert(Elem * z)
{
   // �������� ���
   z->left = NULL;
   z->right = NULL;

   Elem * y = NULL;
   Elem * Node = root;

   // ����� �����
   while(Node != 0)
   {
	  // ������� ��������
	  y = Node;
	  if(strcmp(z->Name, Node->Name) < 0)
		 Node = Node->left;
	  else
		 Node = Node->right;
   }
   // ��������� ��������
   z->parent = y;

   if(y == 0) // ������� ������ (������������)
	  root = z;
   // ��� ���� ������?
   else if(strcmp(z->Name, y->Name) < 0)
	  y->left = z;
   else
	  y->right = z;
}

void Tree::Del(Elem * z)
{
   // �������� �����
   if(z != 0)
   {
	  Elem * Node, * y;

	  // �� 2 �������
	  if(z->left == 0 || z->right == 0)
		 y = z;
	  else
		 y = Next(z);

	  if(y->left != 0)
		 Node = y->left;
	  else
		 Node = y->right;

	  if(Node != 0)
		 Node->parent = y->parent;
	  // ��������� �������� ����?
	  if(y->parent == 0)
		 root = Node;
	  else if(y == y->parent->left) // ����� �� ��������?
		 y->parent->left = Node;
	  else
		 y->parent->right = Node;  // ������ �� ��������?

	  if(y != z)
	  {
		 // ����������� ������ ����
		 strcpy(z->Name, y->Name);
		 strcpy(z->Opponent, y->Opponent);
		 strcpy(z->Match, y->Match);
		 z->OppPoints = y->OppPoints;
		 z->OwnerPoints = y->OwnerPoints;
	  }

	  delete y;
   }
   else // �������� ����� ������
	  while(root != 0)
		 Del(root);
}





// ��������� �������
Tree tournament;

void Game(char Commands[][20], int N)
{
   int i, j;
   int p1, p2; // ����

   // ������ ������� ������ � ������ �� 2 ���� - ���� � � ������
   int k;

   Elem * temp;
   for(k = 0; k < 2; k++)
	  for(i = 0; i < N - 1; i++)
	  {
		 for(j = i + 1; j < N; j++)
		 {
			temp = new Elem;
			if(k == 0)
			{
			   // 1 ����
			   strcpy(temp->Name, Commands[i]);
			   strcpy(temp->Opponent, Commands[j]);
			}
			else
			{
			   // 2 ����
			   strcpy(temp->Name, Commands[j]);
			   strcpy(temp->Opponent, Commands[i]);
			}

			p1 = rand() % 6;
			p2 = rand() % 6;

			if(p1 > p2)
			{
			   temp->OwnerPoints = 3;
			   temp->OppPoints = 0;
			}
			else if(p1 == p2)
			{
			   temp->OwnerPoints = 1;
			   temp->OppPoints = 1;
			}
			else
			{
			   temp->OwnerPoints = 0;
			   temp->OppPoints = 3;
			}

			// ������ �����
			sprintf(temp->Match, " %d : %d ", p1, p2);
			// ���������� ������
			tournament.Insert(temp);
		 }
	  }
}

void main()
{
   srand(time(0));

   const int N = 4;
   char Commands[4][20] =
   {
	  "Arsenal",
	  "Liverpool",
	  "Lids United",
	  "Manchester United"
   };

   // ����
   Game(Commands, N);
   // ����� �����������
   tournament.Print(tournament.GetRoot());
}
*/

