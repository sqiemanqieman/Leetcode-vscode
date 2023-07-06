/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0;
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (; i < g.size(); ++i){
            while(j < s.size() && g[i] > s[j]) ++j;
            if (j == s.size()) return res;
            ++res;
            ++j;
        }

        return res;
    }
};
// @lc code=end

