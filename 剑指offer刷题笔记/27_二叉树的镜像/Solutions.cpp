
// 我的解法
// 跟官方给出的解法原理是一样的
// 但是官方解法多了对当前节点的左节点和右节点是否为空的判断
// 这个判断我认为加不加都行，因为就算两个子节点是NULL，镜像操作把两个NULL的指针换一下也没什么问题
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
    void Mirror(TreeNode *pRoot) {
        if(!pRoot) return;
        
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};


// 官方解法见参考书