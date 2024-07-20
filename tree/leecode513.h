//
// Created by macos on 24-7-20.
//

#ifndef LEECODE513_H
#define LEECODE513_H

#include <iostream>
#include "TreeNode.h"

int maxLevel = INT_MIN;

void find(TreeNode * root, int level, int &result) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        if (level > maxLevel) {
            result = root->val;
            maxLevel = level;
        }
    }

    find(root->left, level + 1, result);
    find(root->right, level + 1, result);
}

int findBottomLeftValue(TreeNode* root) {
    int result;
    find(root, 0, result);
    return result;
}

#endif //LEECODE513_H
