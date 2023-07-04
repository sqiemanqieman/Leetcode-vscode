/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // 单调栈解法
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> m;
        stack<int> ms; // 单调栈
        for (int i = 0; i < nums1.size(); ++i)
            m.insert(pair<int, int>(nums1[i],i));
            
        for (auto i : nums2){
            while(! ms.empty() && ms.top() < i){
                res[m[ms.top()]] = i;
                ms.pop();
            }
            if (m.find(i) != m.end())
                ms.push(i);
        }
        return res;
    }

    
#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> nums1{2,4};
        vector<int> nums2{1,2,3,4};
        cout << nextGreaterElement(nums1, nums2);
    }
#endif

};
// @lc code=end

