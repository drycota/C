#include "pch.h"
#include "class.h"

// ����������� � ����������
/*
// �������� ������ CreateAndDestroy
class CreateAndDestroy
{
public:
	CreateAndDestroy(int value)  // �����������
	{
	  data = value;
	  cout << " Object " << data << " constructor\n";
	}

	~CreateAndDestroy()    // ����������
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

��������� ������ ���������

Object 1 constructor
Object 2 constructor
Object 2 destructor
Object 1 destructor
*/

// ������������� ������������ � ��������� �� ������
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

//����������� ������ _3D � �����������
_3D::_3D(double initX, double initY, double initZ)
{
	x = initX;
	y = initY;
	z = initZ;
	cout << "\nWhis arguments!!!\n";
}

//����������� ������ _3D ��� ����������
_3D::_3D()
{
	x=y=z=0;
	cout << "\nNo arguments!!!\n";
}

void main()
{
	//��������� ������ A, ����������
	//����������� ��� ����������
	//��� ����� ������ ���������������� �����
	//�� ������ ������� "No arguments!!!"
	_3D A;

	//��������� ������ B, ����������
	//����������� c �����������
	//��� ����� ������ ����������������
	//���������������� �����������
	//�� ������ ������� "Whis arguments!!!"
	_3D B (3,4,0);

	// ��������� ��������� �� ������ ����
	// _3D � � ���� ��������� ������������
	// ����� ������� B
	_3D*PB=&B;

	// ����� ��������� ���������� �������
	// Show()
	PB->Show();
}
*/

// ������������ ��������� ������ ��� ������
/*
class Point
{
	double x, y;
public:
	// ����������� � �����������
	// �� ���������
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
	// �������� �������
	Point A(2,3);
	// ����� ����������� �� �����
	A.Show();

	cout<<"****************************";
	// �������� ��������� �� ������
	Point*PA;

	// ������������ ��������� ������ ��� ����
	// ������ ���� Point
	// � ������� ������� - ��������� ��� ������������
	PA=new Point(4,5);

	// ��������, ���������� �� ������
	// � �����, ���� �� ����������
	if(!PA) exit(0);

	// ����� ��������� ���������� �������
	// Show()
	PA->Show();

	cout<<"****************************";
	// �������� ��������� �� ������
	Point*PB;

	// ������������ ��������� ������ ��� ������
	// �������� ���� Point
	// ��������� �� ����������
	// ������������ ���������
	// ������������ �� ���������
	PB=new Point[10];

	// ��������, ���������� �� ������
	// � �����, ���� �� ����������
	if(!PB) exit(0);

	// ����� ������� Show() ��� ������� ��������
	// ������� PB
	for(int i=0;i<10;i++){
		PB[i].Show();
	}

	// �������� ������� ��
	delete PA;

	// �������� ������� �B
	delete[]PB;
// � ������ ������� ����������� ����������� � ����������� �� ���������.
// ��� ������� � ���, ��� ��� ������������ ��������� ������ ��� ������ �������� ���������� �������� ��������� � �����������. 
// ��� ������� �������� ������������ ��������� �� ���������. ��� �������� ����� ���� ������ �����, ������ ����������� ��� ����������.
}
*/

// ����������� �������
/*
// � ������� �� ��������, ��� �������� ������������ ������� ��������� � ����������� �������� �����.
class Point
{
	double x, y;
public:
	//����������� � �����������
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
	// �������� ������� ��������
	// �������� ���������� � �����������
	Point AR[2]={Point(2,3),Point(4,5)};

	// ����� ������� Show() ��� ������� ��������
	// ������� AR
	for(int i=0;i<2;i++){
		AR[i].Show();
	}
}
*/

// ��������� this
/*
class Student	// ����� �������.
{
	char name[50]; // ���
	char surname[50]; // �������
	int age; // �������
public:
	//�����������:
	Student(char name[],char surname[],int age)
	{
		// ���������� � ����������� ���������:
		strcpy(this->name,name);
		strcpy(this->surname,surname);
		this->age=age;
	}
	void Show()
	{
		// ����� this �������� ��������������,
		// ������ ������������ ��� �����
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

// ����������� �����������
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
// �������� ������� � �������
// ������ ������ ������� - ��� ��������� ����� ������������� �������, � ��� ������, ��� ���� ������ �������� � ����, ��������, 
// ��������� ��������� �� ����������� ���������� ������� ������, �� ��� ����������� ��������� ������, ����������� �� �� �� ������� ������. 
// � ��� ������ ���������� ���������� �����, ���, ��� �������, ������� ������������ ������, �� �������������� ������� ������, 
// �� ������� �������� ������-"��������", ��� �������� � ���������� ��������� �������.
void f (ClassName o)
{
	cout << "Function f!!!\n";
}

void main()
{
	ClassName c1;
	f(c1);
}

��������� ������ ���������:

ClassName!!!
Function f!!!
~ClassName!!!
~ClassName!!!
// ����������� ���������� ������ ���� ���. ��� ���������� ��� �������� �1. ������ ���������� ����������� ������: ���� ��� ��� ����� o, 
// ������ ��� ��� ������ ������� c1. ��� ����, ��� ���������� ���������� ������, ����� ����� ������������� ���������� �������, ��������, 
// ��� ��������, ���������� ������� ������������ ����������� ���������� ������� ������.

*********************************************************************************************
// ������� ������� �� �������
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

��������� ������ ���������:

ClassName!!!
ClassName!!!
Function f
~ClassName!!!
~ClassName!!!
~ClassName!!!
// ����������� ���������� ��� ����: ��� �1 � obj. ������ ������������ ����� ���. ��� �� ���? ����, ��� ���� ���������� ��������� �1, 
// ��� ���� - obj. "������" ����� ����������� (������ �� �����) ���������� ��� ��� ����������� ���������� �������, ������� �������� ������ 
// ������������� �������. ����������� ��� �����, ����� ������� ���������� ������. ����� ����, ��� ������� ���������� ���� ��������, 
// ����������� ���������� ���������� �������. �����������, ��� ���� ����������, ��������, ������������ ����������� ���������� ������, 
// �� ���������� ���������� ������� �������� � ���������� ������������� �������.

*******************************************************************************************************
// ������������� ������ ������� ������ ��� ��������
void main()
{
	ClassName c1;

	// ��� ��!!! ������ ���������� �����������.
	ClassName c2=c1;
}

��������� ������ ���������:

ClassName!!!
~ClassName!!!
~ClassName!!!
// ����������� ���������� ���� ���: ��� �1. ��� �2 ����������� �� �����������. ������ ���������� ����������� ��� ����� ��������. 
// �, ���������, �2 �������� ������ ������ �1, ����������, �������������� ����������� ���������� ������, ���������� ������ ��� ������ 
// � ���� �� ��������� ���� ������. ��� ��������� �������� � ������.


****************************************************************************************************
// ����������� ����������� ��� ����������� ����� ��������� ����� ���������� ������� �������� ����� �������.
���_������ (const ���_������ & obj)
{
 ... // ���� ������������
}
// ����� obj - ��� ������ �� ������ ��� ����� �������. ����������� ����������� ���������� ������ ���, ����� ��������� ����� �������. 
// ����� �������, � ������������ ����������� ����� �������� "����" ������ ��� ����� ������.
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
	// ������������� ������ ������� ������
	ClassName c1;
	ClassName c2=c1;

	// �������� ������� � �������
	ClassName a;
	f(a);

	//������� ������� �� �������
	r();
}

��������� ������ ���������:

// �������� ������ �1
ClassName!!!

// ������������� ������� �2 �������� �1
Copy ClassName!!!

// �������� ������ �
ClassName!!!

// �������� � � ������� �� ��������
// ��������� ����� �
Copy ClassName!!!

// ���������� ������� f
Function f!!!

// ������������ ����� o
~ClassName!!!

// �������� ������ o
// ������ ������� r
ClassName!!!

// ���������� ������� r
Function r!!!

// ������� �� �������
// ��������� ����� ������� �
Copy ClassName!!!

// ����������� ������ o
~ClassName!!!

// ������������ ��� �����
~ClassName!!!

// ����������� ������ �
~ClassName!!!

// ����������� ������ �2
~ClassName!!!

// ����������� ������ �1
~ClassName!!!

// ������ �������� ������������ ����������� ���� ������ ������ ����������� �������������� ����� �������� � ����������, ���������� ������. 
// ���� ������ - �������� ������� �� ������ ��� �� ���������
*/

