
// 我的解法：用vector
class Solution1 {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0) return -1;

		vector<int> vec;
		for (int i = 0; i < n; i++)
			vec.push_back(i);

		int nowPtr = 0;
		for (int i = 0; i < n - 1; i++)
		{
			nowPtr = (nowPtr + m - 1) % (n - i);
			vec.erase(vec.begin() + nowPtr);
		}
		return vec[0];
	}
};


// 官方解法1：用链表
class Solution2 {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0) return -1;

		ListNode* head = CreateRoundListNode(n);
		ListNode* cur = head;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m - 2; j++)
			{
				cur = cur->next;
			}

			ListNode* temp = cur->next;
			cur->next = temp->next;
			cout << temp->val << endl;
			delete temp;
			cur = cur->next;
		}

		return cur->val;
	}

private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {
		}
	};

	ListNode* CreateRoundListNode(int n)
	{
		if (n == 0) return NULL;

		ListNode* head = new ListNode(0);
		ListNode* cur = head;
		for (int i = 1; i < n; i++)
		{
			ListNode* p = new ListNode(i);
			cur->next = p;
			cur = cur->next;
		}
		cur->next = head;

		return head;
	}
};


// 官方解法2：找数学关系
class Solution3 {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0) return -1;

		int result = 0;
		for (int i = 2; i <= n; i++)
		{
			result = (result + m) % i;
		}
		return result;
	}
};