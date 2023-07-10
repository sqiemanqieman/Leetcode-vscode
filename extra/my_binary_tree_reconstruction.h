#pragma once
//前序、后续、层序遍历中的任意一种遍历加上中序遍历都能恢复构造一棵二叉树。

#include "common.h"

#include "tree.h"

class Solution {
public:

	// reconstruct binary tree according in-order and level-order.
	void levelAndInOrder(vector<int> in, vector<int> level) {
		map<int, int> m;
		for (int i = 0; i < in.size(); ++i) m.insert(pair<int, int>(in[i], i));
		auto root = build(level, m);
		cout << levelOrder(root);
		Tree t;
		t.root = root;
		cout << t.preOrder();
	}

	TreeNode* build(vector<int> level, map<int, int>& m) {
		if (level.size() == 0) return nullptr;
		auto root = new TreeNode(level[0]);
		int in_root_index = m[level[0]];
		vector<int> l_level, r_level;
		for (int i = 0; i < level.size(); ++i)
			if (m[level[i]] < in_root_index) l_level.push_back(level[i]);
			else if (m[level[i]] > in_root_index) r_level.push_back(level[i]); 
			else continue;
		root->left = build(l_level, m);
		root->right = build(r_level, m);
		return root;	
	}

	void test() {
		levelAndInOrder({ 1,3, 4,5, 8,11 }, { 5,3, 8,1,4,11 });

		unordered_set<vector<int>, VectorHash, VectorEqual> us;
		us.insert({ 1,321,3 }); us.insert({ 321,1,3 });
		cout << us;
	}

	class VectorHash {
	public:
		size_t operator()(const vector<int>& value) const noexcept {
			auto h = hash<int>();
			size_t res{ 0 };
			for (auto i : value) {
				res ^= h(i);
			}
			return res;
		}
	};

	struct VectorEqual {
		const bool operator()(const vector<int>& _Left, const vector<int>& _Right) const {
			vector<int> left(_Left);
			vector<int> right(_Right);
			sort(left.begin(), left.end());
			sort(right.begin(), right.end());
			for (int i = 0; i < left.size(); ++i)
				if (left[i] != right[i]) return false;
			return true;
		}

	};
};