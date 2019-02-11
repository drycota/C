#include "pch.h"
#include "file.h"

// Функции библиотеки stdio.h
/*
Функции библиотеки stdio.h

--------------------------------------------------------------------------------
FILE *fopen(const char *filename, const char *mode)



Функция открывает файл.

filename - путь к файлу

mode - тип доступа

r - чтение, если файла нет, то данная функция генерирует ошибку (возвращает 0)
w - запись, если файла нет, то файл создаётся, если есть исходное содержимое удаляется
a - добавление в конец, если файла нет, то он создаётся
r+ чтение и запись (файл должен существовать)
w+ - чтение и запись (принцип работы как у w)
a+ - добавление и чтение (принцип работы как у a)
Примечание: Все вышеописанные режимы предназначены для текстового открытия файла. Для двоичного открытия перед режимом достаточно добавить букву b. Например, br.
Если функция отработала успешно, из неё возвращается указатель на открытый файл, в противном случае - нуль.

Примечание: Указатель на открытый файл принято хранить в типе данных FILE*.

--------------------------------------------------------------------------------
int fclose( FILE *stream )



Функция закрывает файл.

stream - указатель на закрываемый файл.

Если всё проходит успешно, то данная функция возвращает 0, или EOF в случае ошибки.

Примечание: EOF (End Of File) - обозначение конца файла.

--------------------------------------------------------------------------------
char *fgets( char *string, int n, FILE *stream )



Считывает строку начиная с текущей позиции.

Считывание останавливается:

...если был найден символ перехода на новую строчку ( он помещается в строку )
...если достигнут конец файла
...если считано n-1 символов.
string - cтрока, в которую попадают считанные данные

n - количество элементов в string

stream - указатель на открытый файл

Если всё прошло успешно функция возвращает считанную строку, если произошла ошибка или достигнут конец файла возвращается 0.


--------------------------------------------------------------------------------
int fputs( const char *string, FILE *stream )



Записывает строку в файл, начиная с текущей позиции.

string - строка для записи

stream - указатель на открытый файл, куда производиться запись

Если функция отрабатывает успешно из неё возвращается неотрицательное значение. При ошибке возвращается EOF.


--------------------------------------------------------------------------------
size_t fread( void *buffer, size_t size, size_t count, FILE *stream )



Функция считывает данные из файла в буфер.

buffer - адрес массива, куда запишутся данные

size - размер элемента массива в байтах

count - максимальное количество элементов для считывания

stream - указатель на открытый файл.

Функция возвращает количество считанных байт.

Примечание: Тип данных size_t определен в библиотеке stdio.h следующим образом: typedef unsigned int size_t;. Другими словами, это обычный беззнаковый int.

--------------------------------------------------------------------------------
size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream )



Функция записывает массив данных в файл.

buffer - адрес массива, где содержатся данные

size - размер элемента массива в байтах

count - максимальное количество элементов для записи в файл

stream - указатель на открытый файл.

Функция возвращает количество записанных байт.


--------------------------------------------------------------------------------
int feof( FILE *stream )



Функция проверяет достигнут ли конец файла.

stream - указатель на открытый файл

Функция возвращает ненулевое значение, если достигнут конец файла, нуль возвращается в противном случае.


--------------------------------------------------------------------------------
int _fileno( FILE *stream )



Данная функция возвращает дескриптор файла.

stream - указатель на открытый файл.


--------------------------------------------------------------------------------
int fseek ( FILE *stream, int offset [, int whence] )



Устанавливает смещение в файле

stream - указатель на открытый файл

offset - смещение, измеряемое в байтах от начала файла

whence - точка, от которой производится смещение

SEEK_SET (0) - начало файла
SEEK_CUR (1) - позиция текущего указателя файла
SEEK_END (2) - конец файла (EOF)
Функция возвращает значение 0, если указатель файла успешно перемещен, и ненулевое значение в случае неудачного завершения.


--------------------------------------------------------------------------------

*/

