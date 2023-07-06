/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), 
        [](const int& left, const int& right){return abs(left) < abs(right);});
        for (int i = nums.size()-1; i >= 0; --i){
            if (k == 0) break;
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                --k;
            } 
        }
        if (k) nums[0] *= (k % 2 ? -1 : 1); 
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end

