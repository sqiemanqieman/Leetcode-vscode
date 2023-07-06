/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // version 1: DP 算法
    int maxSubArray(vector<int>& nums) {
        int res = numeric_limits<int>::min();
        vector<int> dp(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); ++i){
            dp[i] = max(nums[i-1], dp[i-1] + nums[i-1]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

// @lc code=end

