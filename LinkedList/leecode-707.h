//
// Created by wfx on 24-6-23.
//

#ifndef LEECODE_707_H
#define LEECODE_707_H

#endif //LEECODE_707_H

#include "ListNode.h"

// leecode 设计链表
class MyLinkedList {
public:
    /**
     * 构造函数
     */
    MyLinkedList() {
        dummyNode = new ListNode();
    }

    // 2. 获取指定位置的元素
    int get(int index) {
        ListNode *node = getNode(index);
        return node == nullptr ? -1 : node->val;
    }

    void addAtHead(int val) {
        ListNode *newHead = new ListNode(val, dummyNode->next);
        dummyNode->next = newHead;
    }

    void addAtTail(int val) {
        ListNode *newTail = new ListNode(val);

        ListNode *tail = dummyNode;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newTail;
    }

    void addAtIndex(int index, int val) {
        ListNode *preNode = getNode(index - 1);
        if (nullptr != preNode) {
            ListNode *newNode = new ListNode(val, preNode->next);
            preNode->next = newNode;
        }
    }

    void deleteAtIndex(int index) {
        ListNode *preNode = getNode(index - 1);
        if (nullptr != preNode) {
            ListNode *node = preNode->next;
            if (node != nullptr) {
                preNode->next = node->next;
                delete node;
            }
        }
    }

private:
    ListNode *getNode(int index) {
        if (index == -1) {
            return dummyNode;
        }

        ListNode *node = dummyNode;
        for (int i = 0; i <= index; ++i) {
            if (node == nullptr) {
                break;
            }

            node = node->next;
        }

        return node;
    }
private:
    ListNode *dummyNode;   // 虚拟头节点
};