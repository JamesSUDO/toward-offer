
// 我的解法：直接一个循环搞定
class Solution {
public:
    int Fibonacci(int n) {
        int val_1 = 0, val_2 = 1;
        if(n == 0) return 0;
        
        for(int i = 1; i < n; i++)
        {
            int temp = val_2;
            val_2 = val_1 + val_2;
            val_1 = temp;
        }
        return val_2;
    }
};

// 官方解法同我的解法
// 有几点要说明：
// 此题考察点在于是否会用递归来实现，如果用递归，效率会很低，这算是一个陷阱吧
// 除了书上的比较冷门的那个时间复杂度o(logn)算法外，还有一个直接套通项公式的算法，时间复杂度o(1)
// 关于详细的说明，可以参考我的博客这篇文章，解决的是上台阶问题，实际就是斐波那契。
// https://blog.csdn.net/IcdKnight/article/details/104902902