
// 我的解法：构建辅助容器set
class Solution1 {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		set<int> s;
		for (int i = 0; i < data.size(); i++)
		{
			set<int>::iterator iter = s.find(data[i]);
			if (iter == s.end())
				s.insert(data[i]);
			else
				s.erase(iter);
		}

		*num1 = *(s.begin());
		*num2 = *(++s.begin());
	}
};


// 官方解法：异或
class Solution2 {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int result = 0x0;
		for (int i = 0; i < data.size(); i++)
		{
			result ^= data[i];
		}

		int firstBit1 = findFirstBit1(result);

		*num1 = 0x0, *num2 = 0x0;
		for (int i = 0; i < data.size(); i++)
		{
			if (isBit1(data[i], firstBit1)) 
				*num1 ^= data[i];
			else 
				*num2 ^= data[i];
		}
	}
	
	// 找到对应二进制数从右往左第一位是1的位
	int findFirstBit1(int num)
	{
		int count = 0;
		while (((num & 0x1) == 0) && num != 0)
		{
			num = num >> 1;
			count++;
		}
		return count;
	}

	// 检查对应二进制数从右往左第k位是否为1
	bool isBit1(int num, int k)
	{
		num = num >> k;
		return (num & 0x1);
	}
};