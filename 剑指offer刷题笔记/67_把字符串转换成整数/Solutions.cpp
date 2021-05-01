
// 我的解法
class Solution {
public:
	int StrToInt(string str) {
		int i = 0;
		bool isPos = true;
		int sum = 0;

		while (i < str.size() && str[i] == ' ') i++;

		if (i < str.size())
		{
			if (str[i] == '+') i++;
			else if (str[i] == '-') { i++; isPos = false; }
		}

		for (; i < str.size(); i++)
		{
			if (str[i] > '9' || str[i] < '0') return 0;

			int temp = (int)(str[i] - '0');
			if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && temp > 7))
            {
                if (!isPos && temp == 8) return INT_MIN;
                else return 0;
            }

			sum = sum * 10 + temp;
		}
		return isPos ? sum : (sum * -1);
	}
};


// 官方解法略，见参考书