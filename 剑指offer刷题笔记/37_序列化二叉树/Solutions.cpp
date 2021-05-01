
// 我的解法
class Solution1 {
public:
	char* Serialize(TreeNode *root) {
		string str;
		inOrder(root, str);

		char* char_str = new char[str.size()];
		strcpy(char_str, str.c_str());
		return char_str;
	}

	void inOrder(TreeNode* root, string &str) {
		if (!root) {
			str.push_back('#');
			str.push_back(',');
			return;
		}

		str += to_string(root->val);
		str.push_back(',');

		if (!root->left && !root->right) {
			str.push_back('!');
			str.push_back(',');
			return;
		}
		inOrder(root->left, str);
		inOrder(root->right, str);
	}

	TreeNode* Deserialize(char *str) {
		if (str == NULL || *str == '#') {
			return NULL;
		}

		int val = 0;
		while (*str != ',') {
			val = *str - '0' + val * 10;
			str++;
		}
		TreeNode* head = new TreeNode(val);
		inOrderInverse(head, str);
		return head;
	}

	char* inOrderInverse(TreeNode* node, char* curChar) {
		curChar++;
		if (*curChar == '!') {
			return curChar + 1;
		}

		// left node
		if (*curChar != '#') {
			int val = 0;
			while (*curChar != ',') {
				val = *curChar - '0' + val * 10;
				curChar++;
			}
			TreeNode* temp = new TreeNode(val);
			node->left = temp;
			curChar = inOrderInverse(node->left, curChar);
		}
		else {
			curChar += 1;
		}

		curChar++;
		if (*curChar == '!') {
			return curChar + 1;
		}

		// right node
		if (*curChar != '#') {
			int val = 0;
			while (*curChar != ',') {
				val = *curChar - '0' + val * 10;
				curChar++;
			}
			TreeNode* temp = new TreeNode(val);
			node->right = temp;
			curChar = inOrderInverse(node->right, curChar);
		}
		else {
			curChar += 1;
		}
		return curChar;
	}
};

// 牛客上的一个解法
class Solution2 {
public:
	char* Serialize(TreeNode *root) {
		if (!root) return (char *)"#";

		string res = to_string(root->val);
		res.push_back(',');

		char* left = Serialize(root->left);
		char* right = Serialize(root->right);

		char* ret = new char[res.size() + strlen(left) + strlen(right)];
		strcpy(ret, res.c_str());
		strcat(ret, left);
		strcat(ret, right);

		return ret;
	}

	TreeNode* Deserialize(char* &str) {
		if (*str == '#') {
			str++;
			return nullptr;
		}
		int val = 0;
		while (*str != ',') {
			val = val * 10 + (*str - '0');
			str++;
		}
		str++;

		TreeNode* root = new TreeNode(val);
		root->left = Deserialize(str);
		root->right = Deserialize(str);

		return root;
	}
};

// 官方解法略，见参考书
