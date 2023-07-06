/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); ++i){
            res.insert(people[i][1] + res.begin(), people[i]);
        }
        return res;
    }
    
private:
    static bool cmp(const vector<int>& left, const vector<int>& right){
        if (left[0] != right[0]) return left[0] > right[0];
        return left[1] < right[1];
    }
};
// @lc code=end

