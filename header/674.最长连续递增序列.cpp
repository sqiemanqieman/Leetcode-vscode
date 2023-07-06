/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] > nums[i-1]){
                dp[i] = max(dp[i], dp[i-1] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// @lc code=end

