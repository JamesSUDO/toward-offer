# 替换空格

[链接](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。



我的解法是新建一个空字符串，然后直接末尾添加元素即可。



官方解法直接操作原数组，通过倒序访问的方式避免数组元素被覆盖，代码见参考书。