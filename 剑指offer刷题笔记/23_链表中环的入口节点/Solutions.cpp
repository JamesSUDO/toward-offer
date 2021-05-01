
// 我的解法
class Solution1 {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL) return pHead;
		ListNode* fast = pHead;
		ListNode* slow = fast;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				int count = 1;
				slow = slow->next;
				while (slow != fast) {
					slow = slow->next;
					count++;
				}

				fast = pHead;
				slow = fast;
				while (count--) fast = fast->next;
				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
		return NULL;
	}
};


// 牛客上的一个解法
class Solution2 {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* fast = pHead;
		ListNode* slow = fast;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				slow = pHead;
				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
		return NULL;
	}
};


// 官方解法略，见参考书