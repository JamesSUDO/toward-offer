
// 解法
// 参考官方解答
// 用一个一维vector存储前序遍历的得到的val，到叶节点判断是否满足条件
// 满足条件就把一维数组push到二维数组中
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL) return {};
        
        vector<vector<int> >  vec;
	    vector<int> cur_vec;

	    helper(vec, cur_vec, root, expectNumber, 0);
        
        return vec;
    }
    
    void helper(vector<vector<int> > &vec, vector<int> cur_vec, TreeNode* node, const int expectNumber, int curSum)
    {
	    curSum += node->val;
	    cur_vec.push_back(node->val);
	    if (!node->left && !node->right && curSum == expectNumber)
	    {
		    vec.push_back(cur_vec);
	    }

	    if (node->left && !node->right) helper(vec, cur_vec, node->left, expectNumber, curSum);

	    if (!node->left && node->right) helper(vec, cur_vec, node->right, expectNumber, curSum);

	    if (node->left && node->right)
	    {
		    if (node->left < node->right)
		    {
			    helper(vec, cur_vec, node->left, expectNumber, curSum);
			    helper(vec, cur_vec, node->right, expectNumber, curSum);
		    }
		    else
		    {
			    helper(vec, cur_vec, node->right, expectNumber, curSum);
			    helper(vec, cur_vec, node->left, expectNumber, curSum);
		    }
	    }

	    cur_vec.pop_back();
	}
};