//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_239_H
#define DATASTRUCT_LEECODE_239_H

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class MyQueue {
public:
    int front() {
        return deque1.front();
    }

    void pop(int x) {
        int val = front();
        if (val == x) {
            deque1.pop_front();
        }
    }

    void push(int x) {
        while (!deque1.empty() && deque1.back() < x) {
            deque1.pop_back();
        }

        deque1.push_back(x);
    }
private:
    std::deque<int> deque1;
};

// leecode239 计算滑动窗口的最大值, k为滑动窗口的大小
// 思路：使用一个双端队列来存储可能成为滑动窗口最大值的内容，并随着滑动窗口的移动修改队列内容，这里采用的数据结构为deque
// pop: 当滑动窗口要删除的值等于最大值，则将其从队列中删除，否则不做处理
// push: 当滑动窗口要加入的值大于队列尾部元素，则循环删除队列尾部元素，并将此元素入队列。
//       tips:队列中存储的是滑动窗口的最大值，或者可能成为最大值的元素。
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    std::vector<int> result;

    MyQueue queue1;
    for (int i = 0; i < k; ++i) {
        queue1.push(nums[i]);
    }
    result.push_back(queue1.front());

    int slow = 0, fast = k;
    for (; fast < nums.size(); ++fast) {
        queue1.pop(nums[slow++]);
        queue1.push(nums[fast]);
        result.push_back(queue1.front());
    }
    return result;

}

#endif //DATASTRUCT_LEECODE_239_H
