#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to prefix notation
string infixToPrefix(string infix) {
    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Stack to hold operators
    stack<char> operators;

    // Output string
    string prefix = "";

    // Scan the infix expression from left to right
    for (char& c : infix) {
        // If character is an operand, add it to the output
        if (isalnum(c)) {
            prefix += c;
        }
        // If character is an operator
        else if (isOperator(c)) {
            // Pop operators from the stack and add them to the output until a lower precedence operator is encountered
            while (!operators.empty() && precedence(operators.top()) > precedence(c)) {
                prefix += operators.top();
                operators.pop();
            }
            // Push the current operator onto the stack
            operators.push(c);
        }
        // If character is a parenthesis
        else if (c == ')') {
            operators.push(c);
        }
        else if (c == '(') {
            // Pop operators from the stack and add them to the output until a closing parenthesis is encountered
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            // Discard the closing parenthesis
            operators.pop();
        }
    }

    // Pop any remaining operators from the stack and add them to the output
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    // Reverse the output to obtain the prefix notation
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infix = "4 + 8 * 1 - 4 / 2";
    string prefix = infixToPrefix(infix);
    cout << "Prefix notation: " << prefix << endl;
    return 0;
}
