#include <cmath>
#include <cctype>
#include <string>
#include "shunt.hpp"

double evaluate(const std::string& infix) {
    Stack<double> stack;
    std::string postfix = infixToPostfix(infix);

    for (char c : postfix) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            stack.push(std::stod(std::string(1, c)));
        } else {
            double b = stack.pop();
            double a = stack.pop();
            switch (c) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                case '^':
                    stack.push(std::pow(a, b));
                    break;
            }
        }
    }

    return stack.pop();
}
