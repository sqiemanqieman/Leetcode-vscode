/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int start_9;
        for (int i = num.size() - 2; i >= 0; --i){
            if (num[i] > num[i+1]){
                --num[i];
                start_9 = i + 1;
            }
        }
        for (int i = start_9; i < num.size(); ++i)
            num[i] = '9';
        return stoi(num);
    }
};
// @lc code=end

