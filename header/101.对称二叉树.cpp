/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

#ifdef RUN_IN_LOCAL
#include "common.h"
#endif
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
bool isSymmetric(TreeNode* root) { // using queue
	if (!root) return true;
	queue<TreeNode*> q;
	q.push(root->left); q.push(root->right);
	while (!q.empty()) {
		TreeNode* node1 = q.front();
		q.pop();
		TreeNode* node2 = q.front();
		q.pop();
		if (!node1 && node2) return false;
		if (node1 && !node2) return false;
		if (!node1 && !node2) continue;
		if (node1->val != node2->val) return false;
		q.push(node1->left);
		q.push(node2->right);
		q.push(node1->right);
		q.push(node2->left);
	}
	return true;
}

//bool isSymmetric(TreeNode* root) { // using deque
//	if (!root) return true;
//	deque<TreeNode*> dq;
//	queue<TreeNode*> q;
//	dq.push_front(root->left);
//	dq.push_back(root->right);
//	while (!dq.empty()) {
//		int half_size = (int)dq.size() / 2;
//		for (int i = 0; i < half_size; ++i) {
//			auto node1 = dq.front();
//			dq.pop_front();
//			auto node2 = dq.back();
//			dq.pop_back();
//			if (!node1 && node2) return false;
//			if (node1 && !node2) return false;
//			if (!node1 && !node2) continue;
//			if (node1->val != node2->val) return false;
//			q.push(node1); q.push(node2);
//		}
//		while (!q.empty()) {
//			auto n1 = q.front();
//			q.pop();
//			auto n2 = q.front();
//			q.pop();
//			dq.push_front(n1->left);
//			dq.push_back(n2->right);
//			dq.push_front(n1->right);
//			dq.push_back(n2->left);
//		}
//	}
//	return true;
//}
};
// @lc code=end

