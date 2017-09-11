class Solution {
public:
    void SolveOperator(std::stack<int> &numStack, char op) {
        int numB = numStack.top();
        numStack.pop();
        int numA = numStack.top();
        numStack.pop();
        if (op == '+') numA += numB;
        else numA -= numB;                    
        numStack.push(numA);
    }

    int calculate(string s) {
        std::stack<int> numStack;
        std::stack<char> operatorStack;
        s = '(' + s + ')';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                operatorStack.push(s[i]);
            }
            else if (s[i] == ')') {
                while (operatorStack.top() != '(') {
                    char op = operatorStack.top();
                    SolveOperator(numStack, op);
                    operatorStack.pop();
                }
                operatorStack.pop();
            }
            else if (s[i] == '+' or s[i] == '-') {
                while (!operatorStack.empty()) {
                    char op = operatorStack.top();
                    if (op == '+' || op == '-') {
                        SolveOperator(numStack, op);
                        operatorStack.pop();
                    }
                    else break;
                }
                operatorStack.push(s[i]);
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                int num = 0, j = i;
                while(j < s.size() && s[j] >= '0' && s[j] <= '9') {
                    num = num * 10 + s[j] - '0';
                    ++j;
                }
                i = j - 1;
                numStack.push(num);
            }
        }
        return numStack.top();
    }
};

