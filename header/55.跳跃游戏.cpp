/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_range = 0;
        for (int i = 0; i < nums.size(); ++i){
            max_range = max(i + nums[i], max_range);
            if (max_range >= nums.size() - 1) return true;
            if (max_range == i) return false;
        }
        return false;
    }
};
// @lc code=end

