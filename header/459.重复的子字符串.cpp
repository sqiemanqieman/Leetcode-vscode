/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
*/
class Solution {
public:
    // 移动匹配法
    // bool repeatedSubstringPattern(string s) {
    //    string t = s + s;
    //    t.erase(t.begin());
    //    t.erase(t.end() - 1);
    //    return t.find(s) != t.npos;
    // }

    // KMP next_table method
	bool repeatedSubstringPattern(string s) {
        vector<int> next_table;
        nextTable(next_table, s);
        int len = s.size() - 1 - next_table[s.size() - 1];
        // int len = next_table[s.size()-1] + 1;
        if (len > s.size() / 2) return false;
        if (s.size() % len != 0) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i % len] != s[i])
                return false;
        }
        return true;
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

    void test(){
        cout << repeatedSubstringPattern("aabaaba");
    }
};

// @lc code=end

