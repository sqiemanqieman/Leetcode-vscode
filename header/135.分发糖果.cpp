/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i){
            if (ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i){
            if (ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i+1] + 1, candies[i]);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end

