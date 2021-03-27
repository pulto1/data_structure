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

// ��������
// ʱ�临�Ӷȣ�O(N^2)  
// �ռ临�Ӷȣ�O(1)
// ʲô�������ã�˳��������߽ӽ��������  ʲô�������������
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; ++i)
	{
		// ��end+1�����ݲ���[0,end]����������
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

// ϣ������ O(N^1.3��N^2��
void ShellSort(int* a, int n)
{
	// 1.gap>1�൱��Ԥ����������ӽ�����
	// 2.gap==1���൱��ֱ�Ӳ������򣬱�֤����
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; // +1��֤�����һ��gapһ����1
		// gap == 1���һ�ξ��൱��ֱ�Ӳ�������
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


// ѡ������
// O(N^2)
void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0, end = n - 1;
	while (begin < end)
	{
		// ��[begin,end]֮���ҳ���С�������������±�
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
		// ���maxi��beginλ���ص�����maxi��λ����Ҫ����
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

// ������
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

// ʱ�临�Ӷ�O(N*logN)
void HeapSort(int* a, int n)
{
	// �����򣬽���ѻ���С��?
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

		// ���һ��ð�ݵĹ�����û�з�����������ǰ�����Ѿ����򣬲���Ҫ��ð��
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
// ����ָ�뷨
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	int keyindex = end;
	while (begin < end)
	{
		// begin�Ҵ�
		while (begin < end && a[begin] <= a[keyindex])
		{
			++begin;
		}

		// end��С
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

// �ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);

	// �ӣ��ӵ���˼������λ�õ�ֵ�������ˣ����Ը������µ�ֵ��
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			++begin;

		// ����ҵ���key�����ұߵĿӣ�beginλ�þ��γɵ��µĿ�
		a[end] = a[begin];

		while (begin < end && a[end] >= key)
			--end;

		// �ұ��ҵ���keyС�����ߵĿӣ�endλ�þ��γɵ��µĿ�
		a[begin] = a[end];
	}

	a[begin] = key;

	return begin;
}

// 3��ǰ��ָ�뷨
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

// �ݹ�ķǵݹ� -- 1����ѭ��(쳲������������) һЩ�򵥵ݹ���ܸ�ѭ�� 2��ջģ��洢���ݷǵݹ�
// �ǵݹ飺1�����Ч�ʣ��ݹ齨��ջ֡���������ĵģ����Ƕ����ִ��ļ����������Ż�΢����΢���Ժ��Բ��ƣ�
//         2���ݹ����ȱ���ǣ����ջ֡�����̫����ܻᵼ��ջ�������Ϊϵͳջ�ռ�һ�㲻����M����
//            ���ݽṹջģ��ǵݹ飬�����Ǵ洢�ڶ��ϵģ�����G����Ŀռ�              
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

	// �ѹ鲢�õ���tmp�������ڿ����ص�ԭ����
	for (int i = left; i <= right; ++i)
		a[i] = tmp[i];
}

// ʱ�临�Ӷ�O(N*logN)
// �ռ临�Ӷ�O(N)
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	// �鲢[left,mid][mid+1,right]����
	MergeArr(a, left, mid, mid + 1, right, tmp);
}

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

// �鲢����ǵݹ�ʵ��
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
			// 1���ϲ�ʱֻ�е�һ��,�ڶ��鲻���ڣ��Ͳ���Ҫ�ϲ�
			if (begin2 >= n)
				break;

			// 2���ϲ�ʱ�ڶ���ֻ�в������ݣ���Ҫ����end2�߽�
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
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
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
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	// �ָ��һ��һ�����ݣ��ڴ������д����С�ļ���
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
				printf("���ļ�ʧ��\n");
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

	// ���û���鲢���ļ���ʵ����������
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";

	for (int i = 2; i < n; i++)
	{
		//��ȡfile1��file2�����й鲢��mfile
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

	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		countArr[a[i] - min]++;
	}

	//����
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