
// 我的解法：以连续整数的个数为条件遍历，用求和通项公式确定符合的情况
class Solution1 {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > vec2d;
		int nMax = pow(sum * 2, 0.5);
		for (int n = nMax; n >= 2; n--)
		{
			if (isOdd(n))
			{
				if (sum % n == 0)
				{
					vector<int> vec;
					int firstNum = sum / n - n / 2;
					for (int i = 0; i < n; i++)
					{
						vec.push_back(firstNum + i);
					}
					vec2d.push_back(vec);
				}
			}
			else
			{
				if (sum % n != 0 && (sum * 2) % n == 0)
				{
					vector<int> vec;
					int firstNum = sum / n + 1 - n / 2;
					for (int i = 0; i < n; i++)
					{
						vec.push_back(firstNum + i);
					}
					vec2d.push_back(vec);
				}
			}
		}
		return vec2d;
	}

	bool isOdd(int n)  // 是否为奇数
	{
		if ((n & 0x1) == 1) return true;
		else return false;
	}
};


// 官方解法：双指针
class Solution2 {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > vec2d;

		int small = 1, big = 2;
		int middle = (1 + sum) / 2;
		int curSum = small + big;
		while (small <= middle)
		{
			if (curSum == sum)
			{
				vector<int> vec;
				for (int i = small; i <= big; i++)
				{
					vec.push_back(i);
				}
				vec2d.push_back(vec);

				big++;
				small++;
				curSum = curSum + big - (small - 1);
			}

			else if (curSum < sum)
			{
				big++;
				curSum += big;
			}
			else
			{
				curSum -= small;
				small++;
			}
		}
		return vec2d;
	}
};