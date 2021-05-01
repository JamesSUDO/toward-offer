
// 我的解法
// 感觉是最简便的一种形式了
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
    ListNode* ReverseList(ListNode* pHead) {
        //if(pHead == NULL || pHead->next == NULL) return pHead;
        if(pHead == NULL) return pHead;
        ListNode* newHead = NULL;
        while(pHead != NULL)
        {
            ListNode* p = pHead->next;
            pHead->next = newHead;
            newHead = pHead;
            pHead = p;
        }
        
        return newHead;
    }
};


// 官方解法：见参考书
// 此题的立意是要想好所有的情况，保证代码可以全部执行通过
// 针对此题的情况，包括有空链表，只有一个节点的链表，和多节点的链表