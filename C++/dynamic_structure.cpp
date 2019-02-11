#include "pch.h"
#include "dynamic_structure.h"

// Стек
/*
Стек - динамическая структура данных, представляющая из себя упорядоченный набор элементов, в которой добавление новых элементов 
// и удаление существующих производится с одного конца, называемого вершиной стека.
//  элементы извлекаются из стека в порядке, обратном их добавлению в эту структуру, то есть действует принцип LIFO (Last In First Out) 
// или "последний пришёл первый ушёл". 
// Основные операции над стеком и его элементами.
// 1. Добавление элемента в стек.
// 2. Удаление элемента из стека.
// 3. Проверка, пуст ли стек. (Стек считается "пустым", если указатель вершины совпадает с указателем нижней границы.)
// 4. Просмотр элемента в вершине стека без удаления.
// 5. Очистка стека.

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	// Нижняя и верхняя границы стека
	enum {EMPTY = -1, FULL = 20};

	// Массив для хранения данных
	char st[FULL + 1];

	// Указатель на вершину стека
	int top;

public:
	// Конструктор
	Stack();

	// Добавление элемента
	void Push(char c);

	// Извлечение элемента
	char Pop();

	// Очистка стека
	void Clear();

	// Проверка существования элементов в стеке
	bool IsEmpty();

	// Проверка на переполнение стека
	bool IsFull();

	// Количество элементов в стеке
	int GetCount();
};

Stack::Stack()
{
	// Изначально стек пуст
	top = EMPTY;
}

void Stack::Clear()
{
	// Эффективная "очистка" стека
	// (данные в массиве все еще существуют,
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// Полон?
	return top == FULL;
}

int Stack::GetCount()
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(char c)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if(!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if(!IsEmpty())
		return st[top--];
	else // Если в стеке элементов нет
		return 0;
}

void main()
{
	srand(time(0));
	Stack ST;
	char c;
	// пока стек не заполнится
	while(!ST.IsFull()){
		c=rand()%4+2;
		ST.Push(c);
	}
	// пока стек не освободится
	while(c=ST.Pop()){
			cout<<c<<" ";
	}
	cout<<"\n\n";

}

*/

// Очередь
/*
// Очередь — это последовательный набор элементов с переменной длиной. При этом, добавление элементов в очередь происходит с одной стороны, 
// а удаление — с другой стороны. Данная конструкция функционирует по идеологии FIFO (First In — First Out), то есть "первым пришел — первым вышел". 
// Для очереди принято выделять конечную последовательность элементов, из которых в каждый текущий момент времени элементами очереди заняты 
// лишь часть последовательных элементов

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	// Очередь
	int * Wait;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	Queue(int m);

	//Деструктор
	~Queue();

	// Добавление элемента
	void Add(int c);

	// Извлечение элемента
	int Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};

void Queue::Show(){
	cout<<"\n-------------------------------------\n";
	//демонстрация очереди
	for(int i=0;i<QueueLength;i++){
		cout<<Wait[i]<<" ";
	}
	cout<<"\n-------------------------------------\n";
}

Queue::~Queue()
{
	//удаление очереди
	delete[]Wait;
}

Queue::Queue(int m)
{
	//получаем размер
	MaxQueueLength=m;
	//создаем очередь
	Wait=new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void Queue::Clear()
{
	// Эффективная "очистка" очереди
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void Queue::Add(int c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if(!IsFull())
		Wait[QueueLength++] = c;
}

int Queue::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот,
	// который вошел первым и сдвигаем очередь
	if(!IsEmpty()){
		//запомнить первый
		int temp=Wait[0];

		//сдвинуть все элементы
		for(int i=1;i<QueueLength;i++)
			Wait[i-1]=Wait[i];

		//уменьшить количество
		QueueLength--;

		//вернуть первый(нулевой)
		return temp;
	}

	else // Если в стеке элементов нет
		return -1;
}

void main()
{
	srand(time(0));

	//создание очереди
	Queue QU(25);

	//заполнение части элементов
	for(int i=0;i<5;i++){
		QU.Add(rand()%50);
	}
	//показ очереди
	QU.Show();

	//извлечение элемента
	QU.Extract();

	//показ очереди
	QU.Show();
}
*/

