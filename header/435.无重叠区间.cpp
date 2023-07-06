/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;


bool cmp(const vector<int>& l, const vector<int>& r){
    return l[0] < r[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 1;
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& l, const vector<int>& r){
                return l[0] < r[0];});
        int right_most = intervals[0][1];
        for (int i = 0; i < intervals.size();) {
            while(i < intervals.size() && intervals[i][0] < right_most) {
                right_most = min(right_most, intervals[i][1]);
                ++i;
            }
            if (i == intervals.size()) break;
            right_most = intervals[i][1];
            ++res;
        }
        return intervals.size() - res;
    }
};
// @lc code=end

