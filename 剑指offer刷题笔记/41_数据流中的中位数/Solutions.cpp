
// 我的解法
class Solution1 {
public:
	void Insert(int num) {
		int index = array.size() - 1;
		array.push_back(num);
		for (; index >= 0 && num < array[index]; index--) {
			array[index + 1] = array[index];
		}
		array[index + 1] = num;
	}

	double GetMedian() {
		if (array.empty()) return 0;

		return (array[array.size() / 2] + array[(array.size() - 1) / 2]) / 2;
	}

private:
	vector<int> array;

};

// 牛客的一个解法
class Solution2 {
public:
	void Insert(int num) {
		if (count % 2 == 0) {  // 如果是偶数则插入到大顶锥
			maxHeap.push(num);
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else {  // 如果是奇数则插入到小顶锥
			minHeap.push(num);
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		count++;
	}

	double GetMedian() {
		return count % 2 == 0 ? (double)(maxHeap.top() + minHeap.top()) / 2 : minHeap.top();
	}

private:
	priority_queue<int> maxHeap;  // 大顶锥
	priority_queue<int, vector<int>, greater<int>> minHeap;  // 小顶锥
	int count = 0;
};


// 官方解法略，见参考书