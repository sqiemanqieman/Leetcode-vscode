/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start

#include "../header/common.h"
#include <boost/bind.hpp>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> nums) {
        vector<vector<int>> res;
        return res;
    }
};

bool f(int a, int b) {return a < b;}

int main(){
    Solution solution;
    solution.permuteUnique({1,32,4});
    vector<int> a{5,252,2,62,626,22,52,6790};
    sort(a.begin(), a.end(), boost::bind(f, _1, _2));
}
// @lc code=end

