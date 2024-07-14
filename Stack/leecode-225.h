//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_225_H
#define DATASTRUCT_LEECODE_225_H

#include <iostream>
#include <queue>


// leecode225 用两个栈实现队列

// 队列为先进先出，因此无论怎么处理都不可能变为栈的先进后厨，】
// 因此其中一个队列作为数据备份，pop时主队列只留最后一个元素，其他元素移入备份队列，操作结束后再移动回来

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        if (!queue2.empty()) {
            queue2.push(x);
            return;
        }
        queue1.push(x);
    }

    int pop() {
        while (queue1.size() > 1) {
            int value = queue1.front();
            queue1.pop();
            queue2.push(value);
        }

        int result = queue1.front();
        queue1.pop();

        while (!queue2.empty()) {
            int value = queue2.front();
            queue2.pop();
            queue1.push(value);
        }

        return result;
    }

    int top() {
        while (queue1.size() > 1) {
            int value = queue1.front();
            queue1.pop();
            queue2.push(value);
        }

        int result = queue1.front();
        queue1.pop();
        queue2.push(result);

        while (!queue2.empty()) {
            int value = queue2.front();
            queue2.pop();
            queue1.push(value);
        }

        return result;
    }

    bool empty() {
        return queue1.empty() && queue2.empty();
    }
private:
    std::queue<int> queue1;   // 主队列
    std::queue<int> queue2;   // 备份队列
};
#endif //DATASTRUCT_LEECODE_225_H
