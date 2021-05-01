
// 我的解法：负数转成符号位置0的补码，然后逐位对2求余
// 要注意的一点：负数的补码形式，符号本应是1，但这里被置为0了，所以要把这个1加回来
// 还要注意：除法运算效率比移位要低得多，所以不建议这个解法
class Solution {
public:
     int  NumberOf1(int n) {
         int num = 0;
         if(n < 0)
         {
             n = INT_MAX + n + 1;
             num = 1;
         }
         while(n != 0)
         {
             if( n % 2 != 0) num ++;
             n =n / 2;
         }
         return num;
     }
};


// 官方解法1：用32位中只带1位1的标志位做与运算
class Solution2 {
public:
     int  NumberOf1(int n) {
         unsigned int flag = 1;  // 也可以定义int型
         int count = 0;
         while(flag)
         {
             if(n & flag) count++;
             flag = flag << 1;
         }
         return count;
     }
};


// 官方解法2
// 这个解法很巧妙，让当前的数和当前数减1作与运算，得到的结果恰好是把当前数的最后一个1变成0
// 循环此操作，每次都会把最后一个1置0，最后计算置了几次，就是存在多少个1
class Solution3 {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n)
         {
             count++;
             n = n & (n -1);
         }
         return count;
     }
};