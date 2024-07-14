//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_142_H
#define DATASTRUCT_LEECODE_142_H

#include <iostream>
#include "../LinkedList/ListNode.h"

// leecode142 判断链表是否存在环，若存在找出环的入口

// 为什么要使用虚拟头节点? 处理入环节点为头节点的问题
// 若头节点为入环节点，则需要额外处理，若使用虚拟节点，则不用额外处理即可
ListNode *detectCycle(ListNode *head) {
    ListNode *dummyNode = new ListNode(0, head);
    ListNode *fast = dummyNode, *slow = dummyNode;

    ListNode *result = nullptr;
    bool cycle = false;
    while (fast != nullptr && fast->next != nullptr) {
        fast = cycle ? fast->next : fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            if (cycle) {
                result = fast;
                break;
            }

            cycle = true;
            slow = dummyNode;
        }
    }

    delete dummyNode;
    return result;
}

#endif //DATASTRUCT_LEECODE_142_H
