/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        // vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        // for (int i = 1; i <= nums1.size(); ++i){
        //     for (int j = 1; j <= nums2.size(); ++j){
        //         if (nums1[i-1] == nums2[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + 1;
        //             res = max(res, dp[i][j]);
        //         }
        //     }
        // }
        // return res;

        // version 2 滚动数组
        vector<int> dp(nums2.size()+1, 0);
        for (int i = 1; i <= nums1.size(); ++i){
            for (int j = nums2.size(); j > 0; --j){
                if (nums1[i-1] == nums2[j-1]){
                    dp[j] = dp[j-1] + 1;
                    res = max(res, dp[j]);
                }
                else dp[j] = 0;
            }
        }
        return res;
    }
};

// @lc code=end

