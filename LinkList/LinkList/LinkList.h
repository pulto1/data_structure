#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;
// 结点
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

//struct SList
//{
//	SListNode* head;
//	SListNode* tail;
//};

void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);
void SListPushFront(SListNode** phead, SListDataType x);
void SListPopFront(SListNode** phead);
SListNode* SListFind(SListNode* phead, SListDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SListDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);


void SListPrint(SListNode* phead);




