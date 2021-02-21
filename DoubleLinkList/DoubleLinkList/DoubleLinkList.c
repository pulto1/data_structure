#define _CRT_SECURE_NO_WARNINGS

#include "DoubleLinkList.h"

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;

	return node;
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");
}


void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	
	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;

}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;

	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;
}

// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;
}

// 双向链表头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;

	phead->next = second;
	second->prev = phead;

	free(first);
}

// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}

	return NULL;

}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

// 双向链表销毁
void ListDestory(ListNode** pphead)
{
	assert(*pphead);
	ListNode* cur = *pphead;
	while (cur != *pphead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(*pphead);
	*pphead = NULL;
}

void ListClear(ListNode* phead)
{
	assert(phead);
	//清理所有数据结点，保留头结点，可以继续使用

	ListNode* cur = phead;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	phead->next = phead;
	phead->prev = phead;
}