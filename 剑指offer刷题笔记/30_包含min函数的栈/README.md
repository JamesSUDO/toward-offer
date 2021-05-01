# 包含min函数的栈

[链接](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。



我的解法是新建一个辅助的栈stack2，负责保存当前最小元素。具体做法是，每当stack1要压入数据时，比1较此value和stack2栈顶元素，若此value小，则压入stack2。当stack1弹出value时，判断此value是否等于stack2，若等则弹出。



官方解法同我的解法，主要考察的点在于此题的解法直接理解起来很抽象，需要自己举个实际例子验证，详见参考书。