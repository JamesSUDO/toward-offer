
// 我的解法：递归找到叶节点和对应深度，再作判断
class Solution1 {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL) return true;

		set<int> s;
		if (!pRoot->left || !pRoot->right)  // 需要规避根节点的左子节点或右子节点为空的特殊情况
			s.insert(1);

		return isBalanced(pRoot, 1, s);
	}

	bool isBalanced(TreeNode* root, int depth, set<int> &s)
	{
		if (!root->left && !root->right) // 如果是叶节点
		{
			if (s.find(depth) == s.end())
			{
				if (s.size() == 2) // 深度值最多只能有两个，如果出现第三个，必不可能为平衡二叉树
					return false;
				else if (s.size() == 1)  // 判断当前深度和另一个深度的关系
				{
					if (*s.begin() - depth > 1 || *s.begin() - depth < -1) return false;
				}
				s.insert(depth);  // 如果当前无深度值，或者深度个数1的时候满足差值小于等于1，则插入新深度值
			}
			return true;
		}

		bool left = true, right = true;
		if (root->left) left = isBalanced(root->left, depth + 1, s);
		if (root->right) right = isBalanced(root->right, depth + 1, s);

		return left && right;
	}
};


// 官方解法：递归遍历每一个节点，比较左右两子节点对应深度
class Solution2 {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return isBalanced(pRoot, depth);
	}

	bool isBalanced(TreeNode* root, int &depth)
	{
		if (root == NULL)
		{
			depth = 0;
			return true;
		}
		
		int left, right;
		if (isBalanced(root->left, left) && isBalanced(root->right, right))
		{
			int diff = left - right;
			if (diff >= -1 && diff <= 1)
			{
				depth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
};