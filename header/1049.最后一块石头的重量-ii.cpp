/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0, plus<>());
        int bag_size = sum / 2;
        vector<int>& weights = stones;
        vector<int>& values = stones;

        vector<int> dp(bag_size+1, 0);
        for (int i = 0; i < stones.size(); ++i){
            for (int j = bag_size; j >= weights[i]; --j){
                dp[j] = max(dp[j], dp[j-weights[i]]+ values[i]);
            }
        }

        return sum - dp.back() - dp.back();
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> stones{2,7,4,1,8,1};
        cout << lastStoneWeightII(stones);
    }
#endif

};
// @lc code=end

