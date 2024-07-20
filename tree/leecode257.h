//
// Created by macos on 24-7-20.
//

#ifndef LEECODE257_H
#define LEECODE257_H

#include <iostream>
#include <vector>
#include "TreeNode.h"

// leecode257 计算二叉树的全部路径
// 使用前序遍历

using namespace std;

void getPaths(TreeNode *root, std::string path, std::vector<std::string> &paths) {
    if (root == nullptr) {
        return;
    }

    path += std::to_string(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        paths.emplace_back(std::move(path));
        return;
    }

    getPaths(root->left, path + "->", paths);
    getPaths(root->right, path + "->", paths);
}

vector<string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> paths;
    getPaths(root, "", paths);
    return paths;
}

#endif //LEECODE257_H
