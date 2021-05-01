
// 我的解法
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> arr2d;
        if (!pRoot) return arr2d;
 
        queue<TreeNode *> que;
        que.push(pRoot);
 
        while (!que.empty()) {
            vector<int> arr;
            for (int i = que.size(); i > 0; i--) {
                TreeNode* cur = que.front();
                que.pop();
                arr.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            arr2d.push_back(arr);
        }
        return arr2d;
    }
};


// 官方解法略，见参考书