// Набор функций для работы с файлами
/*
stdio.h - переименование и удаление файлов.

--------------------------------------------------------------------------------

rename (char * oldname, char * newname)

Переименовывает файл.

oldname - путь и текущее имя файла

newname - путь и новое имя файла

Функция возвращает 0, если имя файла было успешно изменено, и ненулевое значение, если замена не произошла.

Примечание: Кстати!!! Если указать не только новое имя, но и новый путь - файл будет не только переименован, но и перенесён.

--------------------------------------------------------------------------------

int remove(const char * filename)

Удаляет файл.

filename - путь и имя файла

Функция возвращает 0, если имя файл был успешно удален, и ненулевое значение, если удаление не произошло.

Примечание: Помните!!! В момент удаления файл должен быть закрыт. Кроме того, не забывайте, что удаление необратимо.

--------------------------------------------------------------------------------

io.h - поиск файлов.

--------------------------------------------------------------------------------

_findfirst(char * path, _finddata_t * fileinfo)

Находит файлы по указанному пути, соответсвтующие маске.

Примечание: Маска - строка, критерий поиска, содержащая символы * (любая последовательность любых символов) и ? (любой один символ)
path - строка, в которой содержится комбинация пути и маски.

fileinfo - указатель на объект структуры, в который запишется информация о найденном файле. Структура содержит следующие поля:

unsigned attrib - содержит информацию об атрибутах файла.
_A_NORMAL - Обычный файл без запретов на чтение или запись.
_A_RDONLY - Файл только для чтения.
_A_HIDDEN - Скрытый файл.
_A_SYSTEM - Системный файл.
_A_SUBDIR - Директория.
_A_ARCH - Архивный файл.
time_t time_create - время/дата создания файла (равно -1 для FAT систем).
time_t time_access - время/дата последнего открытия файла (равно -1 для FAT систем).
time_t time_write - время/дата последнего редактирования файла
_fsize_t size - размер файла
char name[260] - имя файла
Если всё пройдет успешно, информация о первом найденном файле запишется в объект структуры _finddata_t. При этом в оперативной памяти сформируется "список", обладающий внутренним указателем, который изначально будет установлен на первом найденном файле. В этом случае функция вернет уникальный номер, связанный с полученной группой файлов.

Если поиск завершится неудачей, функция вернет -1.


--------------------------------------------------------------------------------

_findnext(long done, _finddata_t * fileinfo)

Функция осуществляет переход на следующий найденный файл в группе.

done - уникальный номер группы файлов в памяти.

fileinfo - указатель на объект структуры, в который запишется информация о следующем найденном файле.

Если достигнут конец списка файлов, функция вернет -1.


--------------------------------------------------------------------------------

_findclose(long done)

Функция очищает память от группы найденных файлов.

done - уникальный номер группы файлов в памяти.


*/

// Функции библиотеки io.h
/*
int _access( const char *path, int mode )



Функция определяет разрешения файла или директории.

path - путь к файлу или директории

mode - флаги для проверки

00 - проверка на существование
02 - проверка на разрешение на запись
04 - проверка на разрешение на чтение
06 - проверка на чтение и запись
Если разрешение есть, функция возвращает ноль, в случае отсутствия -1.

Примечание: Директории можно проверять только на существование.

--------------------------------------------------------------------------------
long _filelength( int handle )



Возвращает размер файла в байтах.

handle - дескриптор файла.

В случае ошибки функция возвращает -1.


--------------------------------------------------------------------------------
int _locking( int handle, int mode, long nbytes )



Блокирует или разблокирует байты файла начиная с текущей позиции в файле.

handle - дескриптор файла

mode - тип блокировки

_LK_LOCK - блокирует байты, если заблокировать байты не получается попытка повторяется через 1 секунду.Если после 10 попыток байты не заблокируются функция генерирует ошибку и возвращает -1
_LK_NBLCK - блокирует байты, если заблокировать байты не получается функция генерирует ошибку и возвращает -1
_LK_NBRLCK - то же самое, что и _LK_NBLCK
_LK_RLCK - то же самое, что и _LK_LOCK
_LK_UNLCK - разблокировка байт, которые были до этого заблокированы
nbytes - количество байт для блокировки

Функция locking возвращает -1, если происходит ошибка и 0 в случае успеха.

Примечание: Для работы этой функции кроме io.h, нужно подключить sys/locking.h

*/

// Операции по работе с директориями
/*
Библиотека direct.h

--------------------------------------------------------------------------------

int _mkdir( const char *dirname )

Создает директорию по указанному пути.

dirname - Путь и имя для создаваемой директории.


--------------------------------------------------------------------------------

int _rmdir( const char *dirname )

Удаляет директорию по указанному пути.

dirname - Путь и имя для удаляемой директории.


--------------------------------------------------------------------------------

Обе функции возвращают -1 в случае ошибки.


--------------------------------------------------------------------------------

Примечание: Кстати!!! Для переименования директории можно использовать функцию rename из библиотеки stdio.h.
Внимание!!! Удалить и переименовать можно только пустую директорию!!!


*/

