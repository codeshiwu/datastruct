//
// Created by macos on 24-7-19.
//

#ifndef LEECODE110_H
#define LEECODE110_H

#include <iostream>
#include "TreeNode.h"

// leecode110:判断二叉树是否为高度平衡二叉树
// 后序遍历：计算左右子树的高度差

int getHigh(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int lHigh = getHigh(root->left);
    if (lHigh == -1) {
        return -1;
    }
    int rHigh = getHigh(root->right);
    if (rHigh == -1) {
        return -1;
    }

    if (abs(rHigh - lHigh) > 1) {
        return -1;
    } else {
        return max(rHigh, lHigh) + 1;
    }
}

bool isBalanced(TreeNode* root) {
    return getHigh(root) != -1;
}

#endif //LEECODE110_H
