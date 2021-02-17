#define _CRT_SECURE_NO_WARNINGS

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) 
	{
		ListNode* lessHead, *lessTail;
		ListNode* greaterHead, *greaterTail;
		lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
		greaterHead = greaterTail = (ListNode*)malloc(sizeof(ListNode));
		lessHead->next = greaterHead->next = NULL;

		ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}

			else
			{
				greaterTail->next = cur;
				greaterTail = greaterTail->next;
			}

			cur = cur->next;
		}

		lessTail->next = greaterHead->next;
		greaterTail->next = NULL;

		ListNode* List = lessHead->next;
		free(lessHead);
		free(greaterHead);

		return List;
	}
};

typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	ListNode* curA = headA;
	int la = 0;

	while (curA)
	{
		++la;
		curA = curA->next;
	}

	ListNode* curB = headB;
	int lb = 0;

	while (curB)
	{
		++lb;
		curB = curB->next;
	}

	ListNode* longList = headA;
	ListNode* shortList = headB;

	if (lb > la)
	{
		longList = headB;
		shortList = headA;
	}

	int gap = abs(la - lb);

	while (gap--)
	{
		longList = longList->next;
	}

	while (longList)
	{
		if (longList == shortList)
			return longList;

		longList = longList->next;
		shortList = shortList->next;
	}

	return NULL;
}

bool hasCycle(struct ListNode *head) 
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}

	return flast;
}

struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode* slow, *fast;
	slow = fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			break;
	}

	if (fast == NULL || fast->next == NULL)
		return NULL;

	struct ListNode* meet = fast;

	while (head != meet)
	{
		head = head->next;
		meet = meet->next;
	}

	return meet;
}
