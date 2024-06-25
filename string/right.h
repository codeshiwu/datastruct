//
// Created by wfx on 24-6-26.
//

#ifndef RIGHT_H
#define RIGHT_H

#include <iostream>
#include <string>

using namespace std;

void reverse(int beg, int end, string &s) {
    for (int i = beg, j = end; i < j; ++i, --j) {
        swap(s[i], s[j]);
    }
}

/**
 * 右旋字符串的倒数n个字符
 * 如： abcde k=2   ---》 deabc
 * @param k
 * @param s
 */
void rightReverse(int k, string &s) {
    reverse(0, s.size() - 1, s);
    reverse(0, k - 1, s);
    reverse(k, s.size() - 1, s);
}

#endif //RIGHT_H
