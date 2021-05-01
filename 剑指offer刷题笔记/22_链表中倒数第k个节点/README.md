# 链表中倒数第k个节点

[链接](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

输入一个链表，输出该链表中倒数第k个结点。



我的解法是利用快慢指针即可。方法不难，但是我一开始提交的报错了，因为没考虑到特殊情况
：当k大于链表元素个数，在快指针的循环中，会出现操作空指针的错误，因此在每一次的循环都加了是否为空指针的判断。



官方解法和我的解法一样，此题的核心是要注意代码的鲁棒性，把所有异常情况都考虑进去。