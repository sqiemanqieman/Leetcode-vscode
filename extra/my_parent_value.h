#pragma once

/*
 2023复旦计算机夏令营机考第三题

一棵树有n个节点，给你前序遍历（中左右）和逆前序遍历（中右左）的结果，请给出每
个节点的父亲节点的值(根节点没有父亲节点，设置其值为0)
输入
5（节点个数）
5 3 1 2 4（前序遍历）
5 4 3 2 1（逆前序遍历）
输出：
3 3 5 5 0 (1的父亲节点是3,2的父亲节点是3，…)
*/

#include "common.h"

class ParentValue {
public:
	void solve() {
		findParent(); map<int*, int>m; 
	}

	void findParent() {
		int n;
		cin >> n;
		vector<int> pre(n, 0);
		vector<int> inv_pre(n, 0);
		vector<int> parents(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> pre[i];
		for (int i = 0; i < n; ++i)
			cin >> inv_pre[i];

		parents[pre[0] - 1] = 0;
		_recursion(pre[0], vector<int>(pre.begin() + 1, pre.end()),
			vector<int>(inv_pre.begin() + 1, inv_pre.end()), parents);

		cout << parents;
	}


private:
	void _recursion(int parent_value, vector<int> pre, vector<int> inv_pre, vector<int>& parents) {
		if (pre.empty()) return;
		auto root1 = pre[0], root2 = inv_pre[0];
		parents[root1 - 1] = parent_value;
		if (root1 == root2) {
			vector<int> p1, p2;
			_find_p1_p2(pre, inv_pre, p1, p2);
			_recursion(root1, p1, p2, parents);
		}
		else {
			parents[root2 - 1] = parent_value;
			vector<int> p1, p2, p3, p4;
			_find_p1_p2_p3_p4(pre, inv_pre, p1, p2, p3, p4);
			_recursion(root1, p1, p2, parents);
			_recursion(root2, p3, p4, parents);
		}
	}


	void _find_p1_p2(vector<int> pre, vector<int> inv_pre, vector<int>& p1, vector<int>& p2) {
		for (auto i = pre.begin() + 1; i < pre.end(); ++i)
			p1.push_back(*i);
		for (auto i = inv_pre.begin() + 1; i < inv_pre.end(); ++i)
			p2.push_back(*i);
	}

	void _find_p1_p2_p3_p4(vector<int> pre, vector<int> inv_pre,
		vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		for (auto i = pre.begin() + 1; i < pre.end(); ++i) {
			if (*i == inv_pre[0]) break;
			p1.push_back(*i);
		}
		bool find = false;
		for (auto i = inv_pre.begin() + 1; i < inv_pre.end(); ++i) {
			if (*i != pre[0] && !find) continue;
			if (*i == pre[0]) { find = true; continue; }
			p2.push_back(*i);
		}

		find = false;
		for (auto i = pre.begin() + 1; i < pre.end(); ++i) {
			if (*i != inv_pre[0] && !find) continue;
			if (*i == inv_pre[0]) { find = true; continue; }
			p3.push_back(*i);
		}
		for (auto i = inv_pre.begin() + 1; i < inv_pre.end(); ++i) {
			if (*i == pre[0]) break;
			p4.push_back(*i); 
			int c = 3; 
		}
	}
	
public:
	void test() {
		solve();
	}
}; 
// [1,2,2,3,null,null,3,4,null,null,4]