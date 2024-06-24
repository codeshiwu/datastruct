//
// Created by wfx on 24-6-25.
//

#ifndef LEECODE_383_H
#define LEECODE_383_H

// leecode383 赎金信

#include <iostream>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int buffer[26] = {0};
    for (auto i : magazine) {
        buffer[i - 'a']++;
    }

    for (auto i : ransomNote) {
        int count = buffer[i - 'a'];
        if (count == 0) {
            return false;
        }

        buffer[i - 'a']--;
    }

    return true;
}

bool canConstruct1(string ransomNote, string magazine) {
    int buffer[26] = {0};
    for (auto i : ransomNote) {
        buffer[i - 'a']++;
    }

    for (auto i : magazine) {
        buffer[i - 'a']--;
    }

    for (int i = 0; i < 26; ++i) {
        if (buffer[i] > 0) {
            return false;
        }
    }

    return true;
}

#endif //LEECODE_383_H
