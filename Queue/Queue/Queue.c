#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

// 初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

// 销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_head;

	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	pq->_head = pq->_tail = NULL;
}

// 队尾入队列
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));

	if (newnode == NULL)
	{
		printf("内存不足\n");
		exit(-1);
	}

	newnode->_data = x;
	newnode->_next = NULL;

	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newnode;
	}

	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

// 队头出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head);

	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;

	if (pq->_head == NULL)
	{
		pq->_tail = NULL;
	}
}

// 获取队列头部元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);

	return pq->_head->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);

	return pq->_tail->_data;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->_head == NULL ? 1 : 0;
}

// 获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_head;
	int size = 0;

	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}