/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> weights;
        for (auto &str : strs){
            int count_0 = 0;
            for (auto j : str)
                count_0 += (j == '0');
            weights.push_back({count_0, str.size()-count_0});
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < strs.size(); ++i){
            for (int j = m; j >= weights[i].first; --j){
                for (int k = n; k >= weights[i].second; --k){
                    dp[j][k] = max(dp[j][k], 
                        1+dp[j-weights[i].first][k-weights[i].second]);
                }
            }
        }

        return dp.back().back();
    }

        
#ifdef RUN_IN_LOCAL
    void test(){
        vector<string> strs{"10", "0001", "111001", "1", "0"};
        int m = 5;
        int n = 3;
        cout << findMaxForm(strs, m, n);
    }
#endif

};
// @lc code=end

