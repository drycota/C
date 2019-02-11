#include "pch.h"
#include "class.h"

// Конструктор и деструктор
/*
// описание класса CreateAndDestroy
class CreateAndDestroy
{
public:
	CreateAndDestroy(int value)  // конструктор
	{
	  data = value;
	  cout << " Object " << data << " constructor\n";
	}

	~CreateAndDestroy()    // деструктор
	{
		cout << " Object " << data << " destructor\n";
	}
private:
	int data;
};

void main ()
{
	CreateAndDestroy one(1);
	CreateAndDestroy two(2);
}

РЕЗУЛЬТАТ РАБОТЫ ПРОГРАММЫ

Object 1 constructor
Object 2 constructor
Object 2 destructor
Object 1 destructor
*/

// Перегруженные конструкторы и указатель на объект
/*
class _3D
{
	double x, y, z;
	public:
	_3D ();
	_3D (double initX, double initY, double initZ);
	void Show(){
		cout<<x<<" "<<y<<" "<<z<<"\n";
	}
};

//конструктор класса _3D с параметрами
_3D::_3D(double initX, double initY, double initZ)
{
	x = initX;
	y = initY;
	z = initZ;
	cout << "\nWhis arguments!!!\n";
}

//конструктор класса _3D без параметров
_3D::_3D()
{
	x=y=z=0;
	cout << "\nNo arguments!!!\n";
}

void main()
{
	//создается объект A, вызывается
	//конструктор без параметров
	//все члены класса инициализируются нулем
	//на экране надпись "No arguments!!!"
	_3D A;

	//создается объект B, вызывается
	//конструктор c параметрами
	//все члены класса инициализируются
	//соответствующими переменными
	//на экране надпись "Whis arguments!!!"
	_3D B (3,4,0);

	// создается указатель на объект типа
	// _3D и в этот указатель записывается
	// адрес объекта B
	_3D*PB=&B;

	// через указатель вызывается функция
	// Show()
	PB->Show();
}
*/

// Динамическое выделение памяти под объект
/*
class Point
{
	double x, y;
public:
	// конструктор с параметрами
	// по умолчанию
	Point(double iX=1,double iY=1){
		x=iX;
		y=iY;
		cout << "\nWhis arguments!!!\n";
	}
	void Show(){
		cout<<x<<" "<<y<<"\n";
	}
};

void main()
{
	// создание объекта
	Point A(2,3);
	// показ содержимого на экран
	A.Show();

	cout<<"****************************";
	// создание указателя на объект
	Point*PA;

	// Динамическое выделение памяти под один
	// объект типа Point
	// в круглых скобках - параметры для конструктора
	PA=new Point(4,5);

	// проверка, выделилась ли память
	// и выход, если не выделилась
	if(!PA) exit(0);

	// через указатель вызывается функция
	// Show()
	PA->Show();

	cout<<"****************************";
	// создание указателя на объект
	Point*PB;

	// Динамическое выделение памяти под массив
	// объектов типа Point
	// параметры не передаются
	// используются параметры
	// конструктора по умолчанию
	PB=new Point[10];

	// проверка, выделилась ли память
	// и выход, если не выделилась
	if(!PB) exit(0);

	// Вызов функции Show() для каждого элемента
	// массива PB
	for(int i=0;i<10;i++){
		PB[i].Show();
	}

	// Удаление объекта РА
	delete PA;

	// Удаление массива РB
	delete[]PB;
// в данном примере использован конструктор с параметрами по умолчанию.
// Это связано с тем, что при динамическом выделении памяти под массив объектов НЕВОЗМОЖНО передать параметры в конструктор. 
// Для массива объектов используются параметры по умолчанию. Эту проблему можно было решить иначе, создав конструктор без параметров.
}
*/

// Статические массивы
/*
// В отличие от динамики, при создании статического массива параметры в конструктор передать можно.
class Point
{
	double x, y;
public:
	//конструктор с параметрами
	Point(double iX,double iY){
		x=iX;
		y=iY;
		cout << "\nWhis arguments!!!\n";
	}
	void Show(){
		cout<<x<<" "<<y<<"\n";
	}
};

void main()
{
	// создание массива объектов
	// передача параметров в конструктор
	Point AR[2]={Point(2,3),Point(4,5)};

	// Вызов функции Show() для каждого элемента
	// массива AR
	for(int i=0;i<2;i++){
		AR[i].Show();
	}
}
*/

// Указатель this
/*
class Student	// Класс студент.
{
	char name[50]; // имя
	char surname[50]; // фамилия
	int age; // возраст
public:
	//Конструктор:
	Student(char name[],char surname[],int age)
	{
		// Компоненты и одноименные параметры:
		strcpy(this->name,name);
		strcpy(this->surname,surname);
		this->age=age;
	}
	void Show()
	{
		// Здесь this является необязательным,
		// однако использовать его можно
		cout << "\nNAME - " << this->name;
		cout << "\nSURNAME - " << this->surname;
		cout << "\nAGE - " << this->age;
		cout << "\n\n";
	}
};

void main(void)
{
	Student A("Ivan","Sidoroff",25);
	A.Show();
}
*/

// Конструктор копирования
/*
class ClassName
{
public:
	ClassName ()
	{
		cout << "ClassName!!!\n";
	}
	~ClassName ()
	{
		cout << "~ClassName!!!\n";
	}
};
// Передача объекта в функцию
// Объект внутри функции - это побитовая копия передаваемого объекта, а это значит, что если объект содержит в себе, например, 
// некоторый указатель на динамически выделенную область памяти, то при копировании создается объект, указывающий на ту же область памяти. 
// И как только вызывается деструктор копии, где, как правило, принято высвобождать память, то высвобождается область памяти, 
// на которую указывал объект-"оригинал", что приводит к разрушению исходного объекта.
void f (ClassName o)
{
	cout << "Function f!!!\n";
}

void main()
{
	ClassName c1;
	f(c1);
}

Результат работы программы:

ClassName!!!
Function f!!!
~ClassName!!!
~ClassName!!!
// Конструктор вызывается только один раз. Это происходит при создании с1. Однако деструктор срабатывает дважды: один раз для копии o, 
// второй раз для самого объекта c1. Тот факт, что деструктор вызывается дважды, может стать потенциальным источником проблем, например, 
// для объектов, деструктор которых высвобождает динамически выделенную область памяти.

*********************************************************************************************
// Возврат объекта из функции
ClassName f()
{
	ClassName obj;
	cout << "Function f\n";
	return obj;
}


void main()
{
	ClassName c1;
	f();
}

Результат работы программы:

ClassName!!!
ClassName!!!
Function f
~ClassName!!!
~ClassName!!!
~ClassName!!!
// Конструктор вызывается два раза: для с1 и obj. Однако деструкторов здесь три. Как же так? Ясно, что один деструктор разрушает с1, 
// еще один - obj. "Лишний" вызов деструктора (второй по счету) вызывается для так называемого временного объекта, который является копией 
// возвращаемого объекта. Формируется эта копия, когда функция возвращает объект. После того, как функция возвратила свое значение, 
// выполняется деструктор временного объекта. Естественно, что если деструктор, например, высвобождает динамически выделенную память, 
// то разрушение временного объекта приведет к разрушению возвращаемого объекта.

*******************************************************************************************************
// Инициализация одного объекта другим при создании
void main()
{
	ClassName c1;

	// Вот он!!! Момент побитового копирования.
	ClassName c2=c1;
}

Результат работы программы:

ClassName!!!
~ClassName!!!
~ClassName!!!
// Конструктор вызывается один раз: для с1. Для с2 конструктор не срабатывает. Однако деструктор срабатывает для обоих объектов. 
// А, поскольку, с2 является точной копией с1, деструктор, высвобождающий динамически выделенную память, вызывается дважды для одного 
// и того же фрагмента этой памяти. Это неминуемо приведет к ошибке.


****************************************************************************************************
// Конструктор копирования или конструктор копии позволяет точно определить порядок создания копии объекта.
имя_класса (const имя_класса & obj)
{
 ... // тело конструктора
}
// Здесь obj - это ссылка на объект или адрес объекта. Конструктор копирования вызывается всякий раз, когда создается копия объекта. 
// Таким образом, в конструкторе копирования можно выделить "свою" память под новый объект.
****************************************************************************************************

class ClassName
{
public:
	ClassName ()
	{
		cout << "ClassName!!!\n";
	}
	ClassName (ClassName&obj){
		cout << "Copy ClassName!!!\n";
	}
	~ClassName ()
	{
		cout << "~ClassName!!!\n";
	}
};
void f(ClassName o){
	cout<<"Function f!!!\n";
}

ClassName r(){
	ClassName o;
	cout<<"Function r!!!\n";
	return o;
}
void main()
{
	// инициализация одного объекта другим
	ClassName c1;
	ClassName c2=c1;

	// передача объекта в функцию
	ClassName a;
	f(a);

	//возврат объекта из функции
	r();
}

Результат работы программы:

// создался объект с1
ClassName!!!

// инициализация объекта с2 объектом с1
Copy ClassName!!!

// создался объект а
ClassName!!!

// передача а в функцию по значению
// создалась копия о
Copy ClassName!!!

// отработала функция f
Function f!!!

// уничтожилась копия o
~ClassName!!!

// создался объект o
// внутри функции r
ClassName!!!

// отработала функция r
Function r!!!

// возврат из функции
// создалась копия объекта о
Copy ClassName!!!

// уничтожился объект o
~ClassName!!!

// уничтожилась его копия
~ClassName!!!

// уничтожился объект а
~ClassName!!!

// уничтожился объект с2
~ClassName!!!

// уничтожился объект с1
~ClassName!!!

// Помимо создания конструктора копирования есть другой способ организации взаимодействия между функцией и программой, передающей объект. 
// Этот способ - передача объекта по ссылке или по указателю
*/

