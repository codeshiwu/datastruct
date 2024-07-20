//
// Created by macos on 24-7-20.
//

#ifndef LEECODE654_H
#define LEECODE654_H

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

// leecode654 构建最大二叉树
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }

    if (1 == nums.size()) {
        return new TreeNode(nums[0]);
    }

    int root = INT_MIN, rootIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > root) {
            root = nums[i];
            rootIndex = i;
        }
    }

    std::vector<int> vecL = std::vector<int>(nums.begin(), nums.begin() + rootIndex);
    std::vector<int> vecR = std::vector<int>(nums.begin() + rootIndex + 1, nums.end());

    return new TreeNode(root, constructMaximumBinaryTree(vecL), constructMaximumBinaryTree(vecR));
}

#endif //LEECODE654_H
