/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
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
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0]; // 持有
        dp[0][1] = 0; // 卖出(后一天不可买入)
        dp[0][2] = 0; // 不持有且非卖出状态(后一天可以买入)
        for (int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
        }
        return max(dp.back()[1], dp.back()[2]);
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> prices{1};
        cout << maxProfit(prices);
    }
#endif

};

// @lc code=end

