
// 我的解法1
// 使用递归，每一次递归都用循环来遍历当前str的所有元素
// 新建curStr保存每次递归遍历str的元素，push的同时操作str，把此元素从str中erase
// 然后进入下一次递归，当str为空时，把curStr push到vector中
// 注意一点就是循环的时候，要申请一个临时的str和curStr而不能在原字符串操作
// 否则在下一次循环中，所用的str和curStr都是被上一次循环改动过的
// 最后对此vector用双层循环遍历，去掉一样的元素
class Solution1 {
public:
	vector<string> Permutation(string str) {
        if(str.empty()) return {};
        
		vector<string> vStr;
		string curStr;

		helper(vStr, curStr, str);
        
        for(int i = 0; i < vStr.size() - 1; i++)
        {
            for(int j = i + 1; j < vStr.size(); j++)
            {
                if(vStr[i] == vStr[j])
                {
                    vStr.erase(vStr.begin() + j);
                    j--;
                }
            }
        }

		return vStr;
	}

	void helper(vector<string> &vStr, string curStr, string &str)
	{
		if (str.empty())
		{
			vStr.push_back(curStr);
			return;
		}

		for (int i = 0; i < str.size(); i++)
		{
			string strTemp = str;
			string::iterator iter = strTemp.begin();

			string curStrTemp = curStr;

			curStrTemp.push_back(str[i]);

			strTemp.erase(iter + i);
			helper(vStr, curStrTemp, strTemp);
		}
	}
};


// 我的解法2
// 在解法1的基础上改进了一下，同样是递归遍历str，把元素push到curStr中
// 不同之处在于每次push了str的元素后，不对str执行erase，而是用了set
// 以当前被push的str中的元素位置为键值存到set中
// 每次在循环的时候，先判断set中有无当前元素序号，没有的话才执行push，并把此序号键值存到map
class Solution2 {
public:
	vector<string> Permutation(string str) 
	{
		if (str.empty()) return {};

		set<int> s;
		string curStr;
		vector<string> vecStr;

		helper(vecStr, curStr, s, str);

		for (int i = 0; i < vecStr.size() - 1; i++)
		{
			for (int j = i + 1; j < vecStr.size(); j++)
			{
				if (vecStr[i] == vecStr[j])
				{
					vecStr.erase(vecStr.begin() + j);
					j--;
				}
			}
		}

		return vecStr;
	}

	void helper(vector<string> &vecStr, string curStr, set<int> s, const string str)
	{
		if (s.size() == str.size())
		{
			vecStr.push_back(curStr);
		}

		for (int i = 0; i < str.size(); i++)
		{
			// 每一次循环都要把curStr和s重置
			// 因此每次都用一个临时变量拷贝，而不直接在原变量上操作
			set<int> tempSet = s;
			string tempCurStr = curStr;

			if (tempSet.find(i) == tempSet.end())
			{
				tempSet.insert(i);
				tempCurStr.push_back(str[i]);

				helper(vecStr, tempCurStr, tempSet, str);
			}
		}
	}
};


// 官方解法3：递归+交换string中元素
// 不新建辅助字符串来存取元素，直接在原str上操作
// 第一次递归，交换第0个元素和循环的第i个(i从0到str.size())
// 第n次递归，交换第n个元素和循环的第i个(i从n到str.size())
// 当n等于str.size()时，把当前str push到vector中
// 此解法不能通过牛客所有范例，牛客有要求是让所有的字符串按字典序列顺序排列，此解法不能保证
class Solution3 {
public:
	vector<string> Permutation(string str) 
	{
		if (str.empty()) return {};

		string curStr;
		vector<string> vecStr;

		helper(vecStr, str, 0);

		return vecStr;
	}

	void helper(vector<string> &vecStr, string str, int curNum)
	{
		if (curNum == str.size())
		{
			vecStr.push_back(str);
		}

		for (int i = curNum; i < str.size(); i++)
		{
			string curStr = str;
			if (i == curNum || curStr[i] != curStr[curNum])
			{
				// exchange
				char temp = curStr[i];
				curStr[i] = curStr[curNum];
				curStr[curNum] = temp;

				helper(vecStr, curStr, curNum + 1);
			}
		}
	}
};