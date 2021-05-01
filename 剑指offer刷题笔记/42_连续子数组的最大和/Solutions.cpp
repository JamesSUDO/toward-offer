
// 我的解法：动态规划（贪心算法）
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty()) return 0;

		int curMax = array[0];
		int allMax = curMax;
		for (int i = 1; i < array.size(); i++)
		{
			curMax = getMax(array[i], curMax + array[i]);
			allMax = getMax(allMax, curMax);
		}

		return allMax;
	}

	int getMax(int a, int b)
	{
		if (a > b) return a;
		else return b;
	}
};


// 官方解法也是动态规划，代码略。