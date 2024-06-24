//
// Created by wfx on 24-6-24.
//

#ifndef LEECODE_202_H
#define LEECODE_202_H
#include <unordered_map>
#include <unordered_set>

// leecode-202 快乐数

int sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += ((n % 10) * (n % 10));
        n = n / 10;
    }

    return sum;
}

// 核心思想：可能会无限循环，因此一定存在重复的数据
bool isHappy(int n) {
    std::unordered_set<int> map1;

    while ((n = sum(n)) != 1) {
        if (map1.contains(n)) {
            return false;
        }

        map1.insert(n);
    }

    return true;
}

#endif //LEECODE_202_H
