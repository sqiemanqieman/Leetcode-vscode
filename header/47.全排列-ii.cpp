/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;

        sort(nums.begin(), nums.end());
        vector<int> candidate;
        unordered_multiset<int> numbers(nums.begin(), nums.end());
        backtracking(numbers, candidate, res);
        return res;
    }

    void backtracking(unordered_multiset<int> nums,
            vector<int>& candidate, vector<vector<int>>& res){
        if (nums.empty()) {
            res.push_back(candidate);
            return ;
        }
        set<int> s;
        unordered_multiset<int> tmp;
        for (auto i : nums){
            if (s.find(i) != s.end()) continue;
            s.insert(i);
            candidate.push_back(i);
            tmp = nums;
            tmp.erase(tmp.find(i));
            backtracking(tmp, candidate, res);
            candidate.pop_back();
        }
    }

#ifdef RUN_IN_LOCAL
    void test(){
        cout << permuteUnique({1,1,2});
    }
#endif

};
// @lc code=end

