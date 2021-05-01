
// 我的解法：先用二分查找找到k的位置，再向两边遍历统计次数
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int position = binarySearch(data, k, 0, data.size() - 1);

		int count = 0;
		for (int i = position; i < data.size(); i++)
		{
			if (data[i] != k) break;
			count++;
		}
		for (int i = position - 1; i >= 0; i--)
		{
			if (data[i] != k) break;
			count++;
		}
		return count;
	}


	int binarySearch(vector<int> array, int k, int left, int right)
	{
		if (left >= right) return left;

		int mid = (left + right) / 2;
		if (k == array[mid]) return mid;

		if (k > array[mid])
		{
			return binarySearch(array, k, mid + 1, right);
		}

		if (k < array[mid])
		{
			return binarySearch(array, k, left, mid - 1);
		}
	}
};


// 官方解法：利用两次二分查找找到第一个k和最后一个k
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int firstK = getFirstK(data, k, 0, data.size() - 1);
		cout << firstK << endl;

		if (firstK == -1) return 0;

		int lastK = getLastK(data, k, 0, data.size() - 1);
		cout << lastK << endl;
		return lastK - firstK + 1;
	}

	int getFirstK(vector<int> array, int k, int left, int right)
	{
		if (left > right) return -1;

		int mid = (left + right) / 2;
		if (array[mid] == k)
		{
			if (mid == 0 || array[mid - 1] != k)
				return mid;
			else
				return getFirstK(array, k, left, mid - 1);
		}

		if (array[mid] > k)
			return getFirstK(array, k, left, mid - 1);

		if (array[mid] < k)
			return getFirstK(array, k, mid + 1, right);
	}

	int getLastK(vector<int> array, int k, int left, int right)
	{
		if (left > right) return -1;

		int mid = (left + right) / 2;
		if (array[mid] == k)
		{
			if (mid == array.size() - 1 || array[mid + 1] != k)
				return mid;
			else
				return getLastK(array, k, mid + 1, right);
		}

		if (array[mid] > k)
			return getLastK(array, k, left, mid - 1);

		if (array[mid] < k)
			return getLastK(array, k, mid + 1, right);
	}
};