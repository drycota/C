#include "pch.h"
#include "file.h"

// ������� ���������� stdio.h
/*
������� ���������� stdio.h

--------------------------------------------------------------------------------
FILE *fopen(const char *filename, const char *mode)



������� ��������� ����.

filename - ���� � �����

mode - ��� �������

r - ������, ���� ����� ���, �� ������ ������� ���������� ������ (���������� 0)
w - ������, ���� ����� ���, �� ���� ��������, ���� ���� �������� ���������� ���������
a - ���������� � �����, ���� ����� ���, �� �� ��������
r+ ������ � ������ (���� ������ ������������)
w+ - ������ � ������ (������� ������ ��� � w)
a+ - ���������� � ������ (������� ������ ��� � a)
����������: ��� ������������� ������ ������������� ��� ���������� �������� �����. ��� ��������� �������� ����� ������� ���������� �������� ����� b. ��������, br.
���� ������� ���������� �������, �� �� ������������ ��������� �� �������� ����, � ��������� ������ - ����.

����������: ��������� �� �������� ���� ������� ������� � ���� ������ FILE*.

--------------------------------------------------------------------------------
int fclose( FILE *stream )



������� ��������� ����.

stream - ��������� �� ����������� ����.

���� �� �������� �������, �� ������ ������� ���������� 0, ��� EOF � ������ ������.

����������: EOF (End Of File) - ����������� ����� �����.

--------------------------------------------------------------------------------
char *fgets( char *string, int n, FILE *stream )



��������� ������ ������� � ������� �������.

���������� ���������������:

...���� ��� ������ ������ �������� �� ����� ������� ( �� ���������� � ������ )
...���� ��������� ����� �����
...���� ������� n-1 ��������.
string - c�����, � ������� �������� ��������� ������

n - ���������� ��������� � string

stream - ��������� �� �������� ����

���� �� ������ ������� ������� ���������� ��������� ������, ���� ��������� ������ ��� ��������� ����� ����� ������������ 0.


--------------------------------------------------------------------------------
int fputs( const char *string, FILE *stream )



���������� ������ � ����, ������� � ������� �������.

string - ������ ��� ������

stream - ��������� �� �������� ����, ���� ������������� ������

���� ������� ������������ ������� �� �� ������������ ��������������� ��������. ��� ������ ������������ EOF.


--------------------------------------------------------------------------------
size_t fread( void *buffer, size_t size, size_t count, FILE *stream )



������� ��������� ������ �� ����� � �����.

buffer - ����� �������, ���� ��������� ������

size - ������ �������� ������� � ������

count - ������������ ���������� ��������� ��� ����������

stream - ��������� �� �������� ����.

������� ���������� ���������� ��������� ����.

����������: ��� ������ size_t ��������� � ���������� stdio.h ��������� �������: typedef unsigned int size_t;. ������� �������, ��� ������� ����������� int.

--------------------------------------------------------------------------------
size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream )



������� ���������� ������ ������ � ����.

buffer - ����� �������, ��� ���������� ������

size - ������ �������� ������� � ������

count - ������������ ���������� ��������� ��� ������ � ����

stream - ��������� �� �������� ����.

������� ���������� ���������� ���������� ����.


--------------------------------------------------------------------------------
int feof( FILE *stream )



������� ��������� ��������� �� ����� �����.

stream - ��������� �� �������� ����

������� ���������� ��������� ��������, ���� ��������� ����� �����, ���� ������������ � ��������� ������.


--------------------------------------------------------------------------------
int _fileno( FILE *stream )



������ ������� ���������� ���������� �����.

stream - ��������� �� �������� ����.


--------------------------------------------------------------------------------
int fseek ( FILE *stream, int offset [, int whence] )



������������� �������� � �����

stream - ��������� �� �������� ����

offset - ��������, ���������� � ������ �� ������ �����

whence - �����, �� ������� ������������ ��������

SEEK_SET (0) - ������ �����
SEEK_CUR (1) - ������� �������� ��������� �����
SEEK_END (2) - ����� ����� (EOF)
������� ���������� �������� 0, ���� ��������� ����� ������� ���������, � ��������� �������� � ������ ���������� ����������.


--------------------------------------------------------------------------------

*/

