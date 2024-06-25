//
// Created by wfx on 24-6-25.
//

#ifndef LEECODE_344_H
#define LEECODE_344_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseString(vector<char>& s) {
    // int beg = 0, end = s.size() - 1;
    // while (beg < end) {
    //     std::swap(s[beg], s[end]);
    //     beg++;
    //     end--;
    // }

    for (int beg = 0, end = s.size() - 1; beg < end; beg++, end--) {
        std::swap(s[beg], s[end]);
    }
}

#endif //LEECODE_344_H
