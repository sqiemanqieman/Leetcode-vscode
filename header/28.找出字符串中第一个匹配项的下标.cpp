/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 int strStr(string haystack, string needle) {
        if (needle.empty()) 
            return 0;
        vector<int> next_table;
        nextTable(next_table, needle);
        int max_size = (int)haystack.size() - (int)needle.size() + 1;
        int i{ 0 }, j{ 0 };
        for (i = 0; i < max_size; ++i) {
            for (; j < needle.size(); ++j) {
                if (haystack[i + j] == needle[j])
                    continue;
                if (j == 0)
                    break;
                i = i + j - 1 - next_table[j-1] - 1;
                j = next_table[j - 1] + 1;
                break;
            }
            if (j == needle.size())
                return i;
        }
        return -1;
    }

    void nextTable(vector<int>& next_table, const string& needle) const {
        if (!needle.empty())
            next_table.push_back(-1);
        for (int i = 1; i < needle.size(); ++i) {
            int j = next_table[i - 1] + 1;
            while (j && needle[i] != needle[j]) {
                j = next_table[j - 1] + 1;
            }
            if (j)
                next_table.push_back(j);
            else 
                next_table.push_back(needle[j] == needle[i] ? 0 : -1);
        }
    }
};
// @lc code=end

