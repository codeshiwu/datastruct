//
// Created by wfx on 24-6-23.
//

#ifndef LEECODE_142_H
#define LEECODE_142_H

// leecode142 判断链表是否成环，若为环则计算入口，反之则返回null
#include "ListNode.h"

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode *dummyNode = new ListNode(0, head);

    ListNode *fastNode = dummyNode;
    ListNode *slowNode = dummyNode;

    bool loop = false;
    while (fastNode != nullptr && fastNode->next != nullptr) {
        ListNode *fastNode = loop ? fastNode->next : fastNode->next->next;
        ListNode *slowNode = slowNode->next;

        if (fastNode == slowNode) {
            if (loop) {
                return fastNode;
            }
            // 说明有环
            slowNode = dummyNode;
            loop = true;
        }
    }

    return nullptr;
}

#endif //LEECODE_142_H
