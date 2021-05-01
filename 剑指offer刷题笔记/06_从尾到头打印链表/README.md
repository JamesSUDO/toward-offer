# 用两个栈实现队列

[链接](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。



我的解法是push操作就直接push即可；pop操作是先把stack1元素全pop到stack2中，实现反序，再pop stack2，再重新把stack2元素push到stack1。此方法虽然可以，但是pop操作需要两个循环来遍历stack中所有元素，这其中有很多重复的不必要操作。



官方解法是push还是直接push；执行pop操作，先进行一个判断，判断stack2是否空，如果空，则stack1的所有元素pop进去，然后再stack2再pop。为啥当空的时候才能pop，是因为非空的话，stack1元素pop到stack2中，会在先pop到是stack2元素的后面，而根据stack的先入后出原则，后pop的元素会先出去，这不符合队列的先入先出原则。