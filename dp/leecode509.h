//
// Created by macos on 24-7-21.
//

#ifndef LEECODE509_H
#define LEECODE509_H

#include <iostream>
#include <vector>

// leecode509 计算斐波那契数列的大小

int fib(int n) {
    if (n <= 1) {
        return n;
    }

    std::vector<int> dpArr(n + 1);

    dpArr[0] = 0;
    dpArr[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dpArr[i] = dpArr[i - 1] + dpArr[i - 2];
    }

    return dpArr[n];
}

#endif //LEECODE509_H
