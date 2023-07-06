/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n_5 = 0;
        int n_10 = 0;
        int n_20 = 0;
        for (int i = 0 ; i < bills.size(); ++i){
            switch(bills[i]){
            case 5:
                ++n_5;
                break;
            case 10:
                ++n_10;
                --n_5;
                if (n_5 < 0) return false;
                break;
            case 20:
                ++n_20;
                if (n_10) --n_10, --n_5;
                else n_5 -= 3;
                if (n_5 < 0) return false;
                break;
            }
        }
        return true;
    }
};
// @lc code=end

