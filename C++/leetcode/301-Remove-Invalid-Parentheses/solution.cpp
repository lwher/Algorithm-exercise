class Solution {
public:
    bool IsValid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else if(s[i] == ')') {
                if (cnt > 0) --cnt;
                else return false;
            }
        }
        if (cnt) return false;
        else return true;
    }

    void Dfs(const string &s, int pos, string now, int left, int right, set<string> &isExist, vector<string> &res) {
        if (s.size() - pos < left + right) return;
        if (pos == s.size()) {
            if (IsValid(now) && !isExist.count(now)) {
                isExist.insert(now);
                res.push_back(now);
            }
            return;
        }
        Dfs(s, pos + 1, now + s[pos], left, right, isExist, res);
        if (s[pos] == '(' && left > 0) {
            Dfs(s, pos + 1, now, left - 1, right, isExist, res);
        }
        if (s[pos] == ')' && right > 0) {
            Dfs(s, pos + 1, now, left,  right - 1, isExist, res);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftUseless = 0, rightUseless = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') leftUseless++;
            if (s[i] == ')') {
                if (leftUseless > 0) --leftUseless;
                else ++rightUseless;
            }
        }
        set<string> isExist;
        vector<string> res;
        Dfs(s, 0, "", leftUseless, rightUseless, isExist, res);
        return res;
    }
};

