// 我的解法：利用栈的性质
class Solution1 {
public:
	string ReverseSentence(string str) {
		stack<string> stk;
		string strResult;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ')
			{
				string strTemp;
				while (i < str.size() && str[i] != ' ')
					strTemp.push_back(str[i++]);

				stk.push(strTemp);
			}
		}

		if (stk.empty()) return str;

		while (stk.size() != 1)
		{
			strResult += stk.top();
			stk.pop();
			strResult += " ";
		}
		strResult += stk.top();
		stk.pop();

		return strResult;
	}
};


// 官方解法：两次翻转字符串
class Solution2 {
public:
	void reverseStr(string &str, int left, int right)
	{
		while (left < right)
			swap(str[left++], str[right--]);
	}

	string ReverseSentence(string str) {
		string strResult = str;
		reverseStr(strResult, 0, strResult.size() - 1);
		for (int left = 0; left < strResult.size(); left++)
		{
			if (strResult[left] != ' ')
			{
				int right = left + 1;
				while (right < strResult.size() && strResult[right] != ' ')
					right++;
				reverseStr(strResult, left, right - 1);
				left = right;
			}
		}
		return strResult;
	}
};