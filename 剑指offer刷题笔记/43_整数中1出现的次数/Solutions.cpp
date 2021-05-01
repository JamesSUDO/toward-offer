
// 我的解法：暴力法
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            count += countNum(i);
        }
        return count;
    }
 
    int countNum(int n)
    {
        int count = 0;
        while (n != 0)
        {
            if (n % 10 == 1) count++;
            n /= 10;
        }
        return count;
    }
};


// 官方解法：找数字规律
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n == 0) return 0;

		// 先找到位数和最高为的数字以及除去最高位的剩余数字
		int digitNum = 1;  // 位数
		int topNum = n;  // 最高位数字
		while (topNum >= 10)
		{
			topNum /= 10;
			digitNum++;
		}
		int otherNum = n - topNum * pow(10, digitNum - 1);  // 除去最高位的剩余数字


		// 1在最高位的情况
		int numFirstDigit;  // 最高位为1的个数
		if (topNum != 1)  // 先要判断当前边界值最高位是否为1
		{
			numFirstDigit = pow(10, digitNum - 1);
		}
		else
		{
			numFirstDigit = otherNum + 1;
		}

		// 1在其它位的情况
		int numOtherDigit = topNum * (digitNum - 1) * pow(10, digitNum - 2);

		return numFirstDigit + numOtherDigit + NumberOf1Between1AndN_Solution(otherNum);
	}
};