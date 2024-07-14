//
// Created by 15387 on 2024/7/14.
//

#ifndef DATASTRUCT_LEECODE_347_H
#define DATASTRUCT_LEECODE_347_H

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class MyCompare {
public:
    // 此表达式为true，说明是严格小于，也就是说lhs出现的次数越多，其越小于rhs，及出现次数越多，优先级越低，即小根堆
    bool operator() (const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> map1;

    for (auto &num : nums) {
        map1[num]++;
    }

    // 小根堆
    // 构建理由：小根堆出队时都是最小值，遍历时可以持续排除比较小的值
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyCompare> queue1;

    for (auto iter = map1.begin(); iter != map1.end(); ++iter) {
        if (queue1.size() < k) {
            queue1.push(*iter);
            continue;
        }

        if (queue1.size() == k && iter->second > queue1.top().second) {
            queue1.pop();
            queue1.push(*iter);
        }
    }

    std::vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
        result[i] = queue1.top().first;
        queue1.pop();
    }

    return result;
}

#endif //DATASTRUCT_LEECODE_347_H
