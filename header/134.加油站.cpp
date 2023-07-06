/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0;
        int min_val = INT_MAX;
        for (int i = 0; i < gas.size(); ++i){
            rest += (gas[i]-cost[i]);
            min_val = min(rest, min_val);
        }
        if (min_val >= 0) return 0;
        
        if (rest < 0) return -1;
        
        for (int i = gas.size() - 1; i >= 0; --i){
            min_val += gas[i] - cost[i];
            if (min_val >= 0) return i;
        }
        return -1;
    }
};
// @lc code=end

