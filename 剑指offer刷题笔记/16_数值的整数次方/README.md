# 数值的整数次方

[链接](https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。保证base和exponent不同时为0。



我的解法是几次方就做几次乘法运算，时间复杂度：o(n)，此解法中规中矩，官方题解更巧妙。



官方解法是每次循环不乘以base，而是乘以当前得到的result值。比如求5次方，相当于两个2次方相乘，再乘以base，很容易用递归实现。时间复杂度：o(logn)，很巧妙，要记住。

