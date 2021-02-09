#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

// 顺序表，有效数组在数组中必须是连续
// 静态顺序表设计 （固定大小）
//typedef int SLDataType;
//#define N 10
//
//// vector
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};
//
//void SeqListPushBack(struct SeqList* ps, SLDataType x);
//void SeqListPopBack(struct SeqList* ps);
//void SeqListPushFront(struct SeqList* ps, SLDataType x);
//void SeqListPopFront(struct SeqList* ps);

// 动态顺序表设计 （大小可变）
typedef int SLDataType;

// vector
typedef struct SeqList
{
	SLDataType* a;
	int size;      // 有效数据的个数
	int capacity;  // 容量
}SL;

// 尾插尾删  头插头删
void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);

void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);

void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

// 任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

// 顺序表查找
int SeqListFind(SL* psl, SLDataType x);

// ...
//int SeqListSort(SL* psl);
//int SeqListBinaryFind(SL* psl, SLDataType x);





