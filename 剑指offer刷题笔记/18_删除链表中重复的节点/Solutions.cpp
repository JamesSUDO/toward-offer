
// 我的解法1：单独拿出头节点重复的情况处理
class Solution1 {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		// 先处理头节点
		while (pHead && pHead->next && pHead->val == pHead->next->val) {
			int value = pHead->val;
			while (pHead && pHead->val == value) {
				ListNode* temp = pHead;
				pHead = pHead->next;
				delete temp;
			}
		}

		// 处理后面的节点
		ListNode* node = pHead;
		ListNode* lastNode = nullptr; // 可以任意初始化，因为在遇到需要删除的节点之前lastNode一定会被赋值
		while (node && node->next) {
			if (node->val != node->next->val) {
				lastNode = node;
				node = node->next;
			}
			else {
				int value = node->val;
				while (node && node->val == value) {
					ListNode* temp = node;
					node = node->next;
					delete temp;
				}
				lastNode->next = node;
			}
		}
		return pHead;
	}
};


// 我的解法2：手动添加一个头节点再处理
class Solution2 {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr) return pHead;

		ListNode* tempHead = new ListNode(0);
		tempHead->next = pHead;

		ListNode* node = pHead;
		ListNode* lastNode = tempHead;
		while (node && node->next) {
			if (node->val == node->next->val) {
				int value = node->val;
				while (node && node->val == value) {
					ListNode* temp = node;
					node = node->next;
					delete temp;
				}
				lastNode->next = node;
			}
			else {
				lastNode = node;
				node = node->next;
			}
		}
		pHead = tempHead->next;
		delete tempHead;

		return pHead;
	}
};


// 递归解法
class Solution3 {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead || !pHead->next) return pHead;

		if (pHead->val == pHead->next->val) {
			ListNode* node = pHead->next;
			while (node && node->val == pHead->val) {
				ListNode* temp = node;
				node = node->next;
				delete temp;
			}
			return deleteDuplication(node);
		}
		else {
			pHead->next = deleteDuplication(pHead->next);
			return pHead;
		}
	}
};


// 官方解法略，详见参考书