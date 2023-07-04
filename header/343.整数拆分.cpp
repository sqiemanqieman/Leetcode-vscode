/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i < n+1; ++i){
            for (int j = 1; j < i; ++j){
                dp[i] = max(j*dp[i-j], dp[i]);
                dp[i] = max(dp[i], j*(i-j));
            }
        }
        return dp[n];
    }

#ifdef RUN_IN_LOCAL
    void test(){
        cout << integerBreak(10);
    }
#endif

};
// @lc code=end

