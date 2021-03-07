#define _CRT_SECURE_NO_WARNINGS

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = (parent * 2) + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[parent] < a[child])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}
	}
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	*returnSize = k;
	int* retArr = (int*)malloc(sizeof(int)* k);

	if (k == 0)
		return retArr;

	for (int i = 0; i < k; i++)
	{
		retArr[i] = arr[i];
	}

	//建K个数的大堆
	for (int i = (k - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDown(retArr, k, i);
	}

	for (int j = k; j < arrSize; j++)
	{
		if (arr[j] < retArr[0])
		{
			retArr[0] = arr[j];
			AdjustDown(retArr, k, 0);
		}
	}

	return retArr;
}