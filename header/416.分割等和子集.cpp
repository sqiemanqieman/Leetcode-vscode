/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;


// 是01背包问题
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0, plus<>());
        if (sum % 2) return false;
        int half_sum = sum / 2;
        int bag_size = half_sum;
        vector<int>& weights = nums;
        vector<int>& values = nums;
        
        vector<int> dp(bag_size+1,0);
        for (int i = 0; i < nums.size(); ++i){
            for (int j = bag_size; j >= weights[i]; --j){
                dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
            }
        }
        return dp.back() == bag_size;
    }

    
#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> nums{1,5,11,5};
        cout << canPartition(nums);
    }
#endif

};

// @lc code=end

