
// 我的解法：构建辅助容器set，利用键不重复找到相同节点
class Solution1 {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		set<ListNode*> s;
		while (pHead1 != NULL)
		{
			s.insert(pHead1);
			pHead1 = pHead1->next;
		}

		while (pHead2 != NULL && s.find(pHead2) == s.end())
		{
			pHead2 = pHead2->next;
		}

		return pHead2;
	}
};


// 官方解法1：利用stack先进先出特性倒序遍历两链表
class Solution1 {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		stack<ListNode*> s1, s2;
		while (pHead1 != NULL)
		{
			s1.push(pHead1);
			pHead1 = pHead1->next;
		}
		while (pHead2 != NULL)
		{
			s2.push(pHead2);
			pHead2 = pHead2->next;
		}

		ListNode* result = NULL;
		while (!s1.empty() && !s2.empty() && s1.top() == s2.top())
		{
			result = s1.top();
			s1.pop();
			s2.pop();
		}
		return result;
	}
};


// 官方解法2：先得到两链表长度，再正序遍历找到相同节点
class Solution2 {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int count1 = 0, count2 = 0;
		ListNode* temp1 = pHead1, *temp2 = pHead2;
		while (temp1 != NULL)
		{
			count1++;
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			count2++;
			temp2 = temp2->next;
		}

		for (int i = 0; i < count1 - count2; i++)
		{
			pHead1 = pHead1->next;
		}

		for (int i = 0; i < count2 - count1; i++)
		{
			pHead2 = pHead2->next;
		}

		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1 == pHead2) return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return NULL;
	}
};
