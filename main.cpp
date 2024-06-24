#include <iostream>
#include "LinkedList/leecode-24.h"
#include "LinkedList/leecode-19.h"

int main() {
    // ListNode *node1 = new ListNode(4);
    // ListNode *node2 = new ListNode(3, node1);
    ListNode *node3 = new ListNode(2, nullptr);
    ListNode *node4 = new ListNode(1, node3);

    removeNthFromEnd1(node4, 1);



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
