
#include "stdio.h"
#include "iostream.h"

int count=0; //���������� ������� ��������� �� �������� �����

void counter (FILE *f1) //���������-������� ���������� ��������� (�������) � ����� � ��������� �������
{
	cout << "\n---void counter function is called---";
	int value;
	while (fscanf(f1,"%d", &value)==1) //��������� ������ ���� - ������ ����� ��������� ���������� �����, ��� �� ���������� ���
		{
			count++;
		}
	cout << "\nFile count OK"; //���������
	cout << "\nTime series contain " << count << " elements.";
}

int *fill_array (FILE *f1) //��������� ���������� ������������� ������� � ������� �����
{
	cout << "\n---int *fill_array function is called---";
	int *row; //������������� ������������� ������� ��� �������� ���������� ����
	if ((row = new int [count])==NULL) //���������� �� ������?
		{
			printf ("\nPointer error.");
			return NULL;
		}
	int i;
	for(i=0;i<count;i++) //��������� ������ ���� - ��� � ������������ ������
	{
		fscanf(f1,"%d", &row[i]);
	}
	cout << "\nFile input OK";
	return row;
}

void print_array (int* row) //�������� ���������� ������������� �������
{
	cout << "\n---void print_array function is called---";
	for(int i=0;i<count;i++) //������� �� ����� ��� ����������
	{
		cout << "\n " << i <<": "<<row[i];
	}
}

int main(int argc, char* argv[])
{
	cout << "\n\n---int main function is called---";
	FILE *f1, *f2; //��������� �� ������
	if (argc!=3)//�������� ��������� ������
	{
		printf("\nFiles are not found");
		return 1;
	}
	printf("\nFiles are being opened");
	if((f1=fopen(argv[1], "r")) == NULL) //��������� �������� ����� - ���� � �������� ��������� �����
	{
		perror(argv[1]);
		return 1;
	}
	if((f2=fopen(argv[2], "w+")) == NULL) //��������� ��������� ����� ��� ������ �����������
	{
		perror(argv[2]);
		return 1;
	}
	counter(f1); //��������� ������� �������, ��������� - � count
           if(fseek(f1, 0, SEEK_SET))
	{
		perror(argv[1]);
		return 1;
	}
	int *row; //������������� ������������� ������� ��� ���������� ������
	row=fill_array (f1);//������������ ������ ����������� ����������� ��������, ����������� ���� � ��������� �������
	print_array (row);//� ��������� �� �����
	return 0;
}
