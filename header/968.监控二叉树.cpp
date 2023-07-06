/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// @lc code=start


// Definition for a binary tree node.
#define RUN_IN_LOCAL

#ifdef RUN_IN_LOCAL
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 0 被覆盖
    // 1 不覆盖
    // 2 有监控器
    int minCameraCover(TreeNode* root) {
        int res = 0;
        if (traversal(root, res) == 1) ++res;
        return res;
    }

    int traversal (TreeNode* root, int& res){
        if (! root) return 0;
        int l = traversal(root->left, res);
        int r = traversal(root->right, res);
        if (l == 0 && r == 0) return 1;
        if (l == 1 || r == 1) {
            ++res;
            return 2;
        }
        if (l == 2 || r == 2) return 0;
        return 0;
    }
};
// @lc code=end

