#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

void TestInsertSort()
{
	int a[] = { 3, 1, 4, 1, 7, 9, 8, 2, 0, 5 };
	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	//PrintArray(a, sizeof(a) / sizeof(int));
}

void TestCountSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(a, sizeof(a) / sizeof(int));
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	//TestInsertSort();
	/*TestShellSort();*/
	/*MergeSortFile("Sort.txt");*/
	TestCountSort();
	return 0;
}

