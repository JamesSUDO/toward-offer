
// 我的解法
class Solution {
public:
	int movingCount(int threshold, int rows, int cols) {
		vector<vector<bool> > matrix(rows, vector<bool>(cols, true));
		return helper(matrix, 0, 0, threshold);
	}

	int helper(vector<vector<bool> >& matrix, int row, int col, int threshold) {
		if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[row].size() ||
			matrix[row][col] == false || judgeSum(row, col, threshold)) {
			return 0;
		}

		matrix[row][col] = false;
		return helper(matrix, row - 1, col, threshold) + 
			   helper(matrix, row + 1, col, threshold) +
			   helper(matrix, row, col - 1, threshold) +
			   helper(matrix, row, col + 1, threshold) + 1;
	}

	bool judgeSum(int a, int b, int threshold) {
		int sum = 0;
		while (a) {
			sum += a % 10;
			a /= 10;
		}
		while (b) {
			sum += b % 10;
			b /= 10;
		}
		return sum > threshold;
	}
};


// 官方解法略，见参考书