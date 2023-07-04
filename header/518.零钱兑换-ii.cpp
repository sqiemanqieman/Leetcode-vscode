/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i){
            for (int j = coins[i]; j <= amount; ++j){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp.back();
    }


#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> nums{2};
        cout << change(3, nums);
    }
#endif


};

// @lc code=end

