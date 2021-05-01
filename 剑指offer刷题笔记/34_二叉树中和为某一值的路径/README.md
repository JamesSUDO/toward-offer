# 二叉树中和为某一值的路径

[链接](https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)



一开始的想法是递归前序遍历二叉树，然后用二维的vector不断push_back前一步的vector，也就是二维数组的最后一项再push一遍，如果最后不满足条件，再把二维数组中的当前一维vector pop出去，然后程序一直没改对...后来看了参考书，才发现我整复杂了，直接往函数参数里加一个一维的vector即可，当满足条件时直接把这个一维vector push到二维的vector中。

然后注意牛客网这个题有个要求，在返回值的list中，数组长度大的数组靠前，因此在左右子节点先后顺序上不一定，如果两个子节点都存在，就先递归调用val小的子节点。