// ����������� �����
/*
class Personal
{
public:
	// ����������� � �����������
	// �� �������� ����� ������
	// ������ � ����� ������� ���
	// �� �����������, �� ������������
	// ����������� - ������������ ����,
	// ������� �� ���������� ��������
	// ������ ������������ ������
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

	// ������ ����������� �������
	// ������ ��� ����������
	// �������� �����-�� �� �������
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
	char*picture_data; // ���� � ����������
	char*name; // ���
	int age; // �������
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

// � ������ ������� ������ Name, Age, Picture ��������� ������������. ����� ����, ����� ��������� � ������������� ����������� ����������: 
// �������� ������� SetName � SetPicture, ������������ �������� ������� Name � Picture. ���������� ��������� �������� ����, ��� ���������� 
// ����������� ������� �� ����� �������� �������� � ���� ��������� ��������� �������, ������������ ����� Personal. 
// ��� ������ ����������� ������� ��������� ����������� ��������, ���������� ������� �� ������.
*/

// ������ �� �������� ������ - ������
/*
#include <iostream>
#include <string.h>

using namespace std;

class string_
{
private:
	// ������
	char* S;

	// ����� ������
	int len;
public:
	// ����������� �� ���������
	// ��� ����������
	string_();

	// ������������� �����������
	// � ����������
	string_(char* s);

	// ����������� �����������
	string_(const string_& s);

	// ����������
	~string_(){
		delete [] S;
	}

	// ����� ����������
	void Sort(string_ s[], int n);

	// ����������� �����
	// ������������ ����������
	// ������
	const char*GetStr()const
	{
		return S;
	}
	// ����� ����������� �������� ����������
	// � ������� ������������
	void SetStr()
	{
		// ���� ������ �� ������ - ��������
		if(S!=NULL)
			delete[]S;

		// ������� ������
		// � ����������� � ������������ ������
		char a[256];
		cin.getline(a,256);

		// ������������ ������
		len=strlen(a)+1;

		// �������� ������
		S = new char[len];

		// ������������ � ������
		// ��������� ������
		strcpy(S,a);
	}

	// ����� ����������� �������� ����������
	// � ������� ���������
	void SetStr2(char*str)
	{
		// ���� ������ �� ������ - ��������
		if(S!=NULL)
			delete[]S;

		// ������������ ������
		len=strlen(str)+1;

		// �������� ������
		S = new char[len];

		// ������������ � ������
		// ������ �� ���������
		strcpy(S, str);
	}
};

string_::string_()
{
	// ��������� �������������
	S = NULL;
	len = 0;
}

string_::string_(char* s)
{
	len = strlen(s);
	S = new char[len + 1];
	// ������������� �������,
	// ���������� �������������
	strcpy(S, s);
}

string_::string_(const string_& s)
{
	len = s.len;
	// ���������� �����������
	S = new char[len + 1];
	strcpy(S, s.S);
}

void string_::Sort(string_ s[], int n)
{
	//  ���������� �����
	//  ������� ��������

	string_ temp;

	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			// ��������� ���� �����
			if(strcmp(s[j].S,s[j-1].S)<0)
			{
				// ������ ������� s[j] � temp
				temp.SetStr2(s[j].S);

				// ������ ������� s[j-1] � s[j]
				s[j].SetStr2(s[j-1].S);

				// ������ ������� temp � s[j-1]
				s[j-1].SetStr2(temp.S);
			}
		}
	}
}

void main()
{
	int n,i;

	// ������ ���������� �����
	cout << "Input the number of string s:\t";
	cin >> n;

	if(n < 0)
	{
		cout << "Error number:\t" << n << endl;
		return;
	}

	// �������� �� ������ ������ Enter ("\n")
	char c[2];
	cin.getline(c, 2);

	// ������� ������ �� n �����
	string_ *s = new string_[n];

	// ���� ����� c ����������
	for(i = 0; i < n; i++)
		s[i].SetStr();

	// ���������� �����
	// ����� ����� ���������,
	// ��� ��� ������� ��������
	// ��� ������ ��������,
	// � �� ��� ������ �����������
	s->Sort(s, n);

	// ����� ��������������� �����
	for(i = 0; i < n; i++)
		cout<<"\n"<<s[i].GetStr()<<"\n";

	// �������� ������� �����
	delete [] s;
}
*/

