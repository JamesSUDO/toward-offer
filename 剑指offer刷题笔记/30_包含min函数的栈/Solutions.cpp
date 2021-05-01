
// 我的解法：新建一个辅助的栈stack2，负责保存当前最小元素
// 具体做法是，每当stack1要压入数据时，比较此value和stack2栈顶元素，若此value小，则压入stack2
// 当stack1弹出value时，判断此value是否等于stack2，若等则弹出
class Solution {
public:
    void push(int value) {
        stack1.push(value);
        if(stack2.empty() || value < stack2.top())
        {
            stack2.push(value);
        }
    }
    void pop() {
        if (stack1.top() == stack2.top()) stack2.pop();
        
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
    
private:
    stack<int> stack1, stack2;
};


// 官方解法同我的解法，代码略
// 主要考察的点在于此题的解法直接理解起来很抽象，需要自己举个实际例子验证
// 详见参考书