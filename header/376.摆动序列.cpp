/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;
        int state = -1;
        for (int i = 1; i < nums.size();){
            if (nums[i] > nums[i-1]){
                while(i < nums.size() && nums[i] > nums[i-1]) ++i;
                if (state == -1 || state == 1)
                    ++res;
                state = 0;
            }
            else if (nums[i] < nums[i-1]){
                while(i < nums.size() && nums[i] < nums[i-1]) ++i;
                if (state == -1 || state == 0)
                    ++res;
                state = 1;
            }
            else {
                while(i < nums.size() && nums[i] == nums[i-1]) ++i;
            }
        }
        return res;
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> nums({1,10});
        cout << wiggleMaxLength(nums);
    }
#endif

};

// @lc code=end

