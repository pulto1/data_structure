#define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

void Test()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPrint(pList);
	SListNode* pos = SListFind(pList, 3);
	SListEraseAfter(pos);
	SListPrint(pList);

	/*SListInsertAfter(pos, 0);
	SListPrint(pList);*/

	/*SListFind(pList, 3)->data = 0;
	SListPrint(pList);*/

	//SListPopFront(&pList);
	//SListPrint(pList);
	//SListPopFront(&pList);
	//SListPrint(pList);


	/*SListPushFront(&pList, -1);
	SListPrint(pList);
	SListPushFront(&pList, -2);
	SListPrint(pList);*/

	/*SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);*/


	/*SListPushBack(&pList, 0);
	SListPrint(pList);*/
}

int main()
{
	Test();
}