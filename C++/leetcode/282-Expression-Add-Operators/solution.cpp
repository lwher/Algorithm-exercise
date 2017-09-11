class Solution {
public:
	void Dfs(const string &num, const int &target, vector<string> &res, string nowStr, int pos, long long nowRes, long long lastNum) {
		if (pos == num.size()) {
			if (nowRes == target) {
				res.push_back(nowStr);
			}
			return;
		}
		string nowNum = "";
		long long number = 0;
		for (int i = pos; i < num.size(); ++i) {
			if (i == pos + 1 && num[pos] == '0') 
				break;
			nowNum += num[i];
			number = number * 10 + num[i] - '0';
			if (pos == 0) {
				Dfs(num, target, res, nowNum, i + 1, nowRes + number, number);
			}
			else {
				Dfs(num, target, res, nowStr + "+" + nowNum, i + 1, nowRes + number, number);
				Dfs(num, target, res, nowStr + "-" + nowNum, i + 1, nowRes - number, -number);
				Dfs(num, target, res, nowStr + "*" + nowNum, i + 1, nowRes - lastNum + lastNum * number, lastNum * number);
			}
		}
	}

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        Dfs(num, target, res, "", 0, 0, 0);
        return res;
    }
};
