
// 我的解法1
// 遍历链表，把每一个都存到数组中，再调用sort函数排序，最后把新值存到链表中
// 方法有点取巧，不建议
class Solution1 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1
            ;
        vector<int> vec;
        ListNode* cur = pHead1;
        while(cur->next != NULL)
        {
            vec.push_back(cur->val);
            cur = cur->next;
        }
         
        cur->next = pHead2;
        while(cur != NULL)
        {
            vec.push_back(cur->val);
            cur = cur->next;
        }
         
        sort(vec.begin(), vec.end());
         
        cur = pHead1;
        for(int i = 0; i < vec.size(); i++)
        {
            cur->val = vec[i];
            cur = cur->next;
        }
         
        return pHead1;
    }
};


// 我的解法2：循环法+新建一个头节点
// 注意要把所有特殊情况都考虑进去
class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL) return pHead2;
	    if (pHead2 == NULL) return pHead1;

	    // 这里把cur2插到cur1中
	    ListNode* tempHead1 = new ListNode(LONG_MIN);  // 在链表1的头部前面插入新的头部，最后删掉
	    tempHead1->next = pHead1;
	    ListNode* cur1 = tempHead1;
	    ListNode* cur2 = pHead2;

	    while (cur1 != NULL && cur2 != NULL)
	    {
		    if (cur1->next == NULL || cur2->val < cur1->next->val)
		    {
			    ListNode* temp1 = cur1->next;
			    cur1->next = cur2;

			    while (cur2->next != NULL && (temp1 == NULL || cur2->next->val < temp1->val))
			    {
				    cur2 = cur2->next;
			    }

			    ListNode* temp2 = cur2->next;
			    cur2->next = temp1;

			    cur1 = temp1;
			    cur2 = temp2;
		    }

		    else
		    {
			    cur1 = cur1->next;
		    }
	    }

	    pHead1 = tempHead1->next;
	    delete tempHead1;
	    return pHead1;
    }
};


// 官方解法：递归
// 比较两个链表的当前头节点，把较小的拿出来当作合成链表的节点，再继续用拿掉头节点的新链表继续递归
// 要考虑到其中一个链表变为空的情况，此时返回另一个链表
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        
        ListNode* cur = NULL;
        
        if(pHead1->val > pHead2->val)
        {
            cur = pHead2;
            cur->next = Merge(pHead1, pHead2->next);
        }
        else
        {
            cur = pHead1;
            cur->next = Merge(pHead1->next, pHead2);
        }
        
        return cur;
    }
};