// ����� ������� ��� ������ � �������
/*
stdio.h - �������������� � �������� ������.

--------------------------------------------------------------------------------

rename (char * oldname, char * newname)

��������������� ����.

oldname - ���� � ������� ��� �����

newname - ���� � ����� ��� �����

������� ���������� 0, ���� ��� ����� ���� ������� ��������, � ��������� ��������, ���� ������ �� ���������.

����������: ������!!! ���� ������� �� ������ ����� ���, �� � ����� ���� - ���� ����� �� ������ ������������, �� � ��������.

--------------------------------------------------------------------------------

int remove(const char * filename)

������� ����.

filename - ���� � ��� �����

������� ���������� 0, ���� ��� ���� ��� ������� ������, � ��������� ��������, ���� �������� �� ���������.

����������: �������!!! � ������ �������� ���� ������ ���� ������. ����� ����, �� ���������, ��� �������� ����������.

--------------------------------------------------------------------------------

io.h - ����� ������.

--------------------------------------------------------------------------------

_findfirst(char * path, _finddata_t * fileinfo)

������� ����� �� ���������� ����, ��������������� �����.

����������: ����� - ������, �������� ������, ���������� ������� * (����� ������������������ ����� ��������) � ? (����� ���� ������)
path - ������, � ������� ���������� ���������� ���� � �����.

fileinfo - ��������� �� ������ ���������, � ������� ��������� ���������� � ��������� �����. ��������� �������� ��������� ����:

unsigned attrib - �������� ���������� �� ��������� �����.
_A_NORMAL - ������� ���� ��� �������� �� ������ ��� ������.
_A_RDONLY - ���� ������ ��� ������.
_A_HIDDEN - ������� ����.
_A_SYSTEM - ��������� ����.
_A_SUBDIR - ����������.
_A_ARCH - �������� ����.
time_t time_create - �����/���� �������� ����� (����� -1 ��� FAT ������).
time_t time_access - �����/���� ���������� �������� ����� (����� -1 ��� FAT ������).
time_t time_write - �����/���� ���������� �������������� �����
_fsize_t size - ������ �����
char name[260] - ��� �����
���� �� ������� �������, ���������� � ������ ��������� ����� ��������� � ������ ��������� _finddata_t. ��� ���� � ����������� ������ ������������ "������", ���������� ���������� ����������, ������� ���������� ����� ���������� �� ������ ��������� �����. � ���� ������ ������� ������ ���������� �����, ��������� � ���������� ������� ������.

���� ����� ���������� ��������, ������� ������ -1.


--------------------------------------------------------------------------------

_findnext(long done, _finddata_t * fileinfo)

������� ������������ ������� �� ��������� ��������� ���� � ������.

done - ���������� ����� ������ ������ � ������.

fileinfo - ��������� �� ������ ���������, � ������� ��������� ���������� � ��������� ��������� �����.

���� ��������� ����� ������ ������, ������� ������ -1.


--------------------------------------------------------------------------------

_findclose(long done)

������� ������� ������ �� ������ ��������� ������.

done - ���������� ����� ������ ������ � ������.


*/

// ������� ���������� io.h
/*
int _access( const char *path, int mode )



������� ���������� ���������� ����� ��� ����������.

path - ���� � ����� ��� ����������

mode - ����� ��� ��������

00 - �������� �� �������������
02 - �������� �� ���������� �� ������
04 - �������� �� ���������� �� ������
06 - �������� �� ������ � ������
���� ���������� ����, ������� ���������� ����, � ������ ���������� -1.

����������: ���������� ����� ��������� ������ �� �������������.

--------------------------------------------------------------------------------
long _filelength( int handle )



���������� ������ ����� � ������.

handle - ���������� �����.

� ������ ������ ������� ���������� -1.


--------------------------------------------------------------------------------
int _locking( int handle, int mode, long nbytes )



��������� ��� ������������ ����� ����� ������� � ������� ������� � �����.

handle - ���������� �����

mode - ��� ����������

_LK_LOCK - ��������� �����, ���� ������������� ����� �� ���������� ������� ����������� ����� 1 �������.���� ����� 10 ������� ����� �� ������������� ������� ���������� ������ � ���������� -1
_LK_NBLCK - ��������� �����, ���� ������������� ����� �� ���������� ������� ���������� ������ � ���������� -1
_LK_NBRLCK - �� �� �����, ��� � _LK_NBLCK
_LK_RLCK - �� �� �����, ��� � _LK_LOCK
_LK_UNLCK - ������������� ����, ������� ���� �� ����� �������������
nbytes - ���������� ���� ��� ����������

������� locking ���������� -1, ���� ���������� ������ � 0 � ������ ������.

����������: ��� ������ ���� ������� ����� io.h, ����� ���������� sys/locking.h

*/

// �������� �� ������ � ������������
/*
���������� direct.h

--------------------------------------------------------------------------------

int _mkdir( const char *dirname )

������� ���������� �� ���������� ����.

dirname - ���� � ��� ��� ����������� ����������.


--------------------------------------------------------------------------------

int _rmdir( const char *dirname )

������� ���������� �� ���������� ����.

dirname - ���� � ��� ��� ��������� ����������.


--------------------------------------------------------------------------------

��� ������� ���������� -1 � ������ ������.


--------------------------------------------------------------------------------

����������: ������!!! ��� �������������� ���������� ����� ������������ ������� rename �� ���������� stdio.h.
��������!!! ������� � ������������� ����� ������ ������ ����������!!!


*/