// Копирование файлов
/*
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
using namespace std;

// Функция, выводящая на экран строку
void RussianMessage(char *str){
	char message[100];
	//перевод строки из кодировки Windows
	//в кодировку MS DOS
	CharToOem(str,message);
	cout<<message;
}
// Функция копирования файла
bool CopyFile(char *source,char *destination){
	const int size=65536;
	FILE *src,*dest;
	// Открытие Файла
	if(!(src=fopen(source,"rb"))){
		return false;
	}
	// Получение дескриптора файла
	int handle=_fileno(src);

	// выделение памяти под буффер
	char *data=new char[size];
	if(!data){
		return false;
	}
	// Открытие файла, куда будет производиться копирование
	if(!(dest=fopen(destination,"wb"))){
		delete []data;
		return false;
	}
	int realsize;
	while (!feof(src)){
		// Чтение данных из файла
		realsize=fread(data,sizeof(char),size,src);
		// Запись данных в файл
		fwrite(data,sizeof(char),realsize,dest);
	}

	// Закрытие файлов
	fclose(src);
	fclose(dest);
	return true;
}
void main(){
	// __MAX_PATH - Константа, определяющая максимальный размер пути.
	// Даная константа содержится в stdlib.h
	char source[_MAX_PATH];
	char destination[_MAX_PATH];
	char answer[20];
	RussianMessage("\nВведите путь и название копируемого файлу:\n");
	// Получение пути к первому файлу
	cin.getline(source,_MAX_PATH);
	// Проверка Существует ли файл
	if(_access(source,00)==-1){
		RussianMessage("\nУказан неверный путь или название файла\n");
		return;
	}
	RussianMessage("\nВведите путь и название нового файла:\n");
	// Получение пути к второму файлу
	cin.getline(destination,_MAX_PATH);
	// Проверка на существование файла
	if(_access(destination,00)==0){
		RussianMessage("\nТакой Файл уже существует перезаписать его(1 - Да /2 - Нет)?\n");
		cin.getline(answer,20);
		if(!strcmp(answer,"2")){
			RussianMessage("\nОперация отменена\n");
			return;
		}
		else if(strcmp(answer,"1")){
			RussianMessage("\nНеправильный ввод\n");
			return;
		}
		if(_access(destination,02)==-1){
			RussianMessage("\nНет доступа к записи.\n");
			return;
		}
	}

	// Копирование файла
	if(!CopyFile(source,destination)){
		RussianMessage("\nОшибка при работе с файлом\n");
	}
}
*/

// Пример программы. Игра "Виселица".
/*
// Смысл игры состоит в том, что пользователь за некоторое количество попыток должен отгадать слово, в нашем случае английское. 
// В папку с проектом, в котором вы будете компилировать данный код, необходимо положить файл words.txt. Этот файл должен содержать 
// несколько английских слов, расположенных в столбик (одно под другим).

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

// Максимальная длина слова
#define MAX_WORD_LENGTH 21

// Кол-во попыток
int Tries = 10;

// Кол-во угаданных слов
int CountWords = 0;

// Загрузка слова
bool LoadWord(FILE * file, char * word)
{
   int i = 0;
   char s[MAX_WORD_LENGTH] = {0};
   // Кол-во слов в файле
   static int count = -1;

   if(count == -1)
   {
	  // Подсчет количества слов
	  while(!feof(file))
	  {
		 fgets(s, MAX_WORD_LENGTH, file);
		 count++;
	  }
	  // Слов нет?
	  if(count == 0)
		 return false;
	  // Возврат файлового указателя в начало файла
	  fseek(file, 0, 0);
   }

   // Случайное слово
   int n = rand() % count;
   // Поиск слова
   while(i <= n)
   {
	  fgets(s, MAX_WORD_LENGTH, file);
	  i++;
   }
   // Определяем длину слова
   int wordlen = strlen(s);
   // Минимальная длина слова 2 буквы
   if(wordlen <= 1)
	  return false;

   // Убираем Enter (в DOS'е 2 байта 13 10)
   if(s[wordlen - 1] == 10)
	  s[wordlen - 2] = 0;
   else if(s[wordlen - 1] == 13)
	  s[wordlen - 1] = 0;
   // Копируем слово
   strcpy(word, s);
   // Получаем дескриптор файла
   int hFile = _fileno(file);
   // Вычисляем размер файла
   int size = _filelength(hFile);

   // Блокировка файла
   fseek(file, 0, 0);
   _locking(hFile, _LK_NBLCK, size);

   return true;
}

// Игра
void Game(char * word)
{
   // Перевод в большие буквы
   strupr(word);

   int len = strlen(word);
   // Строка-копия
   char * copy = new char[len + 1];
   memset(copy, '*', len);
   copy[len] = 0;

   // Алфавит + пробелы
   char letters[52];

   int i, j = 0;
   for(i = 0; i < 26; i++)
   {
	  letters[j++] = i + 'A';
	  letters[j++] = ' ';
   }
   // Замыкающий ноль
   letters[51] = 0;

   // Буква
   char letter;

   char * pos;
   bool replace = false;

   do {
	  // Очистка экрана
	  system("cls");
	  cout << copy << endl << endl;
	  cout << letters << endl << endl;
	  cout << "Count of tries: " << Tries << endl << endl;
	  cout << "Input any letter:\t";

	  cin >> letter;
	  // Звуковой сигнал
	  Beep(500, 200);

	  // if(letter >= 'A' && letter <= 'Z'
	  // || letter >= 'a' && letter <= 'z')

	  // Буква?
	  if(!isalpha(letter))
	  {
		 cout << "It's not a letter" << endl;
		 // Задержка на 1 секунду
		 Sleep(1000);
		 continue;
	  }

	  // Перевод буквы в большую
	  letter = toupper(letter);

	  // Поиск буквы в алфавите
	  pos = strchr(letters, letter);

	  // Такая буква уже была
	  if(pos == 0)
	  {
		 cout << "This letter have been already pressed" << endl;
		 Sleep(1000);
		 continue;
	  }
	  else
	  {
		 // Убираем букву из алфавита
		 pos[0] = ' ';
	  }

	  // Поиск буквы в слове
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

	  // Условие победы
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
   // Открываем файл на чтение в двоичном режиме
   FILE * f = fopen("words.txt", "rb");

   // Если файл не открылся
   if(f == 0)
   {
	  // Ошибка
	  perror("Open");
	  return;
   }

   srand(time(0));

   char Word[20];
   // Пытаемся загрузить слово
   if(!LoadWord(f, Word))
   {
	  // Если неудачно
	  cout << "Error !!!" << endl;
	  fclose(f);
	  return;
   }

   char answer;
   // Играем, пока не надоест
   do
   {
	  Game(Word);
	  // Если попыток не осталось, то выход
	  if(Tries == 0)
	  {
		 cout << "Count of words: " << CountWords << endl;
		 cout << "Bye-bye" << endl;
		 break;
	  }
	  // Если остались
	  cout << "Continue ??? (Y/N)\t";

	  cin >> answer;
	  // Еще играем?
	  if(answer == 'Y' || answer == 'y')
		 if(!LoadWord(f, Word))
		 {
			cout << "Error !!!" << endl;
			fclose(f);
			return;
		 }

   }while(answer == 'Y' || answer == 'y');


   // получаем дескриптор
   int hFile = _fileno(f);

   // Разблокировка файла
   int size = _filelength(hFile);
   fseek(f, 0, 0);
   _locking(hFile, _LK_UNLCK, size);
   fclose(f);
}


*/

