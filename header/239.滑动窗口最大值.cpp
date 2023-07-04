/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

// 单调队列解法
class MonotoneQueue {
public:
    void pop(int value) {
        if (que.front() == value)
            que.pop_front();
    }

    void push(int value) {
        while (!que.empty() && value > que.back())
            que.pop_back();
        que.push_back(value);
    }

    int front() {
        return que.front();
    }
    deque<int> que; // 使用deque实现单调队列
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotoneQueue mq;
        vector<int> res;
        if (k > nums.size()) return res;

        for (int i = 0; i < k; ++i) {
            mq.push(nums[i]);
        }
        res.push_back(mq.front());

        for (int i = 0; i < nums.size() - k; ++i) {
            mq.pop(nums[i]);
            mq.push(nums[i + k]);
            res.push_back(mq.front());
        }

        return res;
    }

#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> nums{1,3,-1,-3,5,3,6,7};
        int k = 3;
        cout << maxSlidingWindow(nums, k);
    }
#endif

};
// @lc code=end

