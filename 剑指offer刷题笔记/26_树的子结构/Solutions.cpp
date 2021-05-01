
// 官方解法：递归
// 我小改动了一下，原理都一样
// 需要用到两个递归函数，先在外层递归遍历A的节点，直到找到A的当前节点值等于B的根节点值
// 然后进入内层递归，遍历A当前节点往下和B的所有节点，判断B和A的一部分是否相同
// 若相同则直接返回true，否则继续外层递归，遍历A的下一个节点
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 如果一直遍历到NULL都没有值相同的节点，返回false
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        
        if(pRoot1->val == pRoot2->val)
        {
            // 若两节点值相同，则判断两节点的子树是否一样
            if(JudgeSameSubtree(pRoot1->left, pRoot2->left) &&
               JudgeSameSubtree(pRoot1->right, pRoot2->right))
                return true;
        }
        
        // 若上面没有直接返回true，则进行A下一个节点的判断
        return HasSubtree(pRoot1->left, pRoot2) || 
               HasSubtree(pRoot1->right, pRoot2);
    }
    
    bool JudgeSameSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL) return true;  // 和下面的if不能颠倒顺序
        
        if(pRoot1 == NULL) return false;
        
        if(pRoot1->val != pRoot2->val) return false;
        
        return JudgeSameSubtree(pRoot1->left, pRoot2->left) && 
               JudgeSameSubtree(pRoot1->right, pRoot2->right);
    }
};