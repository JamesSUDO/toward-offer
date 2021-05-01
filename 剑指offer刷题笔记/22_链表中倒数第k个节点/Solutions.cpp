
// 我的解法：利用快慢指针即可
// 方法不难，但是我一开始提交的报错了，因为没考虑到特殊情况
// 当k大于链表元素个数，在快指针的循环中，会出现操作空指针的错误
// 因此在每一次的循环都加了是否为空指针的判断
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //if (pListHead == NULL) return NULL; // 可加可不加，因为后面循环有判断fast是否为NULL
        
        ListNode* fast = pListHead, *slow = fast;
        for (int i = 0; i < k; i++)
        {
            if(fast == NULL) return NULL;
            fast = fast->next;
        }
        
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};


// 官方解法：和我的解法一样
// 此题的核心是要注意代码的鲁棒性，把所有异常情况都考虑进去