// ���������� ����������
/*
// ������ �������������� ��������: 
// ::
// * (�������������, � �� �������� ���������)
// ?:
// sizeof
// ##
// #
// .

class Digit{
	private:
		int dig; // �����
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

		// ����������� ������ ���������
		// �������� ��������, ��� ���������
		// ��������, ������� �� �������� �
		// ��� ���� �������� - ��� �������,
		// ������� ����� ���������� ������
		// �� ��������� � ���������
		// ����� ������� ���������� � ������� this
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
	// ��������� ������ ����������
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

// ������ ������ ������ � �������������� �����������
/*
#include <iostream>
#include <string.h>

using namespace std;

class string_
{
private:
	// ������
	char* S;

	// ����� ������
	int len;
public:
	// ����������� �� ���������
	// ��� ����������
	string_();

	// ������������� �����������
	// � ����������
	string_(char* s);

	// ����������� �����������
	string_(const string_& s);

	// ����������
	~string_(){
		delete [] S;
	}

	// ����� ����������
	void Sort(string_ s[], int n);

	// ����������� �����
	// ������������ ����������
	// ������
	const char*GetStr()const
	{
		return S;
	}
	// ����� ����������� �������� ����������
	// � ������� ������������
	void SetStr()
	{
		// ���� ������ �� ������ - ��������
		if(S!=NULL)
			delete[]S;

		// ������� ������
		// � ����������� � ������������ ������
		char a[256];
		cin.getline(a,256);

		// ������������ ������
		len=strlen(a)+1;

		// �������� ������
		S = new char[len];

		// ������������ � ������
		// ��������� ������
		strcpy(S,a);
	}

	// ���������� ��������� ���������
	// ������ �������� ���������� ������ � ������� ��������� this
	// ������� ��������� ��������� �����
	string_ operator+(const string_&);

	// ���������� ��������� ���������
	// ������ �������� ���������� ������ � ������� ��������� this
	// ������� ��������� ���������� ������������ �������� ���� �����
	// � �������� ������1=������2. ����������, ��� �������� ��������
	// ��������� ������� ���������� �����������, ��� �������
	// ����������� ����������� - ��������.
	string_&operator=(const string_&);

	// ���������� ����
	// ������� ��������� �������������� ������� ������ � ���� char*
	operator char*() { return S; }
};

string_::string_()
{
	// ��������� �������������
	S = NULL;
	len = 0;
}

string_::string_(char* s)
{
	len = strlen(s);
	S = new char[len + 1];
	// ������������� �������,
	// ���������� �������������
	strcpy(S, s);
}

string_::string_(const string_& s)
{
	len = s.len;
	// ���������� �����������
	S = new char[len + 1];
	strcpy(S, s.S);
}

void string_::Sort(string_ s[], int n)
{
	//  ���������� �����
	//  ������� ��������

	string_ temp;

	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			// ��������� ���� �����
			if(strcmp(s[j].S,s[j-1].S)<0)
			{
				// ������, ����� � ��� ����
				// ������������� �������� �����
				// �� �� ��������� � ��������������
				// ������� SetStr2, ������� ������������
				// � ������� ������� ��� ������������

				// ������ ������� s[j] � temp
				temp=s[j];

				// ������ ������� s[j-1] � s[j]
				s[j]=s[j-1];

				// ������ ������� temp � s[j-1]
				s[j-1]=temp;
			}
		}
	}
}

// ������� ��������� ����� (�������������
// �������� ����)
string_ string_::operator+(const string_ &str)
{
	// �������� ���������� �������
	string_ s;

	// ���������� ����� ����� ������
	s.len = len + str.len;

	// ��������� ������ ��� ����� ������
	s.S = new char[s.len + 1];

	// ������������� ������ ����� ������
	strcpy(s.S, S);

	//  ������������� ������ ����� ������
	strcat(s.S, str.S);

	//  ������� ������ �������
	return s;
}

// �������, ����������� ���������� ������������
string_& string_::operator=(const string_ &str)
{
	// �������������� �������� STRING = STRING;
	// (������������ ������ ����),
	// ��� STRING ���������� ������ string
	if(this == &str)
		 return *this;

	// ���� ������� ����� �� ���������
	// ��� ������, � ������� ������������ ������
	// �� �������������
	if(len != str.len || len == 0)
	{
		// �������� ������ ������
		delete [] S;
		// ���������� ����� ����� ������
		len = str.len;
		// ��������� ������ ��� ����� ������
		S = new char[len + 1];
	}

	// ������������� ������
	strcpy(S, str.S);

	// ������� ������ �� "������ ����"
	// ��������� ����� �������� ������������
	// ������������ �������� ���� �����
	// ��������, string_ a, b, c; a = b = c;
	return *this;
}


void main()
{
	int n,i;

	// ������ ���������� �����
	cout << "Input the number of string s:\t";
	cin >> n;

	if(n < 0)
	{
		cout << "Error number:\t" << n << endl;
		return;
	}

	// �������� �� ������ ������ Enter ("\n")
	char c[2];
	cin.getline(c, 2);

	// ������� ������ �� n �����
	string_ *s = new string_[n];

	// ���� ����� c ����������
	for(i = 0; i < n; i++)
		s[i].SetStr();

	// ���������� �����
	// ����� ����� ���������,
	// ��� ��� ������� ��������
	// ��� ������ ��������,
	// � �� ��� ������ �����������
	s->Sort(s, n);

	// ����� ��������������� �����
	for(i = 0; i < n; i++)
		cout<<"\n"<<s[i].GetStr()<<"\n";

	// �������� ������� �����
	delete [] s;

	cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	//��������� �� ���� �������� + � ��������������

	string_ A,B,C,RES;

	A="Ivanov ";
	B="Ivan ";
	C="Ivanovich";
	RES=A+B+C;
	cout<<RES.GetStr()<<"\n\n";
}
*/

// ���������� ���������� � ����������
/*
// ���������� ���������� �������� ++ � -- ����� �� ���������� �� ���������� ������ ������� ��������. ������� �������, ������� ����������� 
// ������: operator++ � operator--, ���������� ���������� �������� ��� ����� ������.
// ��� ����������� ����������� �������� "++" � "--" ��������-������� ������ ����� ��� ���� �������������� �������� ���� int. 
// ����� � ��������� ����� ������������ ����������� ���������, �� ���������� ������ ������� � ���������� ���� int. ��� ���� �������� 
// ���������� !�� �����!, � �������� ��� � ������� ����� ����� ����. 

// �����, ����������� ������ � "����� �����"
class Pair{

	// ����� �����.
	int N;
	// ������������ �����.
	double x;
public:
	// ����������� c �����������
	Pair(int n, double xn)
	{
		N = n;
		x = xn;
	}
	// ������� ��� ������ ������ �� �����
	void display()
	{
		cout << "\nPair: N = " << N << " x = " << x << "\n";
	}
	// ������������ ������� (���������� --):
	Pair& operator -- ()
	{
		// ��������� ���������� �������
		// � ������ ��� � ���������� ���
		// �� ����� ������ ���������
		N /= 10;
		x /= 10;
		return *this;
	}
	// ������������ ������� (����������� --):
	Pair& operator -- (int k)
	{
		// �������� ��������� ����������
		// ������� � �����������
		// ���������� ���� Pair
		// (������� ������������ �����
		// �������� ��������������� ���������
		// int k ������������ ��� ��������� 0.)
		Pair temp(0,0.0);
		temp.N=N+k;
		temp.x=x+k;

		// ��������� ������ � 10 ���
		N /= 10;
		x /= 10;

		// ���������� ������� �������� �������.
		// ����� "����������� �����"
		// �� ���������� ������� �����������
		// �����, �. �. � �������� �=B++
		// � � ������������ �������
		// �������� ������� B, ����� ��� ��� B
		// ����������
		return temp;
	}
};
void main()
{
	// ������� ������ Z ������ � ���
	// �� � ����� ������������������
	Pair Z(10,20.2);

	// ����� ������� � ������������ ����
	cout<<"\nObject Z (before):\n";
	Z.display();

	cout<<"\n-----------------\n";

	// ����������� ������� Pref ���������
	// � ���������� ������ (� ������ ������
	// ������� ��������� Z, � ����� ����������
	// ������������).

	Pair Pref=--Z;

	// ���������� ��������� ������
	// ���������� �����
	cout<<"\nPrefix\n";
	cout<<"\nObject Pref:\n";
	Pref.display();
	cout<<"\nObject Z (after):\n";
	Z.display();

	cout<<"\n-----------------\n";

	// ����������� ������� Postf ���������
	// � ����������� ������ (� ������ ������
	// ������� ���������� ������������,
	// � ����� ��������� Z).
	Pair Postf=Z--;

	// ���������� ��������� ������
	// ����������� �����
	cout<<"\nPostfix\n";
	cout<<"\nObject Postf:\n";
	Postf.display();
	cout<<"\nObject Z (after):\n";
	Z.display();
}
____________________________________________________________

��������� ������ ���������:

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

// ���������� ��������� ��������������
/*
// ��������� A [ i ], ��� A - ������ ������������ ���� class, �������������� ������������ ��� A.operator [ ] ( i )
class A{

	// ������ �� 10 ���������
	// ���� int
		int a[10];

	// ������ �������
	int size;

public:

	// ����������� ��� ����������
		A(){
		size=10;
		for (int i = 0; i < 10; i++)

		// ��������, ��� �������� [], �������������� �����,
		// � ������������ ������ �, �������� �����������,
		// ��� ��� ��� ����������� ��� ������ ������� ���� int.

			a [i] = i + 1;
	}

	// ���������� ���������
	// ��������������
	// ������� �� ������ �����������
	// ��� �������� ������[i]=��������
	// �� ����� ������ ��������������
	// �������� ��� ������
		int&operator[](int j){

		// ������� ����������� �������
			return a [j];
	}

	// ������� ������� ����������
	// ������ �������
	int Get () const {
		return size;
	}
};

void main () {

	int i,j;

	// ������ � ����� �������� ���� �
	A object;

	cout<<"\nOne object:\n";

	for(i=0;i<object.Get();i++){

		// ��������� array[i] ���������������� ���
		// object.operator [](j).
		cout<<object[i]<<" ";
	}
	cout<<"\n\n";

	// ������ � �������� �������� ���� �
		A array [3];

	cout<<"\nArray of objects:\n";

	for(i=0;i<3;i++){
		for(j=0;j<object.Get();j++){

			// ��������� array[i][j] ���������������� ���
			// (array [i]).operator [](j).
			// ������ �� ���� �������� [] �������� �����������,
			// ��� ��� ����������� ��� ������ �������.
			// ��� ���� �������, ����� ��� ����� ��� ��������.
			// ������ �������� [] - ����������������,
			// ��� ��� ����������� ������ �������� [] �������� ������ ���� �.

				cout << array [i][j] << " ";
		}
		cout <<"\n\n";
	}
}
___________________________________

��������� ������ ���������:

One object:
1 2 3 4 5 6 7 8 9 10

Array of objects:
1 2 3 4 5 6 7 8 9 10

1 2 3 4 5 6 7 8 9 10

1 2 3 4 5 6 7 8 9 10
*/