// Константный метод
/*
class Personal
{
public:
	// конструктор с параметрами
	// мы выделяем здесь память
	// однако в нашем примере нет
	// ни деструктора, ни конструктора
	// копирования - единственная цель,
	// которую мы преследуем показать
	// работу константного метода
	Personal(char*p,char*n,int a){
		name=new char[strlen(n)+1];
		if(!name){
			cout<<"Error!!!";
			exit(0);
		}
		picture_data=new char[strlen(n)+1];
		if(!picture_data){
			cout<<"Error!!!";
			exit(0);
		}
		strcpy(picture_data,p);
		strcpy(name,n);
		age=a;
	}

	// Группа константных методов
	// внутри них невозможно
	// изменить какое-то из свойств
	const char*Name()const{
		return name;
	}
	int Age()const{
		return age;
	}
	const char*Picture()const{
		return picture_data;
	}

	void SetName(const char*n){
		strcpy(name,n);
	}
	void SetAge(int a){
		age=a;
	}
	void SetPicture(const char*p){
		strcpy(picture_data,p);
	}

private:
	char*picture_data; // путь к фотографии
	char*name; // имя
	int age; // возраст
};

void main(){
	Personal A("C:\\Image\\","Ivan",23);
	cout<<"Name: "<<A.Name()<<"\n\n";
	cout<<"Age: "<<A.Age()<<"\n\n";
	cout<<"Path for picture: "<<A.Picture()<<"\n\n";
	A.SetPicture("C:\\Test\\");
	A.SetName("Leonid");
	A.SetAge(90);
	cout<<"Name: "<<A.Name()<<"\n\n";
	cout<<"Age: "<<A.Age()<<"\n\n";
	cout<<"Path for picture: "<<A.Picture()<<"\n\n";
}

// В данном примере методы Name, Age, Picture объявлены константными. Кроме того, можно наблюдать и использование константных указателей: 
// параметр методов SetName и SetPicture, возвращаемое значение методов Name и Picture. Компилятор обеспечит проверку того, что реализация 
// константных методов не имеет побочных эффектов в виде изменения состояния объекта, реализующего класс Personal. 
// Как только обнаружится попытка выполнить запрещенную операцию, компилятор сообщит об ошибке.
*/

// Пример на создание класса - СТРОКА
/*
#include <iostream>
#include <string.h>

using namespace std;

class string_
{
private:
	// Строка
	char* S;

	// Длина строки
	int len;
public:
	// Конструктор по умолчанию
	// без параметров
	string_();

	// Перегруженный конструктор
	// с параметром
	string_(char* s);

	// Конструктор копирования
	string_(const string_& s);

	// Деструктор
	~string_(){
		delete [] S;
	}

	// Метод сортировки
	void Sort(string_ s[], int n);

	// Константный метод
	// возвращающий содержимое
	// строки
	const char*GetStr()const
	{
		return S;
	}
	// метод позволяющий изменить содержимое
	// с помощью пользователя
	void SetStr()
	{
		// если строка не пустая - очистить
		if(S!=NULL)
			delete[]S;

		// создаем массив
		// и запрашиваем у пользователя данные
		char a[256];
		cin.getline(a,256);

		// просчитываем размер
		len=strlen(a)+1;

		// выделяем память
		S = new char[len];

		// переписываем в объект
		// введенную строку
		strcpy(S,a);
	}

	// метод позволяющий изменить содержимое
	// с помощью параметра
	void SetStr2(char*str)
	{
		// если строка не пустая - очистить
		if(S!=NULL)
			delete[]S;

		// просчитываем размер
		len=strlen(str)+1;

		// выделяем память
		S = new char[len];

		// переписываем в объект
		// строку из параметра
		strcpy(S, str);
	}
};

string_::string_()
{
	// Начальная инициализация
	S = NULL;
	len = 0;
}

string_::string_(char* s)
{
	len = strlen(s);
	S = new char[len + 1];
	// Инициализация строкой,
	// переданной пользователем
	strcpy(S, s);
}

string_::string_(const string_& s)
{
	len = s.len;
	// Безопасное копирование
	S = new char[len + 1];
	strcpy(S, s.S);
}

void string_::Sort(string_ s[], int n)
{
	//  Сортировка строк
	//  Методом пузырька

	string_ temp;

	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			// сравнение двух строк
			if(strcmp(s[j].S,s[j-1].S)<0)
			{
				// запись стороки s[j] в temp
				temp.SetStr2(s[j].S);

				// запись стороки s[j-1] в s[j]
				s[j].SetStr2(s[j-1].S);

				// запись стороки temp в s[j-1]
				s[j-1].SetStr2(temp.S);
			}
		}
	}
}

void main()
{
	int n,i;

	// Вводим количество строк
	cout << "Input the number of string s:\t";
	cin >> n;

	if(n < 0)
	{
		cout << "Error number:\t" << n << endl;
		return;
	}

	// Забираем из потока символ Enter ("\n")
	char c[2];
	cin.getline(c, 2);

	// Создаем массив из n строк
	string_ *s = new string_[n];

	// Ввод строк c клавиатуры
	for(i = 0; i < n; i++)
		s[i].SetStr();

	// Сортировка строк
	// Вызов через указатель,
	// так как функция работает
	// для группы объектов,
	// а не для одного конкретного
	s->Sort(s, n);

	// Вывод отсортированных строк
	for(i = 0; i < n; i++)
		cout<<"\n"<<s[i].GetStr()<<"\n";

	// Удаление массива строк
	delete [] s;
}
*/

// Перегрузка операторов
/*
// Нельзя переопределять операции: 
// ::
// * (разыменование, а не бинарное умножение)
// ?:
// sizeof
// ##
// #
// .

class Digit{
	private:
		int dig; // число
	public:
		Digit(){
			dig=0;
		}
		Digit(int iDig){
			dig=iDig;
		}
		void Show(){
			cout<<dig<<"\n";
		}

		// перегружаем четыре оператора
		// обратите внимания, все операторы
		// бинарные, поэтому мы передаем в
		// них один параметр - это операнд,
		// который будет находиться справа
		// от оператора в выражении
		// левый операнд передается с помощью this
		Digit operator+(const Digit &N)
		{
			Digit temp;
			temp.dig=dig+N.dig;
			return temp;
		}
		Digit operator-(const Digit &N)
		{
			Digit temp;
			temp.dig=dig-N.dig;
			return temp;
		}
		Digit operator*(const Digit &N)
		{
			Digit temp;
			temp.dig=dig*N.dig;
			return temp;
		}
		Digit Digit::operator%(const Digit &N)
		{
			Digit temp;
			temp.dig=dig%N.dig;
			return temp;
		}
};
void main()
{
	// проверяем работу операторов
	Digit A(8),B(3);
	Digit C;

	cout<<"\Digit A:\n";
	A.Show();

	cout<<"\Digit B:\n";
	B.Show();

	cout<<"\noperator+:\n";
	C=A+B;
	C.Show();

	cout<<"\noperator-:\n";
	C=A-B;
	C.Show();

	cout<<"\noperator*:\n";
	C=A*B;
	C.Show();

	cout<<"\noperator%:\n";
	C=A%B;
	C.Show();
}
*/

