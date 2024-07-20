//
// Created by macos on 24-7-20.
//

#ifndef LEECODE112_H
#define LEECODE112_H

#include <iostream>
#include "TreeNode.h"

// leecode 112 计算是否有路径之和等于target
bool hasPathSum(TreeNode *root, int targetSum, int sum) {
    if (!root) {
        return false;
    }

    if (root->left == nullptr && root->right == nullptr) {
        if (sum + root->val == targetSum) {
            return true;
        }

        return false;
    }

    bool bRet1 = hasPathSum(root->left, targetSum, sum + root->val);
    if (bRet1) {
        return true;
    }
    bool bRet2 = hasPathSum(root->right, targetSum, sum + root->val);
    if (bRet2) {
        return true;
    }

    return bRet1 && bRet2;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return hasPathSum(root, targetSum, 0);
}

#endif //LEECODE112_H
