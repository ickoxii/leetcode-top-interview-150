class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> stk;
        int operand = 0;
        int result = 0;
        int sign = 1;

        for (char c : s) {
            if (c == ' ') {
                continue;  // Ignore spaces
            }
            if (isdigit(c)) {
                operand = operand * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * operand;
                operand = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * operand;
                operand = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * operand;
                operand = 0;

                int prevSign = stk.top();
                stk.pop();
                int prevResult = stk.top();
                stk.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += sign * operand;
        return result;
    }
};