// Пример класса СТРОКА с перегруженными операторами
/*
#include <iostream>
#include <string.h>

using namespace std;

class string_
{
private:
	// Строка
	char* S;

	// Длина строки
	int len;
public:
	// Конструктор по умолчанию
	// без параметров
	string_();

	// Перегруженный конструктор
	// с параметром
	string_(char* s);

	// Конструктор копирования
	string_(const string_& s);

	// Деструктор
	~string_(){
		delete [] S;
	}

	// Метод сортировки
	void Sort(string_ s[], int n);

	// Константный метод
	// возвращающий содержимое
	// строки
	const char*GetStr()const
	{
		return S;
	}
	// метод позволяющий изменить содержимое
	// с помощью пользователя
	void SetStr()
	{
		// если строка не пустая - очистить
		if(S!=NULL)
			delete[]S;

		// создаем массив
		// и запрашиваем у пользователя данные
		char a[256];
		cin.getline(a,256);

		// просчитываем размер
		len=strlen(a)+1;

		// выделяем память
		S = new char[len];

		// переписываем в объект
		// введенную строку
		strcpy(S,a);
	}

	// Перегрузка бинарного оператора
	// Первый параметр передается неявно с помощью указателя this
	// Функция реализует сцепление строк
	string_ operator+(const string_&);

	// Перегрузка бинарного оператора
	// Первый параметр передается неявно с помощью указателя this
	// Функция реализует корректное присваивание объектов друг другу
	// в ситуации объект1=объект2. Напоминаем, эта ситуация является
	// четвертым случаем побитового копирования, при котором
	// конструктор копирования - бессилен.
	string_&operator=(const string_&);

	// Перегрузка типа
	// Функция реализует преобразование объекта класса к типу char*
	operator char*() { return S; }
};

string_::string_()
{
	// Начальная инициализация
	S = NULL;
	len = 0;
}

string_::string_(char* s)
{
	len = strlen(s);
	S = new char[len + 1];
	// Инициализация строкой,
	// переданной пользователем
	strcpy(S, s);
}

string_::string_(const string_& s)
{
	len = s.len;
	// Безопасное копирование
	S = new char[len + 1];
	strcpy(S, s.S);
}

void string_::Sort(string_ s[], int n)
{
	//  Сортировка строк
	//  Методом пузырька

	string_ temp;

	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			// сравнение двух строк
			if(strcmp(s[j].S,s[j-1].S)<0)
			{
				// теперь, когда у нас есть
				// перегруженный оператор равно
				// мы не нуждаемся в дополнительной
				// функции SetStr2, которую использовали
				// в прошлом примере для присваивания

				// запись стороки s[j] в temp
				temp=s[j];

				// запись стороки s[j-1] в s[j]
				s[j]=s[j-1];

				// запись стороки temp в s[j-1]
				s[j-1]=temp;
			}
		}
	}
}

// Функция сцепления строк (перегруженный
// бинарный плюс)
string_ string_::operator+(const string_ &str)
{
	// Создание временного объекта
	string_ s;

	// Вычисление новой длины строки
	s.len = len + str.len;

	// Выделение памяти под новую строку
	s.S = new char[s.len + 1];

	// Инициализация первой части строки
	strcpy(s.S, S);

	//  Инициализация второй части строки
	strcat(s.S, str.S);

	//  Возврат нового объекта
	return s;
}

// Функция, реализующая безопасное присваивание
string_& string_::operator=(const string_ &str)
{
	// Предотвращение варианта STRING = STRING;
	// (присваивание самому себе),
	// где STRING переменная класса string
	if(this == &str)
		 return *this;

	// если размеры строк не совпадают
	// или строка, в которою производится запись
	// не сформированна
	if(len != str.len || len == 0)
	{
		// Удаление старой строки
		delete [] S;
		// Вычисление новой длины строки
		len = str.len;
		// Выделение памяти под новую строку
		S = new char[len + 1];
	}

	// Инициализация строки
	strcpy(S, str.S);

	// Возврат ссылки на "самого себя"
	// Благодаря этому возможно многократное
	// присваивание объектов друг другу
	// например, string_ a, b, c; a = b = c;
	return *this;
}


void main()
{
	int n,i;

	// Вводим количество строк
	cout << "Input the number of string s:\t";
	cin >> n;

	if(n < 0)
	{
		cout << "Error number:\t" << n << endl;
		return;
	}

	// Забираем из потока символ Enter ("\n")
	char c[2];
	cin.getline(c, 2);

	// Создаем массив из n строк
	string_ *s = new string_[n];

	// Ввод строк c клавиатуры
	for(i = 0; i < n; i++)
		s[i].SetStr();

	// Сортировка строк
	// Вызов через указатель,
	// так как функция работает
	// для группы объектов,
	// а не для одного конкретного
	s->Sort(s, n);

	// Вывод отсортированных строк
	for(i = 0; i < n; i++)
		cout<<"\n"<<s[i].GetStr()<<"\n";

	// Удаление массива строк
	delete [] s;

	cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	//Проверяем на деле оператор + и преобразование

	string_ A,B,C,RES;

	A="Ivanov ";
	B="Ivan ";
	C="Ivanovich";
	RES=A+B+C;
	cout<<RES.GetStr()<<"\n\n";
}
*/

// Перегрузка инкремента и декремента
/*
// Перегрузка префиксных операций ++ и -- ничем не отличается от перегрузки других унарных операций. Другими словами, функции конкретного 
// класса: operator++ и operator--, определяют префиксные операции для этого класса.
// При определении постфиксных операций "++" и "--" операции-функции должны иметь еще один дополнительный параметр типа int. 
// Когда в программе будет использовано постфиксное выражение, то вызывается версия функции с параметром типа int. При этом параметр 
// передавать !не нужно!, а значение его в функции будет равно нулю. 

// Класс, реализующий работу с "парой чисел"
class Pair{

	// Целое число.
	int N;
	// Вещественное число.
	double x;
public:
	// Конструктор c параметрами
	Pair(int n, double xn)
	{
		N = n;
		x = xn;
	}
	// функция для показа данных на экран
	void display()
	{
		cout << "\nPair: N = " << N << " x = " << x << "\n";
	}
	// Компонентная функция (префиксная --):
	Pair& operator -- ()
	{
		// Уменьшаем содержимое объекта
		// в десять раз и возвращаем его
		// на место вызова оператора
		N /= 10;
		x /= 10;
		return *this;
	}
	// Компонентная функция (постфиксная --):
	Pair& operator -- (int k)
	{
		// временно сохраняем содержимое
		// объекта в независимую
		// переменную типа Pair
		// (Попытка использовать здесь
		// значение дополнительного параметра
		// int k подтверждает его равенство 0.)
		Pair temp(0,0.0);
		temp.N=N+k;
		temp.x=x+k;

		// уменьшаем объект в 10 раз
		N /= 10;
		x /= 10;

		// возвращаем прежнее значение объекта.
		// таким "тактическим ходом"
		// мы добиваемся эффекта постфиксной
		// формы, т. е. в ситуации А=B++
		// в А записывается текущее
		// значение объекта B, тогда как сам B
		// изменяется
		return temp;
	}
};
void main()
{
	// создаем объект Z именно с ним
	// мы и будем экспериментировать
	Pair Z(10,20.2);

	// показ объекта в первозданном виде
	cout<<"\nObject Z (before):\n";
	Z.display();

	cout<<"\n-----------------\n";

	// присваиваем объекту Pref выражение
	// с префиксной формой (в данном случае
	// сначала изменится Z, а затем произойдет
	// присваивание).

	Pair Pref=--Z;

	// показываем результат работы
	// префиксной формы
	cout<<"\nPrefix\n";
	cout<<"\nObject Pref:\n";
	Pref.display();
	cout<<"\nObject Z (after):\n";
	Z.display();

	cout<<"\n-----------------\n";

	// присваиваем объекту Postf выражение
	// с постфиксной формой (в данном случае
	// сначала произойдет присваивание,
	// а затем изменится Z).
	Pair Postf=Z--;

	// показываем результат работы
	// постфиксной формы
	cout<<"\nPostfix\n";
	cout<<"\nObject Postf:\n";
	Postf.display();
	cout<<"\nObject Z (after):\n";
	Z.display();
}
____________________________________________________________

Результат работы программы:

Object Z (before):

Pair: N = 10 x = 20.2

-----------------

Prefix

Object Pref:

Pair: N = 1 x = 2.02

Object Z (after):

Pair: N = 1 x = 2.02

-----------------

Postfix

Object Postf:

Pair: N = 1 x = 2.02

Object Z (after):

Pair: N = 0 x = 0.202
*/

