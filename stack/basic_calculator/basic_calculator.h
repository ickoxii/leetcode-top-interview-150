 /* Given a string s representing a valid expression,
  * implement a basic calculator to evaluate it, and
  * return the result of the evaluation. */

class Solution {
private:
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


public:
    int calculate(string s) {
        vector<string> postfix;
        // convert to postfix
        stack<char> operators;
        int currNum = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case 40: // '('
                    operators.push(s[i]);
                    break;
                case 41: // ')'
                    while (!operators.empty() && operators.top() != '(') {
                        string c = operators.top();
                        operators.pop();
                        postfix.push_back(c);
                    }
                    if (!operators.empty()) {
                        operators.pop();
                    }
                    break;
                case 42: // '*'
                case 43: // '+'
                case 45: // '-'
                case 47: // '/'
                    operators.push(s[i]);
                    break;
                default:
                    while (isdigit(s[i]) && i < s.size()) {
                        currNum += s[i] - 48;
                        i++;
                    }
                    postfix.push_back(to_string(currNum));
                    if (i < s.size()) {
                        i--;
                    }
                    break;
            }
        }

        while (!operators.empty()) {
            string c = operators.top();
            operators.pop();
            postfix.push_back(c);
        }
        
        return evalRPN(postfix);; 
    }
};