// Cохранение объектов структуры в файл
/*
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
// структура, хранящая
// информацию о человеке
struct Man{
	//Имя
	char name[255];
	//Возраст
	int age;
};
void main()
{
	//Создание объектов структуры
	Man A,B;
	//Запись в объект A
	//информации, полученной
	//с клавиатуры
	cout<<"\nEnter name:\n";
	cin>>A.name;
	cout<<"\nEnter age:\n";
	cin>>A.age;

	//открытие файла на запись
	FILE*f=fopen("Test.txt","w+");
	if(!f) exit(0);
	//запись объекта А в файл
	fwrite(&A,sizeof(Man),1,f);
	fclose(f);

	//открытие файла на чтение
	f=fopen("Test.txt","r+");
	if(!f) exit(0);
	//считывание содержимого файла
	//в объект B
	fread(&B,sizeof(Man),1,f);
	//открытие файла на запись
	fclose(f);

	//показ результата на экран
	cout<<"\nName - "<<B.name<<"\n\nAge - "<<B.age<<"\n\n";
}
*/

// Пример программы на работу с файлами
/*
// Здесь находятся функции переименования и удаления
#include <stdio.h>
// Здесь находятся функции для поиска файлов
#include <io.h>
#include <string.h>
#include <iostream>
using namespace std;
// для функции AnsiToOem
#include <windows.h>

// Переименовать существующий файл
void RenameFile();

// Удалить существующий файл
void RemoveFile();

// Поиск файлов в каталоге
void Dir();

void main()
{
	// предлагаем выбрать пункт меню для выполнения
	cout << "Please, select preffer number...\n";

	//выбор пользователя
	char ch;
	do{
		// Переименовать
		cout << "\n1 - Rename\n";
		// Удалить
		cout << "2 - Remove\n";
		// Просмотреть некоторую папку(каталог)
		cout << "3 - View some folder\n";
		// Выход
		cout << "0 - Exit\n\n";
		cin >> ch;

		// анализируем и вызываем
		// соответствующую  функцию
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
	} while(ch != '0');      // Выход из программы
}

// Переименовать существующий файл
void RenameFile()
{
	char oldName[50], newName[50];

	// В одной переменной запомним существующее имя (oldName),
	cout << "Enter old name:";
	cin >> oldName;

	// А в другой новое имя(newName)
	cout << "Enter new name:";
	cin >> newName;

	// Произведем переименование и проверку результата
	if (rename(oldName, newName) != 0)
		cout << "Error!\n Couldn't rename file. Check old and new filename...\n\n";
	else
		cout << "Ok...\n\n";
}

// Удалить существующий файл
void RemoveFile()
{
	char Name[50];
	// Получаем имя и путь к удаляемому файлу
	cout << "Enter name:";
	cin >> Name;

	//Удаляем файл и проверяем результат
	if (remove(Name) != 0)
		cout << "Error!\n Couldn't remove file. Check filename...\n";
	else
		cout << "Ok...\n" ;
}

// Поиск файлов в каталоге
void Dir()
{
	// Запросим ПУТЬ (например, папка Temp на диске C, запишется
	// таким вот образом: c:\temp\)
	char path[70];
	cout << "\nEnter full path (for example, C:\\):";
	cin >> path;

	// Запросим маску файлов
	char mask[15];
	cout << "\nEnter mask (for example, *.* or *.txt):";
	cin >> mask;

	// Соединив две строки, мы получим результат
	// т.е. что хочет найти пользователь и где
	strcat(path, mask);

	// Объявление указателя fileinfo на структуру _finddata_t
	// и создание динамического объекта структуры _finddata_t
	_finddata_t *fileinfo=new _finddata_t;

	// Начинаем поиск
	long done = _findfirst(path,fileinfo);

	// если done будет равняться -1,
	// то поиск вести бесмысленно
	int MayWeWork = done;

	// Счетчик, содержит информацию о количестве найденых файлов.
	int count = 0;
	while (MayWeWork!=-1)
	{
		count++;
		// перекодировали имя найденного файла
		// на случай, если оно кириллическое
		AnsiToOem(fileinfo->name,fileinfo->name);
		// Распечатали имя найденного файла
		cout << fileinfo->name << "\n\n";
		// Пытаемся найти следующий файл из группы
		MayWeWork = _findnext(done, fileinfo);
	}
	// Вывод сообщения о количестве найденных файлов.
	cout << "\nInformation: was found " << count;
	cout << " file(s) in folder..." << path << "\n\n";

	// Очистка памяти
	_findclose(done);
	delete fileinfo;
}
*/

