# 第一个只出现一次的字符

[链接](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）



我的解法用到了辅助容器，使用哈希表来保存每个字符出现次数，最后遍历找到第一个出现一次的字符即可。



官方解法是用数组来模拟哈希表，思想同。