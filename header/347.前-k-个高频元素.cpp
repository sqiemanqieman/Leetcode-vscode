/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
class comparison {
    public: // // 小顶堆比较
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& i : nums) {
            auto it = m.find(i);
            if (it == m.end())
                m.insert(pair<int, int>(i, 1));
            else
                ++(it->second);
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>, comparison> pq; // 小顶堆
        for (auto& i : m) {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

