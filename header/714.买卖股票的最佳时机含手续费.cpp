/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i] - fee);
        }
        return max(dp.back()[0], dp.back()[1]);
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> prices{1, 3, 2, 8, 4, 9};
        cout << maxProfit(prices,2);
    }
#endif

};

// @lc code=end

