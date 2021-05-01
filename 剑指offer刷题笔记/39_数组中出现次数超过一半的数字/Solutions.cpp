
// 我的解法：用关联容器记录每个数字出现的次数，以空间换取时间效率
class Solution1 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		unordered_map<int, int> m;

		for (int i = 0; i < numbers.size(); i++)
		{
			if (m.find(numbers[i]) == m.end())
			{
				m.insert(pair<int, int>(numbers[i], 1));
			}
			else
			{
				m[numbers[i]]++;
			}

			if (m[numbers[i]] * 2 > numbers.size()) return numbers[i];
		}

		return 0;
	}
};


// 官方解法1：快排思想
class Solution2 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        
		// 找到按顺序排列的中间元素值
		int middle = numbers.size() / 2;
		int left = 0, right = numbers.size() - 1;
		int position = 0;
		while (position != middle)
		{
			position = partition(numbers, left, right);

			if (position > middle)
				right = position - 1;
			else if (position < middle)
				left = position + 1;
		}

		// 对中间元素值个数计数
		int value = numbers[position];
		int count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == value) count++;
		}

		if (count * 2 > numbers.size()) return value;
		else return 0;
	}

	// 快排核心代码partition
	int partition(vector<int> &array, int left, int right)
	{
		int i = left, j = right, pivot = array[left];
		while (i < j)
		{
			while (i < j && array[j] >= pivot)
				j--;
			if (i < j)
				array[i++] = array[j];

			while (i < j && array[i] <= pivot)
				i++;
			if (i < j)
				array[j--] = array[i];
		}
		array[i] = pivot;

		return i;
	}
};


// 官方解法2：巧妙利用数组特点
class Solution3 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		if (numbers.empty()) return 0;

		int count = 1;
		int value = numbers[0];

		// 先找到疑似的
		for (int i = 1; i < numbers.size(); i++)
		{
			if (numbers[i] == value) count++;

			else
			{
				if (count != 0) count--;
				else
				{
					count = 1;
					value = numbers[i];
				}
			}
		}
		
		// 再遍历数组判断是否符合条件
		count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == value) count++;
		}

		if (count * 2 > numbers.size()) return value;
		else return 0;
	}
};