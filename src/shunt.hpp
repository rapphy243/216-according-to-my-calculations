#include <cctype>
#include <string>
#include "stack.hpp"
#include "queue.hpp"

int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*') {
        return 2;
    } else if (c == '/') {
        return 3;
    }
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string infixToPostfix(const std::string& infix) {
    Stack<char> stack;
    Queue<char> output;
    bool expectOperand = true;

    for (char c : infix) {
        if (std::isspace(c)) {
            continue; // Ignore whitespace
        }

        if (std::isdigit(c)) {
            if (!expectOperand) {
                return "";
            }
            output.enqueue(c);
            expectOperand = false;
        }
        else if (c == '(') {
            if (!expectOperand) {
                return "";
            }
            stack.push(c);
            expectOperand = true;
        }
        else if (c == ')') {
            if (expectOperand) {
                return "";
            }
            while (!stack.isEmpty() && stack.top() != '(') {
                output.enqueue(stack.pop());
            }
            if (stack.isEmpty()) {
                return "";
            }
            stack.pop(); // Remove the '(' from the stack
            expectOperand = false;
        } else if (isOperator(c)) {
            if (expectOperand) {
                return "";
            }
            while (!stack.isEmpty() && stack.top() != '(' && priority(stack.top()) >= priority(c)) { 
                output.enqueue(stack.pop());
            }
            stack.push(c);
            expectOperand = true;
        } else {
            return "";
        }
    }

    if (expectOperand) { // last character was an operator, the expression is invalid
        return "";
    }

    while (!stack.isEmpty()) { // Pop all the operators from the stack
        if (stack.top() == '(') { 
            return "";
        }
        output.enqueue(stack.pop());
    }

    std::string postfix;
    while (!output.isEmpty()) {
        postfix += output.dequeue();
    }

    return postfix;
}
