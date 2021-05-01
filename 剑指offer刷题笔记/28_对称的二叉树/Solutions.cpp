
// 我的解法
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot) return true;
		if (!pRoot->left && !pRoot->right) return true;
		if ((!pRoot->left || !pRoot->right)) return false;
		return helper(pRoot->left, pRoot->right);
	}

	bool helper(TreeNode* leftNode, TreeNode* rightNode) {
		if (!leftNode && !rightNode) return true;
		if (!leftNode || !rightNode) return false;

		if (leftNode->val != rightNode->val) return false;
		return helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left);
	}
};


// 官方解法略，见参考书