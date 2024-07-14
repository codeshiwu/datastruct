//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_151_H
#define DATASTRUCT_LEECODE_151_H

#include <iostream>
#include <string>

using namespace std;

// leecode 151 反转字符串中的单词
// 核心思路：1.去除多余空格 2.反转整个字符串 3.反转单个单词
void removeSpace(std::string &str) {
    int slow = 0;
    for (int i = 0; i < str.size(); ++i) {
        // 只处理非空格字符
        if (str[i] == ' ') {
            continue;
        }

        if (slow != 0) {
            str[slow++] = ' ';
        }

        while (i < str.size() && str[i] != ' ') {
            str[slow++] = str[i++];
        }
    }

    str.resize(slow);
}

void reverse(std::string &str, int beg, int end) {
    while (beg < end) {
        std::swap(str[beg++], str[end--]);
    }
}

string reverseWords(string s) {
    removeSpace(s);
    reverse(s, 0, s.size() - 1);

    int beg = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i == s.size() - 1 || s[i + 1] == ' ') {
            reverse(s, beg, i);
            beg = i + 2;
        }
    }

    return s;
}



#endif //DATASTRUCT_LEECODE_151_H
