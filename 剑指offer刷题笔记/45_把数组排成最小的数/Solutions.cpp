
// 我的解法1：暴力法
class Solution1 {
public:
	// 计算位数
	int countNum(int value)
	{
		int count = 1;
		while (value > 9)
		{
			value /= 10;
			count++;
		}
		return count;
	}

	string PrintMinNumber(vector<int> numbers) {
        if (numbers.size() == 0) return "";
        
		vector<vector<int> > vec2d;
		unordered_set<int> s;
		vector<int> vec;
		getAllOrders(numbers, vec2d, vec, s);

		double sum_min = 0;
		for (int j = 0; j < vec2d[0].size(); j++)
		{
			sum_min = sum_min * pow(10, countNum(vec2d[0][j])) + vec2d[0][j];
		}

		for (int i = 0; i < vec2d.size(); i++)
		{
			double curSum = 0;
			for (int j = 0; j < vec2d[i].size(); j++)
			{				
				curSum = curSum * pow(10, countNum(vec2d[i][j])) + vec2d[i][j];
			}

			if (curSum < sum_min) sum_min = curSum;
		}

		string str = to_string(sum_min);
		string str_out;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '.') break;
			str_out.push_back(str[i]);

		}
		return str_out;
	}

	// 得到所有的排列，结果存在二维数组中
	void getAllOrders(const vector<int> &numbers, vector<vector<int> > &vec2d, vector<int> &vec, unordered_set<int> s)
	{
		if (vec.size() == numbers.size())
		{
			vec2d.push_back(vec);
			return;
		}

		for (int i = 0; i < numbers.size(); i++)
		{
			unordered_set<int> sCur = s;
			vector<int> vecCur = vec;

			if (sCur.find(i) == sCur.end())
			{
				vecCur.push_back(numbers[i]);
				sCur.insert(i);
				getAllOrders(numbers, vec2d, vecCur, sCur);
			}
		}
	}
};


// 我的解法2：自定比较规则+排序
class Solution2 {
public:
	string PrintMinNumber(vector<int> numbers) 
	{
		string s;
		vector<string> vStr = vecIntToStr(numbers);
		quickSort(vStr, 0, vStr.size() - 1);

		for (int i = 0; i < vStr.size(); i++)
		{
			s += vStr[i];
		}

		return s;
	}

	// int转string
	vector<string> vecIntToStr(vector<int> numbers)
	{
		vector<string> vStr;
		for (int i = 0; i < numbers.size(); i++)
		{
			vStr.push_back(to_string(numbers[i]));
		}
		return vStr;
	}

	// 自定义比较逻辑
	bool isBiggerOrEqual(string a, string b)
	{
		int i = 0, j = 0;
		int aSize = a.size(), bSize = b.size();
		int sizeMax = aSize + bSize;

		for(int i = 0; i < sizeMax; i++)
		{
			// 判断
			if (a[i % aSize] > b[i % bSize]) return true;
			if (a[i % aSize] < b[i % bSize]) return false;
		}

		return true;
	}

	// 快排
	void quickSort(vector<string> &vStr, int left, int right)
	{
		if (left >= right) return;
		
		int i = left, j = right;
		string pivot = vStr[left];
		while (i < j)
		{
			while (i < j && isBiggerOrEqual(vStr[j], pivot))
				j--;
			if (i < j)
				vStr[i++] = vStr[j];

			while (i < j && isBiggerOrEqual(pivot, vStr[i]))
				i++;
			if (i < j)
				vStr[j--] = vStr[i];
		}
		vStr[i] = pivot;

		quickSort(vStr, left, i - 1);
		quickSort(vStr, i + 1, right);
	}
};