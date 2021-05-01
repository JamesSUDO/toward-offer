
// 我的解法：暴力法运行超时
class Solution1 {
public:
	int InversePairs(vector<int> data) {
		int count = 0;
		for (int i = 0; i < data.size() - 1; i++)
		{
			for (int j = i + 1; j < data.size(); j++)
			{
				if (data[i] > data[j]) count++;
			}
		}
		return count % 1000000007;
	}
};

// 官方解法：使用归并排序思想
class Solution2 {
public:
	int InversePairs(vector<int> data) {
		vector<int> tmp;
		tmp.reserve(data.size());
		return mergeSort(data, tmp, 0, data.size() - 1) % 1000000007;
	}

	long mergeSort(vector<int> &array, vector<int> &tmp, int left, int right)
	{
		if (left >= right) return 0;

		int mid = (left + right) / 2;
		long leftCount = mergeSort(array, tmp, left, mid);
		long rightCount = mergeSort(array, tmp, mid + 1, right);

		long count = merge(array, tmp, left, mid, right);

		return leftCount + rightCount + count;
	}

	long merge(vector<int> &array, vector<int> &tmp, int left, int mid, int right)
	{
		long count = 0;
		int i = left, j = mid + 1, k = left;
		while (i <= mid && j <= right)
		{
			if (array[i] > array[j])
			{
				count += mid - i + 1;
				tmp[k++] = array[j++];
			}
			else
				tmp[k++] = array[i++];
		}

		while (i <= mid)
			tmp[k++] = array[i++];
		while (j <= right)
			tmp[k++] = array[j++];

		for (i = left; i <= right; i++)
			array[i] = tmp[i];

		return count;
	}
};