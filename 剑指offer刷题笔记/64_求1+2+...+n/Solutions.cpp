
// 官方解法1：利用构造函数求解
class Temp {
public:
	Temp() { ++n, sum += n; }

	static void reset() { n = 0, sum = 0; }
	static int getSum() { return sum; }

private:
	static int n;
	static int sum;
};

int Temp::n = 0;
int Temp::sum = 0;

class Solution1 {
public:
	int Sum_Solution(int n) {
		Temp::reset();
		Temp* a = new Temp[n];

		return Temp::getSum();
	}
};


// 官方解法2：利用虚函数
class ReturnClass;
ReturnClass* Array[2];

class ReturnClass {
public:
	virtual int getSum(int n)
	{
		return 0;
	}
};

class Solution2 : ReturnClass {
public:
	int getSum(int n) {
		return n + Array[!!n]->getSum(n - 1);
	}

	int Sum_Solution(int n)
	{
		ReturnClass a;
		Solution2 b;
		Array[0] = &a;
		Array[1] = &b;

		return Array[!!n]->getSum(n);
	}
};


// 官方解法3：利用函数指针
class Solution3 {
public:
	int Sum_Solution(int n)
	{
		return sumSolution(n);
	}

private:
	static int sumReturn(int n)
	{
		return 0;
	}

	static int sumSolution(int n)
	{
		getSum f[2] = { sumReturn, sumSolution };
		return n + f[!!n](n - 1);
	}

	typedef int(*getSum)(int);
};