// Кольцевая очередь
/*
// Кольцевая очередь очень похожа на простую очередь. Она тоже построенна на идеологии FIFO, напоминаем - элемент, который добавили в очередь первым, 
// первым ее и покинет. Разница лишь в том, что элемент, который выходит из начала очереди, будет перемещён в её конец

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class QueueRing
{
	// Очередь
	int * Wait;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueueRing(int m);

	//Деструктор
	~QueueRing();

	// Добавление элемента
	void Add(int c);

	// Извлечение элемента
	bool Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};

void QueueRing::Show(){
	cout<<"\n-------------------------------------\n";
	//демонстрация очереди
	for(int i=0;i<QueueLength;i++){
		cout<<Wait[i]<<" ";
	}
	cout<<"\n-------------------------------------\n";
}

QueueRing::~QueueRing()
{
	//удаление очереди
	delete[]Wait;
}

QueueRing::QueueRing(int m)
{
	//получаем размер
	MaxQueueLength=m;
	//создаем очередь
	Wait=new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void QueueRing::Clear()
{
	// Эффективная "очистка" очереди
	QueueLength = 0;
}

bool QueueRing::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool QueueRing::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int QueueRing::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void QueueRing::Add(int c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if(!IsFull())
		Wait[QueueLength++] = c;
}

bool QueueRing::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот,
	// который вошел первым и сдвигаем очередь
	if(!IsEmpty()){
		//запомнить первый
		int temp=Wait[0];

		//сдвинуть все элементы
		for(int i=1;i<QueueLength;i++)
			Wait[i-1]=Wait[i];

		//забрасываем первый "вытолкнутый элемент в конец"
		Wait[QueueLength-1]=temp;
		return 1;

	}
	else return 0;
}

void main()
{
	srand(time(0));

	//создание очереди
	QueueRing QUR(25);

	//заполнение части элементов
	for(int i=0;i<5;i++){
		QUR.Add(rand()%50);
	}
	//показ очереди
	QUR.Show();

	//извлечение элемента
	QUR.Extract();

	//показ очереди
	QUR.Show();
}
*/

// Очередь с приоритетом
/*
// Существует несколько видов приоритетных очередей: 
// 1. Очередь с приоритетным включением - последовательность элементов очереди является строго упорядоченной. Другими словами, каждый элемент 
// при попадании в очередь сразу же располагается согласно своего приоритета. А в момент исключения элемента просто извлекается элемент из начала.
// 2. Очереди с приоритетным исключением - элемент добавляется в конец очереди, а при извлечении осуществляется самого приоритетного элемента, 
// который впоследствии удаляется из очереди.

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class QueuePriority
{
	// Очередь
	int * Wait;
	// Приоритет
	int * Pri;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueuePriority(int m);

	//Деструктор
	~QueuePriority();

	// Добавление элемента
	void Add(int c,int p);

	// Извлечение элемента
	int Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};

void QueuePriority::Show(){
	cout<<"\n-------------------------------------\n";
	//демонстрация очереди
	for(int i=0;i<QueueLength;i++){
		cout<<Wait[i]<<" - "<<Pri[i]<<"\n\n";
	}
	cout<<"\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength=m;
	//создаем очередь
	Wait=new int[MaxQueueLength];
	Pri=new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	// Эффективная "очистка" очереди
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void QueuePriority::Add(int c,int p)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if(!IsFull()){
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

int QueuePriority::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот,
	// у которого наивысший приоритет и сдвигаем очередь
	if(!IsEmpty()){


		//пусть приоритетный элемент - нулевой
		int max_pri=Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri=0;

		//ищем приоритет
		for(int i=1;i<QueueLength;i++)
			//если встречен более приоритетный элемент
			if(max_pri<Pri[i]){
				max_pri=Pri[i];
				pos_max_pri=i;
			}

		//вытаскиваем приоритетный элемент
		int temp1=Wait[pos_max_pri];
		int temp2=Pri[pos_max_pri];

		//сдвинуть все элементы
		for(int i=pos_max_pri;i<QueueLength-1;i++){
			Wait[i]=Wait[i+1];
			Pri[i]=Pri[i+1];
		}
		//уменьшаем количество
		QueueLength--;
		// возврат извлеченного элемента
		return temp1;

	}
	else return -1;
}

void main()
{
	srand(time(0));

	//создание очереди
	QueuePriority QUP(25);

	//заполнение части элементов
	for(int i=0;i<5;i++){

		// значения от 0 до 99 (включительно)
		// и приоритет от 0 до 11 (включительно)
		QUP.Add(rand()%100,rand()%12);
	}
	//показ очереди
	QUP.Show();

	//извлечение элемента
	QUP.Extract();

	//показ очереди
	QUP.Show();
}
*/

