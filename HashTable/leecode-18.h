//
// Created by wfx on 24-6-25.
//

#ifndef LEECODE_18_H
#define LEECODE_18_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// leecode18 求四数之和
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > target && nums[i] >= 0) {
            break;
        }

        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                break;
            }

            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int beg = j + 1;
            int end = nums.size() - 1;
            while (beg < end) {
                long sum = (long)nums[i] + nums[j] + nums[beg] + nums[end];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[beg], nums[end]});

                    while (beg < end && nums[beg] == nums[beg + 1]) beg++;
                    while (beg < end && nums[end] == nums[end - 1]) end--;

                    beg++; end--;
                } else if (sum > target) {
                    end--;
                } else {
                    beg++;
                }
            }
        }
    }

    return result;
}

#endif //LEECODE_18_H
