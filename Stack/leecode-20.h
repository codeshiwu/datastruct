//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_20_H
#define DATASTRUCT_LEECODE_20_H

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// leecode 20: 有效的括号
bool isValid(string s) {
    std::stack<char> stack1;

    for (auto &ch : s) {
        if (ch == '[' || ch == '{' || ch == '(') {
            stack1.push(ch);
            continue;
        }

        if (stack1.empty()) {
            return false;
        }

        auto ch1 = stack1.top();
        stack1.pop();

        if (ch == ']' && ch1 != '[') {
            return false;
        } else if (ch == '}' && ch1 != '{') {
            return false;
        } else if (ch == ')' && ch1 != '(') {
            return false;
        }
    }

    return stack1.empty();
}

#endif //DATASTRUCT_LEECODE_20_H
