# 连续子数组的最大和

[链接](https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组和的最大值。要求时间复杂度为o(n)。

例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。



我的方法是使用动态规划或贪心算法，二者在这个题上代码是一样的。原理是遍历数组，先找出当前位置的最大，然后再与总最大比较，更新总最大值。还有一个方法是分治算法，不过这个时间复杂度是o(n*logn)，分治算法代码略，详细可见我的博客：[链接](https://blog.csdn.net/IcdKnight/article/details/104986951)



官方解法也是动态规划。