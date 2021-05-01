# 字符串的排列

[链接](https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。



我的第1个解法是使用递归，每一次递归都用循环来遍历当前str的所有元素，新建curStr保存每次递归遍历str的元素，push的同时操作str，把此元素从str中erase，然后进入下一次递归，当str为空时，把curStr push到vector中。注意一点就是循环的时候，要申请一个临时的str和curStr而不能在原字符串操作，否则在下一次循环中，所用的str和curStr都是被上一次循环改动过的。最后对此vector用双层循环遍历，去掉一样的元素。



我的第2个解法，在解法1的基础上改进了一下，同样是递归遍历str，把元素push到curStr中，不同之处在于每次push了str的元素后，不对str执行erase，而是用了set，以当前被push的str中的元素位置为键值存到set中。每次在循环的时候，先判断set中有无当前元素序号，没有的话才执行push，并把此序号键值存到map。



官方解法3是直接交换次序，不新建辅助字符串来存取元素，直接在原str上操作。第一次递归，交换第0个元素和循环的第i个(i从0到str.size())， 第n次递归，交换第n个元素和循环的第i个(i从n到str.size())。 当n等于str.size()时，把当前str push到vector中。注意此解法不能通过牛客所有范例，牛客有要求是让所有的字符串按字典序列顺序排列，此解法不能保证。