// Перегрузка оператора индексирования
/*
// выражение A [ i ], где A - объект абстрактного типа class, представляется компилятором как A.operator [ ] ( i )
class A{

	// массив из 10 элементов
	// типа int
		int a[10];

	// размер массива
	int size;

public:

	// конструктор без параметров
		A(){
		size=10;
		for (int i = 0; i < 10; i++)

		// очевидно, что операция [], использованная здесь,
		// в конструкторе класса А, является стандартной,
		// так как она выполняется над именем массива типа int.

			a [i] = i + 1;
	}

	// перегрузка оператора
	// индексирования
	// возврат по ссылке осуществлен
	// для ситуации ОБЪЕКТ[i]=ЗНАЧЕНИЕ
	// на место вызова индексирования
	// вернется сам объект
		int&operator[](int j){

		// возврат конкретного объекта
			return a [j];
	}

	// функция которая возвращает
	// размер массива
	int Get () const {
		return size;
	}
};

void main () {

	int i,j;

	// Работа с одним объектом типа А
	A object;

	cout<<"\nOne object:\n";

	for(i=0;i<object.Get();i++){

		// выражение array[i] интерпретируется как
		// object.operator [](j).
		cout<<object[i]<<" ";
	}
	cout<<"\n\n";

	// Работа с массивом объектов типа А
		A array [3];

	cout<<"\nArray of objects:\n";

	for(i=0;i<3;i++){
		for(j=0;j<object.Get();j++){

			// выражение array[i][j] интерпретируется как
			// (array [i]).operator [](j).
			// Первая из двух операций [] является стандартной,
			// так как выполняется над именем массива.
			// При этом неважно, какой тип имеют его элементы.
			// Вторая операция [] - переопределенная,
			// так как результатом первой операции [] является объект типа А.

				cout << array [i][j] << " ";
		}
		cout <<"\n\n";
	}
}
___________________________________

Результат работы программы:

One object:
1 2 3 4 5 6 7 8 9 10

Array of objects:
1 2 3 4 5 6 7 8 9 10

1 2 3 4 5 6 7 8 9 10

1 2 3 4 5 6 7 8 9 10
*/

// Оператор "круглые скобки".()
/*
class MyPoint{
	int X;
	int Y;
public:
	MyPoint(){
		X=0;
		Y=0;
	}

	// перегруженный оператор ()
	void operator()(int x,int y){
			X=x;
		Y=y;
	}
	void Show(){
		cout<<X<<" "<<Y<<"\n\n";
	}
};
void main(){
	MyPoint P;
	P.Show();

	//изменение значений полей объекта
	P(2,3);
	P.Show();
}
*/

// Перегрузка операторов new, new[], delete, delete[]
/*
# include <iostream>
using namespace std;
// библиотека для функций
// выделения памяти
#include <malloc.h>

class SomeClass{
	int some;

public:
	// перегруженные операторы new и delete,
	// здесь также используются дополнительные
	// параметры, передаваемые внутрь операторов
	void * operator new(size_t size,char* str = "New");
	void   operator delete(void* ptr);

	// перегруженные операторы new [] и delete []
	void * operator new [] (size_t fullsize, char* str = "New []");
	void   operator delete [] (void* ptr);
};

void * SomeClass::operator new( size_t size,char* str)
{
	cout <<"\n"<<str<<"\n";
	
	// Здесь, для выделения памяти используется стандартная функция
	// void *malloc( size_t size );
	// В неё передаётся size - количество байт, которое нужно
	// выделить. Если память выделяется, то из malloc возвращается
	// адрес начала выделенного блока.
	
void*ptr = malloc(size);

if (!ptr) {
	cout << "\nError memory new!!!\n";
}
else {
	cout << "\nMemory new - OK!!!\n";
}
return ptr;
}
void * SomeClass::operator new[](size_t fullsize, char* str)
{
	cout << "\n" << str << "\n";
	
	// Здесь, для выделения памяти используется стандартная функция
	// void *malloc( size_t size );
	// В неё передаётся size - количество байт, которое нужно
	// выделить. Если память выделяется, то из malloc возвращается
	// адрес начала выделенного блока.
	
	void*ptr = malloc(fullsize);

	if (!ptr) {
		cout << "\nError memory new[]!!!\n";
	}
	else {
		cout << "\nMemory new[] - OK!!!\n";
	}
	return ptr;
}

void SomeClass::operator delete(void* ptr)
{
	// Для очистки памяти используется стандартная функция
	// void free( void * memblock );
	// Функция free очищает память, memblock - адрес начала
	// очищаемого участка
	
	free(ptr);
	cout << "\nDelete memory\n";
}

void SomeClass::operator delete[](void* ptr)
{
	free(ptr);
	cout << "\nDelete [] memory\n";
}

void main()
{
	// Вызывается оператор new( size_t size,char* str="New")
	// на место size будет подставлен размер класса SomeClass,
	// а str получит значение по умолчанию т.е. "New"
	
	SomeClass *p = new SomeClass;

	// Вызывается оператор new[](size_t size,char* str="New[]")
	// на место size будет подставлен размер класса SomeClass,
	// умноженный на количество запрашиваемых элементов
	// а str получит значение по умолчанию т.е. "New[]"
	
	SomeClass *r = new SomeClass[3];

	// Вызывается оператор delete(void* ptr)
	// на место ptr будет подставлен адрес памяти,
	// выделенной под объект р
	
	delete p;

	// Вызывается оператор delete[](void* ptr)
	// на место ptr будет подставлен адрес памяти,
	// выделенной под объект r
	
	delete[]r;
}
_____________________________________________________

Результат работы программы :

New

Memory new - OK!!!

New[]

Memory new[] - OK!!!

Delete memory

Delete[] memory
*/

// Дружественные функции
/*
// Класс - прямоугольник
class rect{

	// ширина и высота
	int Width, Height;
	//символ для отображения
	char Symb;
	// Прототип дружественной функции для замены символа:
	friend void friend_put(rect*r,char s);

  public:
	// Конструктор.
	rect(int wi, int hi, char si)
	{
		Width = wi;
		Height = hi;
		Symb = si;
	}
	// Вывод фигуры на экран
	void display ()
	{
		cout<<"\n\n";
		for(int i=0;i<Height;i++){
			for(int j=0;j<Width;j++){
				cout<<Symb;
			}
			cout<<"\n\n";
		}
		cout<<"\n\n";
	}
};
// Дружественная функция замены
// символа в конкретном объекте:
void friend_put(rect*r, char s)
{
	// обращение к закрытому члену здесь допустимо
	// т. к. функция "дружит" с классом
	r->Symb = s;
}
void main ()
{
	// Создание объектов
	rect A(5,3,'A');
	rect B(3,5,'B');
	A.display ();
	B.display ();
	//замена символов с помощью
	//friend-функции
	friend_put(&A,'a');
	friend_put(&B,'b');
	A.display ();
	B.display ();
}

********************************************************************************************
// дружественная функция двух классов "точка на плоскости" и "прямая на плоскости". 

#include <iostream>
using namespace std;

// Предварительное  упоминание о классе line_.
class  line_;

// Класс  "точка на плоскости":
class point_
{
	// Координаты точки на плоскости.
		float x, y;
public:
		// Конструктор.
		point_(float xn = 0, float yn = 0)
		{
			x = xn;
			y = yn;
		}
		friend float uclon(point_,line_);
};

// Класс "прямая на плоскости":
class line_
{
	// Параметры прямой.
		float A, B, C;
public:
		// Конструктор.
		line_(float a, float b, float c)
		{
			A = a;
			B = b;
			C = c;
		}
			friend float uclon(point_,line_);
};
// Внешнее определение дружественной функции.
float uclon(point_ p, line_ l)
{
	// вычисление отклонения прямой
	return l.A * p.x + l.B * p.y + l.C;
}
void main()
{
	// Определение точки P.
	point_ P(16.0,12.3);

	// Определение прямой L.
	line_ L(10.0,-42.3,24.0);

	cout << "\n Result" << uclon(P,L) << "\n\n";
}

*/

