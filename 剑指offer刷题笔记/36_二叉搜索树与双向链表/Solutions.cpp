
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 我的解法：递归中序遍历，用vector存储节点指针
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
        if(pRootOfTree == NULL) return NULL;
        
		vector<TreeNode*> vec;
		inOrder(vec, pRootOfTree);
        
        if(vec.size() == 1) return pRootOfTree;

		vec[0]->right = vec[1];

		for (int i = 1; i < vec.size() - 1; i++)
		{
			vec[i]->left = vec[i - 1];
			vec[i]->right = vec[i + 1];
		}

		vec[vec.size() - 1]->left = vec[vec.size() - 2];
        
        return vec[0];
	}

	void inOrder(vector<TreeNode*> &vec, TreeNode* node)
	{
		if (node == NULL) return;

		inOrder(vec, node->left);
		vec.push_back(node);
		inOrder(vec, node->right);
	}
};


// 官方解法：同样是递归中序遍历，没有用辅助数组，代码略