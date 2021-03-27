#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(4 * sizeof(STDataType));
	ps->_capacity = 4;
	ps->_top = 0;
}

// ��ջ 
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

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	ps->_top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 1 : 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
}