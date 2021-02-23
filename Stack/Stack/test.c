#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

void Test()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);

	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestroy(&st);
}

int main()
{
	Test();
	return 0;
}