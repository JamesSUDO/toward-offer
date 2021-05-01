
// 我的解法：先快排，再找前k个元素
class Solution1 {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if(k > input.size()) return {};
        
		quickSort(input, 0, input.size() - 1);

		vector<int> result;
		for (int i = 0; i < k; i++)
		{
			result.push_back(input[i]);
		}

		return result;
	}

	void quickSort(vector<int> &array, int left, int right)
	{
		if (left < right)
		{
			int i = left, j = right, pivot = array[left];
			while (i < j)
			{
				while (i < j && array[j] >= pivot) j--;
				if (i < j) array[i++] = array[j];

				while (i < j && array[i] <= pivot) i++;
				if (i < j) array[j--] = array[i];
			}
			array[i] = pivot;

			quickSort(array, left, i - 1);
			quickSort(array, i + 1, right);
		}
	}
};


// 官方解法1：用快排的partition代码思想
class Solution2 {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k > input.size())  return {};

		int num = 0, left = 0, right = input.size() - 1;
		while (num != k)
		{
			num = partition(input, left, right);
			if (num > k) right = num - 1;
			else if (num < k) left = num + 1;
		}

		vector<int> result;
		for (int i = 0; i < k; i++)
		{
			result.push_back(input[i]);
		}

		return result;
	}

	int partition(vector<int> &array, int left, int right)
	{
		int pivot = array[left];
		while (left < right)
		{
			while (left < right && array[right] >= pivot) right--;
			if (left < right) array[left++] = array[right];

			while (left < right && array[left] <= pivot) left++;
			if (left < right) array[right--] = array[left];
		}
		array[left] = pivot;

		return left;
	}
};


// 官方解法2：用红黑树按顺序存储四个数字
class Solution3 {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k > input.size()) return {};

		multiset<int, greater<int>> s;  // 默认为less升序，这里为方便用greater降序排列		
		for (int i = 0; i < k; i++)
		{
			s.insert(input[i]);
		}

		for (int i = k; i < input.size(); i++)
		{
			if (input[i] < *s.begin())
			{
				s.erase(s.begin());
				s.insert(input[i]);
			}
		}

		vector<int> result;
		for (multiset<int, greater<int>>::iterator iter = s.begin(); iter != s.end(); iter++)
		{
			result.push_back(*iter);
		}
		return result;
	}
};