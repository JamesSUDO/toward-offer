# 二叉搜索树的后序遍历序列

[链接](https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。



一直在想有没有时间复杂度为n的方法，没有想到，然后看了参考书也没有。估计这个解法，也就是参考书解法的思想，应该是最简的了。方法是递归，每一次递归输入的最右元素一定是根节点，然后循环比较跟节点值是否大于左节点，小于右节点即可。满足则进行下一次子数组的递归判断，不满足则直接return false。