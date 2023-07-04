/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0]) break;
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; ++i){
            if (obstacleGrid[0][i]) break;
            dp[0][i] = 1;
        } 

        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if(obstacleGrid[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }

        
#ifdef RUN_IN_LOCAL
    void test(){
        // vector<vector<int>> obstacle_grid{{0,0,0},{0,1,0},{0,0,0}};
        vector<vector<int>> obstacle_grid{{0,1},{0,0}};
        cout << uniquePathsWithObstacles(obstacle_grid);
    }
#endif

};
// @lc code=end

