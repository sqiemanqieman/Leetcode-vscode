/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int last_index[27];
        memset(&last_index, 0, 27 * sizeof(int));
        for (int i = 0; i < s.size(); ++i){
            last_index[s[i] - 'a'] = max(last_index[s[i] - 'a'], i);
        }
        int rightmost = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i){
            rightmost = max(last_index[s[i]-'a'], rightmost);
            if (rightmost == i) {
                res.push_back(i - start+1);
                start = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end

