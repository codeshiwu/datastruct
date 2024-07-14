//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_27_H
#define DATASTRUCT_LEECODE_27_H

#include <iostream>
#include <vector>

using namespace std;


// leecode-27 删除nums中所有等于val的元素，并返回nums的剩余数量
int removeElement(vector<int>& nums, int val) {
    int fastIndex = 0, slowIndex = 0;
    for (; fastIndex < nums.size(); ++fastIndex) {
        if (nums[fastIndex] != val) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }

    return slowIndex--;
}

#endif //DATASTRUCT_LEECODE_27_H
