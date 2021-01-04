#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <time.h>


using namespace std;

int read(int *a, char in[])
{
	int l;
	ifstream fin(in);
	if (!fin.is_open())
		return -1;
	fin >> l;
	for (int i = 0; i < l; i++)
	{
		fin >> a[i];
	}
	return l;
}

bool check(int *a, int l)
{
	bool ans = 1;
	for (int i = 1; i < l; i++)
	{
		if (a[i] < a[i - 1])
			return 0;
	}
	return ans;
}

void random(int *a, int l)
{
	for (int i = 0; i < l; i++)
	{
		a[i] = rand() % 1001;
	}
}

void display(int *a, int l)
{
	for (int i = 0; i < l; i++)
	{
		cout << a[i] << ' ';

	}
	cout << endl;
}

void bubbleSort(int *a, int l)
{
	for (int i = 0; i < l - 1; i++)
	{
		bool s = 0;
		for (int j = (l - 1); j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				s = 1;
			}
		}
		if (s == 0)
			break;
	}
}

int* merge_sort_inside(int *up, int *down, unsigned int left, unsigned int right)
{
	if (left == right)
	{
		down[left] = up[left];
		return down;
	}

	unsigned int middle = (left + right) / 2;

	int *l_buff = merge_sort_inside(up, down, left, middle);
	int *r_buff = merge_sort_inside(up, down, middle + 1, right);

	int *target = l_buff == up ? down : up;

	unsigned int l_cur = left, r_cur = middle + 1;
	for (unsigned int i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right)
		{
			if (l_buff[l_cur] < r_buff[r_cur])
			{
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle)
		{
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	return target;
}

void merge_sort(int *a, unsigned int l)
{
	int *buff = new int[l];
	buff = merge_sort_inside(a, buff, 0, l);
	for (unsigned int i = 0; i < l; i++)
        a[i] = buff[i];
	delete buff;
}

int main()
{
    cout.precision(10);
	clock_t start, stop;
	int l;
	bool k;
	//char in[] = "input.txt";
	cout << "Enter the length of array: " << endl;
	cin >> l;
	cout << "Press 0 to use Bubble Sort, 1 to use Merge Sort " << endl;
	cin >> k;
	int *a = new int[l];
	random(a, l);
	//display(a, l);
	if (k == 0)
	{
		start = clock();
		bubbleSort(a, l);
		stop = clock();
		double t = (double)(stop - start)/CLOCKS_PER_SEC;
		cout << "Bubble Sort:" << endl << "Check: " << check(a, l) << ' ' << "Time: " << t << endl;
	}
	else
	{
		start = clock();
		merge_sort(a, l);
		stop = clock();
		double t = (double)(stop - start)/CLOCKS_PER_SEC;
		cout << "Merge Sort:" << endl << "Check: " << check(a, l) << " " << "Time: " << t << endl;

	}
	delete a;
}
