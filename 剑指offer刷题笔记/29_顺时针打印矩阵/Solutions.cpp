
// 我的解法
// 给定一个不断变化的边界，当每次移动到边界时，换一个方向继续移动
// 外面的循环是循环每次的一整圈，里面的四个循环分别是四个方向
// 每次执行内层循环时，都要先更新一下边界
// 注意此边界条件会忽略最后一个遍历到的元素，所以在循环结束要单独把这个元素push
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> vec;
        if(matrix.empty() || matrix[0].empty()) return vec;
        
        int up_boundary = 0;
        int down_boundary = matrix.size() - 1;
        int left_boundary = 0;
        int right_boundary = matrix[0].size() - 1;
        
        int i = 0, j = 0;
        while(left_boundary <= right_boundary && up_boundary <= down_boundary)
        {
		    up_boundary++;
		    for (j; j < right_boundary; j++) vec.push_back(matrix[i][j]);
            
		    right_boundary--;
		    for (i; i < down_boundary; i++) vec.push_back(matrix[i][j]);

            if (up_boundary > down_boundary) break;  // 防止单独行时行重复打印
		    down_boundary--;
		    for (j; j > left_boundary; j--) vec.push_back(matrix[i][j]);

            if (left_boundary > right_boundary) break;  // 防止单独列时列重复打印
		    left_boundary++;
		    for (i; i > up_boundary; i--) vec.push_back(matrix[i][j]);
        }
        vec.push_back(matrix[i][j]);
        
        return vec;
    }
};


// 官方解法
// 方法差不多，不同的地方在于官方解法规定了每次的外层循环初始点都是左上点(start, start) (0 <= 2 * start < n)
// 代码略，见参考书