// �������� "������� ������".()
/*
class MyPoint{
	int X;
	int Y;
public:
	MyPoint(){
		X=0;
		Y=0;
	}

	// ������������� �������� ()
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

	//��������� �������� ����� �������
	P(2,3);
	P.Show();
}
*/

// ���������� ���������� new, new[], delete, delete[]
/*
# include <iostream>
using namespace std;
// ���������� ��� �������
// ��������� ������
#include <malloc.h>

class SomeClass{
	int some;

public:
	// ������������� ��������� new � delete,
	// ����� ����� ������������ ��������������
	// ���������, ������������ ������ ����������
	void * operator new(size_t size,char* str = "New");
	void   operator delete(void* ptr);

	// ������������� ��������� new [] � delete []
	void * operator new [] (size_t fullsize, char* str = "New []");
	void   operator delete [] (void* ptr);
};

void * SomeClass::operator new( size_t size,char* str)
{
	cout <<"\n"<<str<<"\n";
	
	// �����, ��� ��������� ������ ������������ ����������� �������
	// void *malloc( size_t size );
	// � �� ��������� size - ���������� ����, ������� �����
	// ��������. ���� ������ ����������, �� �� malloc ������������
	// ����� ������ ����������� �����.
	
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
	
	// �����, ��� ��������� ������ ������������ ����������� �������
	// void *malloc( size_t size );
	// � �� ��������� size - ���������� ����, ������� �����
	// ��������. ���� ������ ����������, �� �� malloc ������������
	// ����� ������ ����������� �����.
	
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
	// ��� ������� ������ ������������ ����������� �������
	// void free( void * memblock );
	// ������� free ������� ������, memblock - ����� ������
	// ���������� �������
	
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
	// ���������� �������� new( size_t size,char* str="New")
	// �� ����� size ����� ���������� ������ ������ SomeClass,
	// � str ������� �������� �� ��������� �.�. "New"
	
	SomeClass *p = new SomeClass;

	// ���������� �������� new[](size_t size,char* str="New[]")
	// �� ����� size ����� ���������� ������ ������ SomeClass,
	// ���������� �� ���������� ������������� ���������
	// � str ������� �������� �� ��������� �.�. "New[]"
	
	SomeClass *r = new SomeClass[3];

	// ���������� �������� delete(void* ptr)
	// �� ����� ptr ����� ���������� ����� ������,
	// ���������� ��� ������ �
	
	delete p;

	// ���������� �������� delete[](void* ptr)
	// �� ����� ptr ����� ���������� ����� ������,
	// ���������� ��� ������ r
	
	delete[]r;
}
_____________________________________________________

��������� ������ ��������� :

New

Memory new - OK!!!

New[]

Memory new[] - OK!!!

Delete memory

Delete[] memory
*/

// ������������� �������
/*
// ����� - �������������
class rect{

	// ������ � ������
	int Width, Height;
	//������ ��� �����������
	char Symb;
	// �������� ������������� ������� ��� ������ �������:
	friend void friend_put(rect*r,char s);

  public:
	// �����������.
	rect(int wi, int hi, char si)
	{
		Width = wi;
		Height = hi;
		Symb = si;
	}
	// ����� ������ �� �����
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
// ������������� ������� ������
// ������� � ���������� �������:
void friend_put(rect*r, char s)
{
	// ��������� � ��������� ����� ����� ���������
	// �. �. ������� "������" � �������
	r->Symb = s;
}
void main ()
{
	// �������� ��������
	rect A(5,3,'A');
	rect B(3,5,'B');
	A.display ();
	B.display ();
	//������ �������� � �������
	//friend-�������
	friend_put(&A,'a');
	friend_put(&B,'b');
	A.display ();
	B.display ();
}

********************************************************************************************
// ������������� ������� ���� ������� "����� �� ���������" � "������ �� ���������". 

#include <iostream>
using namespace std;

// ���������������  ���������� � ������ line_.
class  line_;

// �����  "����� �� ���������":
class point_
{
	// ���������� ����� �� ���������.
		float x, y;
public:
		// �����������.
		point_(float xn = 0, float yn = 0)
		{
			x = xn;
			y = yn;
		}
		friend float uclon(point_,line_);
};

// ����� "������ �� ���������":
class line_
{
	// ��������� ������.
		float A, B, C;
public:
		// �����������.
		line_(float a, float b, float c)
		{
			A = a;
			B = b;
			C = c;
		}
			friend float uclon(point_,line_);
};
// ������� ����������� ������������� �������.
float uclon(point_ p, line_ l)
{
	// ���������� ���������� ������
	return l.A * p.x + l.B * p.y + l.C;
}
void main()
{
	// ����������� ����� P.
	point_ P(16.0,12.3);

	// ����������� ������ L.
	line_ L(10.0,-42.3,24.0);

	cout << "\n Result" << uclon(P,L) << "\n\n";
}

*/

// ������������� ���������� ����������
/*
#include <iostream>
using namespace std;

// ����� ����������� ������
// � ���������� ���������
class Flag
{
	bool flag;
	// ������������� ������� (����������
	// ��������� ! - ������ �������� �����
	// �� ���������������)
	friend Flag& operator !(Flag&f);
 public:

	 // �����������.
	 Flag(bool iF)
	 {
		 flag = iF;
	 }
	 // ������������ ������� ������ �������� �����
	 // � ��������� �������:
	 void display(){
		 if(flag) cout<<"\nTRUE\n";
		 else cout<<"\nFALSE\n";
	 }
};

// ����������� �������������
// ��������-�������.
// (this �� ����������, ������� 1 ��������)
Flag& operator !(Flag & f)
{
	//������ �������� �� ���������������
	f.flag=!f.flag;
	return f;
}

void main()
{
	Flag A(true);

	// ����� ���������� ��������
	A.display();

	// ������ �������� �� ���������������
	// � ������� �������������� ���������
	A=!A;
	// ����� ����������� ��������
	A.display();
}

��������� ���������� ���������:

TRUE

FALSE
*/

// ���������� ����������(�������������� �� ������� ������� ���������)
/*
#include <iostream>
using namespace std;

// ����� "�����"
class Point
{
	 // ���������� �����
	 int X;
	 int Y;
 public:

	 // �����������
	 Point(int iX,int iY){
		 X=iX;
		 Y=iY;
	 }

	 //����� �� �����
	 void Show(){
		cout<<"\n+++++++++++++++++++++\n";
		cout<<"X = "<<X<<"\tY = "<<Y;
		cout<<"\n+++++++++++++++++++++\n";
	 }

	 // ������������� �������� +
	 // ����� ������ ��� �������� Point+int
	 Point&operator+(int d){
		 Point P(0,0);
		 P.X=X+d;
		 P.Y=Y+d;
		 return P;
	 }
	 // ������� ������� �
	 // privat-������ ��� ���
	 // ���������� ���������� ����������
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

// ���������� ����������
// ��� �������� int + Point
// ������ � private-������
// ����� ����������� �������
Point&operator+(int d,Point&Z){
		 Point P(0,0);
		 P.SetX(d+Z.GetX());
		 P.SetY(d+Z.GetY());
		 return P;
}

void main()
{
	// �������� �������
		Point A(3,2);
	A.Show();

	//��������-����� +
	Point B=A+5;
	B.Show();

	//���������� ��������
	Point C=2+A;
	C.Show();
}
*/

