#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"
#include "Stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// 插入排序
// 时间复杂度：O(N^2)  
// 空间复杂度：O(1)
// 什么情况下最好？顺序有序或者接近有序最好  什么情况下最坏？逆序最坏
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; ++i)
	{
		// 把end+1的数据插入[0,end]的有序区间
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序 O(N^1.3—N^2）
void ShellSort(int* a, int n)
{
	// 1.gap>1相当于预排序，让数组接近有序
	// 2.gap==1就相当于直接插入排序，保证有序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; // +1保证了最后一次gap一定是1
		// gap == 1最后一次就相当于直接插入排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		PrintArray(a, n);
	}
}


// 选择排序
// O(N^2)
void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0, end = n - 1;
	while (begin < end)
	{
		// 在[begin,end]之间找出最小数和最大的数的下标
		int mini, maxi;
		mini = maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		// 如果maxi和begin位置重叠，则maxi的位置需要修正
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 时间复杂度O(N*logN)
void HeapSort(int* a, int n)
{
	// 排升序，建大堆还是小堆?
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

// O(N^2)
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		// 如果一趟冒泡的过程中没有发生交换，则前部分已经有序，不需要再冒泡
		if (exchange == 0)
		{
			break;
		}

		--end;
	}
}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else // a[begin] > a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}

// [begin, end]
// 左右指针法
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	int keyindex = end;
	while (begin < end)
	{
		// begin找大
		while (begin < end && a[begin] <= a[keyindex])
		{
			++begin;
		}

		// end找小
		while (begin < end && a[end] >= a[keyindex])
		{
			--end;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[keyindex]);

	return begin;
}

// [left, right]
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;


	int div = PartSort3(a, left, right);

	//PrintArray(a+left, right-left+1);
	//printf("[%d,%d]%d[%d,%d]\n", left, div - 1, div, div + 1, right);

	//[left, div-1] div [div+1, right]
	QuickSort(a, left, div - 1);
	QuickSort(a, div+1, right);

	//if (left < right)
	//{
	//	int div = PartSort(a, left, right);
	//	//[left, div-1] div [div+1, right]
	//	QuickSort(a, left, div - 1);
	//	QuickSort(a, div + 1, right);
	//}
}

// 挖坑法
int PartSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	// 坑（坑的意思就是这位置的值被拿走了，可以覆盖填新的值）
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			++begin;

		// 左边找到比key大的填到右边的坑，begin位置就形成的新的坑
		a[end] = a[begin];

		while (begin < end && a[end] >= key)
			--end;

		// 右边找到比key小的填到左边的坑，end位置就形成的新的坑
		a[begin] = a[end];
	}

	a[begin] = key;

	return begin;
}

// 3、前后指针法
int PartSort3(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int keyindex = end;

	while (cur < end)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}

	Swap(&a[++prev], &a[keyindex]);

	return prev;
}

// 递归改非递归 -- 1、改循环(斐波那契数列求解) 一些简单递归才能改循环 2、栈模拟存储数据非递归
// 非递归：1、提高效率（递归建立栈帧还是有消耗的，但是对于现代的计算机，这个优化微乎其微可以忽略不计）
//         2、递归最大缺陷是，如果栈帧的深度太深，可能会导致栈溢出。因为系统栈空间一般不大在M级别
//            数据结构栈模拟非递归，数据是存储在堆上的，堆是G级别的空间              
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		// [begin, end]
		int div = PartSort3(a, begin, end);
		// [begin, div-1] div [div+1, end]

		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}

		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}

	StackDestroy(&st);
}

void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	// 把归并好的再tmp的数据在拷贝回到原数组
	for (int i = left; i <= right; ++i)
		a[i] = tmp[i];
}

// 时间复杂度O(N*logN)
// 空间复杂度O(N)
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	// 归并[left,mid][mid+1,right]有序
	MergeArr(a, left, mid, mid + 1, right, tmp);
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i,i+gap-1] [i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// 1、合并时只有第一组,第二组不存在，就不需要合并
			if (begin2 >= n)
				break;

			// 2、合并时第二组只有部分数据，需要修正end2边界
			if (end2 >= n)
				end2 = n - 1;

			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		//PrintArray(a, n);
		gap *= 2;
	}

	free(tmp);
}

void _MergeSortFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);

	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}

		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}

	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}

	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	// 分割成一段一段数据，内存排序后写到，小文件，
	int n = 10;
	int a[10];
	int i = 0;
	int num = 0;
	char subfile[20];
	int filei = 1;
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);
			sprintf(subfile, "%d", filei++);
			FILE* fin = fopen(subfile, "w");
			if (fin == NULL)
			{
				printf("打开文件失败\n");
				exit(-1);
			}
			for (int i = 0; i < n; i++)
			{
				fprintf(fin, "%d\n", a[i]);
			}
			fclose(fin);

			i = 0;
			memset(a, 0, sizeof(int) * n);
		}
	}

	// 利用互相归并到文件，实现整体有序
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";

	for (int i = 2; i < n; i++)
	{
		//读取file1和file2，进行归并出mfile
		_MergeSortFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(file2, "%d", i + 1);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}

	fclose(fout);
}

void CountSort(int* a, int n)
{
	assert(a);

	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int) * range);
	memset(countArr, 0, sizeof(int) * range);

	//统计次数
	for (int i = 0; i < n; i++)
	{
		countArr[a[i] - min]++;
	}

	//排序
	int index = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArr[j]--)
		{
			a[index++] = j + min;
		}
	}

	free(countArr);
}