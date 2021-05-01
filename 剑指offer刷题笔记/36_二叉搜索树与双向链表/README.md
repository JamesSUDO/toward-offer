# 二叉搜索树与双向链表

[链接](https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。



我的解法是递归中序遍历，依次把节点指针存入vector中，存储顺序恰好就是题目要求的顺序，然后遍历vector的元素，把每个元素的left指向前一个，right指向后一个元素即可。



官方解法没有用vector，是直接中序遍历的同时操作得。

