#define _CRT_SECURE_NO_WARNINGS

typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return NULL;

	//1.
	Node* cur = head;
	while (cur)
	{
		Node* copy = (Node*)malloc(sizeof(Node));
		copy->next = NULL;
		copy->random = NULL;
		copy->val = cur->val;

		Node* next = cur->next;
		cur->next = copy;
		copy->next = next;

		cur = next;
	}

	//2.处理拷贝结点的random
	cur = head;
	while (cur)
	{
		Node* copy = cur->next;
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;

		cur = cur->next->next;
	}

	//3.拆
	cur = head;
	Node* copyHead = cur->next;
	while (cur)
	{
		Node* copy = cur->next;
		Node* next = copy->next;

		cur->next = next;
		if (next)
			copy->next = next->next;
		else
			copy->next = NULL;

		cur = next;
	}

	return copyHead;
}

typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* sortHead = head;
	Node* cur = head->next;
	sortHead->next = NULL;

	while (cur)
	{
		Node* next = cur->next;

		//把cur插入到sortHead链表中，并且保持有序
		if (cur->val <= sortHead->val)
		{
			//头插
			cur->next = sortHead;
			sortHead = cur;
		}

		else
		{
			//中间插
			Node* sortPrev = sortHead;
			Node* sortCur = sortPrev->next;
			while (sortCur)
			{
				if (cur->val <= sortCur->val)
				{
					sortPrev->next = cur;
					cur->next = sortCur;
					break;
				}

				else
				{
					sortPrev = sortCur;
					sortCur = sortCur->next;
				}
			}

			//尾插
			if (sortCur == NULL)
			{
				sortPrev->next = cur;
				cur->next = NULL;
			}
		}

		cur = next;
	}

	return sortHead;
}

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* prev = NULL;
		ListNode* cur = pHead;
		ListNode* next = cur->next;

		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}

			else
			{
				while (next && cur->val == next->val)
				{
					next = next->next;
				}

				if (prev == NULL)
				{
					pHead = next;
				}
					
				else
				{
					prev->next = next;
				}
					
				//释放
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}

				if (cur)
					next = cur->next;
			}
		}
		return pHead;
	}

};

