#pragma once
/*
 2023复旦计算机夏令营机考第四题

有n行列的士兵，每行有一个能量值，每列也有一个能量值，每个士兵的防御力等于
其所在行的能量+所在列的能量。炸弹的伤害为X,防御力大于x的士兵才不会受伤，求要
使至少k个士兵不受伤炸弹伤害所能达到的最大值。：
输入：
2 3 4 (n,m,k)
1 2
4 8 7
输出：
7
*/

#include "common.h"


class Solution {
public:
	void solve() {
		findParent();
	}

	void findParent() {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> row_energy(n, 0);
		vector<int> column_energy(m, 0);
		for (int i = 0; i < n; ++i)
			cin >> row_energy[i];
		for (int i = 0; i < m; ++i)
			cin >> column_energy[i];

		priority_queue<int, vector<int>, greater<int>> q; // 小顶堆
		for (auto i : row_energy) {
			for (auto j : column_energy) {
				q.push(i + j);
				if (q.size() > k)
					q.pop();
			}
		}
		int max_hit = INT_MAX;
		while (!q.empty()) {
			max_hit = min(q.top(), max_hit);
			q.pop();
		}
		--max_hit;
		cout << max_hit;
	}

	void test() {
		solve();
	}
};
