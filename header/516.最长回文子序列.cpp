/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        for (int i = 0; i < s.size(); ++i) dp[i][i] = 1;

        for (int i = s.size() - 1; i >= 0; --i){
            for (int j = i + 1; j < s.size(); ++j){
                if (s[i] != s[j]) dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                else dp[i][j] = 2 + dp[i+1][j-1];
            }
        }
        return dp.front().back();
    }
};

// @lc code=end

