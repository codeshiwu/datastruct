//
// Created by wfx on 24-6-23.
//

#include "List.h"

ListNode *List::removeElements(ListNode *head, int val) {
    if (nullptr == head) {
        return nullptr;
    }

    // 不使用头节点
    while (head != nullptr && head->val == val) {
        ListNode *node = head;
        head = head->next;
        delete node;
    }

    ListNode *node = head;
    while (node != nullptr && node->next != nullptr) {
        ListNode *nextNode = node->next;
        if (nextNode->val == val) {
            node->next = node->next->next;
            delete nextNode;
        } else {
            node = node->next;
        }
    }

    return head;
}




