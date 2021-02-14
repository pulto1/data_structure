#define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

SListNode* BuySListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void SListPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		// 找尾
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
}

void SListPopBack(SListNode** pphead)
{
	// 1、空
	// 2、一个结点
	// 3、一个以上结点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		prev->next = NULL;
	}
}

void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopFront(SListNode** pphead)
{
	// 1.空
	// 2.一个节点 + 3.一个以上的节点 
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);

		*pphead = next;
	}
}

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 单链表查找
SListNode* SListFind(SListNode* phead, SListDataType x)
{
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);

	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode* next = pos->next;
		SListNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}