// Односвязный список
/*
// Односвязный список - это совокупность нескольких объектов, каждый из которых представляет собой элемент списка, состоящий из двух частей. 
// Первая часть элемента - значение, которое он хранит, вторая - информация о следующем элементе списка.
#include <iostream>
using namespace std;


struct Element
{
   // Данные
   char data;
   // Адрес следующего элемента списка
   Element * Next;
};

// Односвязный список
class List
{
   // Адрес головного элемента списка
   Element * Head;
   // Адрес хвостового элемента списка
   Element * Tail;
   // Количество элементов списка
   int Count;

public:
   // Конструктор
   List();
   // Деструктор
   ~List();

   // Добавление элемента в список
   // (Новый элемент становится последним)
   void Add(char data);

   // Удаление элемента списка
   // (Удаляется головной элемент)
   void Del();
   // Удаление всего списка
   void DelAll();

   // Распечатка содержимого списка
   // (Распечатка начинается с головного элемента)
   void Print();

   // Получение количества элементов, находящихся в списке
   int GetCount();
};

List::List()
{
   // Изначально список пуст
   Head = Tail = NULL;
   Count = 0;
}

List::~List()
{
   // Вызов функции удаления
   DelAll();
}

int List::GetCount()
{
   // Возвращаем количество элементов
   return Count;
}

void List::Add(char data)
{
   // создание нового элемента
   Element * temp = new Element;

   // заполнение данными
   temp->data = data;
   // следующий элемент отсутствует
   temp->Next = NULL;
   // новый элемент становится последним элементом списка
   // если он не первый добавленный
   if(Head!=NULL){
		Tail->Next=temp;
		Tail = temp;
   }
   // новый элемент становится единственным
   // если он первый добавленный
   else{
	   Head=Tail=temp;
   }
}

void List::Del()
{
   // запоминаем адрес головного элемента
   Element * temp = Head;
   // перебрасываем голову на следующий элемент
   Head = Head->Next;
   // удаляем бывший головной элемент
   delete temp;
}

void List::DelAll()
{
   // Пока еще есть элементы
   while(Head != 0)
	  // Удаляем элементы по одному
	  Del();
}

void List::Print()
{
   // запоминаем адрес головного элемента
   Element * temp = Head;
   // Пока еще есть элементы
   while(temp != 0)
   {
	  // Выводим данные
	  cout << temp->data << " ";
	  // Переходим на следующий элемент
	  temp = temp->Next;
   }

   cout << "\n\n";
}

// Тестовый пример
void main()
{
   // Создаем объект класса List
   List lst;

   // Тестовая строка
   char s[] = "Hello, World !!!\n";
   // Выводим строку
   cout << s << "\n\n";
   // Определяем длину строки
   int len = strlen(s);
   // Загоняем строку в список
   for(int i = 0; i < len; i++)
	  lst.Add(s[i]);
   // Распечатываем содержимое списка
   lst.Print();
   // Удаляем три элемента списка
   lst.Del();
   lst.Del();
   lst.Del();
   //Распечатываем содержимое списка
   lst.Print();
}
*/

