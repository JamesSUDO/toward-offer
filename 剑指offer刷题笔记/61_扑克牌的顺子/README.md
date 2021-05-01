# 扑克牌的顺子

[链接](https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2~10为数字本身，A为1，J、Q、K分别为11，12，13，这里为方便起见，把大小王设为0。



我的解法是依次遍历数组，得到数组中非0值中的最大值和最小值，用set辅助判断是否有重复元素，如果有的话直接返回false。然后以最大值和最小值计算形成此顺子需要的牌的数量，如果数目大于numbers.size()，直接返回false。

仅一次遍历数组,时间复杂度o(n)。



官方解法是先对数组排序，然后依次访问数组中的非0相邻元素，若相等则返回false，若不相等则计算需要填充的0个数，判断当前0的数量够不够填充，不够则返回false，遍历到数组尾发现够则返回true。

因为涉及到排序，所以时间复杂度相对要高一点，是o(n*logn)。