
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

// 我的解法1：递归
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;
 
        int left = TreeDepth(pRoot->left) + 1;
        int right = TreeDepth(pRoot->right) + 1;
 
        return max(left, right);
    }
};

// 我的解法2：循环，用pair保存当前节点指针和对应深度
class Solution2 {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		int depth = 0;
		int maxDepth = depth;
		TreeNode* p = pRoot;
		stack<pair<TreeNode*, int>> s;

		while (!s.empty() || p != NULL)
		{
			while (p != NULL)
			{
				s.push(pair<TreeNode*, int>(p, ++depth));
				p = p->left;
			}

			p = s.top().first;
			depth = s.top().second;
			maxDepth = depth > maxDepth ? depth : maxDepth;
			s.pop();
			p = p->right;
		}

		return maxDepth;
	}
};