// Дружественная перегрузка операторов
/*
#include <iostream>
using namespace std;

// класс реализующий работу
// с логическим значением
class Flag
{
	bool flag;
	// дружественная функция (перегрузка
	// оператора ! - замена значения флага
	// на противоположное)
	friend Flag& operator !(Flag&f);
 public:

	 // Конструктор.
	 Flag(bool iF)
	 {
		 flag = iF;
	 }
	 // Компонентная функция показа значения флага
	 // в текстовом формате:
	 void display(){
		 if(flag) cout<<"\nTRUE\n";
		 else cout<<"\nFALSE\n";
	 }
};

// Определение дружественной
// операции-функции.
// (this не передается, поэтому 1 параметр)
Flag& operator !(Flag & f)
{
	//замена значения на противоположное
	f.flag=!f.flag;
	return f;
}

void main()
{
	Flag A(true);

	// показ начального значения
	A.display();

	// замена значения на противоположное
	// с помощью перегруженного оператора
	A=!A;
	// показ измененного значения
	A.display();
}

Результат выполнения программы:

TRUE

FALSE
*/

// Глобальная перегрузка(осуществляемая во внешней области видимости)
/*
#include <iostream>
using namespace std;

// класс "точка"
class Point
{
	 // координаты точки
	 int X;
	 int Y;
 public:

	 // конструктор
	 Point(int iX,int iY){
		 X=iX;
		 Y=iY;
	 }

	 //показ на экран
	 void Show(){
		cout<<"\n+++++++++++++++++++++\n";
		cout<<"X = "<<X<<"\tY = "<<Y;
		cout<<"\n+++++++++++++++++++++\n";
	 }

	 // перегруженный оператор +
	 // метод класса для ситуации Point+int
	 Point&operator+(int d){
		 Point P(0,0);
		 P.X=X+d;
		 P.Y=Y+d;
		 return P;
	 }
	 // функции доступа к
	 // privat-членам без них
	 // глобальная перегрузка невозможна
	 int GetX() const{
		 return X;
	 }
	 int GetY() const{
		 return Y;
	 }
	 void SetX(int iX){
		 X=iX;
	 }
	 void SetY(int iY){
		 Y=iY;
	 }
};

// глобальная перегрузка
// для ситуации int + Point
// доступ к private-членам
// через специальные функции
Point&operator+(int d,Point&Z){
		 Point P(0,0);
		 P.SetX(d+Z.GetX());
		 P.SetY(d+Z.GetY());
		 return P;
}

void main()
{
	// создание объекта
		Point A(3,2);
	A.Show();

	//оператор-метод +
	Point B=A+5;
	B.Show();

	//глобальный оператор
	Point C=2+A;
	C.Show();
}
*/

// Перегрузка ввода/вывода данных
/*
#include <iostream>
using namespace std;

// класс "точка"
class Point
{
	 // координаты точки
	 int X;
	 int Y;
 public:

	 // конструктор
	 Point(int iX,int iY){
		 X=iX;
		 Y=iY;
	 }
	// дружественные функции перегрузки ввода и вывода данных
	 friend istream& operator>>(istream& is, Point& P);
	 friend ostream& operator<<(ostream& os, const Point& P);

};
//ввод данных через поток
istream& operator>>(istream&is, Point&P){
	cout<<"Set X\t";
	is >> P.X;
	cout<<"Set Y\t";
		is >> P.Y;
		return is;
}
//вывод данных через поток
ostream& operator<<(ostream&os, const Point&P){
	os << "X = " << P.X << '\t';
		os << "Y = " << P.Y << '\n';
		return os;
}

void main()
{
	// создание объекта
		Point A(0,0);

	// одиночный ввод и вывод
	cin>>A;
	cout<<A;

	// множественное выражение
	Point B(0,0);
	cin>>A>>B;
	cout<<A<<B;
}
*/

// Дружественные классы
/*
// 1. Дружественный класс должен быть определен вне тела класса, "предоставляющего дружбу".
// 2. Все компонентные функции класса-друга будут являться дружественными для другого класса без указания спецификатора friend.
// 3. Все компоненты класса доступны в дружественном классе, но не наоборот.
// 4. Дружественный класс может быть определен позже (ниже), чем описан как дружественный.

# include <iostream>
using namespace std;
// упоминание о классе,
// который будет описан ниже
class	Banana;

// класс, который будет
// дружественным
class	Apple{
public:
	void F_apple(Banana ob);
};
// класс, который "позволяет" с собой "дружить"
class	Banana{
	int	x,y;
public:
	Banana(){
		x=y=777;
	}
	// реализация дружбы
	friend	Apple;
};
//функция, которая
//автоматически становится "другом"
void Apple::F_apple(Banana ob)
{
	//обращение к private - членам
	cout<<ob.x<<"\n";
	cout<<ob.y<<"\n";
}
void main(){
	Banana b;
	Apple a;
	a.F_apple(b);
}
*/

// Статические поля класса
/*
// Статический член класса должен быть инициализирован после определения класса и до первого описания объекта этого класса.
# include <iostream>
# include <string.h>
using namespace std;

class object_{
	char *str;
public:
	//статическое поле класса
	static int num_obj;

	//конструктор
		object_ (char *s){
			str = new char [strlen (s) + 1];
		strcpy ( str, s );
		cout <<"Create " << str <<'\n';

		// увеличиваем значение счетчика
		num_obj ++ ;
		}

	//деструктор
		~object_ (){
		cout <<"Destroy " << str << '\n';
		delete str;

		// уменьшаем значение счетчика
		num_obj --;
		}
};

// Инициализация. Об этом говорит
// ключевое слово int!
int object_::num_obj = 0;

// создание глобальных объектов
object_ s1 ("First global object.");
object_ s2 ("Second global object.");

// вспомогательная функция
void f (char *str) {
	 // Локальный объект
		object_ s(str);
	 // явное обращение к статическому полю
	 // без указания объекта
		cout <<"Count of objects - " <<object_::num_obj<<".\n";
		cout <<"Worked function f()" <<".\n";
}

void main () {
	// явное обращение к статическому полю
		cout <<"Now, count of objects " <<object_::num_obj<<".\n";
	object_ M ("Object in main ().");

	// обращение к статическому полю через объект
		cout <<"Now, count of objects" << M.num_obj <<".\n";

	f ("Local object.");
		f ("Another local object.");

		cout << "Before finish main() count of objects - " <<object_::num_obj<<".\n";
}

Результаты работы программы:

Create First global object.
Create Second global object.
Now, count of objects 2.
Create Object in main ().
Now, count of objects3.
Create Local object.
Count of objects - 4.
Worked function f().
Destroy Local object.
Create Another local object.
Count of objects - 4.
Worked function f().
Destroy Another local object.
Before finish main() count of objects - 3.
Destroy Object in main ().
Destroy Second global object.
Destroy First global object.
*/

// Статические методы класса
/*
# include <iostream>
using namespace std;

class prim{

		int numb;
	// статическое поле
	static int stat_;

public:
		prim (int i) {
		numb=i;
		}

	// Статическая функция. Указатель this не определен,
	// поэтому выбор объекта осуществляется по явно
	// переданному указателю. Поле stat_ не требует
	// указателя на объект,т.к. оно общий для всех объектов класса prim.
		
static void func(int i, prim *p = 0) {
	// если хотя бы один объект есть 
	if (p)
		p->numb = i;
	// если объектов класса нет
	else
		stat_ = i;
}

// Статическая функция обращается только к статическому члену класса, никаких указателей не требуется.

static void show() {
	cout << "stat_=" << stat_ << "\n\n";
}

//показ нестатического члена
void show2() {
	cout << "numb=" << numb << "\n\n";
}
};

// Инициализация статического члена класса. 
int prim::stat_ = 8;

void main() {

// До создания объектов типа prim возможен единственный способ обращения к статической функции-члену.

	prim::show();

	// Можно изменить значение статического члена класса. 
	prim::func(10);

// После создания объекта типа prim можно обратиться к статической функции обычным для абстрактных типов способом.

// Создается объект obj и его поле numb 
// становится равным 23.  
	prim obj(23);
	obj.show2();

	// Можно изменить значение созданного объекта. 
	prim::func(20, &obj); // obj.numb 20. 
	obj.show2();

	obj.func(27, &obj); // obj.numb 27. 
	obj.show2();
}
*/

// Шаблон Синглетон (Singleton pattern)
/*
// Данная конструкция позволяет создавать только один экземпляр класса, и обеспечивает глобальный доступ к этому экземпляру

# include <iostream>
using namespace std;

class Singleton{

private:

	// указатель на единственный экземпляр класса
	static Singleton*s;
	int k;

	//закрытый конструктор
	Singleton(int i){
		k = i;
	}

public:
	//функция для получения указателя на
	//единственный экземпляр класса
	static Singleton*getReference(){
	   return s;
	}

	//получение значения нестатического члена класса
	int getValue(){
		return k;
	}

	//перезапись значения нестатического члена класса
	void setValue(int i){
		k = i;
	}
};

// Инициализация статического члена класса.
Singleton* Singleton::s=new Singleton(3);

void main(){

	//получение указателя на
	//единственный экземпляр класса
	Singleton*p=Singleton::getReference();

	//работа с компонентом объекта
	cout<<p->getValue()<<"\n\n";
	p->setValue(p->getValue()+5);
	cout<<p->getValue()<<"\n\n";
}

// Класс Singleton окончательный — его нельзя расширить.
// Его конструктор закрытый — никакой метод не может создать экземпляр этого класса.
// Единственный экземпляр s класса Singleton — статический, он создается внутри класса.
// Однако можно получить указатель на этот экземпляр методом getReference(), изменить состояние экземпляра s методом setValue() или 
//просмотреть его текущее состояние методом getValue().
*/

