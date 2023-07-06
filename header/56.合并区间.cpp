/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& l, const vector<int>& r){
                return l[0] < r[0];});
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end

