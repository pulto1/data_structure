#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct TreeNode
{
	char val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}

	else
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = str[*pi];
		++(*pi);

		root->left = CreateTree(str, pi);
		root->right = CreateTree(str, pi);

		return root;
	}
}

void InOder(TreeNode* root)
{
	if (root == NULL)
		return;

	InOder(root->left);
	printf("%c ", root->val);
	InOder(root->right);
}

int main()
{
	char str[100];
	scanf("%s", str);

	int i = 0;
	TreeNode* root = CreateTree(str, &i);

	InOder(root);

	return 0;
}

bool _isBalanced(struct TreeNode* root, int* pDepth)
{
	if (root == NULL)
	{
		*pDepth = 0;
		return true;
	}

	else
	{
		int leftDepth = 0;
		if (_isBalanced(root->left, &leftDepth) == false)
			return false;

		int rightDepth = 0;
		if (_isBalanced(root->right, &rightDepth) == false)
			return false;

		if (abs(leftDepth - rightDepth) > 1)
			return false;

		*pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		return true;
	}
}

bool isBalanced(struct TreeNode* root)
{
	int depth = 0;
	return _isBalanced(root, &depth);
}

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
		return true;

	int gap = maxDepth(root->left) - maxDepth(root->right);
	if (abs(gap) > 1)
		return false;

	return isBalanced(root->left) && isBalanced(root->right);
}