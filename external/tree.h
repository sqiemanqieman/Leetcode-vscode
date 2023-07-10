#pragma once

#include "common.h"


class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

TreeNode* createTree(vector<int> vals) {
	int size = (int)vals.size();
	if (size == 0 || vals[0] == INT_MAX) return nullptr;
	queue<TreeNode*> q;
	vector<TreeNode*> nodes;
	for (int i = 0; i < size; ++i) {
		if (vals[i] == INT_MAX) nodes.push_back(nullptr);
		else nodes.push_back(new TreeNode(vals[i]));
	}
	q.push(nodes[0]);
	int i = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (i + 1 < size && nodes[i + 1]) {
			cur->left = nodes[i + 1];
			q.push(cur->left);
		}
		else cur->left = nullptr;
		if (i + 2 < size && nodes[i + 2]) {
			cur->right = nodes[i + 2];
			q.push(cur->right);
		}
		else cur->right = nullptr;
		i += 2;
	}
	return nodes[0];
}

// 递归遍历
void preOrder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        preOrder(cur->left, vec);  // 左
        preOrder(cur->right, vec); // 右
}

void inOrder(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    inOrder(cur->left, vec);  // 左
    vec.push_back(cur->val);    // 中
    inOrder(cur->right, vec); // 右
}

void postOrder(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    postOrder(cur->left, vec);  // 左
    postOrder(cur->right, vec); // 右
    vec.push_back(cur->val);    // 中
}

// 迭代遍历 统一写法
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop();
			if (node->right) st.push(node->right);  // 右
			if (node->left) st.push(node->left);    // 左
			st.push(node);                          // 中
			st.push(NULL);
		} else {
			st.pop();
			node = st.top();
			st.pop();
			result.push_back(node->val);
		}
	}
	return result;
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
			if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

			st.push(node);                          // 添加中节点
			st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

			if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
		} else { // 只有遇到空节点的时候，才将下一个节点放进结果集
			st.pop();           // 将空节点弹出
			node = st.top();    // 重新取出栈中元素
			st.pop();
			result.push_back(node->val); // 加入到结果集
		}
	}
	return result;
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop();
			st.push(node);                          // 中
			st.push(NULL);

			if (node->right) st.push(node->right);  // 右
			if (node->left) st.push(node->left);    // 左

		} else {
			st.pop();
			node = st.top();
			st.pop();
			result.push_back(node->val);
		}
	}
	return result;
}

// 层次遍历
vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	vector<vector<int>> res;
	if (root) q.push(root);
	while (!q.empty()) {
		int size = (int)q.size();
		vector<int> v;
		for (int i = 0; i < size; ++i) {
			auto node = q.front();
			v.push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
			q.pop();
		}
		res.push_back(v);
	}

	return res;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	queue<TreeNode*> q;
	vector<vector<int>> res;
	if (root) q.push(root);
	while (!q.empty()) {
		int size = (int)q.size();
		vector<int> v;
		for (int i = 0; i < size; ++i) {
			auto node = q.front();
			v.push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
			q.pop();
		}
		res.push_back(v);
	}
	reverse(res.begin(), res.end());
	return res;
}

int sumOfLeftLeaves(TreeNode* root) {
	int sum = 0;
	if (!root) return sum;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty()) {
		auto cur = s.top();
		s.pop();
		if (cur) {
			if (cur->right) s.push(cur->right);
			if (cur->left) s.push(cur->left);
			s.push(cur);
			s.push(nullptr);
		}
		else {
			cur = s.top();
			s.pop();
			if (cur->left && !cur->left->left && !cur->left->right)
				sum += cur->left->val;
		}
	}
	return sum;
}




















// class Tree {
// public:
// 	Tree() { root = nullptr; }
// 	Tree(TreeNode* root) :root(root) {}

// 	void create(vector<int> vals) {
// 		int size = (int)vals.size();
// 		if (size == 0 || vals[0] == INT_MAX) return;
// 		queue<TreeNode*> q;
// 		vector<TreeNode*> nodes;
// 		for (int i = 0; i < size; ++i) {
// 			if (vals[i] == INT_MAX) nodes.push_back(nullptr);
// 			else nodes.push_back(new TreeNode(vals[i]));
// 		}
// 		q.push(nodes[0]);
// 		int i = 0;
// 		while (!q.empty()) {
// 			auto cur = q.front();
// 			q.pop();
// 			if (i + 1 < size && nodes[i + 1]) {
// 				cur->left = nodes[i + 1];
// 				q.push(cur->left);
// 			}  else cur->left = nullptr;
// 			if (i + 2 < size && nodes[i + 2]) {
// 				cur->right = nodes[i + 2];
// 				q.push(cur->right);
// 			} else cur->right = nullptr;
// 			i += 2;
// 		}
// 		root = nodes[0];
// 	}

// 	vector<int> preOrder() {
// 		stack<TreeNode*> s;
// 		vector<int> res;
// 		if (root) s.push(root);
// 		while (! s.empty()) {
// 			auto cur = s.top();
// 			s.pop();
// 			res.push_back(cur->val);
// 			if (cur->right) s.push(cur->right);
// 			if (cur->left) s.push(cur->left);
// 		}
// 		return res;
// 	}


// 	vector<vector<int>> levelOrder() {
// 		queue<TreeNode*> q;
// 		vector<vector<int>> res;
// 		if (root) q.push(root);
// 		while (!q.empty()) {
// 			int size = (int)q.size();
// 			vector<int> v;
// 			for (int i = 0; i < size; ++i) {
// 				auto node = q.front();
// 				v.push_back(node->val);
// 				if (node->left) q.push(node->left);
// 				if (node->right) q.push(node->right);
// 				q.pop();
// 			}
// 			res.push_back(v);
// 		}

// 		return res;
// 	}

// //private:
// 	TreeNode* root;
// };
