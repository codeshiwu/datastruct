//
// Created by macos on 24-7-19.
//

#ifndef LEECODE101_H
#define LEECODE101_H

#include <iostream>
#include "TreeNode.h"

// 判断二叉树是否轴对称

bool compare(TreeNode *lNode, TreeNode *rNode) {
    if (lNode == nullptr && rNode == nullptr) {
        return true;
    } else if (lNode == nullptr && rNode != nullptr) {
        return false;
    } else if (lNode != nullptr && rNode == nullptr) {
        return false;
    } else if (lNode->val != rNode->val) {
        return false;
    }

    bool outSide = compare(lNode->left, rNode->right);
    if (!outSide) {
        return false;
    }
    bool inSide = compare(lNode->right, rNode->left);
    if (!inSide) {
        return false;
    }

    return outSide && inSide;
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return false;
    }

    return compare(root->left, root->right);
}

#endif //LEECODE101_H
