
// 我的解法：用set来辅助判断是否有重复
class Solution1 {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty()) return false;

		set<int> s;
		int maxNum = 0, minNum = 13;
		for (int i = 0; i < numbers.size(); i++)
		{
			int curNum = numbers[i];  // 当前牌

			if (curNum != 0)  // 如果不是joker牌
			{
				// 更新最大值和最小值
				if (curNum > maxNum) maxNum = curNum;
				if (curNum < minNum) minNum = curNum;

				// 如果有重复的，直接返回false
				if (s.find(curNum) == s.end())
					s.insert(curNum);
				else
					return false;
			}
		}

		if (maxNum == 0)  // 全是joker是特殊情况，因为这种情况记录的max和min是0和13，并不是牌实际值
			return true;

		if (maxNum - minNum + 1 > numbers.size())  // 判断形成最小值到最大值的顺子牌的数量和总牌数的关系
			return false;
		else 
			return true;
	}
};


// 官方解法：先对数组排序，再依次访问相邻值
class Solution2 {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty()) return false;

		sort(numbers.begin(), numbers.end());

		int cur = 0;
		while (numbers[cur] == 0)
		{
			cur++;
		}

		int numOfZero = cur;
		for (; cur < numbers.size() - 1; cur++)
		{
			int diff = numbers[cur + 1] - numbers[cur];
			if (diff == 0) return false;

			numOfZero -= (diff - 1);
			if (numOfZero < 0) return false;
		}

		return true;
	}
};