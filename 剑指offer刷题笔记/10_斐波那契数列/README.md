# 斐波那契数列

[牛客链接](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。（n<=39）



我的解法是直接用一个循环搞定，时间复杂度o(n)。



官方解法同我的解法，有几点要说明：

- 此题考察点在于是否会用递归来实现，如果用递归，效率会很低，这算是一个陷阱吧。
- 除了书上的比较冷门的那个时间复杂度o(logn)算法外，还有一个直接套通项公式的算法，时间复杂度o(1)，详见下面链接。
- 关于详细的说明，可以参考我的博客这篇文章，链接下面给出，解决的是上台阶问题，实际就是斐波那契。
- https://blog.csdn.net/IcdKnight/article/details/104902902



后面的青蛙上台阶，矩形覆盖都是相关的类似题，原理一样。