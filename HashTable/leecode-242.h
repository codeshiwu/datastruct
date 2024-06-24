//
// Created by wfx on 24-6-24.
//

#ifndef LEECODE_242_H
#define LEECODE_242_H

#include <iostream>
#include <string>

using namespace std;

// leecode-242 计算两个字符串是否是字母异或词
bool isAnagram(string s, string t) {
    int buffer[26];

    for (auto i : s) {
        buffer[i - 'a']++;
    }

    for (auto i : t) {
        buffer[i - 'a']--;
    }

    for (int i = 0; i < 26; ++i) {
        if (buffer[i] != 0) {
            return false;
        }
    }

    return true;
}

#endif //LEECODE_242_H
