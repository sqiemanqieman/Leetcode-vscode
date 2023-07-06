/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int, int>> dp(prices.size(), {0, 0});
        dp[0].first = -prices[0];
        dp[0].second = 0;
        for (int i = 1; i < prices.size(); ++i){
            dp[i].first = max(dp[i-1].first, dp[i-1].second-prices[i]);
            dp[i].second = max(dp[i-1].first + prices[i], dp[i-1].second);
        }
        return dp.back().second;
    }
};

// @lc code=end

