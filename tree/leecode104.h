//
// Created by macos on 24-7-19.
//

#ifndef LEECODE104_H
#define LEECODE104_H

#include <iostream>
#include "TreeNode.h"

// leecode104 计算二叉树的最大深度

int maxDep = INT_MIN;

void maxDepth(TreeNode *root, int depth) {
    if (root == nullptr) {
        if (depth > maxDep) {
            maxDep = depth;
        }

        return;
    }

    maxDepth(root->left, depth + 1);
    maxDepth(root->right, depth + 1);
}

int maxDepth(TreeNode* root) {
    maxDepth(root, 0);
    return maxDep;
}

#endif //LEECODE104_H
