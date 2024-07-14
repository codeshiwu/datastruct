//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_0207_H
#define DATASTRUCT_LEECODE_0207_H

#include <iostream>
#include "../LinkedList/ListNode.h"

// 思路：将两链表拼接在一起后，第一次遍历完成后，若两者相等且等于nullptr，则说明不相交，反之则相交
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA = headA, *nodeB = headB;

    while (nodeA != nodeB) {
        nodeA = nodeA == nullptr ? headB : nodeA->next;
        nodeB = nodeB == nullptr ? headA : nodeB->next;
    }

    return nodeA;
}

#endif //DATASTRUCT_LEECODE_0207_H
