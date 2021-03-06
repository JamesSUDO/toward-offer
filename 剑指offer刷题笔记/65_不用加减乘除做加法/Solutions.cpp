
// 官方解法
class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum;
		int carry;
		while (num2 != 0)
		{
			sum = num1 ^ num2;
			carry = (num1 & num2) << 1;

			num1 = sum;
			num2 = carry;
		}
		return num1;
	}
};