// ���������� �����/������ ������
/*
#include <iostream>
using namespace std;

// ����� "�����"
class Point
{
	 // ���������� �����
	 int X;
	 int Y;
 public:

	 // �����������
	 Point(int iX,int iY){
		 X=iX;
		 Y=iY;
	 }
	// ������������� ������� ���������� ����� � ������ ������
	 friend istream& operator>>(istream& is, Point& P);
	 friend ostream& operator<<(ostream& os, const Point& P);

};
//���� ������ ����� �����
istream& operator>>(istream&is, Point&P){
	cout<<"Set X\t";
	is >> P.X;
	cout<<"Set Y\t";
		is >> P.Y;
		return is;
}
//����� ������ ����� �����
ostream& operator<<(ostream&os, const Point&P){
	os << "X = " << P.X << '\t';
		os << "Y = " << P.Y << '\n';
		return os;
}

void main()
{
	// �������� �������
		Point A(0,0);

	// ��������� ���� � �����
	cin>>A;
	cout<<A;

	// ������������� ���������
	Point B(0,0);
	cin>>A>>B;
	cout<<A<<B;
}
*/

// ������������� ������
/*
// 1. ������������� ����� ������ ���� ��������� ��� ���� ������, "���������������� ������".
// 2. ��� ������������ ������� ������-����� ����� �������� �������������� ��� ������� ������ ��� �������� ������������� friend.
// 3. ��� ���������� ������ �������� � ������������� ������, �� �� ��������.
// 4. ������������� ����� ����� ���� ��������� ����� (����), ��� ������ ��� �������������.

# include <iostream>
using namespace std;
// ���������� � ������,
// ������� ����� ������ ����
class	Banana;

// �����, ������� �����
// �������������
class	Apple{
public:
	void F_apple(Banana ob);
};
// �����, ������� "���������" � ����� "�������"
class	Banana{
	int	x,y;
public:
	Banana(){
		x=y=777;
	}
	// ���������� ������
	friend	Apple;
};
//�������, �������
//������������� ���������� "������"
void Apple::F_apple(Banana ob)
{
	//��������� � private - ������
	cout<<ob.x<<"\n";
	cout<<ob.y<<"\n";
}
void main(){
	Banana b;
	Apple a;
	a.F_apple(b);
}
*/

// ����������� ���� ������
/*
// ����������� ���� ������ ������ ���� ��������������� ����� ����������� ������ � �� ������� �������� ������� ����� ������.
# include <iostream>
# include <string.h>
using namespace std;

class object_{
	char *str;
public:
	//����������� ���� ������
	static int num_obj;

	//�����������
		object_ (char *s){
			str = new char [strlen (s) + 1];
		strcpy ( str, s );
		cout <<"Create " << str <<'\n';

		// ����������� �������� ��������
		num_obj ++ ;
		}

	//����������
		~object_ (){
		cout <<"Destroy " << str << '\n';
		delete str;

		// ��������� �������� ��������
		num_obj --;
		}
};

// �������������. �� ���� �������
// �������� ����� int!
int object_::num_obj = 0;

// �������� ���������� ��������
object_ s1 ("First global object.");
object_ s2 ("Second global object.");

// ��������������� �������
void f (char *str) {
	 // ��������� ������
		object_ s(str);
	 // ����� ��������� � ������������ ����
	 // ��� �������� �������
		cout <<"Count of objects - " <<object_::num_obj<<".\n";
		cout <<"Worked function f()" <<".\n";
}

void main () {
	// ����� ��������� � ������������ ����
		cout <<"Now, count of objects " <<object_::num_obj<<".\n";
	object_ M ("Object in main ().");

	// ��������� � ������������ ���� ����� ������
		cout <<"Now, count of objects" << M.num_obj <<".\n";

	f ("Local object.");
		f ("Another local object.");

		cout << "Before finish main() count of objects - " <<object_::num_obj<<".\n";
}

���������� ������ ���������:

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

// ����������� ������ ������
/*
# include <iostream>
using namespace std;

class prim{

		int numb;
	// ����������� ����
	static int stat_;

public:
		prim (int i) {
		numb=i;
		}

	// ����������� �������. ��������� this �� ���������,
	// ������� ����� ������� �������������� �� ����
	// ����������� ���������. ���� stat_ �� �������
	// ��������� �� ������,�.�. ��� ����� ��� ���� �������� ������ prim.
		
static void func(int i, prim *p = 0) {
	// ���� ���� �� ���� ������ ���� 
	if (p)
		p->numb = i;
	// ���� �������� ������ ���
	else
		stat_ = i;
}

// ����������� ������� ���������� ������ � ������������ ����� ������, ������� ���������� �� ���������.

static void show() {
	cout << "stat_=" << stat_ << "\n\n";
}

//����� �������������� �����
void show2() {
	cout << "numb=" << numb << "\n\n";
}
};

// ������������� ������������ ����� ������. 
int prim::stat_ = 8;

void main() {

// �� �������� �������� ���� prim �������� ������������ ������ ��������� � ����������� �������-�����.

	prim::show();

	// ����� �������� �������� ������������ ����� ������. 
	prim::func(10);

// ����� �������� ������� ���� prim ����� ���������� � ����������� ������� ������� ��� ����������� ����� ��������.

// ��������� ������ obj � ��� ���� numb 
// ���������� ������ 23.  
	prim obj(23);
	obj.show2();

	// ����� �������� �������� ���������� �������. 
	prim::func(20, &obj); // obj.numb 20. 
	obj.show2();

	obj.func(27, &obj); // obj.numb 27. 
	obj.show2();
}
*/

// ������ ��������� (Singleton pattern)
/*
// ������ ����������� ��������� ��������� ������ ���� ��������� ������, � ������������ ���������� ������ � ����� ����������

# include <iostream>
using namespace std;

class Singleton{

private:

	// ��������� �� ������������ ��������� ������
	static Singleton*s;
	int k;

	//�������� �����������
	Singleton(int i){
		k = i;
	}

public:
	//������� ��� ��������� ��������� ��
	//������������ ��������� ������
	static Singleton*getReference(){
	   return s;
	}

	//��������� �������� �������������� ����� ������
	int getValue(){
		return k;
	}

	//���������� �������� �������������� ����� ������
	void setValue(int i){
		k = i;
	}
};

// ������������� ������������ ����� ������.
Singleton* Singleton::s=new Singleton(3);

void main(){

	//��������� ��������� ��
	//������������ ��������� ������
	Singleton*p=Singleton::getReference();

	//������ � ����������� �������
	cout<<p->getValue()<<"\n\n";
	p->setValue(p->getValue()+5);
	cout<<p->getValue()<<"\n\n";
}

// ����� Singleton ������������� � ��� ������ ���������.
// ��� ����������� �������� � ������� ����� �� ����� ������� ��������� ����� ������.
// ������������ ��������� s ������ Singleton � �����������, �� ��������� ������ ������.
// ������ ����� �������� ��������� �� ���� ��������� ������� getReference(), �������� ��������� ���������� s ������� setValue() ��� 
//����������� ��� ������� ��������� ������� getValue().
*/