// Двусвязный список
/*
#include <iostream>
using namespace std;

struct Elem
{
   int data; // данные
   Elem * next, * prev;
};

class List
{
   // Голова, хвост
   Elem * Head, * Tail;
   // Количество элементов
   int Count;

public:

   // Конструктор
   List();
   // Конструктор копирования
   List(const List&);
   // Деструктор
   ~List();

   // Получить количество
   int GetCount();
   // Получить элемент списка
   Elem* GetElem(int);

   // Удалить весь список
   void DelAll();
   // Удаление элемента, если параметр не указывается,
   // то функция его запрашивает
   void Del(int pos = 0);
   // Вставка элемента, если параметр не указывается,
   // то функция его запрашивает
   void Insert(int pos = 0);

   // Добавление в конец списка
   void AddTail(int n);

   // Добавление в начало списка
   void AddHead(int n);

   // Печать списка
   void Print();
   // Печать определенного элемента
   void Print(int pos);

   List& operator = (const List&);
   // сложение двух списков (дописывание)
   List operator + (const List&);

   // сравнение по элементам
   bool operator == (const List&);
   bool operator != (const List&);
   bool operator <= (const List&);
   bool operator >= (const List&);
   bool operator < (const List&);
   bool operator > (const List&);

   // переворачивание списка
   List operator - ();
};

List::List()
{
   // Изначально список пуст
   Head = Tail = NULL;
   Count = 0;
}

List::List(const List & L)
{
   Head = Tail = NULL;
   Count = 0;

   // Голова списка, из которого копируем
   Elem * temp = L.Head;
   // Пока не конец списка
   while(temp != 0)
   {
	  // Передираем данные
	  AddTail(temp->data);
	  temp = temp->next;
   }
}

List::~List()
{
   // Удаляем все элементы
   DelAll();
}

void List::AddHead(int n)
{
   // новый элемент
   Elem * temp = new Elem;

   // Предыдущего нет
   temp->prev = 0;
   // Заполняем данные
   temp->data = n;
   // Следующий - бывшая голова
   temp->next = Head;

   // Если элементы есть?
   if(Head != 0)
	  Head->prev = temp;

   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
	  Head = Tail = temp;
   else
	  // иначе новый элемент - головной
	  Head = temp;

   Count++;
}

void List::AddTail(int n)
{
   // Создаем новый элемент
   Elem * temp = new Elem;
   // Следующего нет
   temp->next = 0;
   // Заполняем данные
   temp->data = n;
   // Предыдущий - бывший хвост
   temp->prev = Tail;

   // Если элементы есть?
   if(Tail != 0)
	  Tail->next = temp;

   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
	  Head = Tail = temp;
   else
	  // иначе новый элемент - хвостовой
   Tail = temp;

   Count++;
}

void List::Insert(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
	  cout << "Input position: ";
	  cin >> pos;
   }

  // Позиция от 1 до Count?
   if(pos < 1 || pos > Count + 1)
   {
	  // Неверная позиция
	  cout << "Incorrect position !!!\n";
	  return;
   }

   // Если вставка в конец списка
   if(pos == Count + 1)
   {
	  // Вставляемые данные
	  int data;
	  cout << "Input new number: ";
	  cin >> data;
	  // Добавление в конец списка
	  AddTail(data);
	  return;
   }
   else if(pos == 1)
   {
	  // Вставляемые данные
	  int data;
	  cout << "Input new number: ";
	  cin >> data;
	  // Добавление в начало списка
	  AddHead(data);
	  return;
   }

   // Счетчик
   int i = 1;

   // Отсчитываем от головы n - 1 элементов
   Elem * Ins = Head;

   while(i < pos)
   {
	  // Доходим до элемента,
	  // перед которым вставляемся
	  Ins = Ins->next;
	  i++;
   }

   // Доходим до элемента,
   // который предшествует
   Elem * PrevIns = Ins->prev;

   // Создаем новый элемент
   Elem * temp = new Elem;

   // Вводим данные
   cout << "Input new number: ";
   cin >> temp->data;

   // настройка связей
   if(PrevIns != 0 && Count != 1)
	  PrevIns->next = temp;

   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;

   Count++;
}

void List::Del(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
	   cout << "Input position: ";
	   cin >> pos;
   }
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
	  // Неверная позиция
	  cout << "Incorrect position !!!\n";
	  return;
   }

   // Счетчик
   int i = 1;

   Elem * Del = Head;

   while(i < pos)
   {
	  // Доходим до элемента,
	  // который удаляется
	  Del = Del->next;
	  i++;
   }

   // Доходим до элемента,
   // который предшествует удаляемому
   Elem * PrevDel = Del->prev;
   // Доходим до элемента, который следует за удаляемым
   Elem * AfterDel = Del->next;

   // Если удаляем не голову
   if(PrevDel != 0 && Count != 1)
	  PrevDel->next = AfterDel;
   // Если удаляем не хвост
	if(AfterDel != 0 && Count != 1)
	  AfterDel->prev = PrevDel;

   // Удаляются крайние?
   if(pos == 1)
	   Head = AfterDel;
   if(pos == Count)
	   Tail = PrevDel;

   // Удаление элемента
   delete Del;

   Count--;
}

void List::Print(int pos)
{
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
	  // Неверная позиция
	  cout << "Incorrect position !!!\n";
	  return;
   }

   Elem * temp;

   // Определяем с какой стороны
   // быстрее двигаться
   if(pos <= Count / 2)
   {
	  // Отсчет с головы
	  temp = Head;
	  int i = 1;

	  while(i < pos)
	  {
		 // Двигаемся до нужного элемента
		 temp = temp->next;
		 i++;
	  }
   }
   else
   {
	   // Отсчет с хвоста
	  temp = Tail;
	  int i = 1;

	  while(i <= Count - pos)
	  {
		 // Двигаемся до нужного элемента
		 temp = temp->prev;
		 i++;
	  }
   }
   // Вывод элемента
   cout << pos << " element: ";
   cout << temp->data << endl;
}

void List::Print()
{
   // Если в списке присутствуют элементы, то пробегаем по нему
   // и печатаем элементы, начиная с головного
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
   // Пока остаются элементы, удаляем по одному с головы
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

   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
	  // Неверная позиция
	  cout << "Incorrect position !!!\n";
	  return 0;
   }

   int i = 1;
   // Ищем нужный нам элемент
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
	// Проверка присваивания элемента "самому себе"
	if(this == &L)
	   return *this;

   // удаление старого списка
   this->~List(); // DelAll();

   Elem * temp = L.Head;

   // Копируем элементы
   while(temp != 0)
   {
	  AddTail(temp->data);
	  temp = temp->next;
   }

   return *this;
}
// сложение двух списков
List List::operator + (const List& L)
{
   // Заносим во временный список элементы первого списка
   List Result(*this);
   // List Result = *this;

   Elem * temp = L.Head;

   // Добавляем во временный список элементы второго списка
   while(temp != 0)
   {
	  Result.AddTail(temp->data);
	  temp = temp->next;
   }

   return Result;
}

bool List::operator == (const List& L)
{
   // Сравнение по количеству
   if(Count != L.Count)
	  return false;

   Elem *t1, *t2;

   t1 = Head;
   t2 = L.Head;

   // Сравнение по содержанию
   while(t1 != 0)
   {
	  // Сверяем данные, которые
	  // находятся на одинаковых позициях
	  if(t1->data != t2->data)
		 return false;

	  t1 = t1->next;
	  t2 = t2->next;
  }

   return true;
}

bool List::operator != (const List& L)
{
   // Используем предыдущую функцию сравнения
   return !(*this == L);
}

bool List::operator >= (const List& L)
{
   // Сравнение по количеству
   if(Count > L.Count)
	  return true;
   // Сравнение по содержанию
   if(*this == L)
	  return true;

   return false;
}

bool List::operator <= (const List& L)
{
   // Сравнение по количеству
   if(Count < L.Count)
	  return true;
   // Сравнение по содержанию
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

// переворот
List List::operator - ()
{
   List Result;

   Elem * temp = Head;
   // Копируем элементы списка, начиная с головного,
   // в свой путем добавления элементов в голову,
   // таким образом временный список Result будет содержать
   // элементы в обратном порядке
   while(temp != 0)
   {
	   Result.AddHead(temp->data);
	   temp = temp->next;
   }

   return Result;
}

// Тестовый пример
void main()
{
   List L;

   const int n = 10;
   int a[n] = {0,1,2,3,4,5,6,7,8,9};

   // Добавляем элементы, стоящие на четных индексах, в голову,
   // на нечетных - в хвост
   for(int i = 0; i < n; i++)
	  if(i % 2 == 0)
		 L.AddHead(a[i]);
	  else
		 L.AddTail(a[i]);

   // Распечатка списка
   cout << "List L:\n";
   L.Print();

   cout << endl;

   // Вставка элемента в список
   L.Insert();
   // Распечатка списка
   cout << "List L:\n";
   L.Print();

   // Распечатка 2-го и 8-го элементов списка
   L.Print(2);
   L.Print(8);

   List T;

   // Копируем список
   T = L;
   // Распечатка копии
   cout << "List T:\n";
   T.Print();

   // Складываем два списка (первый в перевернутом состоянии)
   cout << "List Sum:\n";
   List Sum = -L + T;
   // Распечатка списка
   Sum.Print();
}
*/

