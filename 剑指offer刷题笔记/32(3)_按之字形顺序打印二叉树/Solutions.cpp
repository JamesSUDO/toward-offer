
// 我的解法：顺序层序打印，偶数层执行反序操作
class Solution1 {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> arr2d;
        if (!pRoot) return arr2d;
 
        queue<TreeNode *> que;
        que.push(pRoot);
        bool isReverse = false;
 
        while (!que.empty()) {
            vector<int> arr;
            for (int i = que.size(); i > 0; i--) {
                TreeNode* cur = que.front();
                que.pop();
                arr.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            if (isReverse) reverse(arr.begin(), arr.end());
            isReverse = !isReverse;
            arr2d.push_back(arr);
        }
        return arr2d;
    }
};


// 官方解法：用栈的特性
class Solution2 {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > arr2d;
		if (!pRoot) return arr2d;

		stack<TreeNode *> s1, s2;
		s1.push(pRoot);
		while (!s1.empty()) {
			vector<int> arr1, arr2;
			while (!s1.empty()) {
				TreeNode* cur = s1.top();
				s1.pop();
				arr1.push_back(cur->val);
				if (cur->left) s2.push(cur->left);
				if (cur->right) s2.push(cur->right);
			}
			while (!s2.empty()) {
				TreeNode* cur = s2.top();
				s2.pop();
				arr2.push_back(cur->val);
				if (cur->right) s1.push(cur->right);
				if (cur->left) s1.push(cur->left);
			}
			if (!arr1.empty()) arr2d.push_back(arr1);
			if (!arr2.empty()) arr2d.push_back(arr2);
		}
		return arr2d;
	}
};