//
// Created by wfx on 24-6-25.
//

#ifndef LEECODE_151_H
#define LEECODE_151_H

#include <iostream>
#include <string>

using namespace std;

// leecode151 反转字符串中的单词，单词为非空格组成的字符串
// 注意：反转后的字符串两边不能出现空格字符串

/**
 * 移除字符串两边及单词间的多余空格
 * @param s 字符串
 */
void removeExtraSpace(string &s) {
    int slow = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            // 只处理不是空格的字符
            if (slow != 0) {
                // 单词间手动添加空格
                s[slow++] = ' ';
            }

            // 当前字符不是空格，则复制其后的整个单词
            while (i < s.size() && s[i] != ' ') {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

/**
 * 双指针反转字符串
 * @param beg 开始下标
 * @param end 结束下标
 * @param s 字符串
 */
void reverse(int beg, int end, string &s) {
    for (int i = beg, j = end; i < j; ++i, --j) {
        std::swap(s[i], s[j]);
    }
}

string reverseWords(string s) {
    removeExtraSpace(s);
    reverse(0, s.size() - 1, s);

    int beg = 0;
    for (int i = 0; i <= s.size(); ++i) {
        // 易错点1: 此处需要考虑最后一个单词的情况，仅凭s[i] == ' '是不够的
        //         i == s.size()要放在前面，防止字符串结束时下标访问溢出
        if (i == s.size() || s[i] == ' ') {
            reverse(beg, i - 1, s);

            // 易错点2: 不要写成 beg += i + 1
            beg = i + 1;
        }
    }

    return s;
}

#endif //LEECODE_151_H
