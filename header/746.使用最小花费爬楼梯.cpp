/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 3) return min(cost.front(), cost.back());
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i){
            if (i == cost.size() - 1) {
                dp[i] = min(dp[i-1], dp[i-2] + cost[i]);
                return dp[i];
            }
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return dp.back();
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> cost{1,100,1,1,1,100,1,1,100,1};
        cout << minCostClimbingStairs(cost);
    }
#endif

};
// @lc code=end

