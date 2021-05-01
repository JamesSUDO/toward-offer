
// 这个题，我没想出来有什么好的方法，然后看了书上的解析，写了如下的代码
// 具体原理的说明见readme
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()) return NULL;
        
        TreeNode* root = new TreeNode(pre[0]);
        helper(root, 0, 0, vin.size() - 1, pre, vin);
        return root;
    }
    
    // pre_ptr：对应在pre中元素的序号
    // left和right是对应vin中左端点和右端点
    void helper(TreeNode* root, int pre_ptr, int left, int right, vector<int>& pre, vector<int>& vin)
    {
        int root_num = left;  // root_num是pre数组的当前元素对应在vin中的位置
        for(root_num; root_num <= right; root_num++)
        {
            if(vin[root_num] == pre[pre_ptr]) break;
        }

        if(root_num != left)
        {
            TreeNode* t = new TreeNode(pre[pre_ptr + 1]);
            root->left = t;
            helper(t, pre_ptr + 1, left, root_num - 1, pre, vin);
        }
        
        if(root_num != right)
        {
            TreeNode* t = new TreeNode(pre[pre_ptr + root_num - left + 1]);
            root->right = t;
            helper(t, pre_ptr + root_num - left + 1, root_num + 1, right, pre, vin);
        }
    }
};