// Пример на работу с директориями
/*
#include <iostream>
#include <direct.h>
#include <stdio.h>

using namespace std;

// Переименовать существующую директорию
void RenameDirectory();

// Удалить существующую директорию
void RemoveDirectory();

// создать директорию
void CreateDirectory();

void main()
{
	// предлагаем выбрать пункт меню для выполнения
	cout << "Please, select preffer number...\n";

	//выбор пользователя
	char ch;
	do{
		// Переименовать
		cout << "\n1 - Rename\n";
		// Удалить
		cout << "2 - Remove\n";
		// Создать
		cout << "3 - Create\n";
		// Выход
		cout << "0 - Exit\n\n";
		cin >> ch;

		// анализируем и вызываем
		// соответствующую  функцию
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
	} while(ch != '0');      // Выход из программы
}

// Переименовать существующую директорию
void RenameDirectory()
{
	char oldName[50], newName[50];

	// В одной переменной запомним существующее имя (oldName),
	cout << "Enter old name:";
	cin >> oldName;

	// А в другой новое имя(newName)
	cout << "Enter new name:";
	cin >> newName;

	// Произведем переименование и проверку результата
	if (rename(oldName, newName) != 0)
		cout << "Error!\n Couldn't rename directory.\n\n";
	else
		cout << "Ok...\n\n";
}

// Удалить существующую директорию
void RemoveDirectory()
{
	char Name[50];
	// Получаем имя и путь к удаляемой директории
	cout << "Enter name:";
	cin >> Name;

	//Удаляем директорию и проверяем результат
	if (_rmdir(Name) == -1)
		cout << "Error!\n Couldn't remove directory.\n";
	else
		cout << "Ok...\n" ;
}
// Создать директорию
void CreateDirectory()
{
	char Name[50];
	// Получаем имя и путь к создаваемой директории
	cout << "Enter name:";
	cin >> Name;

	//Создаем директорию и проверяем результат
	if (_mkdir(Name) == -1)
		cout << "Error!\n Couldn't create directory.\n";
	else
		cout << "Ok...\n" ;
}
*/

