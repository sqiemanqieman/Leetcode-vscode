/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int max_range = nums[0];
        int res = 1;
        for (int i = 0; i < nums.size();){
            if (max_range >= nums.size() -1) return res;
            int tmp = max_range;
            while (i <= max_range){
                tmp = max(tmp, i + nums[i]);
                ++i;
            }
            max_range = tmp;
            ++res;
        }
        return res;
    }
};

// @lc code=end

