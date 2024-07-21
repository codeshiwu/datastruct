//
// Created by macos on 24-7-21.
//

#ifndef LEECODE70_H
#define LEECODE70_H

#include <iostream>
#include <vector>

// leecode70 爬楼梯

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }

    std::vector<int> vec1(n + 1);
    vec1[1] = 1;
    vec1[2] = 2;

    for (int i = 3; i <= n; ++i) {
        vec1[i] = vec1[i - 1] + vec1[i - 2];
    }

    return vec1[n];
}

#endif //LEECODE70_H
