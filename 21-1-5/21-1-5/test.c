#define _CRT_SECURE_NO_WARNINGS

// 链式结构：表示队列 
typedef int QDataType;

typedef struct QListNode
{
	QDataType _data;
	struct QListNode* _next;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);

	q->_front = NULL;
	q->_rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_next = NULL;

	if (q->_front == NULL)
	{
		q->_front = newnode;
		q->_rear = newnode;
	}

	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_front);

	QNode* next = q->_front->_next;

	free(q->_front);

	q->_front = next;
	if (q->_front == NULL)
		q->_rear = NULL;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);

	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_front);

	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);

	int count = 0;
	QNode* cur = q->_front;

	while (cur)
	{
		count++;
		cur = cur->_next;
	}

	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_front == NULL ? 1 : 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->_front;

	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}


typedef struct
{
	Queue _q1;
	Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);

	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->_q1))
	{
		QueuePush(&obj->_q1, x);
	}

	else
	{
		QueuePush(&obj->_q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	Queue* empty = &obj->_q1;
	Queue* nonEmpty = &obj->_q2;

	if (QueueEmpty(&obj->_q2))
	{
		empty = &obj->_q2;
		nonEmpty = &obj->_q1;
	}

	while (QueueSize(nonEmpty) > 1)
	{
		QueuePush(empty, QueueFront(nonEmpty));
		QueuePop(nonEmpty);
	}

	int top = QueueFront(nonEmpty);
	QueuePop(nonEmpty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->_q1))
	{
		return QueueBack(&obj->_q1);
	}

	else
	{
		return QueueBack(&obj->_q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2);
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->_q1);
	QueueDestroy(&obj->_q2);
	free(obj);
}

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(4 * sizeof(STDataType));
	ps->_capacity = 4;
	ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->_capacity == ps->_top)
	{
		ps->_capacity *= 2;
		STDataType* ret = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
		if (ret == NULL)
		{
			free(ps);
			ps = NULL;
			exit(-1);
		}

		else
		{
			ps->_a = ret;
		}
	}

	ps->_a[ps->_top] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
}

typedef struct
{
	Stack _pushST;
	Stack _popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->_pushST);
	StackInit(&q->_popST);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->_pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	int front = myQueuePeek(obj);
	StackPop(&obj->_popST);

	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if (!StackEmpty(&obj->_popST))
	{
		return StackTop(&obj->_popST);
	}

	else
	{
		while (!StackEmpty(&obj->_pushST))
		{
			StackPush(&obj->_popST, StackTop(&obj->_pushST));
			StackPop(&obj->_pushST);
		}

		return StackTop(&obj->_popST);
	}
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->_popST) && StackEmpty(&obj->_pushST);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->_pushST);
	StackDestroy(&obj->_popST);

	free(obj);
}

typedef struct
{
	int* _a;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->_a = (int*)malloc(sizeof(int)* (k + 1));
	q->_front = 0;
	q->_rear = 0;
	q->_k = k;

	return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;

	obj->_a[obj->_rear] = value;
	obj->_rear++;
	obj->_rear %= (obj->_k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	++obj->_front;
	obj->_front %= (obj->_k + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	else
		return obj->_a[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}


	else
	{
		int tail = obj->_rear - 1;
		if (tail == -1)
			tail = obj->_k;

		return obj->_a[tail];
	}
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->_a);
	free(obj);
}

typedef int DataType;
struct Node
{
	struct Node* _firstChild1; // 第一个孩子结点
	struct Node* _pNextBrother; // 指向其下一个兄弟结点
	DataType _data; // 结点中的数据域
};