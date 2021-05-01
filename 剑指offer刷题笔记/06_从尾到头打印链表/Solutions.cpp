
// 我的解法：先执行链表反转，再输出
// 方法不太合适，因为并不知道是否允许改动链表结构
/*
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution1 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        //if(head == NULL) return {};
        
        ListNode* newHead = NULL;
        vector<int> m;
        
        while (head)
        {
            ListNode* p = head->next;
            head->next = newHead;
            newHead = head;
            head = p;
        }
        
        while (newHead)
        {
            m.push_back(newHead->val);
            newHead = newHead->next;
        }      
        
        return m;
    }
};


// 官方解法1：用栈来保存遍历链表得到的值，再弹出即可
// 利用栈的先进后出特性
// 书上解法给的是把链表的结点指针存到栈中，我这里是把链表值存到栈中，我认为两者都可以
class Solution2 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        vector<int> m;
        
        while(head)
        {
            s.push(head->val);
            head = head->next;
        }
        
        while(!s.empty())
        {
            m.push_back(s.top());
            s.pop();
        }
        
        return m;
    }
};


// 官方解法2：用递归实现
// 因为递归的在本质上就是一个栈结构，所以考虑用递归
// 如无必要，最好不要用递归，因为递归会导致函数的层级很深，从而可能导致函数调用栈溢出
class Solution3 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head == NULL) return {};
        vector<int> m;
        helper(m, head);
        return m;
    }
    
    void helper(vector<int>& m, ListNode* cur)
    {
        if(cur -> next != NULL) helper(m, cur->next);
        m.push_back(cur->val);
    }
};