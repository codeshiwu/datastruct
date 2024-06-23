//
// Created by wfx on 24-6-23.
//

#ifndef LEECODE_24_H
#define LEECODE_24_H

// leecode24 两两交换链表中的节点
// 交换前 1-2-3-4
// 交换后 2-1-4-3

#include "ListNode.h"

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    int index = 0;
    ListNode *node = head;
    ListNode *lastNode = nullptr;  // 最近的偶数下标节点，下标从0开始，反转之后为新链表中最近的奇数下标节点
    ListNode *newHead = node->next == nullptr ? node : node->next;
    while (node != nullptr) {
        ListNode *nextNode = node->next;
        // 偶数下标处理
        if (index % 2 == 0) {
            // 如果偶数节点为最后一个节点，则保持原状
            if (nextNode == nullptr) {
                break;
            }

            // 若不是第一组需交换数据 如：1->2->3->4 中的 3->4交换
            // 则需要将 1的next指向4
            if (lastNode != nullptr) {
                lastNode->next = nextNode;
            }

            // 记录最近的偶数下标节点，方便奇数节点反转
            lastNode = node;

            // 修改偶数节点的next
            node->next = nextNode->next;
        } else {
            node->next = lastNode;
        }

        node = nextNode; index++;
    }

    return newHead;
}

// 方法2:使用了虚拟头节点，并将步进设置为两个节点
ListNode* swapPairs_dummyNode(ListNode* head) {
    ListNode *dummyNode = new ListNode(0, head);

    ListNode *node = dummyNode;
    while (node != nullptr && node->next != nullptr && node->next->next != nullptr) {
        // node为前置节点
        ListNode *tempNode = node->next->next;  // 节点2
        ListNode *nextNode = node->next;        // 节点1

        // dummy->1->2->3->4
        node->next = tempNode;            // dummy->2->3->4  和 1->2->3->4
        nextNode->next = tempNode->next;  // dummy->2->3->4  和 1->3->4
        tempNode->next = nextNode;        // dummy->2->1->3->4

        node = node->next->next;
    }

    node = dummyNode->next;
    delete dummyNode;
    return node;
}


#endif //LEECODE_24_H
