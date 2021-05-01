
// 我的解法
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode) {
		if (!pNode) return nullptr;
		if (pNode->right) {
			TreeLinkNode* cur = pNode->right;
			while (cur->left) {
				cur = cur->left;
			}
			return cur;
		}

		return getRightNext(pNode);
	}

	TreeLinkNode* getRightNext(TreeLinkNode* pNode) {
		TreeLinkNode* nextNode = pNode->next;
		if (!nextNode) return nullptr;
		if (nextNode->left == pNode) return nextNode;
		return getRightNext(nextNode);
	}
};


// 官方解法略，见参考书