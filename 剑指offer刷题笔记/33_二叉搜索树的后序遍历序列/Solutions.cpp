
// 我的解法
// 一直在想有没有时间复杂度为n的方法，没有想到，然后看了参考书也没有
// 估计这个解法，也就是参考书解法的思想，应该是最简的了
// 方法是递归，每一次递归输入的最右元素一定是根节点
// 然后循环比较跟节点值是否大于左节点，小于右节点即可
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        
        return helper(sequence, 0, sequence.size() - 1);
    }
    
    bool helper(vector<int> &vec, int left, int right)
    {
        if(left >= right) return true;
        
        int i = left;
        int parent = vec[right];
        
        for(i; i < right; i++)
        {
            if(vec[i] > parent) break;
        }
        
        for(int j = i; j < right; j++)
        {
            if(vec[j] < parent) return false;
        }
        
        return helper(vec, left, i - 1) && helper(vec, i, right - 1);
    }
};


// 官方解法思想同，略