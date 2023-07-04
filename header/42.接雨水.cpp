/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // version 1 双指针解法
    // int trap(vector<int>& height) {
    //     vector<int> max_l_height(height.size(), 0);
    //     vector<int> max_r_height(height.size(), 0);
    //     int M = height[0];
    //     int res = 0;

    //     for (int i = 1; i < height.size() - 1; ++i){
    //         M = max(M, height[i]);
    //         max_l_height[i] = M;
    //     }
    //     M = height.back();
    //     for (int i = height.size() - 2; i > 0; --i){
    //         M = max(M, height[i]);
    //         max_r_height[i] = M;
    //     }
    //     for (int i = 1; i < height.size() - 1; ++i){
    //         res += min(max_r_height[i], max_l_height[i]) - height[i];
    //     }
        
    //     return res;
    // }

    // version 2 单调栈解法
    int trap(vector<int>& height) {
        stack<int> ms;
        int res{0};
        ms.push(0);
        for (int i = 1; i < height.size(); ++i){
            if (height[i] < height[ms.top()])
                ms.push(i);
            else if (height[i] == height[ms.top()]){
                ms.pop();
                ms.push(i);
            }
            else {
                while (! ms.empty() && height[i] > height[ms.top()]){
                    int mid = ms.top();
                    ms.pop();
                    if (ms.empty()) break;
                    int left = ms.top();
                    int h = min(height[i], height[left]) - height[mid];
                    res += h * (i - left - 1);
                }
                ms.push(i);
            }
        }
        return res;
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
        cout << trap(height);
    }
#endif

};
// @lc code=end

