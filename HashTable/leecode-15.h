//
// Created by wfx on 24-6-25.
//

#ifndef LEECODE_15_H
#define LEECODE_15_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// leecode 15 求三数之和为0的情况

// 哈希表方法解决
vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            return result;
        }

        // 第一个元素去重
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        std::unordered_set<int> set1;
        for (int j = i + 1; j < nums.size(); ++j) {
            // 第二个元素去重
            if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 2] == nums[j - 1]) {
                continue;
            }

            int c = 0 - nums[i] - nums[j];
            if (set1.find(c) != set1.end()) {
                result.push_back({nums[i], nums[j], c});
                set1.erase(c);  // 第三个元素去重
            } else {
                set1.insert(nums[j]);
            }
        }
    }
    return result;
}

// 双指针发
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            break;
        }

        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int beg = i + 1;
        int end = nums.size() - 1;
        while (beg < end) {
            int sum = nums[i] + nums[beg] + nums[end];
            if (sum == 0) {
                result.push_back({nums[i], nums[beg], nums[end]});
                while(end > beg && nums[beg] == nums[beg + 1]) beg++;
                while(end > beg && nums[end] == nums[end - 1]) end--;

                beg++;
                end--;
            } else if (sum > 0) {
                end--;
            } else {
                beg++;
            }
        }
    }

    return result;
}



#endif //LEECODE_15_H
