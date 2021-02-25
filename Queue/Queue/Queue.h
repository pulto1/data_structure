#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

// 链式结构：表示队列
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;
// 队列的结构
typedef struct Queue{
	QueueNode* _head; //队头
	QueueNode* _tail;  // 队尾
}Queue;
// 初始化队列
void QueueInit(Queue* pq);
// 队尾入队列
void QueuePush(Queue* pq, QDataType x);
// 队头出队列
void QueuePop(Queue* pq);
// 获取队列头部元素
QDataType QueueFront(Queue* pq);
// 获取队列队尾元素
QDataType QueueBack(Queue* pq);
// 获取队列中有效元素个数
int QueueSize(Queue* pq);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* pq);
// 销毁队列
void QueueDestroy(Queue* pq);