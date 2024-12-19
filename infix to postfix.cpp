#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit function

using namespace std;

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if (isalnum(ch)) {
            // Append operands directly to postfix expression
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '('
        } else {
            // Operator encountered
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop all remaining operators
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> operands;

    for (size_t i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            // Push operand to stack
            operands.push(ch - '0'); // Convert char to int
        } else {
            // Operator encountered
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            operands.push(applyOperation(a, b, ch));
        }
    }

    return operands.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression (single-character operands): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;

    return 0;
}

