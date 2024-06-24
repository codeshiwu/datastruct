//
// Created by wfx on 24-6-24.
//

#ifndef LEECODE_349_H
#define LEECODE_349_H

#include<iostream>
#include<vector>

#include <unordered_map>
#include <unordered_set>

using namespace std;

// leecode-349 两个数组的交集
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_map<int, int> map1;
    std::unordered_set<int> result;

    for (auto num : nums1) {
        map1[num]++;
    }

    for (auto num : nums2) {
        auto iter = map1.find(num);
        if (iter != map1.end()) {
            result.insert(num);
        }
    }

    return std::vector<int>(result.begin(), result.end());
}

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
    int arr[1001] = { 0 };

    std::unordered_set<int> result;
    for (auto num : nums1) {
        arr[num]++;
    }

    for (auto num : nums2) {
        if (arr[num] > 0) {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}



#endif //LEECODE_349_H
