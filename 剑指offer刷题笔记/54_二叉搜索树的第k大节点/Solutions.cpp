
// 我的解法
class Solution1 {
public:
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		vector<TreeNode *> array;
		inOrder(pRoot, array);

		if (k > 0 && k <= array.size())
			return array[k - 1];
		else
			return nullptr;
	}

	void inOrder(TreeNode* root, vector<TreeNode *> &array) {
		if (!root) return;

		inOrder(root->left, array);
		array.push_back(root);
		inOrder(root->right, array);
	};
};

// 其它解法
class Solution2 {
	int count = 0;
public:
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (pRoot) {
			TreeNode *ret = KthNode(pRoot->left, k);
			if (ret) return ret;
			if (++count == k) return pRoot;
			ret = KthNode(pRoot->right, k);
			if (ret) return ret;
		}
		return nullptr;
	}
};

// 官方解法略，见参考书