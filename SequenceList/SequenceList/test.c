#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

Test()
{
	SL s;
	SeqListInit(&s);
	SeqListInsert(&s, 0, 1);
	SeqListInsert(&s, 0, 2);
	SeqListInsert(&s, 0, 3);
	SeqListInsert(&s, 0, 4);
	SeqListInsert(&s, 0, 5);
	SeqListInsert(&s, 0, 6);
	SeqListPrint(&s);
	printf("%d\n", SeqListFind(&s, 7));
	//SeqListErase(&s, 1);
	//SeqListPrint(&s);

	/*SeqListPushFront(&s, -1);
	SeqListPrint(&s);
	SeqListPushFront(&s, -2);
	SeqListPrint(&s);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);*/

	/*SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
*/
	
	/*SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);*/
}

int main()
{
	Test();
	return 0;
}
