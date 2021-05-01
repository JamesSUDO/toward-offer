
// 我的解法：构建哈希表
class Solution {
public:
	int FirstNotRepeatingChar(string str) 
	{
		unordered_map<char, int> m;

		for (int i = 0; i < str.size(); i++)
		{
			m[str[i]]++;
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (m[str[i]] == 1) return i;
		}

		return -1;
	}
};

// 官方解法同