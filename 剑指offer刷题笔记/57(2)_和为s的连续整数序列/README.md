# 和为s的连续整数序列

[链接](https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出描述：

```
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。
```



我的解法是以连续整数的个数为条件遍历，用求和公式 sum/n=mid 确定符合的情况。比如 sum=15，我们遍历到n=3时，可计算中间值 15/5=3，因此 1 2 3 4 5 满足条件；再比如 sum=10，我们遍历到n=4时，可计算中间值 10/4=2.5，因此 1 2 3 4 满足条件。

可确定满足题意的条件：当n为奇数时，需要中间值为整数；当n为偶数时，需要中间值小数位是0.5。

然后看边界条件，我们知道n最小是2，再来看最大：同样举几个例子看更清楚一些。首先看 15/5=3，得到结果是1 2 3 4 5，这是最边界情况，n再大就不行了；然后看 10/4=2.5，得到结果是 1 2 3 4，这也是最边界的情况，n再大就不行了。然后有规律：mid>(n/2)，当然上面两个例子说服力还不够，可以自己多举一些例子看看。由 sum/n=mid 有 sum/n>n/2 ，得到 : 
$$
n<\sqrt{sum \ast 2}
$$



官方解法用的是滑动窗口思路，用small和big分别代表窗口的两端，初始化small为1，big为2，每一次循环判断窗口内的数字和是否等于sum，若等于则记录，若大于sum，则 big+1，若小于sum，则 small+1。因为至少两个值，所以small最大不能超过 (1+sum)/2 。以 sum=9 为例构建表格如下：

| small | big  | curSum | curSum?sum |
| ----- | ---- | ------ | ---------- |
| 1     | 2    | 3      | <          |
| 1     | 3    | 6      | <          |
| 1     | 4    | 10     | >          |
| 2     | 4    | 9      | =          |
| 3     | 5    | 12     | >          |
| 4     | 5    | 9      | =          |
| 5     | 6    | 11     | >          |

