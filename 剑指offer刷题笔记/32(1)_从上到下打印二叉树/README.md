# 从上往下打印二叉树

[链接](https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

从上往下打印出二叉树的每个节点，同层节点从左至右打印。



此题属于二叉树的广度优先遍历，因此用队列即可解决。



官方解法同样用的队列，区别于我用的queue，官方用的是deque，二者均可。