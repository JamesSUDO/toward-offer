
// 我的解法：双指针
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> vec;

		int i = 0, j = array.size() - 1;
		while (i < j)
		{
			if (array[i] + array[j] == sum)
			{
				vec.push_back(array[i]);
				vec.push_back(array[j]);
				break;
			}
			else if (array[i] + array[j] < sum)
				i++;
			else
				j--;
		}

		return vec;
	}
};


// 官方解法同