/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // version 1 2d dp;
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0, plus<>());
    //     if (sum < abs(target)) return 0;
    //     if ((sum + target) % 2) return 0;
    //     int bag_size = (sum + target) / 2;
    //     vector<int>& weights = nums;

    //     vector<vector<int>> dp(nums.size()+1, vector<int>(bag_size + 1, 0));
    //     dp[0][0] = 1;  // TODO CAUTION!!!

    //     for (int i = 1; i <= weights.size(); ++i){
    //         for (int j = 0; j <= bag_size; ++j){
    //             dp[i][j] = dp[i-1][j];
    //             if (weights[i-1] <= j)
    //                 dp[i][j] += dp[i-1][j-weights[i-1]];
    //         }
    //     }
    //     return dp[weights.size()][bag_size];
    // }

    // version 2: 1d dp
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0, plus<>());
        if (sum < abs(target)) return 0;
        if ((sum + target) % 2) return 0;
        int bag_size = (sum + target) / 2;
        vector<int>& weights = nums;

        vector<int> dp(bag_size+1,0);
        dp[0] = 1;
        for (int i = 0; i < weights.size(); ++i){
            for (int j = bag_size; j >= weights[i]; --j)
                dp[j] += dp[j - weights[i]];
        }
        return dp.back();
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> nums{1,1,1,1,1};
        cout << findTargetSumWays(nums, 3);
    }
#endif

};


// @lc code=end

