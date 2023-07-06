/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size()+1, vector<int>(s.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i) dp[0][i] = 1;
        for (int i = 1; i <= t.size(); ++i){
            for (int j = 1; j <= s.size(); ++j){
                if (t[i-1] == s[j-1] && dp[i][j-1] < INT_MAX - dp[i-1][j-1]) dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};
// @lc code=end

