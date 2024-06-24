//
// Created by wfx on 24-6-24.
//

#ifndef LEECODE_1_H
#define LEECODE_1_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// leecode-1 计算两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map1;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        map1[target - nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (map1.find(nums[i]) != map1.end() && i != map1[nums[i]]) {
            return vector<int>{i, map1[nums[i]]};
        }
    }

    return result;
}

// 改进版
vector<int> twoSum1(vector<int>& nums, int target) {
    unordered_map<int, int> map1;

    for (int i = 0; i < nums.size(); ++i) {
            auto iter = map1.find(nums[i]);
        if (iter == map1.end()) {
            map1[target - nums[i]] = i;
        } else {
            return vector<int>{i, iter->second};
        }
    }

    return vector<int>{};
}

#endif //LEECODE_1_H
