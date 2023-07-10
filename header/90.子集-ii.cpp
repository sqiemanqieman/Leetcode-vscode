/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
class VectorHash {
    public:
        size_t operator()(const vector<int>& value) const noexcept {
            auto h = hash<int>();
            size_t res{ 0 };
            for (auto i : value) {
                res ^= h(i);
            }
            return res;
        }
    };

    struct VectorEqual {
        const bool operator()(const vector<int>& _Left, const vector<int>& _Right) const {
            if (_Left.size() != _Right.size()) return false;
            vector<int> left(_Left);
            vector<int> right(_Right);
            sort(left.begin(), left.end());
            sort(right.begin(), right.end());
            for (int i = 0; i < left.size(); ++i)
                if (left[i] != right[i]) return false;
            return true;
        }

    };
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> candidate;
        unordered_set<vector<int>, VectorHash, VectorEqual> res;
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        backtracking(nums, 0, candidate, res);
        result = vector<vector<int>>(res.begin(), res.end());
        return result;

    }

    void backtracking(vector<int>& nums, int cur_id,
        vector<int> candidate,
        unordered_set<vector<int>, VectorHash, VectorEqual>& res) {
        if (cur_id >= nums.size()) {
            res.insert(candidate);
            return;
        }
        candidate.push_back(nums[cur_id]);
        backtracking(nums, cur_id+1, candidate, res);
        candidate.pop_back();

        backtracking(nums, cur_id+1, candidate, res);

        return;
    }
};
// @lc code=end

