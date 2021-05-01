# 翻左旋转字符串

[链接](https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey)

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！



我的第一个解法是利用辅助容器实现，从n开始依次遍历数组元素，然后从0遍历到第n-1个元素即可。



我的第二个解法是利用两次翻转的方法，先对0到n-1的元素翻转，再对n到最后的元素翻转，最后翻转整个字符串即可。

