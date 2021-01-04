
#include "stdio.h"
#include "iostream.h"

int count=0; //Глобальный счётчик элементов во входящем файле

void counter (FILE *f1) //Программа-счётчик количества элементов (строчек) в файле с исходными данными
{
	cout << "\n---void counter function is called---";
	int value;
	while (fscanf(f1,"%d", &value)==1) //Считываем первый файл - просто чтобы посчитать количество точек, ещё не записываем его
		{
			count++;
		}
	cout << "\nFile count OK"; //Посчитали
	cout << "\nTime series contain " << count << " elements.";
}

int *fill_array (FILE *f1) //Программа заполнения динамического массива с чтением файла
{
	cout << "\n---int *fill_array function is called---";
	int *row; //Инициализация динамического массива для хранения временного ряда
	if ((row = new int [count])==NULL) //Выделилась ли память?
		{
			printf ("\nPointer error.");
			return NULL;
		}
	int i;
	for(i=0;i<count;i++) //Считываем первый файл - уже в динамический массив
	{
		fscanf(f1,"%d", &row[i]);
	}
	cout << "\nFile input OK";
	return row;
}

void print_array (int* row) //Печатаем содержимое динамического массива
{
	cout << "\n---void print_array function is called---";
	for(int i=0;i<count;i++) //Выводим на экран его содержимое
	{
		cout << "\n " << i <<": "<<row[i];
	}
}

int main(int argc, char* argv[])
{
	cout << "\n\n---int main function is called---";
	FILE *f1, *f2; //Указатели на потоки
	if (argc!=3)//Проверка командной строки
	{
		printf("\nFiles are not found");
		return 1;
	}
	printf("\nFiles are being opened");
	if((f1=fopen(argv[1], "r")) == NULL) //Открываем входящий поток - файл с исходным временным рядом
	{
		perror(argv[1]);
		return 1;
	}
	if((f2=fopen(argv[2], "w+")) == NULL) //Открываем выходящий поток для записи результатов
	{
		perror(argv[2]);
		return 1;
	}
	counter(f1); //Запустили счётчик записей, результат - в count
           if(fseek(f1, 0, SEEK_SET))
	{
		perror(argv[1]);
		return 1;
	}
	int *row; //Инициализация динамического массива для дальнейшей работы
	row=fill_array (f1);//Динамический массив заполняется специальной функцией, открывающей файл с исходными данными
	print_array (row);//И выводится на экран
	return 0;
}
