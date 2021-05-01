# 把字符串转换成整数

[链接](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0



字符串转整数，面试手撕算法很容易问到，因为要考虑到边界情况。

这个题在牛客不能AC，牛客给的一个数据有问题：str = “-2147483649”的时候希望输出-2147483649，这个数超过了int的边界。

所以我又拿解法在leetcode上测试，检验没有问题，给出的解法可放心食用。



官方解法这里不赘述了，原理一样，代码见参考书。