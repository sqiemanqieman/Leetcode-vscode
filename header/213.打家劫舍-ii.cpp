/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> a(nums.begin()+1, nums.end());
        vector<int> b(nums.begin()+2, nums.end()-1);
        return max(_rob(a), _rob(b)+nums[0]);
    }

    int _rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i  = 2; i < nums.size(); ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp.back();
    }
};
// @lc code=end

