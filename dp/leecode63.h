//
// Created by macos on 24-7-21.
//

#ifndef LEECODE53_H
#define LEECODE53_H

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    std::vector<std::vector<int>> dpArr(m, std::vector<int>(n));

    bool hasGrid = false;
    for (int i = 0; i < m; ++i) {
        if (obstacleGrid[i][0]) {
            hasGrid = true;
        }

        if (hasGrid) {
            dpArr[i][0] = 0;
        } else {
            dpArr[i][0] = 1;
        }
    }

    hasGrid = false;
    for (int i = 0; i < n; ++i) {
        if (obstacleGrid[0][i]) {
            hasGrid = true;
        }

        if (hasGrid) {
            dpArr[0][i] = 0;
        } else {
            dpArr[0][i] = 1;
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j]) {
                dpArr[i][j] = 0;
            } else {
                dpArr[i][j] = dpArr[i - 1][j] + dpArr[i][j - 1];
            }
        }
    }

    return dpArr[m - 1][n - 1];
}

#endif //LEECODE53_H
