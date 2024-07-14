//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_1047_H
#define DATASTRUCT_LEECODE_1047_H

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// leecode1047 删除字符串中相邻的重复字符，直接无法删除为止
// 思路：我们要比较当前元素与前一元素是否相等，因此用栈数据结构
string removeDuplicates(string s) {
    std::stack<char> stack1;

    for (auto &ch : s) {
        if (stack1.empty()) {
            stack1.push(ch);
            continue;
        }

        auto ch1 = stack1.top();
        if (ch1 != ch) {
            stack1.push(ch);
        } else {
            stack1.pop();
        }
    }

    std::string str;
    for (int i = stack1.size() - 1; i >= 0; --i) {
        str += stack1.top();
        stack1.pop();
    }

    std::reverse(str.begin(), str.end());
    return str;
}

// 使用字符串自带的类似入栈出栈操作
string removeDuplicates1(string s) {
    std::string result;
    for (auto &ch : s) {
        if (!result.empty() && ch == result.back()) {
            result.pop_back();
            continue;
        } else {
            result.push_back(ch);
        }
    }

    return result;
}

#endif //DATASTRUCT_LEECODE_1047_H
