/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> checkerboard;
        vector<vector<string>> res;
        backtracking(n, 0, checkerboard, res);

        return res;
    }

    void backtracking(int n, int row, vector<string>& checkerboard,
    vector<vector<string>>& res){
        if (row >= n) {
            res.push_back(checkerboard);
            return;
        }
        for (int column = 0; column < n; ++column){
            if (isValid(row, column, checkerboard, n)){
                string tmp(n, '.');
                tmp[column] = 'Q';
                checkerboard.push_back(tmp);
                backtracking(n, row+1, checkerboard, res);
                checkerboard.pop_back();
            }
        }
    }

    bool isValid(int row, int column, vector<string>& checkerboard, int n){
        for (int i = 0; i < row; ++i)
            if (checkerboard[i][column] == 'Q') 
                return false;
        for (int i = row-1, j = column-1; i >= 0 && j >= 0; --i, --j)
            if (checkerboard[i][j] == 'Q')
                return false;
        for (int i = row-1, j = column+1; i >= 0 && j < n; --i, ++j)
            if (checkerboard[i][j] == 'Q') 
            return false;
        return true; 
    }

    
#ifdef RUN_IN_LOCAL
    void test(){
        cout << solveNQueens(4);
    }
#endif

};
// @lc code=end

