/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	string ItoA(int num) {
		string res = "", sign = "";
		if (num == 0){
			return "0";
		}
		if (num < 0) {
			sign += "-";
			num = -num;
		}
		while(num > 0) {
			string tmp = "0";
			tmp[0] = num % 10 + '0';
			res = tmp + res;
			num /= 10;
		}
		return sign + res;
	}

	int AtoI(string num) {
		int res = 0, sign = 1, pos = 0;
		if (num[0] == '-') {
			sign = -1;
			++pos;
		}
		for (int i = pos; i < num.size(); ++i) {
			res = res * 10 + num[i] - '0';
		}
		return sign * res;
	}
    // Encodes a tree to a single string.

	void serializeDfs(string &key, TreeNode* now) {
		key += ItoA(now->val);
		if (now->left != NULL) {
			key += "l";
			serializeDfs(key, now->left);
		}
		if (now->right != NULL) {
			key += "r";
			serializeDfs(key, now->right);
		}
		key += "u";
	}

    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL)
            return res;
        serializeDfs(res, root);
        return res;
    }

    void deserializeDfs(const string &key, TreeNode* now, int &pos) {
    	if (key[pos] == '-' || (key[pos] >= '0' && key[pos] <= '9')) {
    		string val = "";
    		int i = pos;
    		while (i < key.size() && (key[i] == '-' || (key[i] >= '0' && key[i] <= '9'))) {
    			val += key[i];
    			++i;
    		}
    		now->val = AtoI(val);
    		pos = i;
    	}
    	if (key[pos] == 'l') {
    		now->left = new TreeNode(0);
    		deserializeDfs(key, now->left, ++pos);
    	}
    	if (key[pos] == 'r') {
    		now->right = new TreeNode(0);
    		deserializeDfs(key, now->right, ++pos);
    	}
    	if (key[pos] == 'u') {
    		++pos;
    		return;
    	}
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        TreeNode *root = new TreeNode(0);
        int pos = 0;
        deserializeDfs(data, root, pos);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
