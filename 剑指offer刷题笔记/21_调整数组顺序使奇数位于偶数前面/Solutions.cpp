
// 我的解法1：创建两个新数组，分别存储奇数和偶数，最后再全部拷贝给原数组
class Solution1 {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd, even;
        int count = 0;
        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] % 2 == 1) 
            {
                odd.push_back(array[i]);
                count++;
            }
            else even.push_back(array[i]);
        }
        
        for(int i = 0; i < count; i++)
        {
            array[i] = odd[i];
        }
        
        for(int i = 0; i < array.size() - count; i++)
        {
            array[i + count] = even[i];
        }
    }
};


// 我的解法2：利用迭代器
// 从前往后遍历数组，当遇见偶数则删除，并把此值push_back
// 要注意迭代器的失效问题：在push_back的时候如果容量不足则会触发扩容
// 扩容导致vector申请新内存并拷贝数据，然后会释放掉原内存，使得之前的迭代器指针变成野指针
// 所以这里我先删除，再push_back，不会有容量不足的问题
class Solution2 {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator iter = array.begin();
        for(int i = array.size(); i > 0; i--)
        {
            if(*iter % 2 == 0)
            {
                int temp = *iter;
                iter = array.erase(iter);
                array.push_back(temp);
            }
            else iter ++;
        }
    }
};


// 官方解法对应的题目没有奇数（偶数）自身的相对位置不变的要求
// 书上这个例题例题想表达的核心是关于代码的可拓展性
// 就是写一个通用框架能处理各种条件：如奇偶分开，正负分开等等
// 方法就是把判别函数单独拎出来，然后在数组操作函数中循环执行此判别函数即可
// 代码略，详见参考书