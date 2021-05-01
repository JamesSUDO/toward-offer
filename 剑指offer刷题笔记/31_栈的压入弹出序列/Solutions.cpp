
// 参考牛客的解法
// 这个我没想出来，然后看了牛客上其他人提交的解答，明白了
// 原理是用一个辅助的栈来模拟push和pop操作
// 遍历两个数组，每次循环先压入pushV数组的元素
// 然后判断栈顶元素和popV元素，如果相同则弹出，弹出之后如果下一个还相同则继续弹出
// 直到栈顶元素和popV当前元素不同，则进行下一次循环
// 然后换了一种自己比较舒服的代码写法，代码见下
class Solution1 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int push_ptr = 0, pop_ptr = 0;
         
        for(push_ptr; push_ptr < pushV.size(); push_ptr++)
        {
            s.push(pushV[push_ptr]);
             
            while(!s.empty() && s.top() == popV[pop_ptr])
            {
                s.pop();
                pop_ptr++;
            }
        }
         
        return s.empty();
    }
};


// 官方解法
// 官方解法思想跟上面那个解法思想有一定的共通点
// 上面解法是遍历pushV，当栈顶元素和popV当前元素相同,则弹出
// 官方解法是遍历popV，当栈顶元素和popV当前元素不同，则压入pushV元素
class Solution2 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int push_ptr = 0, pop_ptr = 0;
         
        for(pop_ptr; pop_ptr < popV.size(); pop_ptr++)
        {
            while((s.empty() || s.top() != popV[pop_ptr]))
            {
                s.push(pushV[push_ptr++]);
            }
             
            if(s.top() == popV[pop_ptr])
            {
                s.pop();
            }
        }
         
        return s.empty();
    }
};


// 或者这个也跟官方解法是一个意思
class Solution3 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int push_ptr = 0, pop_ptr = 0;
         
        for(pop_ptr; pop_ptr < popV.size(); pop_ptr++)
        {
            if(s.empty() || s.top() != popV[pop_ptr])
            {
                while(pushV[push_ptr] != popV[pop_ptr])
                {
                    s.push(pushV[push_ptr++]);
                }
                push_ptr++;
            }
            else
            {
                s.pop();
            }
        }
         
        return s.empty();
    }
};