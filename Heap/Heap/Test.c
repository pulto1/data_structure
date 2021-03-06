#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

void HeapSort(int* a, int n)
{
	// 1.建堆
	//for (int i = n - 1; i >= 0; ++i)
	// 时间复杂度？
	// 假设树有N个节点，树高度：logN
	// 要注意这里时间复杂度不是N*logN，他的时间复杂度是O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		// 再继续选次小的
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(a, sizeof(a) / sizeof(HPDataType));

	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(HPDataType));
	/*HeapPush(&hp, 13);

	HeapDestory(&hp);
*/
	return 0;
}