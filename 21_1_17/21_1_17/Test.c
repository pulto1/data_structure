#define _CRT_SECURE_NO_WARNINGS

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;

	//结构不同
	if (p == NULL && q != NULL)
		return false;

	if (p != NULL && q == NULL)
		return false;

	//值不同
	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL)
		return false;

	if (isSameTree(s, t));
	return true;

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;

	//结构不同
	if (p == NULL && q != NULL)
		return false;

	if (p != NULL && q == NULL)
		return false;

	//值不同
	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	else
	{
		struct TreeNode* right = root->right;
		root->right = invertTree(root->left);
		root->left = invertTree(right);

		return root;
	}
}

struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	else
	{
		struct TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
}

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL)
		return true;

	//当前树
	if (root->left && root->val != root->left->val)
		return false;

	if (root->right && root->val != root->right->val)
		return false;

	//递归判断左右子树
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void  _preorderTraversal(struct TreeNode* root, int* array, int* pi)
{
	if (root == NULL)
		return;

	//...
	array[(*pi)++] = root->val;
	_preorderTraversal(root->left, array, pi);
	_preorderTraversal(root->right, array, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int size = TreeSize(root);
	int* array = (int*)malloc(sizeof(int)* size);
	int i = 0;
	_preorderTraversal(root, array, &i);

	*returnSize = size;

	return array;
}