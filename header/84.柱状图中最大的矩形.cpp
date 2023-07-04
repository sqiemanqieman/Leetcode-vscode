/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 单调栈解法
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), heights.size());
        stack<int> ms, st;
        int res = 0;
        for (int i = 0, j = heights.size()-1; i < heights.size(); ++i, --j){
            while(! ms.empty() && heights[ms.top()] > heights[i]){
                right[ms.top()] = i;
                ms.pop();
            }
            ms.push(i);
            while(!st.empty() && heights[st.top()] > heights[j]){
                left[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        for (int i = 0; i < heights.size(); ++i)
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        return res;
    }

    // 双指针解法
    // int largestRectangleArea(vector<int>& heights) {
    //     vector<int> minLeftIndex(heights.size());
    //     vector<int> minRightIndex(heights.size());
    //     int size = heights.size();

    //     // 记录每个柱子 左边第一个小于该柱子的下标
    //     minLeftIndex[0] = -1; // 注意这里初始化，防止下面while死循环
    //     for (int i = 1; i < size; i++) {
    //         int t = i - 1;
    //         // 这里不是用if，而是不断向左寻找的过程
    //         while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
    //         minLeftIndex[i] = t;
    //     }
    //     // 记录每个柱子 右边第一个小于该柱子的下标
    //     minRightIndex[size - 1] = size; // 注意这里初始化，防止下面while死循环
    //     for (int i = size - 2; i >= 0; i--) {
    //         int t = i + 1;
    //         // 这里不是用if，而是不断向右寻找的过程
    //         while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
    //         minRightIndex[i] = t;
    //     }
    //     // 求和
    //     int result = 0;
    //     for (int i = 0; i < size; i++) {
    //         int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
    //         result = max(sum, result);
    //     }
    //     return result;
    // }
 
#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> heights{2,1,5,6,2,3};
        cout << largestRectangleArea(heights);
    }
#endif

};
// @lc code=end