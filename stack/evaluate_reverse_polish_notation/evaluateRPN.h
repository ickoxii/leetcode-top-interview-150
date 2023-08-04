 /* You are given an array of strings tokens that
  * represents an arithmetic expressions in RPN.
  *
  * Evaluate the expression. Return an integer
  * that represents the value of the expressions.
  *
  * Note:
  *
  * 1. The valid operators are +, -, *, /
  *
  * 2. each operand may be an integer or another
  * expression.
  *
  * 3. The division between two integers always
  * truncates toward zero.
  *
  * 4. There will not be any division by zero.
  *
  * 5. The input represents a valid RPN expression.
  *
  * 6. The answer and all intermediate calculations
  * can be represented in a 32-bit integer. */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expression;
        for (string& token : tokens) {
            if (token == "+") {
                int var2 = expression.top();
                expression.pop();
                int var1 = expression.top();
                expression.pop();
                expression.push(var1+var2);
            }
            else if (token == "-") {
                int var2 = expression.top();
                expression.pop();
                int var1 = expression.top();
                expression.pop();
                expression.push(var1-var2);
            }
            else if (token == "*") {
                int var2 = expression.top();
                expression.pop();
                int var1 = expression.top();
                expression.pop();
                expression.push(var1*var2);
            }
            else if (token == "/") {
                int var2 = expression.top();
                expression.pop();
                int var1 = expression.top();
                expression.pop();
                expression.push(var1/var2);
            }
            else {
                expression.push(stoi(token));
            }
        }
        return expression.top();
    }
};