// ���������� ��������� ->
/*
#include <iostream>
using namespace std;
// �����, ��������� �� �������
// ����� ��������������
class Temp
{
	int TEMP;
	public:
		//�����������
		Temp(){TEMP=25;}
		//������� ������ �� �����
		void TempFunction(){
			cout<<"TEMP = "<<TEMP<<"\n\n";
		}
		//������� ��������� ��������
		void TempSet(int T){
			TEMP=T;
		}
};

// �����, ��������������� ���������
class MyPtr
{
	//��������� �� ����� Temp
	Temp*ptr;

public:
	//�����������
	MyPtr(Temp*p=NULL){
		ptr=p;
	}

	// �������� �������������� ����
	// �� ������������������ � ����������������
	operator Temp*(){
		return ptr;
	};
	// �������� ��������� ->
	// ������� �������� ����������
	// �������� � "�����������"
	// ���������
	Temp* operator->(){
		return ptr;
	}
	//�������� ++ ��� �������� ��������� ������
	MyPtr operator++(){
		ptr++;
		return *this;
	}
};

void main ()
{
	//�������� ������ �������
	Temp*main_ptr = new Temp;
	//������� ��������� � ������
	//������� ����� "������" ���������
	main_ptr->TempFunction();

	//�������� ������� ������-���������
	MyPtr pTemp(main_ptr);
	//��������� ����� �����-���������
	pTemp->TempFunction();

	//�������� ������� ��������
	//���������������� ������
	Temp*arr_=new Temp[3];

	//���������� ��������������� �������
	//���������� �� 0 �� 2
	for(int i=0;i<3;i++) arr_[i].TempSet(i);

	//�������� ������� ������ ���������
	//� ������ � ���� ������ �������
	//(����� �������� �������������� ����)
	MyPtr arr_temp=arr_;
	//����� �� ���� ������� ������
	arr_temp++;
	//������������ ����������
	arr_temp->TempFunction();

	//�������� ��������
	delete main_ptr;
	delete[]arr_;
}

��������� ������ ���������

TEMP = 25

TEMP = 25

TEMP = 1
*/

// ����� ��������� (smart pointer)
/*
#include <iostream>
using namespace std;
class Temp
{
	int TEMP;
	public:
		//�����������
		Temp(){TEMP=25;}
		//������� ������ �� �����
		void TempFunction(){
			cout<<"TEMP = "<<TEMP<<"\n\n";
		}
		//������� ��������� ��������
		void TempSet(int T){
			TEMP=T;
		}
};
// �����, ����������� ����� ���������
class SmartPointer
{
	// ����������������� ���������
	Temp*ptr;
	//������� �����
	int count_copy;

public:
	//�����������
	SmartPointer (Temp*p=NULL){
		//���������� 0 ��� �������� ����� ���
		count_copy=0;
		ptr=p;
	}
	// ����������� �����������
	SmartPointer (const SmartPointer&obj){
		//��������� ����� - ����������� �������
		ptr=obj.ptr;
		count_copy++;
	}
	//���������� ��������� �����
	SmartPointer operator=(const SmartPointer&obj){
		//��������� ����� - ����������� �������
		ptr=obj.ptr;
		ptr=obj.ptr;
		count_copy++;
		//���������� ��� ������ ��� �������� a=b=c
		return *this;
	}
	// ����������� �������
	~SmartPointer(){
		//���� ������ ���� � ����� ���
		if(ptr!=NULL&&count_copy==0){
			cout<<"\n~Delete Object\n";
			//���������� ������
			delete[]ptr;
		}
		//� ��������� ������(������������ �����)
		else{
			//��������� �������
			count_copy--;
			cout<<"\n~Delete Copy\n";
		}
	}
	//������ ������ ���������� ���������
	Temp* operator->(){
		return ptr;
	}
};

void main(){
	//������� ������
	Temp*main_ptr=new Temp;
	//�������������� ���� �������� ����� ���������
	SmartPointer PTR(main_ptr);
	//��������� ������ ������ ���������
	PTR->TempSet(100);
	PTR->TempFunction();
	// ������� ����� (������ ������������ �����������)
	SmartPointer PTR2=PTR;
}

��������� ������ ���������:
// ������ � �������� ����� ����� ���������
TEMP = 100
//����������� �����
~Delete Copy
//����������� ������ �������
~Delete Object
*/

// ������� � ������������ ����������� � ����� ����������
/*
// ������ ������� � ���������� ������� ���������� ������ ����� �������� ����������� �� ���������� � �����. 
// ���������� ��� ������� � ������� ���� ������.
// 1. ������ ������ ������������ ���������� � ����� ������ �������������� ���������� ������������ ���������-���������� � ���������� ���������, 
// ������� ����� ��������������� �� ��������� ������. � ���� ������� ��������� ��������������� ������������, � �� �������� ������������ � 
// ������� ��������� �������� ���������.
// 2. ������ ������ ��������������� �������� � ������� �������� ��������� ���������� ����������� ����������. 
// ��� �������� ����� ���������� � ������� � ������� ������ �� ���� ���������� (������������) ����������.

// ����������� ����� �������� ����� ����� � �������������� ���������� ���������
#include <iostream>
using namespace std;
//�������� �������.
long summa (int,...);
void main()
{
	cout << "\n summa(2,4,6)=" << summa (2,4,6);

	cout << "\n summa(6,1,2,3,4,5,6)="<< summa (6,1,2,3,4,5,6);

}
//�������� ���������� ����������.
long summa (int k,...)
{
	 //pk �������� ����� ������������
	 //������ ������ ����������.
	 //��� ������� � ���, ��� ���������
	 //������������� �� �������
	 //� ����������� ������
	int *pk=&k;

	//������� �����
	//� - ���������� ����������
	long sm=0;
	for (;k;k--)
		  sm+=*(++pk);

	return sm;
}

// ����������� ����� �������� ����� ����� ��������� ���������������� �������� (����� ��� ����� 0).
#include <iostream>
using namespace std;
// k - ��� ������, ����� ���� ����
// �� ����������� ����������
long summa (int k,...)
{
	//������� � k
	int *pk=&k;
	long sm=0;
	//�������� �� ��� ���,
	//���� �� �������� �������� 0
	while (*pk)
		//������� �����
		 sm+=*(pk++);
	return sm;
}
void main()
{
	// ���������
	cout << "\n summa(4,6,0)="<< summa (4,6,0);
	cout << "\n summa(1,2,3,4,5,6,0)="<< summa (1,2,3,4,5,6,0);
	cout << "\n summa(1,2,0,4,5,6,0)="<< summa (1,2,0,4,5,6,0);
 }

��������� ������ ���������:

summa(4,6,0)=10
summa(1,2,3,4,5,6,0)=21

// �������� ����� �������
// ���������� ���� �� ������� ����
// ��������� ������ ����� �������.
summa(1,2,0,4,5,6,0)=3

**************************************************************************
#include <iostream>
using namespace std;
#include <stdarg.h>
// ������� ������������ ����� ����� ����������� count
// typeof ����������, ������ ���� ����� ��������
// true - ��������� ������ ���� (int)
// false - ��������� ������ ���� (double)
void AnyType(int count,bool typeof,...){
	// ����� ��� ������������� ����������
	int sumi=0;
	// ����� ��� ������������ ����������
	double sumd=0.0;
	// ������ ��������� �� ������ ����������
	va_list arg_ptr;
	// �������� ���� ���������, ������������
	// �� ������� ������������ ���������
	va_start(arg_ptr,count);
	// ���������� ������ ����������� ��������
	va_arg(arg_ptr,bool);
	// count ��� ��������� ����������� ���������
	while(count--){
		// ���� typeof - true, �� ��������� ��������� ���� int
		// ���� typeof - false, �� ��������� ��������� ���� double
		(typeof)?sumi+=va_arg(arg_ptr,int):sumd+=va_arg(arg_ptr,double);
	}
	// ��������� ������ ����������
	va_end(arg_ptr);

	// ���� typeof - true, �� ���������� ����� ���� int
	// ���� typeof - false, �� ���������� ����� ���� double
	(typeof)?cout<<"Integer sum = "<<sumi:cout<<"Double sum = "<<sumd;
	cout<<"\n\n";
}
void main()
{
	// �������� ������� ��� ������������ ���������� ���� int
	AnyType(4,true,3,8,9,4);
	// �������� ������� ��� ������������ ���������� ���� double
	AnyType(3,false,2.5,1.1,3.6);
}

*/