// ����������� ������
/*
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
using namespace std;

// �������, ��������� �� ����� ������
void RussianMessage(char *str){
	char message[100];
	//������� ������ �� ��������� Windows
	//� ��������� MS DOS
	CharToOem(str,message);
	cout<<message;
}
// ������� ����������� �����
bool CopyFile(char *source,char *destination){
	const int size=65536;
	FILE *src,*dest;
	// �������� �����
	if(!(src=fopen(source,"rb"))){
		return false;
	}
	// ��������� ����������� �����
	int handle=_fileno(src);

	// ��������� ������ ��� ������
	char *data=new char[size];
	if(!data){
		return false;
	}
	// �������� �����, ���� ����� ������������� �����������
	if(!(dest=fopen(destination,"wb"))){
		delete []data;
		return false;
	}
	int realsize;
	while (!feof(src)){
		// ������ ������ �� �����
		realsize=fread(data,sizeof(char),size,src);
		// ������ ������ � ����
		fwrite(data,sizeof(char),realsize,dest);
	}

	// �������� ������
	fclose(src);
	fclose(dest);
	return true;
}
void main(){
	// __MAX_PATH - ���������, ������������ ������������ ������ ����.
	// ����� ��������� ���������� � stdlib.h
	char source[_MAX_PATH];
	char destination[_MAX_PATH];
	char answer[20];
	RussianMessage("\n������� ���� � �������� ����������� �����:\n");
	// ��������� ���� � ������� �����
	cin.getline(source,_MAX_PATH);
	// �������� ���������� �� ����
	if(_access(source,00)==-1){
		RussianMessage("\n������ �������� ���� ��� �������� �����\n");
		return;
	}
	RussianMessage("\n������� ���� � �������� ������ �����:\n");
	// ��������� ���� � ������� �����
	cin.getline(destination,_MAX_PATH);
	// �������� �� ������������� �����
	if(_access(destination,00)==0){
		RussianMessage("\n����� ���� ��� ���������� ������������ ���(1 - �� /2 - ���)?\n");
		cin.getline(answer,20);
		if(!strcmp(answer,"2")){
			RussianMessage("\n�������� ��������\n");
			return;
		}
		else if(strcmp(answer,"1")){
			RussianMessage("\n������������ ����\n");
			return;
		}
		if(_access(destination,02)==-1){
			RussianMessage("\n��� ������� � ������.\n");
			return;
		}
	}

	// ����������� �����
	if(!CopyFile(source,destination)){
		RussianMessage("\n������ ��� ������ � ������\n");
	}
}
*/

// ������ ���������. ���� "��������".
/*
// ����� ���� ������� � ���, ��� ������������ �� ��������� ���������� ������� ������ �������� �����, � ����� ������ ����������. 
// � ����� � ��������, � ������� �� ������ ������������� ������ ���, ���������� �������� ���� words.txt. ���� ���� ������ ��������� 
// ��������� ���������� ����, ������������� � ������� (���� ��� ������).

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <time.h<
#include <sys\locking.h>
#include <string.h>
#include <ctype.h>

using namespace std;

// ������������ ����� �����
#define MAX_WORD_LENGTH 21

// ���-�� �������
int Tries = 10;

// ���-�� ��������� ����
int CountWords = 0;

// �������� �����
bool LoadWord(FILE * file, char * word)
{
   int i = 0;
   char s[MAX_WORD_LENGTH] = {0};
   // ���-�� ���� � �����
   static int count = -1;

   if(count == -1)
   {
	  // ������� ���������� ����
	  while(!feof(file))
	  {
		 fgets(s, MAX_WORD_LENGTH, file);
		 count++;
	  }
	  // ���� ���?
	  if(count == 0)
		 return false;
	  // ������� ��������� ��������� � ������ �����
	  fseek(file, 0, 0);
   }

   // ��������� �����
   int n = rand() % count;
   // ����� �����
   while(i <= n)
   {
	  fgets(s, MAX_WORD_LENGTH, file);
	  i++;
   }
   // ���������� ����� �����
   int wordlen = strlen(s);
   // ����������� ����� ����� 2 �����
   if(wordlen <= 1)
	  return false;

   // ������� Enter (� DOS'� 2 ����� 13 10)
   if(s[wordlen - 1] == 10)
	  s[wordlen - 2] = 0;
   else if(s[wordlen - 1] == 13)
	  s[wordlen - 1] = 0;
   // �������� �����
   strcpy(word, s);
   // �������� ���������� �����
   int hFile = _fileno(file);
   // ��������� ������ �����
   int size = _filelength(hFile);

   // ���������� �����
   fseek(file, 0, 0);
   _locking(hFile, _LK_NBLCK, size);

   return true;
}

// ����
void Game(char * word)
{
   // ������� � ������� �����
   strupr(word);

   int len = strlen(word);
   // ������-�����
   char * copy = new char[len + 1];
   memset(copy, '*', len);
   copy[len] = 0;

   // ������� + �������
   char letters[52];

   int i, j = 0;
   for(i = 0; i < 26; i++)
   {
	  letters[j++] = i + 'A';
	  letters[j++] = ' ';
   }
   // ���������� ����
   letters[51] = 0;

   // �����
   char letter;

   char * pos;
   bool replace = false;

   do {
	  // ������� ������
	  system("cls");
	  cout << copy << endl << endl;
	  cout << letters << endl << endl;
	  cout << "Count of tries: " << Tries << endl << endl;
	  cout << "Input any letter:\t";

	  cin >> letter;
	  // �������� ������
	  Beep(500, 200);

	  // if(letter >= 'A' && letter <= 'Z'
	  // || letter >= 'a' && letter <= 'z')

	  // �����?
	  if(!isalpha(letter))
	  {
		 cout << "It's not a letter" << endl;
		 // �������� �� 1 �������
		 Sleep(1000);
		 continue;
	  }

	  // ������� ����� � �������
	  letter = toupper(letter);

	  // ����� ����� � ��������
	  pos = strchr(letters, letter);

	  // ����� ����� ��� ����
	  if(pos == 0)
	  {
		 cout << "This letter have been already pressed" << endl;
		 Sleep(1000);
		 continue;
	  }
	  else
	  {
		 // ������� ����� �� ��������
		 pos[0] = ' ';
	  }

	  // ����� ����� � �����
	  for(i = 0; i < len; i++)
	  {
		 if(word[i] == letter)
		 {
			copy[i] = letter;
			replace = true;
		 }
	  }

	  if(replace == false)
		 Tries--;
	  else
		 replace = false;

	  // ������� ������
	  if(strcmp(word, copy) == 0)
	  {
		 system("cls");
		 cout << copy << endl << endl;
		 cout << letters << endl << endl;
		 cout << "Count of tries: " << Tries << endl << endl;
		 cout << "Congratulation !!!" << endl;
		 CountWords++;
		 break;
	  }

   } while(Tries != 0);

   delete [] copy;
}

void main()
{
   // ��������� ���� �� ������ � �������� ������
   FILE * f = fopen("words.txt", "rb");

   // ���� ���� �� ��������
   if(f == 0)
   {
	  // ������
	  perror("Open");
	  return;
   }

   srand(time(0));

   char Word[20];
   // �������� ��������� �����
   if(!LoadWord(f, Word))
   {
	  // ���� ��������
	  cout << "Error !!!" << endl;
	  fclose(f);
	  return;
   }

   char answer;
   // ������, ���� �� �������
   do
   {
	  Game(Word);
	  // ���� ������� �� ��������, �� �����
	  if(Tries == 0)
	  {
		 cout << "Count of words: " << CountWords << endl;
		 cout << "Bye-bye" << endl;
		 break;
	  }
	  // ���� ��������
	  cout << "Continue ??? (Y/N)\t";

	  cin >> answer;
	  // ��� ������?
	  if(answer == 'Y' || answer == 'y')
		 if(!LoadWord(f, Word))
		 {
			cout << "Error !!!" << endl;
			fclose(f);
			return;
		 }

   }while(answer == 'Y' || answer == 'y');


   // �������� ����������
   int hFile = _fileno(f);

   // ������������� �����
   int size = _filelength(hFile);
   fseek(f, 0, 0);
   _locking(hFile, _LK_UNLCK, size);
   fclose(f);
}


*/

