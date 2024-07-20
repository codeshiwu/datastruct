//
// Created by macos on 24-7-19.
//

#ifndef LEECODE222_H
#define LEECODE222_H

#include <iostream>
#include "TreeNode.h"


// leecode 222 计算完全二叉树的节点个数
// 思路1：普通全部遍历
// 思路2: 利用满二叉树的节点个数性质

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int lHigh = 0, rHigh = 0;

    TreeNode *cur = root;
    while (cur != nullptr) {
        lHigh++;
        cur = cur->left;
    }

    cur = root;
    while (cur != nullptr) {
        rHigh++;
        cur = cur->right;
    }

    if (lHigh == rHigh) {
        // 说明是满二叉树
        return (1 << lHigh)  - 1;
    } else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}
#endif //LEECODE222_H
