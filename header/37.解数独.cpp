/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }

    bool backtracking(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row){
            for (int column = 0; column < 9; ++column){
                if (board[row][column] != '.') continue;
                for (char value = '1'; value <= '9'; ++value){
                    if (isValid(row, column, value, board)){
                        board[row][column] = value;
                        if (backtracking(board)) return true;
                        board[row][column] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(int row, int column, char value, vector<vector<char>>& board){
        for (int i = 0; i < 9; ++i)
            if ( i != row && board[i][column] == value) 
                return false;
        for (int i = 0; i < 9; ++i)
            if (i != column && board[row][i] == value) 
                return false;
        int r_s = (row / 3) * 3;
        int c_s = (column / 3) * 3;
        for (int i = r_s; i < r_s + 3; ++i){
            for (int j = c_s; j < c_s + 3; ++j){
                if (i == row && j == column) continue;
                if (board[i][j] == value) return false;
            }
        }
        return true; 
    }

        
#ifdef RUN_IN_LOCAL
    void test(){
        vector<vector<char>> board{
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };

        solveSudoku(board);

        for (auto &i : board)
            cout << i << endl;
    }
#endif

};
// @lc code=end

