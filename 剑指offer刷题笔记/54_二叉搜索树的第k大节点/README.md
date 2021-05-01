# 二叉搜索树的第k大节点

[链接](https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey)

给定一棵二叉搜索树，请找出其中的第k小的TreeNode结点。



这个先看题目中是二叉搜索树，而二叉搜索树根据其特点，对应中序遍历恰好就是排好序的，所以对其的中序遍历序列找到第k个节点即可。

我的方法是用一个数组储存中序遍历的结果。

也可以不用数组来辅助，直接递归来返回对应的节点即可。代码见解法2，首先往左子节点一直遍历直到null，然后回溯当前节点。再以同样的方式递归遍历其右子节点。判断每一次的节点是否为第k个，满足条件则逐层返回此节点，不满足则继续递归并返回空节点。

官方解法思路同上。