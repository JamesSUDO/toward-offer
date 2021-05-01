
// 我的解法：暴力法
class Solution1 {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
		vector<int> res;
		if (size <= 0 || size > num.size()) return res;

		for (int i = 0; i <= num.size() - size; i++) {
			int maxVal = num[i];
			for (int j = i + 1; j < i + size; j++) {
				maxVal = max(num[j], maxVal);
			}
			res.push_back(maxVal);
		}
		return res;
	}
};

// 官方解法：队列
class Solution2 {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
		deque<int> numQue;
		vector<int> res;
		
		if (size <= 0 || size > num.size()) return res;

		for (int i = 0; i < num.size(); i++) {
			while (!numQue.empty() && num[numQue.back()] <= num[i]) numQue.pop_back();
			numQue.push_back(i);
			if (i - numQue.front() >= size) numQue.pop_front();
			if (i >= size - 1) res.push_back(num[numQue.front()]);
		}

		return res;
	}
};