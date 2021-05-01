
// 我的解法
class Solution {
public:
	bool hasPath(vector<vector<char> >& matrix, string word) {
		bool flag = false;

		// 从任一起点开始，分别判断是否成立
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				flag = flag || helper(matrix, i, j, word, 0);
			}
		}
		return flag;
	}

	bool helper(vector<vector<char> > matrix, int row, int col, const string &word, int index) {
		if (index == word.size()) return true;  // 如果能遍历到最后，则返回true

		 // 如果满足条件则继续递归下去
		if (row >= 0 && col >= 0 && row < matrix.size() && col < matrix[row].size() && matrix[row][col] != ',' && matrix[row][col] == word[index]) {
			matrix[row][col] = ',';  // 将访问过的元素标记为','
			return helper(matrix, row, col - 1, word, index + 1) || helper(matrix, row, col + 1, word, index + 1) || 
				   helper(matrix, row - 1, col, word, index + 1) || helper(matrix, row + 1, col, word, index + 1);
		}

		return false;  // 如果不满足，则返回false
	}
};


// 官方解法略，见参考书