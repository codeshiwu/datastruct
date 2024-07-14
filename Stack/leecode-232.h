//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_232_H
#define DATASTRUCT_LEECODE_232_H

#include <iostream>
#include <stack>

// leecode232 用两个栈来实现队列
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stack1_.push(x);
    }

    int pop() {
        if (stack2_.empty()) {
            while (!stack1_.empty()) {
                int value = stack1_.top();
                stack1_.pop();
                stack2_.push(value);
            }
        }

        int value = stack2_.top();
        stack2_.pop();
        return value;
    }

    int peek() {
        if (stack2_.empty()) {
            while (!stack1_.empty()) {
                int value = stack1_.top();
                stack1_.pop();
                stack2_.push(value);
            }
        }

        int value = stack2_.top();
        return value;
    }

    bool empty() {
        return stack1_.empty() && stack2_.empty();
    }
private:
    std::stack<int> stack1_;
    std::stack<int> stack2_;
};

#endif //DATASTRUCT_LEECODE_232_H
