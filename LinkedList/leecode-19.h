//
// Created by wfx on 24-6-23.
//

#ifndef LEECODE_19_H
#define LEECODE_19_H

// leecode-19 删除链表的倒数第n个节点

#include "ListNode.h"

// 普通方式，首先计算链表的长度，然后根据与n的差值前向遍历，从而获取待删除元素的前一个元素
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode *node = head;
    while (node != nullptr) {
        size++;
        node = node->next;
    }

    size = size - n;
    ListNode *dummyNode = new ListNode(0, head);
    node = dummyNode;
    for (int i = 0; i < size; ++i) {
        node = node->next;
    }

    node->next = node->next->next;
    node = dummyNode->next;
    delete dummyNode;

    return node;
}

// 利用快慢指针
ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode *dummyNode = new ListNode(0, head);
    ListNode *fastNode = dummyNode, *slowNode = dummyNode;

    for (int i = 0; i < n; ++i) {
        fastNode = fastNode ->next;
    }

    // 遍历至链表的最后一个节点
    while (fastNode != nullptr && fastNode->next != nullptr) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }

    slowNode->next = slowNode->next->next;
    ListNode *result = dummyNode->next;
    delete dummyNode;

    return result;
}



#endif //LEECODE_19_H
