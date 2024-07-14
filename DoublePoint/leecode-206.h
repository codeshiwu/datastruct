//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_206_H
#define DATASTRUCT_LEECODE_206_H

#include <iostream>
#include "../LinkedList/ListNode.h"

ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while (cur) {
        ListNode *temp = cur->next;

        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

#endif //DATASTRUCT_LEECODE_206_H