// Шаблонный двусвязный список
/*
#include <iostream>
using namespace std;

template <typename T>
struct Elem
{
   // Любые данные
   T data;
   Elem * next, * prev;
};

template <typename T>
class List
{
   // Голова хвост
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

   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
	  // Неверная позиция
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
	  // Доходим до элемента, который удаляется
	  Del = Del->next;
	  i++;
   }

   // Доходим до элемента, который предшествует удаляемому
   Elem<T> * PrevDel = Del->prev;
   // Доходим до элемента, который следует за удаляемым
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
	  // Доходим до элемента, который удаляется
	  Del = Del->next;
	  i++;
   }

   // Доходим до элемента, который предшествует удаляемому
   Elem<T> * PrevDel = Del->prev;
   // Доходим до элемента, который следует за удаляемым
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
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
	  // Неверная позиция
	  cout << "Incorrect position !!!\n";
	  return;
   }

   Elem<T> * temp;

   // Определяем с какой стороны
   // быстрее двигаться
   if(pos <= Count / 2)
   {
	  // Отсчет с головы
	  temp = Head;
	  int i = 1;

	  while(i < pos)
	  {
		 // Двигаемся до нужного элемента
		 temp = temp->next;
		 i++;
	  }
   }
   else
   {
	  // Отсчет с хвоста
	  temp = Tail;
	  int i = 1;

	  while(i <= Count - pos)
	  {
		 // Двигаемся до нужного элемента
		 temp = temp->prev;
		 i++;
	  }
   }
   // Вывод элемента
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

// Тестовый пример
void main()
{
   List <int> L;

   const int n = 10;
   int a[n] = {0,1,2,3,4,5,6,7,8,9};

   // Добавляем элементы, стоящие на четных индексах, в голову,
   // на нечетных - в хвост
   for(int i = 0; i < n; i++)
	  if(i % 2 == 0)
		 L.AddHead(a[i]);
	  else
		 L.AddTail(a[i]);

   // Распечатка списка
   cout << "List L:\n";
   L.Print();

   cout << "\n\n";

   // Распечатка списка
   cout << "List L:\n";
   L.Print();

   // Распечатка 2-го и 8-го элементов списка
   L.Print(2);
   L.Print(8);

   List <int> T;

   // Копируем список
   T = L;
   // Распечатка копии
   cout << "List T:\n";
   T.Print();

   // Складываем два списка (первый в перевернутом состоянии)
   cout << "List Sum:\n";
   List <int> Sum = -L + T;
   // Распечатка списка
   Sum.Print();
}
*/

