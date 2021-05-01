
// 我的解法
class Solution {
public:
	string replaceSpace(string s) {
		string res;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
				res.push_back(s[i]);
			else
				res += "%20";
		}

		return res;
	}
};

// 官方解法略
