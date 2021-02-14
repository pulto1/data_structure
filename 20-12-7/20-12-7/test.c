#define _CRT_SECURE_NO_WARNINGS

int removeElement(int* nums, int numsSize, int val)
{
	int src = 0, dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}

		else
		{
			src++;
		}
	}
	return dst;
}

int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;

	int prev = 0, cur = 1, dst = 0;

	while (cur < numsSize)
	{
		if (nums[prev] != nums[cur])
		{
			nums[dst] = nums[prev];
			prev++;
			cur++;
			dst++;
		}

		else
		{
			prev++;
			cur++;
		}
	}

	nums[dst] = nums[prev];
	dst++;
	prev++;

	return dst;
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int kSize = 0;
	//1234
	int kNum = K;
	while (kNum)
	{
		kNum++;
		kNum /= 10;
	}

	int len = ASize > kSize ? ASize : kSize;
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));

	//A[]
	//k

	int Ai = ASize - 1;
	int reti = 0;
	int nextNum = 0; //进位

	while (len--)
	{
		int a = 0;
		if (Ai >= 0)
		{
			a = A[Ai];
			Ai--;
		}

		int ret = a + K % 10 + nextNum;
		K /= 10;

		if (ret > 9)
		{
			ret -= 10;
			nextNum = 1;
		}

		else
		{
			nextNum = 0;
		}

		retArr[reti] = ret;
		ret++;
	}

	if (nextNum == 1)
	{
		retArr[reti] = 1;
		reti++;
	}

	int left = 0;
	int right = reti - 1;
	while (left < right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = tmp;
		left++;
		right--;
	}

	*returnSize = reti;
	return retArr;
}

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3 = head->next;

	while (n2)
	{
		//反转
		n2->next = n1;

		//迭代
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}

	return n1;
}