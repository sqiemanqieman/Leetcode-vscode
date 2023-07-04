/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, INT_MAX / 2);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i){
            for (int j = 0; j < coins.size(); ++j){
                if (i >= coins[j])
                    dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
            }
        }

        return dp.back() == INT_MAX / 2 ? -1 : dp.back();
    }
};
// @lc code=end

