
// 我的解法：用到了二分查找
// 时间复杂度：o(m*logn)
class Solution1 {
public:
    bool helper(vector<int>& array, int target, int left, int right)
    {
        if(left > right) return false;
        int mid = left + (right - left) / 2;  // 中点偏左
        if(target == array[mid]) return true;
        
        else if(target < array[mid]) return helper(array, target, left, mid - 1);
        else return helper(array, target, mid + 1, right);
    }
    
    bool Find(int target, vector<vector<int> > array) {
        if(array[0].empty()) return false;
        
        int width = array[0].size();
        for(int i = 0; i < array.size(); i++)
        {
            if(array[i][0] <= target && array[i][width - 1] >= target)
            {
                if(helper(array[i], target, 0, width - 1) == true) return true;
            }
        }
        return false;
    }
};


// 官方解法：一次遍历，从二维数组右上角开始循环
// 时间复杂度：o(m+n)
class Solution2 {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array[0].empty()) return false;  // 可加可不加
        
        // 从右上点开始找起
        int x = array[0].size() - 1;
        int y = 0;
        
        while(x >= 0 && y <array.size())
        {
            if(target == array[y][x]) return true;
            else if (target < array[y][x]) x--;
            else y++;
        }
        
        return false;
    }
};