// C��������� �������� ��������� � ����
/*
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
// ���������, ��������
// ���������� � ��������
struct Man{
	//���
	char name[255];
	//�������
	int age;
};
void main()
{
	//�������� �������� ���������
	Man A,B;
	//������ � ������ A
	//����������, ����������
	//� ����������
	cout<<"\nEnter name:\n";
	cin>>A.name;
	cout<<"\nEnter age:\n";
	cin>>A.age;

	//�������� ����� �� ������
	FILE*f=fopen("Test.txt","w+");
	if(!f) exit(0);
	//������ ������� � � ����
	fwrite(&A,sizeof(Man),1,f);
	fclose(f);

	//�������� ����� �� ������
	f=fopen("Test.txt","r+");
	if(!f) exit(0);
	//���������� ����������� �����
	//� ������ B
	fread(&B,sizeof(Man),1,f);
	//�������� ����� �� ������
	fclose(f);

	//����� ���������� �� �����
	cout<<"\nName - "<<B.name<<"\n\nAge - "<<B.age<<"\n\n";
}
*/

// ������ ��������� �� ������ � �������
/*
// ����� ��������� ������� �������������� � ��������
#include <stdio.h>
// ����� ��������� ������� ��� ������ ������
#include <io.h>
#include <string.h>
#include <iostream>
using namespace std;
// ��� ������� AnsiToOem
#include <windows.h>

// ������������� ������������ ����
void RenameFile();

// ������� ������������ ����
void RemoveFile();

// ����� ������ � ��������
void Dir();

void main()
{
	// ���������� ������� ����� ���� ��� ����������
	cout << "Please, select preffer number...\n";

	//����� ������������
	char ch;
	do{
		// �������������
		cout << "\n1 - Rename\n";
		// �������
		cout << "2 - Remove\n";
		// ����������� ��������� �����(�������)
		cout << "3 - View some folder\n";
		// �����
		cout << "0 - Exit\n\n";
		cin >> ch;

		// ����������� � ��������
		// ���������������  �������
		switch(ch)
		{
			case '1':
				RenameFile();
			break;
			case '2':
				RemoveFile();
			break;
			case '3':
				Dir();
			break;
		}
	} while(ch != '0');      // ����� �� ���������
}

// ������������� ������������ ����
void RenameFile()
{
	char oldName[50], newName[50];

	// � ����� ���������� �������� ������������ ��� (oldName),
	cout << "Enter old name:";
	cin >> oldName;

	// � � ������ ����� ���(newName)
	cout << "Enter new name:";
	cin >> newName;

	// ���������� �������������� � �������� ����������
	if (rename(oldName, newName) != 0)
		cout << "Error!\n Couldn't rename file. Check old and new filename...\n\n";
	else
		cout << "Ok...\n\n";
}

// ������� ������������ ����
void RemoveFile()
{
	char Name[50];
	// �������� ��� � ���� � ���������� �����
	cout << "Enter name:";
	cin >> Name;

	//������� ���� � ��������� ���������
	if (remove(Name) != 0)
		cout << "Error!\n Couldn't remove file. Check filename...\n";
	else
		cout << "Ok...\n" ;
}

// ����� ������ � ��������
void Dir()
{
	// �������� ���� (��������, ����� Temp �� ����� C, ���������
	// ����� ��� �������: c:\temp\)
	char path[70];
	cout << "\nEnter full path (for example, C:\\):";
	cin >> path;

	// �������� ����� ������
	char mask[15];
	cout << "\nEnter mask (for example, *.* or *.txt):";
	cin >> mask;

	// �������� ��� ������, �� ������� ���������
	// �.�. ��� ����� ����� ������������ � ���
	strcat(path, mask);

	// ���������� ��������� fileinfo �� ��������� _finddata_t
	// � �������� ������������� ������� ��������� _finddata_t
	_finddata_t *fileinfo=new _finddata_t;

	// �������� �����
	long done = _findfirst(path,fileinfo);

	// ���� done ����� ��������� -1,
	// �� ����� ����� �����������
	int MayWeWork = done;

	// �������, �������� ���������� � ���������� �������� ������.
	int count = 0;
	while (MayWeWork!=-1)
	{
		count++;
		// �������������� ��� ���������� �����
		// �� ������, ���� ��� �������������
		AnsiToOem(fileinfo->name,fileinfo->name);
		// ����������� ��� ���������� �����
		cout << fileinfo->name << "\n\n";
		// �������� ����� ��������� ���� �� ������
		MayWeWork = _findnext(done, fileinfo);
	}
	// ����� ��������� � ���������� ��������� ������.
	cout << "\nInformation: was found " << count;
	cout << " file(s) in folder..." << path << "\n\n";

	// ������� ������
	_findclose(done);
	delete fileinfo;
}
*/

