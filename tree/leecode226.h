//
// Created by macos on 24-7-19.
//

#ifndef LEECODE226_H
#define LEECODE226_H

#include <future>

#include "TreeNode.h"

// leecode 226 翻转二叉树

// 后序遍历:
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    invertTree(root->left);
    invertTree(root->right);

    std::swap(root->left, root->right);
    return root;
}

#endif //LEECODE226_H
