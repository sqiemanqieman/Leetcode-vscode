/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> ms;

        for (int i = 0; i < nums.size()*2; ++i){
            while(! ms.empty() && nums[ms.top()] < nums[i%nums.size()]){
                res[ms.top()] = nums[i%nums.size()];
                ms.pop();
            }
            if (i < nums.size())
                ms.push(i);
        }
        return res;
    }

        
#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> nums{1,2,1};
        cout << nextGreaterElements(nums);
    }
#endif
};
// @lc code=end

