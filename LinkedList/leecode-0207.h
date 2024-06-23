//
// Created by wfx on 24-6-23.
//

#ifndef LEECODE_0207_H
#define LEECODE_0207_H

// leecode-02.07 计算两链表是否相交
#include "ListNode.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA = headA, *nodeB = headB;

    while (nodeA != nodeB) {
        // 当两个链表同时遍历完成后，一定会相等，若不为null，则是交点，反之则没有交点
        nodeA = nodeA == nullptr ? headB : nodeA->next;
        nodeB = nodeB == nullptr ? headA : nodeB->next;
    }

    return nodeA;
}

#endif //LEECODE_0207_H