// ������ �� ������ � ������������
/*
#include <iostream>
#include <direct.h>
#include <stdio.h>

using namespace std;

// ������������� ������������ ����������
void RenameDirectory();

// ������� ������������ ����������
void RemoveDirectory();

// ������� ����������
void CreateDirectory();

void main()
{
	// ���������� ������� ����� ���� ��� ����������
	cout << "Please, select preffer number...\n";

	//����� ������������
	char ch;
	do{
		// �������������
		cout << "\n1 - Rename\n";
		// �������
		cout << "2 - Remove\n";
		// �������
		cout << "3 - Create\n";
		// �����
		cout << "0 - Exit\n\n";
		cin >> ch;

		// ����������� � ��������
		// ���������������  �������
		switch(ch)
		{
			case '1':
				RenameDirectory();
			break;
			case '2':
				RemoveDirectory();
			break;
			case '3':
				CreateDirectory();
			break;
		}
	} while(ch != '0');      // ����� �� ���������
}

// ������������� ������������ ����������
void RenameDirectory()
{
	char oldName[50], newName[50];

	// � ����� ���������� �������� ������������ ��� (oldName),
	cout << "Enter old name:";
	cin >> oldName;

	// � � ������ ����� ���(newName)
	cout << "Enter new name:";
	cin >> newName;

	// ���������� �������������� � �������� ����������
	if (rename(oldName, newName) != 0)
		cout << "Error!\n Couldn't rename directory.\n\n";
	else
		cout << "Ok...\n\n";
}

// ������� ������������ ����������
void RemoveDirectory()
{
	char Name[50];
	// �������� ��� � ���� � ��������� ����������
	cout << "Enter name:";
	cin >> Name;

	//������� ���������� � ��������� ���������
	if (_rmdir(Name) == -1)
		cout << "Error!\n Couldn't remove directory.\n";
	else
		cout << "Ok...\n" ;
}
// ������� ����������
void CreateDirectory()
{
	char Name[50];
	// �������� ��� � ���� � ����������� ����������
	cout << "Enter name:";
	cin >> Name;

	//������� ���������� � ��������� ���������
	if (_mkdir(Name) == -1)
		cout << "Error!\n Couldn't create directory.\n";
	else
		cout << "Ok...\n" ;
}
*/