// Показ содержимого директории
/*
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
using namespace std;

const int size=255;

// Функция, которая убирает лишние слеши и пробелы справа
void RemoveRSpacesAndRSlashes(char *str){
	int index=strlen(str)-1;
	while(str[index]=='\\'||str[index]==' '){
		index--;
	}
	strncpy(str,str,index);
	str[index+1]='\0';
}
// Функция для показа текущей директории
void ShowCurrentDir(char path[],char temp[]){
	CharToOem(path,temp);
	printf("%s>",temp);
}
// Функция перевода из кодировки
// Windows в кодировку DOS
// Для корректного отображения
// кирилицы
void RussianMessage(char path[]){
	CharToOem(path,path);
}

// Показ на экран содержимого папки
bool ShowDir(char path[]){
	// Показ содержимого текущей директории
	_finddata_t find;
	char pathfind[MAX_PATH];
	strcpy(pathfind,path);
	strcat(pathfind,"\\*.*");
	char info[MAX_PATH];

	// Начало Поиска
	int result=_findfirst(pathfind,&find);
	// Очистка экрана
	system("cls");
	int flag=result;
	if (flag==-1) {
		strcpy(info,"Такой Директории Нет");
		RussianMessage(info);
		printf("%s\n",info);
		return false;
	}

	while(flag!=-1){

		if(strcmp(find.name,".")&&strcmp(find.name,"..")){
			// Проверяем Директория или Нет
			find.attrib&_A_SUBDIR?strcpy(info," Каталог "):strcpy(info," Файл ");
			RussianMessage(info);
			RussianMessage(find.name);
			printf("%30s %10s\n",find.name,info);
		}
		// Продолжаем Поиск
		flag=_findnext(result,&find);
	}

	ShowCurrentDir(path,info);
	// Очищаем ресурсы, выделенные под поиск
	_findclose(result);
	return true;
}

void main(){
	// В данной переменной будет храниться путь к Директории
	char path[MAX_PATH];
	// В данной переменной будет команда, введенная пользователем
	char action[size];
	// Временная переменная
	char temp[MAX_PATH];
	// Получаем Путь к текущей Директории
	GetCurrentDirectory(sizeof(path),path);

	bool flag=true;

	// Показ содержимого текущей директории
	ShowDir(path);
	do{
		// Ввод команды пользователя
		cin.getline(action,size);
		// Убираем пробелы и слэши справа
		RemoveRSpacesAndRSlashes(action);
		// Переход в корневой каталог
		if(!strcmpi(action,"root")){
			path[2]='\0';
			ShowDir(path);
		}
		// Проверка на желание пользователя выйти
		else if(!strcmpi(action,"exit")){
			flag=false;
		}
		// Проверка на команду cd
		else if(!strnicmp(action,"cd",2)){
			// Показ содержимого текущей директории
			if((!strcmpi(action,"cd"))){
				// Показ Директории
				ShowDir(path);
			}
			// Команда cd была дана с параметрами
			else if(!strnicmp(action,"cd ",3)){
				// Находим индекс параметра
				int index=strspn(action+2," ");
				if(index){
					// Проверка на полный путь к Директории
					if(strchr(action+index+2,':')){
						// Попытка отобразить содержимое Директории
						if(ShowDir(action+index+2)){
							strcpy(path,action+index+2);
						}
						else{
							// Произошла Ошибка
							ShowCurrentDir(path,temp);
						}
					}
					// Поднимаемся в родительский каталог
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
							// Произошла Ошибка
							ShowCurrentDir(path,temp);
						}
					}
					// Показ Директории
					else if(!strcmp(action+index+2,".")){
						ShowDir(path);
					}
					else if(!strcmp(action+index+2,"/")){
						ShowDir(path);
					}
					else{
						// Был Дан неполный путь
						strcpy(temp,path);
						strcat(temp,"\\");
						strcat(temp,action+index+2);
						// Попытка отобразить содержимое Директории
						if(ShowDir(temp)){
							strcpy(path,temp);
						}
						else{
							// Произошла Ошибка
							ShowCurrentDir(path,temp);
						}
					}
				}
				else{
					// Показ Директории
					ShowDir(path);
				}
			}
			else{
				// Показ Директории
				ShowDir(path);
			}
		}
		else{
			// Показ Директории
			ShowDir(path);
		}
	}while(flag);

}
*/

// Пример программы, которая создает HTML-документ и окрашивает его фон цветом переданным из командной строки в качестве параметра. (cmd: www.exe ff0000)
/*
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void main(int argc, char * argv[])
{
	//Задаем по умолчанию черный цвет
	char str[7]="000000";
	//формируем начало HTML - документа
	char filehtml[256]="<html><head><title>New file!!!</title></head><body bgcolor = \'#";
	//Открываем файл на запись с созданием
	FILE*f=fopen("C:\\1.html","w+");
	//Если не получилось - останавливаемся
	if(!f) exit(0);
	//Если параметр цвета передан - используем его
	if(argc==2){
		strcpy(str,argv[1]);
	}
	//Присоединяем цвет к документу
	strcat(filehtml,str);
	//Присоединяем окончание к документу
	strcat(filehtml,"\'></body></html>");
	//Сохраняем в файл
	fputs(filehtml,f);
	//Закрываем Файл
	fclose(f);
	cout<<"\nOK.....\n";
}
*/

