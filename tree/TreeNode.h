//
// Created by macos on 24-7-19.
//

#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int val) : val(val), left(nullptr), right(nullptr){}
    TreeNode (int val, TreeNode *left) : val(val), left(left), right(nullptr){}
    TreeNode (int val, TreeNode *left,  TreNode *right) : val(val), left(left), right(right){}
};

#endif //TREENODE_H
