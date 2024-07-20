//
// Created by macos on 24-7-20.
//

#ifndef LEECODE106_H
#define LEECODE106_H

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

// leecode 106 根据中序和后序遍历顺序构造二叉树
// 思路：后序遍历的最后一个元素是树的根节点，用根节点去分割中序遍历的元素，然后分割后序遍历，最后形成两组新的vector，执行上述操作
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty()) {
        return nullptr;
    }

    if (inorder.size() == 1) {
        return new TreeNode(inorder[0]);
    }

    int rootVal = postorder.back();

    int rootIndex = 0;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == rootVal) {
            rootIndex = i; break;
        }
    }

    std::vector<int> inorderL = std::vector<int>(inorder.begin(), inorder.begin() + rootIndex);
    std::vector<int> inorderR = std::vector<int>(inorder.begin() + rootIndex + 1, inorder.end());

    std::vector<int> postorderL = std::vector<int>(postorder.begin(), postorder.begin() + inorderL.size());
    std::vector<int> postorderR = std::vector<int>(postorder.begin() + inorderL.size(), postorder.begin() + inorderL.size() + inorderR.size());

    TreeNode *lNode = buildTree(inorderL, postorderL);
    TreeNode *rNode = buildTree(inorderR, postorderR);

    return new TreeNode(rootVal, lNode, rNode);
}

#endif //LEECODE106_H
