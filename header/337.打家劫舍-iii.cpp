/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        auto tmp = _rob(root);
        return  max(tmp[0], tmp[1]);
    }

    vector<int> _rob(TreeNode* root){
        if (! root) return {0,0};
        
        vector<int> l = _rob(root->left);
        vector<int> r = _rob(root->right);
        int val1 = max(l[0], l[1]) + max(r[0], r[1]);
        int val2 = root->val + l[0] + r[0];
        return {val1, val2};
    }

};
// @lc code=end

