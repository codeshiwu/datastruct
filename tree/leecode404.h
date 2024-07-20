//
// Created by macos on 24-7-20.
//

#ifndef LEECODE404_H
#define LEECODE404_H

#include <iostream>
#include "TreeNode.h"

// leecode404 计算左叶子节点之和
int sum(TreeNode *root, bool bLeft) {
    if (root == nullptr) {
        return 0;
    }

    if (bLeft && !root->left && !root-> right) {
        return root->val;
    }

    int lSum = sumOfLeftLeaves(root->left, true);
    int rSum = sumOfLeftLeaves(root->right, false);

    return lSum + rSum;
}

int sumOfLeftLeaves(TreeNode* root) {
    return sum(root, false);
}

#endif //LEECODE404_H
