#include <iostream>
#include <stack>
using namespace std;

// Check if a character is a valid operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Check if a character is a digit
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

// Validate the expression
bool isValidExpression(const string& expr) {
    for (size_t i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Check for invalid characters
        if (!isDigit(ch) && !isOperator(ch) && ch != ' ' && ch != '(' && ch != ')') {
            return false;
        }

        // Check operator placement
        if (isOperator(ch)) {
            // Operator at start or end is invalid
            if (i == 0 || i == expr.length() - 1) {
                return false;
            }
            // Check if operator is between valid operands
            char prev = expr[i - 1];
            char next = expr[i + 1];
            if (!isDigit(prev) && prev != ')' && !isDigit(next) && next != '(') {
                return false;
            }
        }
    }

    // Check balanced parentheses
    stack<char> st;
    for (char ch : expr) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isValidExpression(expr)) {
        cout << "Valid Expression" << endl;
    } else {
        cout << "Invalid Expression" << endl;
    }

    return 0;
}