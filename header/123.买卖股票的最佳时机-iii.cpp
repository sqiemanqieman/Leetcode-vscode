/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
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
        vector<vector<int>> dp(prices.size(), {0, 0, 0, 0});
        dp[0][0] = -prices[0]; // 第一次持有
        dp[0][1] = 0; // 第一次不持有
        dp[0][2] = -prices[0]; // 第二次持有
        dp[0][3] = 0; // 第二次不持有
        for (int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(-prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i]);
        }

        return max(dp.back()[1], dp.back()[3]);
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> prices{3,3,5,0,0,3,1,4};
        cout << maxProfit(prices);
    }
#endif

};
// @lc code=end

