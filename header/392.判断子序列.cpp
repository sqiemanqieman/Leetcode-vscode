/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // version 1 双指针
        int i = 0, j = 0;
        for (; i < s.size(); ++i){
            while (j < t.size()){
                if (s[i] == t[j]){
                    break;
                }
                ++j;
            }
            if (j == t.size()) return false;
            ++j;
        }
        return true;

        // version 2  DP
        // vector<vector<bool>> dp(s.size()+1, vector<bool>(t.size()+1, false));
        // for (int i = 0; i <= t.size(); ++i) dp[0][i] = true;
        // for (int i = 1; i <= s.size(); ++i){
        //     for (int j = 1; j <= t.size(); ++j){
        //         if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
        //         else dp[i][j] = dp[i][j-1];
        //     }
        // }
        // return dp.back().back();
    }
};

// @lc code=end

