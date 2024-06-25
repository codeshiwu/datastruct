//
// Created by wfx on 24-6-25.
//

#ifndef LEECODE_541_H
#define LEECODE_541_H

#include <iostream>
#include <string>

using namespace std;

string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
        if (s.size() - i < k) {
            // 剩余元素小于K，反转全部字符串
            std::reverse(s.begin() + i, s.end());
        } else {
            // 剩余元素大于等于K，反转前n个字符
            std::reverse(s.begin() + i, s.begin() + i + k);
        }
    }

    return s;
}

#endif //LEECODE_541_H
