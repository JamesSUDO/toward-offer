
// 此解法有误，仅作为反面教材参考!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 这个题...卡了三天...结果这个解法还错了，虽然牛客上代码执行通过了...
// 我的解法：二分法，比较每一次中点与相邻两点的关系，以及中点与左右两端点的关系
// 左右邻点找最小值，左右端点找新范围
// error：比如对于{3, 3, 3, 3, 3, 1, 2, 3}，就会判断错误，没考虑到特殊情况，详见官方解法
// warning：没必要用递归，一个循环即可解决
class Wrong_Solution {  // 解法有误，作为反面教材！！！！！！！！！！！！！！！！
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        
        int num = helper(rotateArray, 0, rotateArray.size() - 1);
        return rotateArray[num];
    }
    
    int helper(vector<int>& m, int left, int right)
    {
        if(right - left <= 1) return right;
        
        int mid = left + (right - left)/ 2;  // 取中间偏左为中点
        
        if (m[mid] >= m[mid - 1] && m[mid] > m[mid + 1]) return mid+1;
        if (m[mid] < m[mid - 1] && m[mid] <= m[mid + 1]) return mid;
        
        if (m[mid] <= m[right]) return helper(m, left, mid - 1);
        if(m[mid] >= m[left]) return helper(m, mid + 1, right);

        return 9999999999999999999;  // 防止有条件遗漏掉，如果遗漏，会出现内存溢出的报错
    }
};

// 官方解法
// 只比较中点和左右两端点的关系
// 原理是当中点在左数组时，值大于等于左端点的值；中点在右数组时，值小于等于右端点的值
// 需要注意一种情况，当选择把前面0个元素搬到后面，此时新数组和原数组相同
// 需要排除一种情况：当左右端点和中点的相等的时候，此时只能顺序查找
class Solution2 {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        
        int left = 0, right = rotateArray.size() - 1;
        if(rotateArray[left] < rotateArray[right])  // 避免第一种特殊情况
            return rotateArray[0];
        
        while(right - left > 1)
        {
            int mid = (right + left)/ 2;  // 取中间偏左为中点
            
            if(rotateArray[left] == rotateArray[right] &&  // 避免第二种特殊情况
               rotateArray[mid]  == rotateArray[left])
            {
                minInorder(rotateArray, left, right);
            }
            
            if(rotateArray[mid] >= rotateArray[left])  // 中点在左序列
            {
                left = mid;
            }
            else if(rotateArray[mid] <= rotateArray[right])  // 中点在右序列
            {
                right = mid;
            }
        }
        return rotateArray[right];
    }
    
    int minInorder(vector<int> rotateArray, int left, int right)
    {
        int min_val = rotateArray[left];
        for(int i = left + 1; i <= right; i++)
        {
            if(rotateArray[i] < min_val) min_val = rotateArray[i];
        }
        return min_val;
    }
};