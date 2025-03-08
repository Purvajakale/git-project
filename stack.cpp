#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> s;
    istringstream iss(expression);
    string token;
    while (iss >> token) {
        // Check if the token starts with a digit or a negative sign followed by a digit
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
            s.push(stoi(token));
        } else { // Otherwise, treat the token as an operator
            if (s.size() < 2) {
                cerr << "Error: insufficient operands for operator '" << token << "'" << endl;
                return 0;
            }
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (token[0]) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': 
                    if (b == 0) {
                        cerr << "Error: Division by zero" << endl;
                        return 0;
                    }
                    s.push(a / b); 
                    break;
                default:
                    cerr << "Error: Unknown operator '" << token << "'" << endl;
                    return 0;
            }
        }
    }
    if (s.size() != 1) {
        cerr << "Error: Invalid postfix expression" << endl;
        return 0;
    }
    return s.top();
}

int main() {
    string expression;
    cout << "Enter a postfix expression (tokens separated by spaces): ";
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << "Result of postfixxxxxxxxxxxxxxx expression is: " << result << endl;

    return 0;
}