#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

// 初始化栈
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = (STDataType*)malloc(sizeof(STDataType)* 4);
	pst->_top = 0;
	pst->_capacity = 4;
}

// 入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);

	//空间不够则增容
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType)* pst->_capacity);
		if (tmp == NULL)
		{
			printf("内存不足\n");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}

	pst->_a[pst->_top] = x;
	pst->_top++;
}

// 出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	--pst->_top;
}

// 获取栈中有效元素个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->_top == 0 ? 1 : 0;
}

// 获取栈顶元素
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	return pst->_a[pst->_top - 1];
}

// 销毁栈
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);

	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}