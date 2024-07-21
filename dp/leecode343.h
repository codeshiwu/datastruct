//
// Created by macos on 24-7-21.
//

#ifndef LEECODE343_H
#define LEECODE343_H

#include <iostream>
#include <vector>

// leecode 343 整数拆分：将正整数n拆分为k个正整数，并计算这k个正整数的最大乘积
int integerBreak(int n) {
    std::vector<int> dp(n + 1);

    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        for (j = 1; j <= i / 2; ++j) { // 这里从1开始拆分，从0开始拆分是没有意义的
            dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
        }
    }

    return dp[n];
}

#endif //LEECODE343_H