// ������� �������
/*
#include <iostream>
using namespace std;

//����������������� �����
template <class T> class TestClass {
private:
	//������� ���� tempo
	//������ ��� ����� ����,
	//��� ����� ����� �������� ������ ��
	//����� �������� ����������� ���������� ������
	T tempo;
public:
	TestClass(){tempo=0;}
	//����������� �������
		T testFunc();
};

//�������-���� ������ TestClass
//��� ��� ����� ���������� ��� ������,
//���������� ����� ���������� template
template <class T>
T TestClass<T>::testFunc() {
	//��������� ������� �� ����� ���������� ����
	//���������� ���������� tempo, ���� T
		cout<<"Type's size is: "<<sizeof(tempo)<<"\n\n";
	return tempo;
}


void main()
{
	//�������� ���������� ���������� ������ TestClass
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

// ������������
/*
#include <iostream>
using namespace std;

// ����� "�����"
class Point{
protected:
	int x;
	int y;
public:
	Point(){
		x=0;
		y=0;
	}
	// ��������� x
	int&GetX(){
		return x;
	}
	// ��������� y
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
	// ��������� ������
	int&GetWidth(){
		return width;
	}
	// ��������� ������
	int&GetHeight(){
		return height;
	}
	// ������� ������
	void MoveX(int DX){
		x+=DX;
	}
	void MoveY(int DY){
		y=DY;
	}
	// ����� �� �����
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
	// �������� �������
	MyWindow A(10,10);
	A.Show();
	// ��������� ����������
	A.GetX()=5;
	A.GetY()=3;
	A.GetWidth()=40;
	A.GetHeight()=50;
	A.Show();
	// ����� "����"
	A.MoveX(2);
	A.MoveY(7);
	A.Show();
}
*/

// ������������� ������������
/*
#include <iostream>
#include <string.h>
using namespace std;

// ����� "����"
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

// ����� "������"
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

// ����� "����", ����������� ��
// ������� "����" � "������"
class Los:public Roga,public Kopyta{

	public:
	char name[255];

	Los(char  *c){
	  strcpy(name,c);
		}

	// ������� ������� ����� ���������� �
		// ��������� ����� ������� �������
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

	//�������� ������� ������-�������
		Los l("Vasya");
		l.DisplayInfo();

}
*/

// ������������ ��������
/*
//�����-��������
template <class T>
class Pair
{
	T a;
	T b;
	public:
	Pair (T t1, T t2);
	//...
};

// ����������� ������ ��������
template <class T>
Pair <T>::Pair (T t1, T t2) : a(t1), b(t2)
{}

// �����-�������

template <class T>
class Trio: public Pair <T>
{
	T c;
	public:
	Trio (T t1, T t2, T t3);
	//...
};

// ��������, ��� ����� ������������� ������������
// ����� �������������� ��������� ���� � � �������� ���������.
template <class T>
Trio<T>::Trio (T t1, T t2, T t3): Pair <T> (t1, t2), c(t3)
{
}
*/

// ����������� ������
/*
#include <iostream>
#include <string.h>
using namespace std;

//����������� ������� �����
class Animal
{
	public:
		//������ ���������
		char Title[20];
		//������� �����������
		Animal(char *t){
			strcpy(Title,t);
		}
		//����� ����������� �������
		virtual void speak()=0;
};

//����� �������
class Frog: public Animal
{
	public:
		Frog(char *Title): Animal(Title){};
		virtual void speak(){
			cout<<Title<<" say "<<"\'kwa-kwa\'\n";
		}
};

//����� ������
class Dog: public Animal
{
	public:
		Dog(char *Title): Animal(Title){};
		virtual void speak(){
			cout<<Title<<" say "<<"\'gav-gav\'\n";
		}
};

//����� �����
class Cat: public Animal
{
	public:
		Cat(char *Title): Animal(Title){};
		virtual void speak(){
			cout<<Title<<" say "<<"\'myau-myau\'\n";
		}
};

//����� ���
class Lion: public Cat
{
	public:
		Lion(char *Title): Cat(Title) {};
		virtual void speak(){
			cout<<Title<<" say "<<"\'rrr-rrr\'\n";
		}

// ������ �� ����� ����������
//		virtual int speak(){
//			cout<<Title<<" say "<<"\'rrr-rrr\'\n";
//			return 0;
//		}

// ��������� ������� �������� ������ Cat   (King say 'myau-myau')
//		virtual void speak(int When) {
//			cout << Title << " say " << "\'rrr-rrr\'\n";
//		}

};


void main()
{
	// ������� ������ ���������� �� ������� ����� Animal
	// � ����� ��� �������� �����������, �������� �������
	// c����� ��������
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

// ����������� ������� �����
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
		return val; //������!
	}
  };

 // � ������������� ������� ������ � ����� val ������������. ���������� �� ������ �� ����� ����� val ��������� � ������� ���������������� ������. 
 // ��� ���������� ��������������� ������� ���� ������������ �������� ���������� ���������
  int Get_Val(){

	return B::val;

 }
// ...���� ������������ ����������� ������� �����

  class A {
	public:
			int val;
  };

  class B : public virtual A {...};

  class C : public virtual A {...};

  class D : public B, public C {

	public:
			int Get_Val() {
			return val; //��� �������� ���������
		}
  };
*/

// ����������� ����������
/*
class Base
{
	private:
		char *sp1;
		int size;

	public:
		//�����������
		Base(const char *S, int s){

			size=s;
			sp1=new char[size];

		}

		//����������
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
		//�����������
		Derived(const char *S1,int s1,const char *S2, int s2): Base(S1,s1){

			size2=s2;
			sp2=new char[size2];

		}

		//����������
		~Derived(){

			cout<<"Derived";
			delete[]sp2;

		}
};

Derived MyStrings(�string 1�,9,�string 2�,9);
// ����� ���� ������ ������ �� ������� ���������, ������� ��������� ���������� ������ Derived, � ����� ���������� �������� ������ Base. 
// ��� ������ ����� ��������� �����������.

Base *pBase; //��������� �� ������� �����
pBase=new Derived(�string 1�,9,�string 2�,9);
delete pBase;
// ���������� "�����", ��� ��������� pBase ������ ��������� �� ������� ������ Base (������ �� ��� ������, ��� ������ ��������� ����� ���������?). 
// � ������ ����������� ��������� ������� ������ ���������� �������� ������, � �� ������ ���� ������, �� ������� � ������ ������. 
// ���� ���������� ������ Derived �� ���������. ���������� ������������ ������ ������).

// ���� �������� ����������� ������������
virtual ~Base(){

	cout<<"Base";
	delete[]sp1;
}

virtual ~Derived(){

	cout<<"Derived";
	delete[]sp2;
}
// ����� �����. ��������� ����������� ��������� ������������, �� �� ������ ����� ������������� ��� �� ����� ���������� ���������. 
// �� ����, ������� ���� ����� ����������, ����� ���������� ����� �������. ��������� ��� ��������� pBase �� ����� ���� ��������� �� ������ 
// ������ Derived, �� ���������� ����� ������ ����� ������, ��� �� ��� � ���������� �������� ������. ���������� �������� ������ ������������� 
// ����������� ����� ����������� ������������ ������. 
*/