// Пример, который, используя средства языка С++, реализует возможность просмотра файла в шестнадцатиричном виде
/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;

// Максимальная длина пути к файлу
#define MAX_PATH 260
// Количество столбцов на экране
#define NUM_COLS 18
// Количество строк на экране
#define NUM_ROWS 24

void main()
{
   char path[MAX_PATH];
   // Запрашиваем путь к файлу
   cout << "Input path to file: ";
   cin.getline(path, MAX_PATH);

   int counter = 0, i = 0, j = 0;
   char text[NUM_COLS];

   // Открытие файла в двоичном режиме
   ifstream input(path, ios::in | ios::binary);
   if (!input)
   {
	  cout << "Cannot open file for display!" << endl;
	  return;
   }

   // Режим отображения в верхнем регистре для шестнадцатиричного вывода
   cout.setf(ios::uppercase);

   // Пока не конец файла, читаем из него данные
   // и производим форматированный вывод на экран
   while (!input.eof())
   {
	  // Посимвольное чтение
	   for (i = 0; (i < NUM_COLS && !input.eof()); i++)
			input.get(text[i]);


	  if (i < NUM_COLS)
		 i--;

	  for (j = 0; j < i; j++)
		 if((unsigned)text[j] < 0x10)

			// Количество символов для отображения числа меньше двух?
			cout << setw(2) << 0 << hex << (unsigned) text[j];

		 else
			cout << setw(3) << hex << (unsigned) text[j];

	  // Выравнивание для незавершенной строки
	  for (; j < NUM_COLS; j++)
		 cout << "   ";

	  cout << "\t";
	  for (j = 0; j < i; j++)
		 // Символ не является управляющим?
		 if(text[j] > 31 && text[j] <= 255)
			cout << text[j];
		 else
			cout << ".";
	  cout << "\n";

	  // Если экран уже заполнен, производим остановку
	  if (++counter == NUM_ROWS)
	  {

		 counter = 0;
		 cout << "Press any key to continue..." << flush;

		 // Ожидаем нажатия любой клавиши
		 getch();
		 cout << "\n";

	  }
   }
   // Закрываем файл
   input.close();
}
*/