// ����� ����������� ����������
/*
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
using namespace std;

const int size=255;

// �������, ������� ������� ������ ����� � ������� ������
void RemoveRSpacesAndRSlashes(char *str){
	int index=strlen(str)-1;
	while(str[index]=='\\'||str[index]==' '){
		index--;
	}
	strncpy(str,str,index);
	str[index+1]='\0';
}
// ������� ��� ������ ������� ����������
void ShowCurrentDir(char path[],char temp[]){
	CharToOem(path,temp);
	printf("%s>",temp);
}
// ������� �������� �� ���������
// Windows � ��������� DOS
// ��� ����������� �����������
// ��������
void RussianMessage(char path[]){
	CharToOem(path,path);
}

// ����� �� ����� ����������� �����
bool ShowDir(char path[]){
	// ����� ����������� ������� ����������
	_finddata_t find;
	char pathfind[MAX_PATH];
	strcpy(pathfind,path);
	strcat(pathfind,"\\*.*");
	char info[MAX_PATH];

	// ������ ������
	int result=_findfirst(pathfind,&find);
	// ������� ������
	system("cls");
	int flag=result;
	if (flag==-1) {
		strcpy(info,"����� ���������� ���");
		RussianMessage(info);
		printf("%s\n",info);
		return false;
	}

	while(flag!=-1){

		if(strcmp(find.name,".")&&strcmp(find.name,"..")){
			// ��������� ���������� ��� ���
			find.attrib&_A_SUBDIR?strcpy(info," ������� "):strcpy(info," ���� ");
			RussianMessage(info);
			RussianMessage(find.name);
			printf("%30s %10s\n",find.name,info);
		}
		// ���������� �����
		flag=_findnext(result,&find);
	}

	ShowCurrentDir(path,info);
	// ������� �������, ���������� ��� �����
	_findclose(result);
	return true;
}

void main(){
	// � ������ ���������� ����� ��������� ���� � ����������
	char path[MAX_PATH];
	// � ������ ���������� ����� �������, ��������� �������������
	char action[size];
	// ��������� ����������
	char temp[MAX_PATH];
	// �������� ���� � ������� ����������
	GetCurrentDirectory(sizeof(path),path);

	bool flag=true;

	// ����� ����������� ������� ����������
	ShowDir(path);
	do{
		// ���� ������� ������������
		cin.getline(action,size);
		// ������� ������� � ����� ������
		RemoveRSpacesAndRSlashes(action);
		// ������� � �������� �������
		if(!strcmpi(action,"root")){
			path[2]='\0';
			ShowDir(path);
		}
		// �������� �� ������� ������������ �����
		else if(!strcmpi(action,"exit")){
			flag=false;
		}
		// �������� �� ������� cd
		else if(!strnicmp(action,"cd",2)){
			// ����� ����������� ������� ����������
			if((!strcmpi(action,"cd"))){
				// ����� ����������
				ShowDir(path);
			}
			// ������� cd ���� ���� � �����������
			else if(!strnicmp(action,"cd ",3)){
				// ������� ������ ���������
				int index=strspn(action+2," ");
				if(index){
					// �������� �� ������ ���� � ����������
					if(strchr(action+index+2,':')){
						// ������� ���������� ���������� ����������
						if(ShowDir(action+index+2)){
							strcpy(path,action+index+2);
						}
						else{
							// ��������� ������
							ShowCurrentDir(path,temp);
						}
					}
					// ����������� � ������������ �������
					else if(!strcmp(action+index+2,"..")){
						char *result=strrchr(path,'\\');
						if(result){
							int delta=result-path;
							strncpy(temp,path,delta);
							temp[delta]='\0';
						}
						else{
							strcpy(temp,path);
						}

						if(ShowDir(temp)){
							strcpy(path,temp);
						}
						else{
							// ��������� ������
							ShowCurrentDir(path,temp);
						}
					}
					// ����� ����������
					else if(!strcmp(action+index+2,".")){
						ShowDir(path);
					}
					else if(!strcmp(action+index+2,"/")){
						ShowDir(path);
					}
					else{
						// ��� ��� �������� ����
						strcpy(temp,path);
						strcat(temp,"\\");
						strcat(temp,action+index+2);
						// ������� ���������� ���������� ����������
						if(ShowDir(temp)){
							strcpy(path,temp);
						}
						else{
							// ��������� ������
							ShowCurrentDir(path,temp);
						}
					}
				}
				else{
					// ����� ����������
					ShowDir(path);
				}
			}
			else{
				// ����� ����������
				ShowDir(path);
			}
		}
		else{
			// ����� ����������
			ShowDir(path);
		}
	}while(flag);

}
*/

// ������ ���������, ������� ������� HTML-�������� � ���������� ��� ��� ������ ���������� �� ��������� ������ � �������� ���������. (cmd: www.exe ff0000)
/*
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void main(int argc, char * argv[])
{
	//������ �� ��������� ������ ����
	char str[7]="000000";
	//��������� ������ HTML - ���������
	char filehtml[256]="<html><head><title>New file!!!</title></head><body bgcolor = \'#";
	//��������� ���� �� ������ � ���������
	FILE*f=fopen("C:\\1.html","w+");
	//���� �� ���������� - ���������������
	if(!f) exit(0);
	//���� �������� ����� ������� - ���������� ���
	if(argc==2){
		strcpy(str,argv[1]);
	}
	//������������ ���� � ���������
	strcat(filehtml,str);
	//������������ ��������� � ���������
	strcat(filehtml,"\'></body></html>");
	//��������� � ����
	fputs(filehtml,f);
	//��������� ����
	fclose(f);
	cout<<"\nOK.....\n";
}
*/

// ������, �������, ��������� �������� ����� �++, ��������� ����������� ��������� ����� � ����������������� ����
/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;

