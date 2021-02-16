#define _CRT_SECURE_NO_WARNINGS

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* newHead = NULL;
	struct ListNode* cur = head;

	while (cur)
	{
		struct ListNode* next = cur->next;

		//头插
		cur->next = newHead;
		newHead = cur;

		cur = next;
	}

	return newHead;
}

typedef struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val)
{
	Node* prev = NULL;
	Node* cur = head;

	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}

			else
			{
				prev->next = cur->next;
				free(cue);
				cur = prev->next;
			}
		}

		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}

int main()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 6;

	Node* n1 = (Node*)malloc(sizeof(Node));
	n2->val = 6;

	Node* n1 = (Node*)malloc(sizeof(Node));
	n3->val = 1;

	Node* n1 = (Node*)malloc(sizeof(Node));
	n4->val = 6;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	return 0;
}

struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

typedef struct ListNode Node;
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	Node* fast = pListHead;
	Node* slow = pListHead;

	while (k--)
	{
		if (fast)
			fast = fast->next;
		else
			return NULL;
	}

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	
	if (l2 == NULL)
		return l1;

	Node* head = NULL;
	Node* tail = NULL;

	if (l1->val < l2->val)
	{
		head = tail = l1;
		l1 = l1->next;
	}

	else
	{
		head = tail = l2;
		l2 = l2->next;
	}

	//取小的尾插
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}

		tail = tail->next;
	}

	if (l1)
		tail->next = l1;

	else
		tail->next = l2;

	return head;
}

typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;

	if (l2 == NULL)
		return l1;

	Node* head = NULL;
	Node* tail = NULL;

	//带有哨兵位的头结点，方便尾插
	head = tail = (Node*)malloc(sizeof(Node));

	//取小的尾插
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}

		tail = tail->next;
	}

	if (l1)
		tail->next = l1;

	else
		tail->next = l2;

	Node* realHead = head->next;
	free(head);

	return realHead;
}