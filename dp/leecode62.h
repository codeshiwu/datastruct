//
// Created by macos on 24-7-21.
//

#ifndef LEECODE63_H
#define LEECODE63_H

#include <iostream>
#include <vector>

using namespace std;

// leecode 62
int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> vec1(m, std::vector<int>(n));

    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            vec1[i][j] = vec1[i - 1][j] + vec1[i][j - 1];
        }
    }

    return vec1[m - 1][n - 1];
}

#endif //LEECODE63_H