// ������������ ����� ���� � �����
#define MAX_PATH 260
// ���������� �������� �� ������
#define NUM_COLS 18
// ���������� ����� �� ������
#define NUM_ROWS 24

void main()
{
   char path[MAX_PATH];
   // ����������� ���� � �����
   cout << "Input path to file: ";
   cin.getline(path, MAX_PATH);

   int counter = 0, i = 0, j = 0;
   char text[NUM_COLS];

   // �������� ����� � �������� ������
   ifstream input(path, ios::in | ios::binary);
   if (!input)
   {
	  cout << "Cannot open file for display!" << endl;
	  return;
   }

   // ����� ����������� � ������� �������� ��� ������������������ ������
   cout.setf(ios::uppercase);

   // ���� �� ����� �����, ������ �� ���� ������
   // � ���������� ��������������� ����� �� �����
   while (!input.eof())
   {
	  // ������������ ������
	   for (i = 0; (i < NUM_COLS && !input.eof()); i++)
			input.get(text[i]);


	  if (i < NUM_COLS)
		 i--;

	  for (j = 0; j < i; j++)
		 if((unsigned)text[j] < 0x10)

			// ���������� �������� ��� ����������� ����� ������ ����?
			cout << setw(2) << 0 << hex << (unsigned) text[j];

		 else
			cout << setw(3) << hex << (unsigned) text[j];

	  // ������������ ��� ������������� ������
	  for (; j < NUM_COLS; j++)
		 cout << "   ";

	  cout << "\t";
	  for (j = 0; j < i; j++)
		 // ������ �� �������� �����������?
		 if(text[j] > 31 && text[j] <= 255)
			cout << text[j];
		 else
			cout << ".";
	  cout << "\n";

	  // ���� ����� ��� ��������, ���������� ���������
	  if (++counter == NUM_ROWS)
	  {

		 counter = 0;
		 cout << "Press any key to continue..." << flush;

		 // ������� ������� ����� �������
		 getch();
		 cout << "\n";

	  }
   }
   // ��������� ����
   input.close();
}
*/

// ������������ ������. ����/����� ������� �/�� ����(-�).
/*
#include <windows.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
   char Answer;
   const int MessageCount = 8;
   int i, j;

   // ���������
   enum {CHOICE = 3, INPUT_FILENAME, INPUT_DIMENSIONS, INPUT_ELEMENTS, FILE_ERROR};

   // ���������
   char Msg[MessageCount][50] =
   {
	  "1. ������� ������ �� ���������� �����\n",
	  "2. �������� ������ � ��������� ����\n",
	  "3. ����� �� ���������\n",
	  "\n��� �����: ",
	  "������� ��� ��������������� �����: ",
	  "������� ����������� �������:\n",
	  "������� �������� �������:\n",
	  "���������� ������� ����\n"
   };

   // ����������� ��������� � ����� ���� �� �����

   for(i = 0; i < MessageCount; i++)
	  AnsiToOem(Msg[i], Msg[i]);

   do
   {
	  for(int i = 0; i < 4; i++)
		 cout << Msg[i];
	  cin >>  Answer;
   } while (Answer < '1' || Answer > '3');

   if(Answer == '3')
	  return;

   // ���������� ��� ����� �����
   char FileName[80];

   // ����������� �������
   int M, N;

   int num;
   cout << "\n" << Msg[INPUT_FILENAME];
   cin >> FileName;

   // ���� ������ ������ ����� ����,
   // �� ������� ������ �� ���������� ����� �� �����
   if(Answer == '1')
   {
	  // ���� ���� � ��������� ������ �� ����������,
	  // ������� ��������� �� ������
	  ifstream inF(FileName, ios::in | ios::_Nocreate);
	  if (!inF)
	  {
		 cout << endl << Msg[FILE_ERROR];
		 return;
	  }
	  // ��������� ����������� �������
	  inF >> M;
	  inF >> N;
	  // ��������� �������� ������� �� ����� � ������� �� ����� �� �����
	  for (i = 0; i < M; i++)
	  {
		 for (j = 0; j < N; j++)
		 {
			inF >> num;
			cout << setw(6) << num;
		 }
		 cout << endl;
	  }
	  inF.close();
   }

   // ���� ������ ������ ����� ����, �� �����������
   // � ������������ ������ � ������� �� � ��������� ����
   else
   {
	  // ��������� ���� ��� ������.
	  // ���� ���� � ��������� ������ �� ����������,
	  // �� ��������� ������� ���
	  ofstream outF(FileName, ios::out);
	  if (!outF)
	  {
		 cout << "\n" << Msg[FILE_ERROR];
		 return;
	  }
	  // ����������� ����������� ������� � ���������� ������ � ����
	  cout << Msg[INPUT_DIMENSIONS];
	  cout << "M: ";
	  cin >> M;
	  cout << "N: ";
	  cin >> N;

	  outF << M << ' ' << N << "\n";

	  cout << Msg[INPUT_ELEMENTS];
	  // ����������� �������� ������� � ���������� �� � ����
	  for (i = 0; i < M; i++)
	  {
		 for(j = 0; j < N; j++)
		 {
			cout << "A[" << i << "][" << j << "] = ";
			cin >> num;
			outF << num << " ";
		 }
		 outF << "\n";
	  }
	  outF.close();
   }
}
*/

