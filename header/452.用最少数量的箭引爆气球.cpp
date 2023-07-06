/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

bool cmp(const vector<int>& l, const vector<int>& r){
    if (l[0] != r[0]) return l[0] < r[0];
    return l[1] < r[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 1;
        sort(points.begin(), points.end(), cmp);
        int right_most = points[0][1];
        for (int i = 0; i < points.size();) {
            while(i < points.size() && points[i][0] <= right_most) {
                right_most = min(right_most, points[i][1]);
                ++i;
            }
            if (i == points.size()) return res;
            right_most = points[i][1];
            ++res;
        }
        return res;
    }
};
// @lc code=end

