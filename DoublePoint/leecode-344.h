//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_344_H
#define DATASTRUCT_LEECODE_344_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int fast = s.size() - 1, slow = 0;
    while (slow < fast) {
        std::swap(s[fast], s[slow]);
        fast--;  slow++;
    }
}

#endif //DATASTRUCT_LEECODE_344_H
