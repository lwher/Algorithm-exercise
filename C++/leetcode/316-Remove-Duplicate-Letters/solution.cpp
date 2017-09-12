class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> myStack;
        vector<int> lastIndex(26);
        vector<bool> IsInStack(26);
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (IsInStack[s[i] - 'a'])
                continue;
            while(!myStack.empty() && myStack.top() > s[i] && lastIndex[myStack.top() - 'a'] > i) {
                IsInStack[myStack.top() - 'a'] = false;
                myStack.pop();
            }
            myStack.push(s[i]);
            IsInStack[s[i] - 'a'] = true;
        }
        string res = "";
        while(!myStack.empty()) {
            res = myStack.top() + res;
            myStack.pop();
        }
        return res;
    }
};