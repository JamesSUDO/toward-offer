# 二叉树的深度

[链接](https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。



我的解法1是递归，代码比较简洁，每次递归返回左右两子树对应的最大深度即可。



我的解法2是用循环法，用辅助容器栈实现二叉树的遍历，栈存的是pair数据类型，保存节点指针和对应深度。当左子树不存在时将当前depth和maxDepth比较，拿二者最大值更新maxDepth。

