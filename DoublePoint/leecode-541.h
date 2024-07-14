//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_541_H
#define DATASTRUCT_LEECODE_541_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void resverse(string &str, int beg, int end) {
    while (beg < end) {
        std::swap(str[beg++], str[end--]);
    }
}

string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
        if (i + k >= s.size()) {
            // 最后一组元素个数不满k个，反转所有字符
            resverse(s, i, s.size() - 1);
        } else {
            // 最后一组元素个数大于K个，反转前K个字符
            resverse(s, i, i + k - 1);
        }
    }

    return s;
}


#endif //DATASTRUCT_LEECODE_541_H