// Перегрузка оператора ->
/*
#include <iostream>
using namespace std;
// класс, указатель на который
// будет инкапсулирован
class Temp
{
	int TEMP;
	public:
		//конструктор
		Temp(){TEMP=25;}
		//функция показа на экран
		void TempFunction(){
			cout<<"TEMP = "<<TEMP<<"\n\n";
		}
		//функция установки значения
		void TempSet(int T){
			TEMP=T;
		}
};

// класс, инкапсулирующий указатель
class MyPtr
{
	//указатель на класс Temp
	Temp*ptr;

public:
	//конструктор
	MyPtr(Temp*p=NULL){
		ptr=p;
	}

	// Оператор преобразования типа
	// от инкапсулированного к инкапсулирующему
	operator Temp*(){
		return ptr;
	};
	// Оператор селектора ->
	// который позволит обратиться
	// напрямую к "спрятанному"
	// указателю
	Temp* operator->(){
		return ptr;
	}
	//оператор ++ для смещения указателя вперед
	MyPtr operator++(){
		ptr++;
		return *this;
	}
};

void main ()
{
	//создание нового объекта
	Temp*main_ptr = new Temp;
	//простое обращение к членам
	//объекта через "родной" указатель
	main_ptr->TempFunction();

	//создание объекта класса-указателя
	MyPtr pTemp(main_ptr);
	//обращение через класс-указатель
	pTemp->TempFunction();

	//создание массива объектов
	//инкапсулируемого класса
	Temp*arr_=new Temp[3];

	//заполнение вышеозначенного массива
	//значениями от 0 до 2
	for(int i=0;i<3;i++) arr_[i].TempSet(i);

	//создание объекта класса указателя
	//и запись в него адреса массива
	//(здесь работает преобразование типа)
	MyPtr arr_temp=arr_;
	//сдвиг на один элемент вперед
	arr_temp++;
	//демонстрация результата
	arr_temp->TempFunction();

	//удаление объектов
	delete main_ptr;
	delete[]arr_;
}

Результат работы программы

TEMP = 25

TEMP = 25

TEMP = 1
*/

// Умный указатель (smart pointer)
/*
#include <iostream>
using namespace std;
class Temp
{
	int TEMP;
	public:
		//конструктор
		Temp(){TEMP=25;}
		//функция показа на экран
		void TempFunction(){
			cout<<"TEMP = "<<TEMP<<"\n\n";
		}
		//функция установки значения
		void TempSet(int T){
			TEMP=T;
		}
};
// Класс, реализующий умный указатель
class SmartPointer
{
	// Инкапсулированный указатель
	Temp*ptr;
	//счётчик копий
	int count_copy;

public:
	//конструктор
	SmartPointer (Temp*p=NULL){
		//записываем 0 при создании копий нет
		count_copy=0;
		ptr=p;
	}
	// конструктор копирования
	SmartPointer (const SmartPointer&obj){
		//создается копия - увеличиваем счётчик
		ptr=obj.ptr;
		count_copy++;
	}
	//перегрузка оператора равно
	SmartPointer operator=(const SmartPointer&obj){
		//создается копия - увеличиваем счётчик
		ptr=obj.ptr;
		ptr=obj.ptr;
		count_copy++;
		//возвращаем сам объект для ситуации a=b=c
		return *this;
	}
	// уничтожение объекта
	~SmartPointer(){
		//если объект есть и копий нет
		if(ptr!=NULL&&count_copy==0){
			cout<<"\n~Delete Object\n";
			//уничтожаем объект
			delete[]ptr;
		}
		//в противном случае(уничтожается копия)
		else{
			//уменьшаем счётчик
			count_copy--;
			cout<<"\n~Delete Copy\n";
		}
	}
	//старая добрая перегрузка селектора
	Temp* operator->(){
		return ptr;
	}
};

void main(){
	//создаем объект
	Temp*main_ptr=new Temp;
	//инициализируем этим объектом умный указатель
	SmartPointer PTR(main_ptr);
	//проверяем работу умного указателя
	PTR->TempSet(100);
	PTR->TempFunction();
	// создаем копию (работа конструктора копирования)
	SmartPointer PTR2=PTR;
}

Результат работы программы:
// работа с объектом через умный указатель
TEMP = 100
//уничтожение копии
~Delete Copy
//уничтожение самого объекта
~Delete Object
*/

// Функции с произвольным количеством и типом аргументов
/*
// Каждая функция с переменным списком параметров должна иметь механизм определения их количества и типов. 
// Существует два подхода к решению этой задачи.
// 1. Первый подход предполагает добавление в конец списка необязательных параметров специального параметра-индикатора с уникальным значением, 
// которое будет сигнализировать об окончании списка. В теле функции параметры последовательно перебираются, и их значения сравниваются с 
// заранее известным концевым признаком.
// 2. Второй подход предусматривает передачу в функцию значения реального количества фактических параметров. 
// Эту величину можно передавать в функцию с помощью одного из явно задаваемых (обязательных) параметров.

// Вычисленияе суммы заданных целых чисел с использованием количества слагаемых
#include <iostream>
using namespace std;
//Прототип функции.
long summa (int,...);
void main()
{
	cout << "\n summa(2,4,6)=" << summa (2,4,6);

	cout << "\n summa(6,1,2,3,4,5,6)="<< summa (6,1,2,3,4,5,6);

}
//Передаем количество параметров.
long summa (int k,...)
{
	 //pk содержит адрес расположения
	 //начала списка параметров.
	 //это связано с тем, что параметры
	 //располагаются по порядку
	 //в оперативной памяти
	int *pk=&k;

	//подсчет суммы
	//к - количество параметров
	long sm=0;
	for (;k;k--)
		  sm+=*(++pk);

	return sm;
}

// Вычисленияе суммы заданных целых чисел используя предопределенное значение (пусть это будет 0).
#include <iostream>
using namespace std;
// k - это теперь, всего лишь один
// из суммируемых параметров
long summa (int k,...)
{
	//начиная с k
	int *pk=&k;
	long sm=0;
	//движемся до тех пор,
	//пока не встретим значение 0
	while (*pk)
		//подсчет суммы
		 sm+=*(pk++);
	return sm;
}
void main()
{
	// тестируем
	cout << "\n summa(4,6,0)="<< summa (4,6,0);
	cout << "\n summa(1,2,3,4,5,6,0)="<< summa (1,2,3,4,5,6,0);
	cout << "\n summa(1,2,0,4,5,6,0)="<< summa (1,2,0,4,5,6,0);
 }

Результат работы программы:

summa(4,6,0)=10
summa(1,2,3,4,5,6,0)=21

// Внимание здесь функция
// доработает лишь до первого нуля
// остальные данные будут утеряны.
summa(1,2,0,4,5,6,0)=3

**************************************************************************
#include <iostream>
using namespace std;
#include <stdarg.h>
// функция подсчитывает сумму чисел количеством count
// typeof определяет, какого типа будут элементы
// true - параметры целого типа (int)
// false - параметры целого типа (double)
void AnyType(int count,bool typeof,...){
	// сумма для целочисленных параметров
	int sumi=0;
	// сумма для вещественных параметров
	double sumd=0.0;
	// создаём указатель на список параметров
	va_list arg_ptr;
	// получаем этот указатель, отталкиваясь
	// от первого фактического параметра
	va_start(arg_ptr,count);
	// пропускаем второй фактический параметр
	va_arg(arg_ptr,bool);
	// count раз считываем последующие параметры
	while(count--){
		// если typeof - true, то считываем параметры типа int
		// если typeof - false, то считываем параметры типа double
		(typeof)?sumi+=va_arg(arg_ptr,int):sumd+=va_arg(arg_ptr,double);
	}
	// закрываем список параметров
	va_end(arg_ptr);

	// если typeof - true, то показываем сумму типа int
	// если typeof - false, то показываем сумму типа double
	(typeof)?cout<<"Integer sum = "<<sumi:cout<<"Double sum = "<<sumd;
	cout<<"\n\n";
}
void main()
{
	// вызываем функцию для суммирования параметров типа int
	AnyType(4,true,3,8,9,4);
	// вызываем функцию для суммирования параметров типа double
	AnyType(3,false,2.5,1.1,3.6);
}

*/

