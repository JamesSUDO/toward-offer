// 我的解法
class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if (m.find(ch) == m.end()) {
            m.insert(pair<char, int>(ch, 1));
            str.push_back(ch);
        }
        else {
            m[ch]++;
        }
    }
    //return the first appearence once char in current stringst ream
    char FirstAppearingOnce()
    {
        for (string::iterator iter = str.begin(); iter != str.end();) {
            if (m[*iter] != 1) {
                iter = str.erase(iter);
            }
            else {
                return *iter;
            }
        }
        return '#';
    }
private:
    unordered_map<char, int> m;
    string str;
};


// 网上他人解法
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		cnt[ch - '\0']++;
		data.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!data.empty() && cnt[data.front()] > 1) {
			data.pop();
		}
		if (!data.empty()) {
			return data.front();
		}
		return '#';
	}
private:
	unsigned int cnt[128] = { 0 };
	queue<char> data;
};


// 官方解法思想同上，略