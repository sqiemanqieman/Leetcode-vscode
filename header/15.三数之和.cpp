/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;

        // 哈希法
        // vector<vector<int>> result;
        // sort(nums.begin(), nums.end());
        // // 找出a + b + c = 0
        // // a = nums[i], b = nums[j], c = -(a + b)
        // for (int i = 0; i < nums.size(); i++) {
        //     // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
        //     if (nums[i] > 0) {
        //         break;
        //     }
        //     if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
        //         continue;
        //     }
        //     unordered_set<int> set;
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (j > i + 2
        //                 && nums[j] == nums[j-1]
        //                 && nums[j-1] == nums[j-2]) { // 三元组元素b去重
        //             continue;
        //         }
        //         int c = 0 - (nums[i] + nums[j]);
        //         if (set.find(c) != set.end()) {
        //             result.push_back({nums[i], nums[j], c});
        //             set.erase(c);// 三元组元素c去重
        //         } else {
        //             set.insert(nums[j]);
        //         }
        //     }
        // }
        // return result;
    }
};
// @lc code=end

