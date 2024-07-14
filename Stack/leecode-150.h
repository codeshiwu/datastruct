//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_150_H
#define DATASTRUCT_LEECODE_150_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// leecode150 计算逆波兰表达式
int calc(std::string &calc, int first, int second) {
    if (calc == "+") {
        return first + second;
    } else if (calc == "-") {
        return first - second;
    } else if (calc == "/") {
        return first / second;
    } else if (calc == "*") {
        return first * second;
    }
}

int evalRPN(vector<string>& tokens) {
    std::stack<int> stack1;

    for (auto &str : tokens) {
        if (str != "+" && str != "-" && str != "*" && str != "/") {
            stack1.push(std::stoi(str));
            continue;
        }

        auto second = stack1.top(); stack1.pop();
        auto first = stack1.top(); stack1.pop();
        stack1.push(calc(str, first, second));
    }

    return stack1.empty() ? 0 : stack1.top();
}

#endif //DATASTRUCT_LEECODE_150_H