// ����� ����������� ����������(����� ��� �������� ������������ ������ ��� ����� ����������� �������)
/*
//����������� ����� ��� ����������� �������
class Something
{

	public:

		//� ��� ������ ����������� ����������
		virtual ~Something()=0;

};

// ���� ����� �����������, ������ ��� �������� � ���� ����� ����������� ������� (����������). ��������� ���������� �����������, 
// �� �������� � ������� ����������� � ������� ���������� �� ������. ���, ��� �������� ������� � ��� ���� ����������� ����� �����������. 
Something::~Something() {};

// ��� ���������� �������, ��������� ����������� ���������� �������� ����� �������, ��� ������� ���������� ���������� ������������ ������, 
// � ����� ��������������� ����������� �������, ����������� ���� � ���� ������������, ������ �� �������� ������������. ��� ��������, 
// ��� ���������� ����� ������������ ����� ~Something(), ���� ����� ����� �������� �����������, ������� ���� ������� ���� ���������� �����������. 
// ���� ����� �� �������, ����������� ������ ������ ������ ���������� �������
*/

// try, catch, throw
/*
# include <iostream>
using namespace std;

void main(){

	// ���� try ��������� ���������
	// ��� ����������
	try{

		// ��������� � ������
		// ������������� �������
		int*ptr=0;
		int size;

		// ���� �������
		cout<<"\nPut size:\n";
		cin>>size;

		// ���� ������ ������� �� �������
		// ������� �� ���������
		if(size<1||size>500)
			// ���������� ���������� ���� char*
			// ���� try ����������
			throw "\n\nErr Size!!!\n\n";

		// ����� ������� ������
		ptr=new int [size];

		// ���������, ���������� �� ������
		if(!ptr)
			// ���� ��� ����������
			// ���������� ���� char*
			// ���� try ����������
			throw "\n\nErr Memory!!!\n\n";

		// ����� ������� �������� ���������� a
		// ������������ ���� ������ �
		// ����������
		int a;
		cout<<"\nPut digit a:\n";
		cin>>a;

		if(a==0)
			// ���� a ����� 0 ����������
			// ���������� ���� int
			// ���� try ����������
			throw a;
	}

	// ����� ���� ���������� ���� int
	catch(int s){
		cout<<"\nError - A = "<<s<<"\n\n";
	}

	// ����� ���� ��������� ���� char*
	catch(char*s){
		cout<<s;
	}
}
*/

// ������������� catch
/*
# include <iostream>
using namespace std;

void main(){

	// ���� � ����
	try{
		// ���������� � �������������
		// ����������
		int a;
		cout<<"\nPut digit a:\n";
		cin>>a;

		// ���� ���������� ����� ����
		if(a==0)
			// ��������� ����������
			// ���� char*
			throw "URRRRRRA!!!";

	}
	// ������������� catch
	catch(...){
		cout<<"\nSome Error!!!!\n\n";
	}
}
*/

// �������������� �����
// const_cast
/*
// const_cast ������������ ��� ������ ��������������� ������������� const �/��� volatile. ����� ��� ������ ��������� � �������� �����, 
// �� ����������� ��������� ��� ��������� const ��� volatile. ���� ����� �������� const_cast ������������ ��� ������ �������� const.
#include <iostream>
using namespace std;
// ��������� �� ������ �������� �����������,
// �������������, ����� ���� �������� ��������
// ������� ������
void test_pow(const int* v){
	int*temp;
	// ������� ����������� const
	// � ������ ����� �������� ������
	temp=const_cast<int*>(v);
	// ��������� �������
	*temp= *v * *v;
}
void main(){
	int x=10;
	// �� ������ - 10
	cout<<"Before - "<<x<<"\n\n";
	test_pow(&x);
	// �� ������ - 100
	cout<<"After - "<<x<<"\n\n";
}
*/

// dynamic_cast 
/*
// dynamic_cast ��������� ���������� ���������� �������� �������� ���������� ����. ���� ����� �������� ��������� ������, 
// �� ��������� ��������������� ������ ����. ���� �������� � �������� ������������ ��� ����������� �����.
#include <iostream>
using namespace std;
// ������� �����
class B{
	public:
	// ����������� ������� ���
	// ������������ ��������������� � �������
	virtual void Test(){
		cout<<"Test B\n\n";
	}
};
// �����-�������
class D:public B{
	public:
	// ��������������� ����������� �������
	void Test(){
		cout<<"Test D\n\n";
	}
};
void main(){
	// ��������� �� �����-��������
	// � ������ ������-��������
	B *ptr_b, obj_b;
	// ��������� �� �����-�������
	// � ������ ������-�������
	D *ptr_d, obj_d;

	// �������� ����� ������� (D*) � ��������� ���� D*
	ptr_d= dynamic_cast<D*> (&obj_d);
	// ���� ��� ������ ������� - �������� !0
	// ��������� ����������
	if(ptr_d){
		cout<<"Good work - ";
		// ����� ����� ������� ������-�������
		// �� ������ - Test D
		ptr_d->Test();
	}
	// ���� ��������� ������ - �������� 0
	else cout<<"Error work!!!\n\n";

	// �������� ����� ������� (D*) � ��������� ���� B*
	ptr_b= dynamic_cast<B*> (&obj_d);
	// ���� ��� ������ ������� - �������� !0
	// ��������� ����������
	if(ptr_b){
		cout<<"Good work - ";
		// ����� ����� ������� ������-�������
		// �� ������ - Test D
		ptr_b->Test();
	}
	// ���� ��������� ������ - �������� 0
	else cout<<"Error work!!!\n\n";

	// �������� ����� ������� (B*) � ��������� ���� B*
	ptr_b= dynamic_cast<B*>(&obj_b);
	// ���� ��� ������ ������� - �������� !0
	// ��������� ����������
	if(ptr_b){
		cout<<"Good work - ";
		// ����� ����� ������� ������-�������
		// �� ������ - Test B
		ptr_b->Test();
	}
	// ���� ��������� ������ - �������� 0
	else cout<<"Error work!!!\n\n";

	// ��������!!! ��� ����������
	// ������� �������� ����� ������� (B*) � ��������� ���� D*
	ptr_d= dynamic_cast<D*> (&obj_b);
	// ���� ��� ������ ������� - �������� !0
	// ��������� ����������
	if(ptr_d)
		cout<<"Good work - ";
	// ���� ��������� ������ - �������� 0
	else cout<<"Error work!!!\n\n";
}
��������� ������ ���������:
Good work - Test D
Good work - Test D
Good work - Test B
Error work!!!
*/

// static_cast
/*
// static_cast ��������� ������������� ���������� �����. ��� ����� ������������ ��� ������ ������������ ��������������. 
// ��� ���� ������� �������� �� ����� ������ ��������� �� �����������.
#include <iostream>
using namespace std;
void main(){
	int i;
	for(i=0;i<10;i++)
		// ���������� ���������� i � ���� double
		// ���������� ������� �� ������, �����������
		// ������������
		cout<<static_cast<double>(i)/3<<"\t";
}


*/

// reinterpret_cast
/*
// reinterpret_cast ��������� ���� ��� � ���������� ������. ��������, ��� ����� ������������ ��� �������� ��������� � ����� ��� 
// � ��������. �������� reinterpret_cast ������� ������������ ��� �������� ����� ����������, ������� ������������ �� ����� �������. 
#include <iostream>
using namespace std;
void main(){
	// ������������� ����������
	int x;
	// ������ (��������� ���� char)
	char*str="This is string!!!";
	// ������������� ������ �� �����
	cout<<str<<"\n\n"; // �� ������ - This is string!!!
	// ����������� ��������� ���� char � �����
	x=reinterpret_cast<int>(str);
	// ������������� ���������
	cout<<x<<"\n\n"; // �� ������ - 4286208
}
*/

