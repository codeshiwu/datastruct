//
// Created by macos on 24-7-19.
//

#ifndef LEECODE_102_H
#define LEECODE_102_H



#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

// leecode102 二叉树的层序遍历

vector<vector<int>> levelOrder(TreeNode *root) {
    std::queue<TreeNode*> queue1;

    std::vector<std::vector<int>> result;
    if (root == nullptr) {
        return result;
    }

    queue1.push(root);
    while (!queue1.empty()) {
        int size = queue1.size();

        std::vector<int> vec1;
        for (int i = 0; i < size; ++i) {
            TreeNode *cur = queue1.front();
            queue1.pop();

            vec1.emplace_back(cur->val);
            if (cur->left) {
                queue1.push(cur->left);
            }

            if (cur->right) {
                queue1.push(cur->right);
            }
        }

        result.push_back(item);
    }

    return result;
}

#endif //LEECODE_102_H
