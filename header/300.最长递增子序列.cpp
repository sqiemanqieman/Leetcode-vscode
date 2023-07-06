/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i){
            for (int j = i - 1; j >= 0; --j){
                if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// @lc code=end

