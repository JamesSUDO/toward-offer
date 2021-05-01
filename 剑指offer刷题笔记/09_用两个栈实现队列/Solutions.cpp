
// 我的解法
// push操作就直接push即可；
// pop操作是先把stack1元素全pop到stack2中，实现反序，再pop stack2，再重新把stack2元素push到stack1
// 此方法虽然可以，但是pop操作需要两个循环来遍历stack中所有元素，这其中有很多重复的不必要操作
class Solution1
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        int val = stack2.top();
        stack2.pop();
        
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


// 官方解法
// push还是直接push
// 执行pop操作，先进行一个判断，判断stack2是否空，如果空，则stack1的所有元素pop进去
// 为啥当空的时候才能pop，是因为非空的话，stack1元素pop到stack2中，会在先pop到是stack2元素的后面
// 根据stack的先入后出原则，后pop的元素会先出去，这不符合队列的先入先出
class Solution2
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int val = stack2.top();
        stack2.pop();
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};