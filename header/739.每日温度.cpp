/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start


#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 单调栈解法 O(n)时间复杂度 （优于暴力解法n^2复杂度）
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> ms;
        for (int i = 0; i < temperatures.size(); ++i){
            while (! ms.empty() && temperatures[ms.top()] < temperatures[i]){
                res[ms.top()] = i - ms.top();
                ms.pop();
            }
            ms.push(i);
        }
        return res;
    }

    
#ifdef RUN_IN_LOCAL
    void test(){
        vector<int> temperature{73,74,75,71,69,72,76,73};
        cout << dailyTemperatures(temperature);
    }
#endif

};
// @lc code=end

