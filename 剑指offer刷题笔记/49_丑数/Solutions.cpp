
// 我的解法：暴力法，超出时间限制
class Solution1 {
public:
	int GetUglyNumber_Solution(int index) {
		int count = 1;
		int number = 1;

		while (count < index)
		{
			number++;

			if (isUglyNumber(number)) count++;
		}

		return number;
	}

	bool isUglyNumber(int a)
	{
		// %2
		while (a % 2 == 0) a /= 2;

		// %3
		while (a % 3 == 0) a /= 3;

		// %5
		while (a % 5 == 0) a /= 5;

		if (a == 1) return true;
		else return false;
	}
};

// 官方解法2：用空间换取时间的提升
class Solution2 {
public:
	int GetUglyNumber_Solution(int index) 
	{
        if(index <= 0) return 0;
		int p2 = 0, p3 = 0, p5 = 0;
		vector<int> array;
		array.push_back(1);
		int count = 1;

		while (count < index)
		{
			int min = findMin(array[p2] * 2, array[p3] * 3, array[p5] * 5);

			if (array[p2] * 2 == min) p2++;
			if (array[p3] * 3 == min) p3++;
			if (array[p5] * 5 == min) p5++;

			array.push_back(min);
			count++;
		}
		return array.back();
	}

	int findMin(int a, int b, int c)
	{
		return min(min(a, b), c);
	}
};