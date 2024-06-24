//
// Created by wfx on 24-6-24.
//

#ifndef LEECODE_454_H
#define LEECODE_454_H

#include <iostream>
#include <vector>

using namespace std;

//leecode-454  四数之和

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    std::unordered_map<int, int> map1;  // key为后两个数的和，value为次数
    for (auto num : nums1) {
        for (auto num1 : nums2) {
            map1[0 - num - num1]++;
        }
    }

    int count = 0;
    for (auto num : nums3) {
        for (auto num1 : nums4) {
            auto iter = map1.find(num + num1);
            if (iter != map1.end()) {
                count += iter->second;  // 此处为易错点，需要加iter—>second, 并非 count++;
            }
        }
    }
    return count;
}

#endif //LEECODE_454_H
