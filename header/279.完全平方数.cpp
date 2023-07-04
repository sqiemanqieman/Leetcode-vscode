/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        int upper = int(sqrt(n));
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i){
            for (int j = 1; j <= upper; ++j){
                if (i >= j * j){
                    dp[i] = min(dp[i], dp[i-j*j] + 1);
                }
            }
        }

        return dp.back();
    }
};
// @lc code=end

