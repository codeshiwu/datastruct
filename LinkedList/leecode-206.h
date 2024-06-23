//
// Created by wfx on 24-6-23.
//

#ifndef LEECODE_206_H
#define LEECODE_206_H

#endif //LEECODE_206_H

#include "ListNode.h"

// 反转链表
ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // 只处理当前节点
    ListNode *newHead = nullptr;
    while (head != nullptr) {
        // 获取下一节点
        ListNode *nextNode = head->next;

        // 反转当前节点
        head->next = newHead;
        // 将当前节点设置为新的头节点
        newHead = head;
        // 链表节点后移
        head = nextNode;
    }

    return newHead;
}