// Шаблоны классов
/*
#include <iostream>
using namespace std;

//параметризованный класс
template <class T> class TestClass {
private:
	//объявим поле tempo
	//какого оно будет типа,
	//это можно будет выяснить ТОЛЬКО во
	//время создания конкретного экземпляра класса
	T tempo;
public:
	TestClass(){tempo=0;}
	//тестируемая функция
		T testFunc();
};

//функция-член класса TestClass
//Так как метод реализован вне класса,
//используем явное упоминание template
template <class T>
T TestClass<T>::testFunc() {
	//программа выводит на экран количество байт
	//занимаемое переменной tempo, типа T
		cout<<"Type's size is: "<<sizeof(tempo)<<"\n\n";
	return tempo;
}


void main()
{
	//создадим конкретные экземпляры класса TestClass
	//char
	TestClass<char> ClassChar;
	ClassChar.testFunc();
	//int
	TestClass<int> ClassInt;
	ClassInt.testFunc();
	//double
	TestClass<double> ClassDouble;
	ClassDouble.testFunc();
}
*/

// Наследование
/*
#include <iostream>
using namespace std;

// Класс "точка"
class Point{
protected:
	int x;
	int y;
public:
	Point(){
		x=0;
		y=0;
	}
	// получение x
	int&GetX(){
		return x;
	}
	// получение y
	int&GetY(){
		return y;
	}
};

class MyWindow: public Point{
	int width;
	int height;
public:
	MyWindow(int W,int H){
		width=W;
		height=H;
	}
	// получение ширины
	int&GetWidth(){
		return width;
	}
	// получение высоты
	int&GetHeight(){
		return height;
	}
	// функции сдвига
	void MoveX(int DX){
		x+=DX;
	}
	void MoveY(int DY){
		y=DY;
	}
	// показ на экран
	void Show(){
		cout<<"--------------\n\n";
		cout<<"X = "<<x<<"\n\n";
		cout<<"Y = "<<y<<"\n\n";
		cout<<"W = "<<width<<"\n\n";
		cout<<"H = "<<height<<"\n\n";
		cout<<"--------------\n\n";
	}
};
void main(){
	// создание объекта
	MyWindow A(10,10);
	A.Show();
	// изменение параметров
	A.GetX()=5;
	A.GetY()=3;
	A.GetWidth()=40;
	A.GetHeight()=50;
	A.Show();
	// сдвиг "окна"
	A.MoveX(2);
	A.MoveY(7);
	A.Show();
}
*/

// Множественное наследование
/*
#include <iostream>
#include <string.h>
using namespace std;

// Класс "рога"
class Roga{

protected:

	char color[25];
	int wes;

public:
		Roga(){

			strcpy(color,"Dirty");
		wes=20;

	}

	Roga(char  *c,int w){

			strcpy(color,c);
		wes=w;

	}

};

// Класс "копыта"
class Kopyta{

protected:

	char forma[25];
	int razmer;

public:
	Kopyta(){
			strcpy(forma,"Big");
		razmer=10;
	}

	Kopyta(char  *c,int w){

			strcpy(forma,c);
		razmer=w;
	}

};

// Класс "Лось", производный от
// классов "рога" и "копыта"
class Los:public Roga,public Kopyta{

	public:
	char name[255];

	Los(char  *c){
	  strcpy(name,c);
		}

	// Функция потомка может обращаться к
		// элементам обоих базовых классов
		void DisplayInfo(){

		cout<<"Name "<<name<<"\n";
			cout<<"Forma "<<forma<<"\n";
			cout<<"Color "<<color<<"\n";
		cout<<"Wes rogov "<<wes<<"\n";
			cout<<"Razmer kopyt "<<razmer<<"\n";

	}
};

void main()
{

	//создание объекта класса-потомка
		Los l("Vasya");
		l.DisplayInfo();

}
*/

// Наследование шаблонов
/*
//класс-родитель
template <class T>
class Pair
{
	T a;
	T b;
	public:
	Pair (T t1, T t2);
	//...
};

// конструктор класса родителя
template <class T>
Pair <T>::Pair (T t1, T t2) : a(t1), b(t2)
{}

// класс-потомок

template <class T>
class Trio: public Pair <T>
{
	T c;
	public:
	Trio (T t1, T t2, T t3);
	//...
};

// Заметьте, что вызов родительского конструктора
// также сопровождается передачей типа Т в качестве параметра.
template <class T>
Trio<T>::Trio (T t1, T t2, T t3): Pair <T> (t1, t2), c(t3)
{
}
*/

// Абстрактные классы
/*
#include <iostream>
#include <string.h>
using namespace std;

//абстрактный базовый класс
class Animal
{
	public:
		//кличка животного
		char Title[20];
		//простой конструктор
		Animal(char *t){
			strcpy(Title,t);
		}
		//чисто виртуальная функция
		virtual void speak()=0;
};

//класс лягушка
class Frog: public Animal
{
	public:
		Frog(char *Title): Animal(Title){};
		virtual void speak(){
			cout<<Title<<" say "<<"\'kwa-kwa\'\n";
		}
};

//класс собака
class Dog: public Animal
{
	public:
		Dog(char *Title): Animal(Title){};
		virtual void speak(){
			cout<<Title<<" say "<<"\'gav-gav\'\n";
		}
};

//класс кошка
class Cat: public Animal
{
	public:
		Cat(char *Title): Animal(Title){};
		virtual void speak(){
			cout<<Title<<" say "<<"\'myau-myau\'\n";
		}
};

//класс лев
class Lion: public Cat
{
	public:
		Lion(char *Title): Cat(Title) {};
		virtual void speak(){
			cout<<Title<<" say "<<"\'rrr-rrr\'\n";
		}

// Ошибка на этапе компиляции
//		virtual int speak(){
//			cout<<Title<<" say "<<"\'rrr-rrr\'\n";
//			return 0;
//		}

// Вызовется функция базового класса Cat   (King say 'myau-myau')
//		virtual void speak(int When) {
//			cout << Title << " say " << "\'rrr-rrr\'\n";
//		}

};


void main()
{
	// объявим массив указателей на базовый класс Animal
	// и сразу его заполним указателями, создавая объекты
	// cписок животных
	Animal *animals[4] = { new Dog("Bob"),
						  new Cat("Murka"),
						  new Frog("Vasya"),
						  new Lion("King") };

	for (int k = 0; k < 4; k++)
		animals[k]->speak();
}

Bob say 'gav-gav'
Murka say 'myau-myau'
Vasya say 'kwa-kwa'
King say 'rrr-rrr'

*/

// Виртуальный базовый класс
/*
 class A {

	public:
		int val;
  };

  class B : public A {...};

  class C : public A {...};

  class D : public B, public C{

	public:
		int Get_Val(){
		return val; //ошибка!
	}
  };

 // В вышеописанном примере доступ к члену val неоднозначен. Компилятор не поймет на какую копию val ссылаться и поэтому просигнализирует ошибку. 
 // Для разрешения неоднозначности следует либо использовать оператор разрешения видимости
  int Get_Val(){

	return B::val;

 }
// ...либо использовать виртуальный базовый класс

  class A {
	public:
			int val;
  };

  class B : public virtual A {...};

  class C : public virtual A {...};

  class D : public B, public C {

	public:
			int Get_Val() {
			return val; //все работает корректно
		}
  };
*/

