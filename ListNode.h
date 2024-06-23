//
// Created by wfx on 24-6-23.
//

#ifndef LISTNODE_H
#define LISTNODE_H

#endif //LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};
