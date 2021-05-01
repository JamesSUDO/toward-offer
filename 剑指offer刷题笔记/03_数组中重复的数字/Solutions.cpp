
// 我的解法：利用辅助容器
class Solution {
public:
	int duplicate(vector<int>& numbers) {
		vector<int> array(numbers.size(), 0);
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] >= numbers.size() || numbers[i] < 0)
				return -1;

			if (array[numbers[i]] == 0)
				array[numbers[i]]++;
			else
				return numbers[i];
		}

		return -1;
	}
};


// 官方解法略