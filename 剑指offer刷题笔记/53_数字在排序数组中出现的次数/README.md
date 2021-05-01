# 数字在排序数组中出现的次数

[链接](https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

统计一个数字在排序数组中出现的次数。



我的解法是二分法，虽然想到了用二分法来解，但实际上我的解法时间复杂度还是o(n)，因为在找到k后，要向两边一个个遍历数k的个数。



官方解法时间复杂度o(logn)，用了两次二分法分别求出来第一个k和最后一个k的位置，最后相减加1就是要求的k的个数。