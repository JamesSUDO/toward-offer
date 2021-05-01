
// 我的解法1：双循环暴力法
class Solution1 {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> result(A.size(), 1);
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < result.size(); j++) {
                if (i != j) {
                    result[j] *= A[i];
                }
            }
        }
        return result;
    }
};

// 我的解法2：
class Solution2 {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> left, right;
        left.push_back(1);
        right.push_back(1);
         
        for (int i = 0; i < A.size() - 1; i++) {
            left.push_back(left.back() * A[i]);
            right.push_back(right.back() * A[A.size() - 1 - i]);
        }
         
        for (int i = 0; i < A.size(); i++) {
            left[i] *= right[right.size() - 1 - i];
        }
        return left;
    }
};

// 官方解法
class Solution3 {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        // 上三角
        B.push_back(1);
        for (int i = 1; i < A.size(); i++) {
            B.push_back(B[i - 1] * A[i - 1]);
        }
        // 下三角
        int temp = 1;
        for (int i = A.size() - 2; i >= 0; i--) {
            temp *= A[i + 1];
            B[i] *= temp;
        }
        return B;
    }
};