// Виртуальный деструктор
/*
class Base
{
	private:
		char *sp1;
		int size;

	public:
		//конструктор
		Base(const char *S, int s){

			size=s;
			sp1=new char[size];

		}

		//деструктор
		~Base(){

			cout<<"Base";
			delete[]sp1;

		}
};
class Derived: public Base
{
	private:
		char *sp2;
		int size2;

	public:
		//конструктор
		Derived(const char *S1,int s1,const char *S2, int s2): Base(S1,s1){

			size2=s2;
			sp2=new char[size2];

		}

		//деструктор
		~Derived(){

			cout<<"Derived";
			delete[]sp2;

		}
};

Derived MyStrings(“string 1”,9,“string 2”,9);
// Когда этот объект выйдет из области видимости, сначала вызовется деструктор класса Derived, а затем деструктор базового класса Base. 
// Вся память будет аккуратно освобождена.

Base *pBase; //указатель на базовый класс
pBase=new Derived(“string 1”,9,“string 2”,9);
delete pBase;
// Компилятор "видит", что указатель pBase должен ссылаться на объекты класса Base (откуда бы ему узнать, что именно присвоено этому указателю?). 
// И вполне естественно программа вызовет только деструктор базового класса, и он удалит одну строку, но оставит в памяти другую. 
// Ведь деструктор класса Derived не вызывался. Получается классическая утечка памяти).

// Надо объявить деструкторы виртуальными
virtual ~Base(){

	cout<<"Base";
	delete[]sp1;
}

virtual ~Derived(){

	cout<<"Derived";
	delete[]sp2;
}
// Смысл таков. Поскольку деструкторы объявлены виртуальными, то их вызовы будут компоноваться уже во время выполнения программы. 
// То есть, объекты сами будут определять, какой деструктор нужно вызвать. Поскольку наш указатель pBase на самом деле ссылается на объект 
// класса Derived, то деструктор этого класса будет вызван, так же как и деструктор базового класса. Деструктор базового класса автоматически 
// выполняется после деструктора производного класса. 
*/

// Чисто виртуальный деструктор(нужен для создания абстрактного класса без чисто виртуальных функций)
/*
//абстрактный класс без виртуальных функций
class Something
{

	public:

		//а это чистый виртуальный деструктор
		virtual ~Something()=0;

};

// Этот класс абстрактный, потому что включает в себя чисто виртуальную функцию (деструктор). Поскольку деструктор виртуальный, 
// то проблемы с вызовом деструктора в будущем возникнуть не должны. Все, что осталось сделать – это дать определение этого деструктора. 
Something::~Something() {};

// Это необходимо сделать, поскольку виртуальный деструктор работает таким образом, что вначале вызывается деструктор производного класса, 
// а затем последовательно деструкторы классов, находящихся выше в цепи наследования, вплоть до базового абстрактного. Это означает, 
// что компилятор будет генерировать вызов ~Something(), даже когда класс является абстрактным, поэтому тело функции надо определять обязательно. 
// Если этого не сделать, компоновщик просто выдаст ошибку отсутствия символа
*/

// try, catch, throw
/*
# include <iostream>
using namespace std;

void main(){

	// блок try способный возбудить
	// три исключения
	try{

		// указатель и размер
		// динамического массива
		int*ptr=0;
		int size;

		// ввод размера
		cout<<"\nPut size:\n";
		cin>>size;

		// если размер выходит за пределы
		// заданно го диапазона
		if(size<1||size>500)
			// возбуждаем исключение типа char*
			// блок try обрывается
			throw "\n\nErr Size!!!\n\n";

		// иначе создаем массив
		ptr=new int [size];

		// проверяем, выделилась ли память
		if(!ptr)
			// если нет возбуждаем
			// исключение типа char*
			// блок try обрывается
			throw "\n\nErr Memory!!!\n\n";

		// иначе создаем тестовую переменную a
		// осуществляем ввод данных с
		// клавиатуры
		int a;
		cout<<"\nPut digit a:\n";
		cin>>a;

		if(a==0)
			// если a равно 0 возбуждаем
			// исключение типа int
			// блок try обрывается
			throw a;
	}

	// отлов всех исключений типа int
	catch(int s){
		cout<<"\nError - A = "<<s<<"\n\n";
	}

	// отлов всех ислючений типа char*
	catch(char*s){
		cout<<s;
	}
}
*/

// Универсальный catch
/*
# include <iostream>
using namespace std;

void main(){

	// вход в блок
	try{
		// объявление и инициализация
		// переменной
		int a;
		cout<<"\nPut digit a:\n";
		cin>>a;

		// если переменная равна нулю
		if(a==0)
			// генерация исключений
			// типа char*
			throw "URRRRRRA!!!";

	}
	// универсальный catch
	catch(...){
		cout<<"\nSome Error!!!!\n\n";
	}
}
*/

// Преобразование типов
// const_cast
/*
// const_cast используется для явного переопределения модификаторов const и/или volatile. Новый тип должен совпадать с исходным типом, 
// за исключением изменения его атрибутов const или volatile. Чаще всего оператор const_cast используется для снятия атрибута const.
#include <iostream>
using namespace std;
// указатель на объект является константным,
// следовательно, через него изменить значение
// объекта нельзя
void test_pow(const int* v){
	int*temp;
	// снимаем модификатор const
	// и теперь можем изменять объект
	temp=const_cast<int*>(v);
	// изменение объекта
	*temp= *v * *v;
}
void main(){
	int x=10;
	// на экране - 10
	cout<<"Before - "<<x<<"\n\n";
	test_pow(&x);
	// на экране - 100
	cout<<"After - "<<x<<"\n\n";
}
*/

// dynamic_cast 
/*
// dynamic_cast проверяет законность выполнения заданной операции приведения типа. Если такую операцию выполнить нельзя, 
// то выражение устанавливается равным нулю. Этот оператор в основном используется для полиморфных типов.
#include <iostream>
using namespace std;
// базовый класс
class B{
	public:
	// виртуальная функция для
	// последующего переопределения в потомке
	virtual void Test(){
		cout<<"Test B\n\n";
	}
};
// класс-потомок
class D:public B{
	public:
	// переопределение виртуальной функции
	void Test(){
		cout<<"Test D\n\n";
	}
};
void main(){
	// указатель на класс-родитель
	// и объект класса-родителя
	B *ptr_b, obj_b;
	// указатель на класс-потомок
	// и объект класса-потомка
	D *ptr_d, obj_d;

	// приводим адрес объекта (D*) к указателю типа D*
	ptr_d= dynamic_cast<D*> (&obj_d);
	// если все прошло успешно - вернулся !0
	// произошло приведение
	if(ptr_d){
		cout<<"Good work - ";
		// здесь вызов функции класса-потомка
		// на экране - Test D
		ptr_d->Test();
	}
	// если произошла ошибка - вернулся 0
	else cout<<"Error work!!!\n\n";

	// приводим адрес объекта (D*) к указателю типа B*
	ptr_b= dynamic_cast<B*> (&obj_d);
	// если все прошло успешно - вернулся !0
	// произошло приведение
	if(ptr_b){
		cout<<"Good work - ";
		// здесь вызов функции класса-потомка
		// на экране - Test D
		ptr_b->Test();
	}
	// если произошла ошибка - вернулся 0
	else cout<<"Error work!!!\n\n";

	// приводим адрес объекта (B*) к указателю типа B*
	ptr_b= dynamic_cast<B*>(&obj_b);
	// если все прошло успешно - вернулся !0
	// произошло приведение
	if(ptr_b){
		cout<<"Good work - ";
		// здесь вызов функции класса-потомка
		// на экране - Test B
		ptr_b->Test();
	}
	// если произошла ошибка - вернулся 0
	else cout<<"Error work!!!\n\n";

	// ВНИМАНИЕ!!! ЭТО НЕВОЗМОЖНО
	// попытка привести адрес объекта (B*) к указателю типа D*
	ptr_d= dynamic_cast<D*> (&obj_b);
	// если все прошло успешно - вернулся !0
	// произошло приведение
	if(ptr_d)
		cout<<"Good work - ";
	// если произошла ошибка - вернулся 0
	else cout<<"Error work!!!\n\n";
}
Результат работы программы:
Good work - Test D
Good work - Test D
Good work - Test B
Error work!!!
*/

// static_cast
/*
// static_cast выполняет неполиморфное приведение типов. Его можно использовать для любого стандартного преобразования. 
// При этом никакие проверки во время работы программы не выполняются.
#include <iostream>
using namespace std;
void main(){
	int i;
	for(i=0;i<10;i++)
		// приведение переменной i к типу double
		// результаты деления на экране, естественно
		// вещественные
		cout<<static_cast<double>(i)/3<<"\t";
}


*/

// reinterpret_cast
/*
// reinterpret_cast переводит один тип в совершенно другой. Например, его можно использовать для перевода указателя в целый тип 
// и наоборот. Оператор reinterpret_cast следует использовать для перевода типов указателей, которые несовместимы по своей природе. 
#include <iostream>
using namespace std;
void main(){
	// целочисленная переменная
	int x;
	// строка (указатель типа char)
	char*str="This is string!!!";
	// демонстрируем строку на экран
	cout<<str<<"\n\n"; // на экране - This is string!!!
	// преобразуем указатель типа char в число
	x=reinterpret_cast<int>(str);
	// демонстрируем результат
	cout<<x<<"\n\n"; // на экране - 4286208
}
*/

