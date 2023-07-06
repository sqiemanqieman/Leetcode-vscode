/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
        for (int i = 0; i < s.size(); ++i) dp[i][i] = 1;
        res += s.size();

        for (int i = s.size()-1; i >= 0; --i){
            for (int j = i+1; j < s.size(); ++j){
                if (s[i] != s[j]) dp[i][j] = 0;
                else dp[i][j] = dp[i+1][j-1];
                if(dp[i][j]) ++res;
            }
        }
        return res;
    }
};
// @lc code=end