// Бинарное дерево
/*
// Бинарное дерево (binary tree) - это упорядоченная древовидная динамическая структура. Каждый элемент (узел) дерева имеет не более 
// двух элементов следующих за ним (потомков) и не более одного предыдущего (родителя)

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;
struct Elem
{
   int  OwnerPoints;		// Очки хозяина
   int  OppPoints;		// Очки соперника
   char Match[10];		// Счет
   char Name[20];		// Команда
   char Opponent[20];		// Соперник

   Elem * left, * right, * parent;
};

class Tree
{
   // корень
   Elem * root;
public:
   Tree();
   ~Tree();
   // печать от указанного узла
   void Print(Elem * Node);
   // поиск от указанного узла
   Elem * Search(Elem * Node, char * key);
   // min от указанного узла
   Elem * Min(Elem * Node);
   // max от указанного узла
   Elem * Max(Elem * Node);
   // следующий для указанного узла
   Elem * Next(Elem * Node);
   // предыдущий для указанного узла
   Elem * Previous(Elem * Node);
   // вставка узла
   void Insert(Elem * z);
   // удаление ветки для указанного узла,
   // 0 - удаление всего дерева
   void Del(Elem * z = 0);
   // получить корень
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

// Рекурсивный обход дерева
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
   // Пока есть узлы и ключи не совпадают
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
   // Поиск самого "левого" узла
   if(Node != 0)
	  while(Node->left != 0)
		 Node = Node->left;

   return Node;
}

Elem * Tree::Max(Elem * Node)
{
   // Поиск самого "правого" узла
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
	  // если есть правый потомок
	  if(Node->right != 0)
		 return Min(Node->right);

	  // родитель узла
	  y = Node->parent;
	  // если Node не корень и Node справа
	  while(y != 0 && Node == y->right)
	  {
		 // Движемся вверх
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
	  // если есть левый потомок
	  if(Node->left != 0)
		 return Max(Node->left);

	  // родитель узла
	  y = Node->parent;
	  // если Node не корень и Node слева
	  while(y != 0 && Node == y->left)
	  {
		 // Движемся вверх
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
   // потомков нет
   z->left = NULL;
   z->right = NULL;

   Elem * y = NULL;
   Elem * Node = root;

   // поиск места
   while(Node != 0)
   {
	  // будущий родитель
	  y = Node;
	  if(strcmp(z->Name, Node->Name) < 0)
		 Node = Node->left;
	  else
		 Node = Node->right;
   }
   // заполняем родителя
   z->parent = y;

   if(y == 0) // элемент первый (единственный)
	  root = z;
   // чей ключ больше?
   else if(strcmp(z->Name, y->Name) < 0)
	  y->left = z;
   else
	  y->right = z;
}

void Tree::Del(Elem * z)
{
   // удаление куста
   if(z != 0)
   {
	  Elem * Node, * y;

	  // не 2 ребенка
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
	  // Удаляется корневой узел?
	  if(y->parent == 0)
		 root = Node;
	  else if(y == y->parent->left) // слева от родителя?
		 y->parent->left = Node;
	  else
		 y->parent->right = Node;  // справа от родителя?

	  if(y != z)
	  {
		 // Копирование данных узла
		 strcpy(z->Name, y->Name);
		 strcpy(z->Opponent, y->Opponent);
		 strcpy(z->Match, y->Match);
		 z->OppPoints = y->OppPoints;
		 z->OwnerPoints = y->OwnerPoints;
	  }

	  delete y;
   }
   else // удаление всего дерева
	  while(root != 0)
		 Del(root);
}





// Турнирная таблица
Tree tournament;

void Game(char Commands[][20], int N)
{
   int i, j;
   int p1, p2; // Счет

   // Каждая команда играет с каждой по 2 раза - дома и в гостях
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
			   // 1 игра
			   strcpy(temp->Name, Commands[i]);
			   strcpy(temp->Opponent, Commands[j]);
			}
			else
			{
			   // 2 игра
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

			// Запись счета
			sprintf(temp->Match, " %d : %d ", p1, p2);
			// Добавление записи
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

   // Игра
   Game(Commands, N);
   // Вывод результатов
   tournament.Print(tournament.GetRoot());
}
*/

