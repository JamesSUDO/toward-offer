// 我的解法1：构建辅助容器
class Solution {
public:
    string LeftRotateString(string str, int n) {
        string result;
        for (int i = n; i < str.size(); i++)
        {
            result.push_back(str[i]);
        }
        for (int i = 0; i < n; i++)
        {
            result.push_back(str[i]);
        }
        return result;
    }
};


// 我的解法2：两次翻转字符串
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (n > str.size()) return "";
		reverseStr(str, 0, n - 1);
		reverseStr(str, n, str.size() - 1);
		reverseStr(str, 0, str.size() - 1);
		return str;
	}

	void reverseStr(string &str, int left, int right)
	{
		while (left < right)
			swap(str[left++], str[right--]);
	}
};
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