// Практический пример. Ввод/вывод массива в/из файл(-а).
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

   // Подсказки
   enum {CHOICE = 3, INPUT_FILENAME, INPUT_DIMENSIONS, INPUT_ELEMENTS, FILE_ERROR};

   // Сообщения
   char Msg[MessageCount][50] =
   {
	  "1. Вывести данные из текстового файла\n",
	  "2. Записать данные в текстовый файл\n",
	  "3. Выход из программы\n",
	  "\nВаш выбор: ",
	  "Введите имя обрабатываемого файла: ",
	  "Введите размерности матрицы:\n",
	  "Введите элементы матрицы:\n",
	  "Невозможно открыть файл\n"
   };

   // Русификация сообщений и вывод меню на экран

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

   // Переменная для имени файла
   char FileName[80];

   // Размерности матрицы
   int M, N;

   int num;
   cout << "\n" << Msg[INPUT_FILENAME];
   cin >> FileName;

   // Если выбран первый пункт меню,
   // то выводим данные из текстового файла на экран
   if(Answer == '1')
   {
	  // Если файл с указанным именем не существует,
	  // выводим сообщение об ошибке
	  ifstream inF(FileName, ios::in | ios::_Nocreate);
	  if (!inF)
	  {
		 cout << endl << Msg[FILE_ERROR];
		 return;
	  }
	  // Считываем размерность массива
	  inF >> M;
	  inF >> N;
	  // Считываем элементы массива из файла и выводим их сразу на экран
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

   // Если выбран второй пункт меню, то запрашиваем
   // у пользователя данные и выводим их в текстовый файл
   else
   {
	  // Открываем файл для записи.
	  // Если файл с указанным именем не существует,
	  // то программа создает его
	  ofstream outF(FileName, ios::out);
	  if (!outF)
	  {
		 cout << "\n" << Msg[FILE_ERROR];
		 return;
	  }
	  // Запрашиваем размерность матрицы и записываем данные в файл
	  cout << Msg[INPUT_DIMENSIONS];
	  cout << "M: ";
	  cin >> M;
	  cout << "N: ";
	  cin >> N;

	  outF << M << ' ' << N << "\n";

	  cout << Msg[INPUT_ELEMENTS];
	  // Запрашиваем элементы массива и записываем их в файл
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

// Практический пример записи объекта класса в файл.
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
	RussianMessage("\nВведите 1 для добавления новой структуры в файл\n");
	RussianMessage("Введите 2 для показа всех структур из файла\n");
	RussianMessage("Введите 3 для выхода\n");
	int choice;
	cin>>choice;
	return choice;
}

class Man{
	// переменная для возраста
	int age;
	// переменная для имени
	char *name;
	// переменная для фамилии
	char *surname;
public:
	// конструктор с параметрами
	Man(char *n,char *s,int a);
	// конструктор
	Man();
	// деструктор
	~Man();
public:
	// функция ввода данных
	void Put();
	// функция показа данных
	void Show();
	// функция сохранения в файл
	void SaveToFile();
	// функция показа содержимого файла
	static void ShowFromFile();
};

// конструктор
Man::Man(){
  name=0;
  surname=0;
  age=0;
}

// конструктор с параметрами
Man::Man(char *n,char *s,int a){
  name=new char[strlen(n)+1];
  if(!name){
	RussianMessage("Ошибка при выделении памяти !!!");
	exit(1);
  }
  strcpy(name,n);
  surname=new char[strlen(s)+1];
  if(!surname){
	RussianMessage("Ошибка при выделении памяти !!!");
	exit(1);
  }
  strcpy(surname,s);

  age=a;
}

// деструктор
Man::~Man(){
  delete[] name;
  delete[] surname;
}

// функция ввода данных
void Man::Put(){
  char temp[1024];
  RussianMessage("\nВведите имя:\n");
  cin>>temp;

  if(name)
	  delete[] name;

  name=new char[strlen(temp)+1];
  if(!name){
	RussianMessage("Ошибка при выделении памяти !!!");
	exit(1);
  }
  strcpy(name,temp);
  RussianMessage("\nВведите фамилию:\n");
  cin>>temp;

  if(surname)
	  delete[] surname;

  surname=new char[strlen(temp)+1];
  if(!surname){
	RussianMessage("Ошибка при выделении памяти !!!");
	exit(1);
  }
  strcpy(surname,temp);

  RussianMessage("\nВведите возраст\n");
  cin>>age;
}

// функция показа данных
void Man::Show(){
   RussianMessage("\nИмя:\n");
   cout<<name;
   RussianMessage("\nФамилия:\n");
   cout<<surname;
   RussianMessage("\nВозраст:\n");
   cout<<age<<"\n";
}

// функция сохранения в файл
void Man::SaveToFile(){
   int size;
   fstream f("men.txt",ios::out|ios::binary|ios::app);
   if(!f){
	 RussianMessage("Файл не открылся для записи !!!");
	 exit(1);
   }
   // Записываем возраст
   f.write((char*)&age,sizeof(age));
   size=strlen(name);
   // Записываем количество символов в имени
   f.write((char*)&size,sizeof(int));
   // Записываем имя
   f.write((char*)name,size*sizeof(char));
   size=strlen(surname);
   // Записываем количество символов в фамилии
   f.write((char*)&size,sizeof(int));
   // Записываем фамилию
   f.write((char*)surname,size*sizeof(char));
   f.close();
}

// функция показа содержимого файла
void Man::ShowFromFile(){
   fstream f("men.txt",ios::in|ios::binary);
   if(!f){
	 RussianMessage("Файл не открылся для чтения !!!");
	 exit(1);
   }
   char *n,*s;
   int a;
   int temp;
   // В цикле зачитываем содержимое файла
   while (f.read((char*)&a,sizeof(int))){

	  RussianMessage("\nИмя:\n");

	  f.read((char*)&temp,sizeof(int));
	  n=new char[temp+1];
	  if(!n){
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	  }
	  f.read((char*)n,temp*sizeof(char));
	  n[temp]='\0';
	  cout<<n;

	  RussianMessage("\nФамилия:\n");
	  f.read((char*)&temp,sizeof(int));
	  s=new char[temp+1];
	  if(!s){
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	  }
	  f.read((char*)s,temp*sizeof(char));
	  s[temp]='\0';
	  cout<<s;

	  RussianMessage("\nВозраст:\n");
	  cout<<a<<"\n";
	  delete []n;
	  delete []s;
   }
}

void main(){
	Man *a;
	// Основной цикл программы
	do{
		switch(RussianMenu()){
		case 1: // Добавление записи
			a=new Man;
			a->Put();
			a->SaveToFile();
			delete a;
			break;
		case 2: // Показ всех записей
			Man::ShowFromFile();
			break;
		case 3://  Прощание с пользователем
			RussianMessage("До Свидания\n");
			return;
		default: // Неправильный ввод
			RussianMessage("Неверный Ввод\n");
		}

	}while(1);

}
*/

