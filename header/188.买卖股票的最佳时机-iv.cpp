/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k, 0));
        for (int i = 0; i < 2*k; i+=2)
            dp[0][i] = -prices[0];

        for (int i = 1; i < prices.size(); ++i){
            for (int j = 0; j < 2 * k; ++j)
                dp[i][j] = max(dp[i-1][j],
                    (j ? dp[i-1][j-1] : 0)  + prices[i] * (j % 2? 1 : -1));
        }
        return dp.back().back();
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> prices{2,1,4,5,2,9,7};
        cout << maxProfit(2, prices);
    }
#endif

};

// @lc code=end

