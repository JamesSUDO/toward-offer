
// 我的解法：几次方就做几次乘法运算
// 时间复杂度：o(n)
// 此解法中规中矩，官方题解更巧妙
class Solution1 {
public:
    double Power(double base, int exponent) {
        if(base == 0) return 0;
        double a = 1;
        for(int i = 0; i < abs(exponent); i++)
        {
            a = a * base;
        }
         
        if(exponent < 0)
        {
            a = 1 / a;
        }
        return a;
    }
};


// 官方解法
// 每次循环不乘以base，而是乘以当前得到的result值
// 比如求5次方，相当于两个2次方相乘，再乘以base，很容易用递归实现
// 时间复杂度：o(logn)，比较巧妙
class Solution2 {
public:
    double Power(double base, int exponent) {
        if(base == 0) return 0;
        if(exponent == 0) return 1;
        
        if(exponent > 0)
            return helper(base, abs(exponent));
        else
            return 1 / helper(base, abs(exponent));
    }
    
    double helper(double base, int exponent)
    {
        if(exponent == 1) return base;
        
        double result =  helper(base, exponent >> 1);
        result *= result;
        if(exponent & 0x1 == 0x1) result *= base;
        
        return result;
    }
};