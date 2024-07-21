//
// Created by macos on 24-7-21.
//

#ifndef LEECODE746_H
#define LEECODE746_H

#include <iostream>
#include <vector>

using namespace std;

// leecode746 使用最小花费爬楼梯

// 1.确定dp数组的含义：dp[i]所代表的含义是到达第i级阶梯的最小花费
// 2.递推公式： 到达第i级台阶有两种方式：从i-1跨一步上来，从i-2跨两步上来，所以 dp[i]有两种推到方式：
//  (1) dp[i] = dp[i - 1] + cost[i - 1]
//  (2) dp[i] = dp[i - 2] + cost[i - 2] 当然上述两种方式都可的话，应该取花费小的 所以最终推到为 dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
// 3.初始化dp数组：从题目来说直接到达第0级和第1级都是无花费的，因此 dp[0] = 0 dp[1] = 0
// 4.遍历顺序：自然是从前往后

int minCostClimbingStairs(vector<int>& cost) {
    std::vector<int> vec1(cost.size() + 1);
    if (cost.size() <= 1) {
        return 0;
    }

    vec1[0] = 0;
    vec1[1] = 0;
    for (int i = 2; i <= cost.size(); ++i) {
        vec1[i] = min(vec1[i - 1] + cost[i - 1], vec1[i - 2] + cost[i - 2]);
    }

    return vec1[cost.size()];
}

#endif //LEECODE746_H
