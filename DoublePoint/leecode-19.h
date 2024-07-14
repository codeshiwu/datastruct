//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_19_H
#define DATASTRUCT_LEECODE_19_H

#include <iostream>
#include "../LinkedList/ListNode.h"

// leecode-19 删除链表的倒数第n个节点

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummyNode = new ListNode(0, head);
    ListNode *cur = dummyNode, *preNode = dummyNode;

    int k = n + 1;
    while (cur != nullptr && k--) {
        cur = cur->next;
    }

    while (cur != nullptr) {
        cur = cur->next;
        preNode = preNode->next;
    }

    ListNode *delNode = preNode->next;
    preNode->next = delNode->next;
    delete delNode;

    ListNode *result = dummyNode->next;
    delete dummyNode;

    return result;
}

#endif //DATASTRUCT_LEECODE_19_H
