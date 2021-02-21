#define _CRT_SECURE_NO_WARNINGS

#include "DoubleLinkList.h"

void Test()
{
	ListNode* phead = ListInit();

	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	ListPrint(phead);
	ListNode* pos = ListFind(phead, 4);
	ListErase(pos);
	ListPrint(phead);

	/*ListInsert(pos, 0);
	ListPrint(phead);*/
	/*pos->data = 0;
	ListPrint(phead);*/

	//ListPopFront(phead);
	//ListPrint(phead);
	//ListPopFront(phead);
	//ListPrint(phead);
	//ListPopFront(phead);
	//ListPrint(phead);

	//ListPushFront(phead, -1);
	//ListPrint(phead);
	//ListPushFront(phead, -2);
	//ListPrint(phead);
	//ListPushFront(phead, -3);
	//ListPrint(phead);

	
	//ListPopBack(phead);
	//ListPrint(phead);
	//ListPopBack(phead);
	//ListPrint(phead);
	//ListPopBack(phead);
	//ListPrint(phead);

	//ListPushBack(phead, 2);
	//ListPrint(phead);
	//ListPushBack(phead, 3);
	//ListPrint(phead);
}

int main()
{
	Test();
	return 0;
}