// ������������ ������ ������ ������� ������ � ����.
/*
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

void RussianMessage(char *message){
	char rmessage[256];
	AnsiToOem(message,rmessage);
	cout<<rmessage;
}

int RussianMenu(){
	RussianMessage("\n������� 1 ��� ���������� ����� ��������� � ����\n");
	RussianMessage("������� 2 ��� ������ ���� �������� �� �����\n");
	RussianMessage("������� 3 ��� ������\n");
	int choice;
	cin>>choice;
	return choice;
}

class Man{
	// ���������� ��� ��������
	int age;
	// ���������� ��� �����
	char *name;
	// ���������� ��� �������
	char *surname;
public:
	// ����������� � �����������
	Man(char *n,char *s,int a);
	// �����������
	Man();
	// ����������
	~Man();
public:
	// ������� ����� ������
	void Put();
	// ������� ������ ������
	void Show();
	// ������� ���������� � ����
	void SaveToFile();
	// ������� ������ ����������� �����
	static void ShowFromFile();
};

// �����������
Man::Man(){
  name=0;
  surname=0;
  age=0;
}

// ����������� � �����������
Man::Man(char *n,char *s,int a){
  name=new char[strlen(n)+1];
  if(!name){
	RussianMessage("������ ��� ��������� ������ !!!");
	exit(1);
  }
  strcpy(name,n);
  surname=new char[strlen(s)+1];
  if(!surname){
	RussianMessage("������ ��� ��������� ������ !!!");
	exit(1);
  }
  strcpy(surname,s);

  age=a;
}

// ����������
Man::~Man(){
  delete[] name;
  delete[] surname;
}

// ������� ����� ������
void Man::Put(){
  char temp[1024];
  RussianMessage("\n������� ���:\n");
  cin>>temp;

  if(name)
	  delete[] name;

  name=new char[strlen(temp)+1];
  if(!name){
	RussianMessage("������ ��� ��������� ������ !!!");
	exit(1);
  }
  strcpy(name,temp);
  RussianMessage("\n������� �������:\n");
  cin>>temp;

  if(surname)
	  delete[] surname;

  surname=new char[strlen(temp)+1];
  if(!surname){
	RussianMessage("������ ��� ��������� ������ !!!");
	exit(1);
  }
  strcpy(surname,temp);

  RussianMessage("\n������� �������\n");
  cin>>age;
}

// ������� ������ ������
void Man::Show(){
   RussianMessage("\n���:\n");
   cout<<name;
   RussianMessage("\n�������:\n");
   cout<<surname;
   RussianMessage("\n�������:\n");
   cout<<age<<"\n";
}

// ������� ���������� � ����
void Man::SaveToFile(){
   int size;
   fstream f("men.txt",ios::out|ios::binary|ios::app);
   if(!f){
	 RussianMessage("���� �� �������� ��� ������ !!!");
	 exit(1);
   }
   // ���������� �������
   f.write((char*)&age,sizeof(age));
   size=strlen(name);
   // ���������� ���������� �������� � �����
   f.write((char*)&size,sizeof(int));
   // ���������� ���
   f.write((char*)name,size*sizeof(char));
   size=strlen(surname);
   // ���������� ���������� �������� � �������
   f.write((char*)&size,sizeof(int));
   // ���������� �������
   f.write((char*)surname,size*sizeof(char));
   f.close();
}

// ������� ������ ����������� �����
void Man::ShowFromFile(){
   fstream f("men.txt",ios::in|ios::binary);
   if(!f){
	 RussianMessage("���� �� �������� ��� ������ !!!");
	 exit(1);
   }
   char *n,*s;
   int a;
   int temp;
   // � ����� ���������� ���������� �����
   while (f.read((char*)&a,sizeof(int))){

	  RussianMessage("\n���:\n");

	  f.read((char*)&temp,sizeof(int));
	  n=new char[temp+1];
	  if(!n){
		RussianMessage("������ ��� ��������� ������ !!!");
		exit(1);
	  }
	  f.read((char*)n,temp*sizeof(char));
	  n[temp]='\0';
	  cout<<n;

	  RussianMessage("\n�������:\n");
	  f.read((char*)&temp,sizeof(int));
	  s=new char[temp+1];
	  if(!s){
		RussianMessage("������ ��� ��������� ������ !!!");
		exit(1);
	  }
	  f.read((char*)s,temp*sizeof(char));
	  s[temp]='\0';
	  cout<<s;

	  RussianMessage("\n�������:\n");
	  cout<<a<<"\n";
	  delete []n;
	  delete []s;
   }
}

void main(){
	Man *a;
	// �������� ���� ���������
	do{
		switch(RussianMenu()){
		case 1: // ���������� ������
			a=new Man;
			a->Put();
			a->SaveToFile();
			delete a;
			break;
		case 2: // ����� ���� �������
			Man::ShowFromFile();
			break;
		case 3://  �������� � �������������
			RussianMessage("�� ��������\n");
			return;
		default: // ������������ ����
			RussianMessage("�������� ����\n");
		}

	}while(1);

}
*/

