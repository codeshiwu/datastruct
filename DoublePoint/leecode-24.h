//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_24_H
#define DATASTRUCT_LEECODE_24_H

#include <iostream>
#include "../LinkedList/ListNode.h"

// leecode24 两两交换链表中的节点


// 核心思路:分三步交换节点
// dummy->1->2->3->4->nullptr   cur: dummy firNode: 1 sedNode: 2
// 第一次交换 1->3
// 第二次交换 d->2
// 第三次交换 2->1    cur:1
ListNode* swapPairs(ListNode* head) {
    ListNode *dummyNode = new ListNode(0, head);

    ListNode *cur = dummyNode;
    while (cur != nullptr && cur->next != nullptr && cur->next->next != nullptr) {
        ListNode * firNode = cur->next;
        ListNode * secNode = firNode->next;

        firNode->next = secNode->next;
        cur->next = secNode;
        secNode->next = firNode;

        cur = firNode;
    }

    ListNode *result = dummyNode->next;
    delete dummyNode;
    return result;
}

#endif //DATASTRUCT_LEECODE_24_H
