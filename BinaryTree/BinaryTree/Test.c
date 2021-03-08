#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* CreateNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL "); return;
	}

	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL "); return;
	}

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL "); return;
	}

	PostOrder(root->_left);
	PostOrder(root->_right);

	printf("%c ", root->_data);
}

//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	
//	++size;
//	TreeSize(root->_left);
//	TreeSize(root->_right);
//
//	return size;
//}

//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return;
//	else
//		(*psize)++;
//
//	TreeSize(root->_left, psize);
//	TreeSize(root->_right, psize);
//}

int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}


int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL && root->_left == NULL)
		return 1;

	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

int main()
{

	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;

	//printf("BinaryTreeSize: %d\n", TreeSize(A));
	//printf("BinaryTreeSize: %d\n", TreeSize(A));

	printf("BinaryLeafTreeSize: %d\n", TreeLeafSize(A));
	/*PostOrder(A);
	printf("\n");*/

	return 0;
}