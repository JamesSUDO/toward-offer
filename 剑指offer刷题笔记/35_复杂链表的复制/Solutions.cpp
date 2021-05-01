
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

// 两层遍历
// 方法比较暴力，不推荐
class Solution1 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) return NULL;
		
        RandomListNode* src = pHead;
 
        RandomListNode* dst_head = new RandomListNode(src->label);
        RandomListNode* dst = dst_head;
 
        src = src->next;
        while (src != NULL)
        {
            RandomListNode* temp = new RandomListNode(src->label);
            dst->next = temp;
             
            dst = dst->next;
            src = src->next;
        }
 
        src = pHead;
        dst = dst_head;
        while (src != NULL && dst != NULL)
        {
            RandomListNode* srcRamdom = pHead, *dstRandom = dst_head;
            while (srcRamdom != NULL && dstRandom != NULL)
            {
                if (src->random == srcRamdom)
                {
                    dst->random = dstRandom;
                    break;
                }
                else
                {
                    srcRamdom = srcRamdom->next;
                    dstRandom = dstRandom->next;
                }
            }
             
            src = src->next;
            dst = dst->next;
        }
         
        return dst_head;
    }
};


// 用map容器，空间消耗换取时间效率
// 时间复杂度o(n)，但是空间有额外开销
class Solution2 {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL) return NULL;

		unordered_map<RandomListNode*, RandomListNode*> m;

		RandomListNode* dst_head = new RandomListNode(pHead->label);
		RandomListNode* src = pHead;
		RandomListNode* dst = dst_head;
		m.insert(pair<RandomListNode*, RandomListNode*>(src, dst));

		src = src->next;
		while (src != NULL)
		{
			RandomListNode* temp = new RandomListNode(src->label);
			dst->next = temp;

			dst = dst->next;
			m.insert(pair<RandomListNode*, RandomListNode*>(src, dst));

			src = src->next;
		}

		src = pHead;
		dst = dst_head;
		while (src != NULL && dst != NULL)
		{
			dst->random = m[src->random];

			src = src->next;
			dst = dst->next;
		}

		return dst_head;
	}
};


// 比较巧妙的一种方法
// 时间复杂度o(n)，且没有额外内存开销
class Solution3 {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL) return NULL;

		// 复制链表并插入到原链表中 A->A'->B->B'->C->C'->D->D'->......
		RandomListNode* p = pHead;
		while (p != NULL)
		{
			RandomListNode* p_new = new RandomListNode(p->label);

			RandomListNode* temp = p->next;
			p->next = p_new;
			p_new->next = temp;
			p = temp;
		}

		// 对新链表节点的random赋值
		p = pHead;
		while (p != NULL)
		{
            if(p->random != NULL)
            {
			    RandomListNode* p_new = p->next;
			    p_new->random = p->random->next;
            }

			p = p->next->next;
		}

		// 拆分链表
		RandomListNode* pNewHead = pHead->next;
		RandomListNode* p_new = pNewHead;
		p = pHead;
		
		while (p_new->next != NULL)  // p->next->next != NULL
		{
			RandomListNode* temp = p_new->next;
			RandomListNode* temp_new = temp->next;

			p->next = temp;
			p_new->next = temp_new;

			p = temp;
			p_new = temp_new;
		}

		p->next = NULL;

		return pNewHead;
	}
};