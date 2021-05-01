
// 我的解法
/* 数值条件
1. +-只能出现在第一位或紧跟e，且不能出现在最后
2. e(E)只能出现一次，不能出现在最后，也不能出现在+-后
3. .只能出现一次，且不能出现在第一位和最后以及e后面所有位置
4. 数字只能是合法数字0-9，且0不能出现在第一位和+-后(除非0后是.)以及e后
*/
class Solution1 {
public:
	bool isNumeric(char* string) {
		bool dotHasShown = false;
		bool eHasShown = false;
		int length = strlen(string);

		for (int i = 0; i < strlen(string); i++) {
			if ((string[i] >= '0' && string[i] <= '9')) {
				if (string[i] == '0') {
					if ((i == 0 || string[i - 1] == '+' || string[i - 1] == '-') && 
						!(i != length - 1 && string[i + 1] == '.') || 
						string[i - 1] == 'e' || string[i - 1] == 'E')
						return false;
				}
			}
			else if (string[i] == '+' || string[i] == '-') {
				if (i != 0 && string[i - 1] != 'e' && string[i - 1] != 'E')
					return false;
			}
			else if (string[i] == 'e' || string[i] == 'E') {
				if (eHasShown || i == length - 1)
					return false;
				eHasShown = true;
			}
			else if (string[i] == '.') {
				if (dotHasShown || eHasShown || i == 0 || i == length)
					return false;
				dotHasShown = true;
			}
			else return false;
		}
		return true;
	}
};


// 官方解法：正则表达式匹配
class Solution2 {
public:
	bool isNumeric(char* string) {
		if (string == NULL)
			return false;

		bool numeric = scanInteger(&string, true);
		if (*string == '.') {
			string++;
			numeric = scanInteger(&string, false) || numeric;
		}
		if (*string == 'e' || *string == 'E') {
			string++;
			numeric = numeric && scanInteger(&string, true);
		}
		return numeric && *string == '\0';
	}

	bool scanInteger(char** str, bool withSign) {
		if (withSign) {
			if (**str == '+' || **str == '-')
				(*str)++;
		}
		char* before = *str;
		while (**str <= '9' && **str >= '0') {
			(*str)++;
		}
		return *str > before;
	}
};