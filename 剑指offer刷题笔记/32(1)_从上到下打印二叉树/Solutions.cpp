
// 此题属于二叉树的广度优先遍历，因此用队列即可解决
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(!root) return {};
        
        vector<int> m;
        queue<TreeNode*> q; q.push(root);
        
        while (!q.empty())
        {
            TreeNode* t = q.front(); q.pop();
            m.push_back(t->val);
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        
        return m;
    }
};


// 官方解法同样用的队列，区别于我用的queue，官方用的是deque，二者均可
// 代码略