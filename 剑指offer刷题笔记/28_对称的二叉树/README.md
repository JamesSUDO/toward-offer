# 对称的二叉树

[链接](https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&&tqId=11211&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。



我的解法是运用一个递归的辅助函数来判断，由题意分析可得，根节点的左节点的左节点和根节点的右节点的右节点是对称的，根节点的左节点的右节点和根节点的右节点的左节点也是对称的，同时相对应的左右节点的对应子节点也有这个关系：leftNode->leftNode = rightNode->rightNode、leftNode->rightNode = rightNode->leftNode。因此用递归即可简单的实现。



官方解法是思想同，详见参考书。