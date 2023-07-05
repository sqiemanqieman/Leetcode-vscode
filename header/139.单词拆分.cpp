/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i){
        for (int j = 0; j < wordDict.size(); ++j){
        if (wordDict[j].size() <= i){ 
            dp[i] = dp[i - wordDict[j].size()] && 
            s.substr(i-wordDict[j].size(), wordDict[j].size()) == wordDict[j];
            if (dp[i]) break;
        }}}
        return dp.back();
    }
};

// @lc code=end

