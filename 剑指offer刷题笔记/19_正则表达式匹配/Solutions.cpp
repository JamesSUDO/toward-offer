
// 我的解法1
class Solution1 {
public:
    bool helper(char* str, char* pattern, int i, int j) {
        // 边界处理
        if (i == strlen(str) && j == strlen(pattern))
            return true;
        if (i != strlen(str) && j == strlen(pattern))
            return false;
        if (i == strlen(str) && j != strlen(pattern)) {
            while (j < strlen(pattern)) {
                if (j + 1 < strlen(pattern) && pattern[j + 1] == '*')
                    j += 2;
                else
                    return false;
            }
            return true;
        }
 
        // 下一个字符是*的情况
        if (j + 1 < strlen(pattern) && pattern[j + 1] == '*') {
            // ".*"的情况
            if (pattern[j] == '.') {
                if (j + 2 == strlen(pattern))
                    return true;
                bool flag = false;
                for (int index = i; index < strlen(str); index++) {
                    if (str[index] == pattern[j + 2])
                        flag = flag || helper(str, pattern, index, j + 2);
                }
                return flag;
            }
            // *前不是.的情况
            else {
                bool flag = helper(str, pattern, i, j + 2);
                while (i < strlen(str) && str[i] == pattern[j]) {
                    i++;
                    flag = flag || helper(str, pattern, i, j + 2);
                }
                return flag;
            }
        }
 
        // 正常情况
        else if (pattern[j] == '.' || str[i] == pattern[j])
            return helper(str, pattern, i + 1, j + 1);
        else
            return false;
    }
 
    bool match(char* str, char* pattern) {
        return helper(str, pattern, 0, 0);
    }
};

// 我的解法2
class Solution2 {
public:
	bool helper(char* str, char* pattern) {
		// 边界处理
		if (*pattern == '\0')
			return *str == '\0';

		// 下一个字符是*的情况
		if (*(pattern + 1) == '*')
			return ((*pattern == '.' && *str != '\0') || *str == *pattern) ? (helper(str, pattern + 2) || helper(str + 1, pattern)) : helper(str, pattern + 2);

		// 下一个字符非*的情况
		if ((*pattern == '.' && *str != '\0') || *str == *pattern)
			return helper(str + 1, pattern + 1);

		return false;
	}

	bool match(char* str, char* pattern) {
		return helper(str, pattern);
	}
};


// 官方解法略，见参考书