# 数据流中的中位数

[链接](https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey)

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。



这个题有多种解法，最简单的就是暴力法，每次都在数组最后面插入新元素，返回中位数时通过排序操作来辅助。

我的解法用到了插入排序，通过插入排序的方法不断插入新元素。

牛客官方给的解法是通过堆来实现，构建一个大顶锥和一个小顶锥，大顶锥存取较小的数，小顶锥存取较大的数，保证两数组size相差不超过1，则数据流的中位数与大顶锥和小顶锥的根节点有关。这里当数目为偶数的时候，将值插入到大顶锥中，然后将大顶锥的根节点元素转移到小顶锥；当数目为奇数时，将值插入到小顶锥中，然后将小顶锥的根节点元素转移到大顶锥中。

官方解法这里不赘述了，原理一样，代码见参考书。