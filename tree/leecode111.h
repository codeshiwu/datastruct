//
// Created by macos on 24-7-19.
//

#ifndef LEECODE111_H
#define LEECODE111_H

#include <iostream>
#include "TreeNode.h"

// leecode 111 计算二叉树的最小深度
/*int minDep = INT_MAX;
void minDepth(TreeNode *root, int depth) {
    if (root->left == nullptr && root->right == nullptr) {
        if (depth < minDep) {
            minDep = depth;
        }

        return;
    }

    if (root->left) minDepth(root->left, depth + 1);
    if (root->right) minDepth(root->right, depth + 1);
}

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    minDepth(root, 1);
    return minDep;
}*/

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    int depth1 = minDepth(root->left);
    int depth2 = minDepth(root->right);

    if (!root->left || !root->right) {
        return depth1 + depth2 + 1;
    }

    return std::min(depth1, depth2) + 1;
}

#endif //LEECODE111_H
