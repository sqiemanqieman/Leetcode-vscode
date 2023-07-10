#pragma once
/*
 2023复旦计算机夏令营机考第三题

给你一个n*m的网格以及一个起点(网格从1开始数)，给出从起点出发，遍历所有网
格，最后回到起点的路径(m、n不全为奇数，题目一定有解)。
输入：←
43(n=4,m=3)
22(从2,2出发)(测试用例中70%是从1,1出发)
输出：
3, 2
3, 3
4, 3
4, 2
4, 1
3, 1
2, 1
1, 1
1, 2
1, 3
2, 3
2, 2
*/

#include "common.h"


class Solution {
public:
	void solve(int m, int n, int i, int j) {
		vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));
		vector<pair<int, int>> path;
		backtracking(m, n, i, j, i, j, visited, path);
		for (int i = 0; i < int(path.size()); ++i)
			cout << path[i].first << ' ' << path[i].second << endl;
	}

	bool backtracking(int m, int n, int s, int t, int i, int j,
		vector<vector<bool>>& visited, vector<pair<int, int>>& path) {
		if (i == s && j == t && !path.empty()) {
			return path.size() == m * n;
		}

		for (int k = 0; k < 4; ++k) {
			int new_i = i + (int)round(cos(k * 3.1415926 / 2));
			int new_j = j + (int)round(sin(-k * 3.1415926 / 2));
			if (!valid(m, n, new_i, new_j, visited)) continue;
			visited[new_i][new_j] = true;
			path.push_back(pair<int, int>(new_i, new_j));
			if (backtracking(m, n, s, t, new_i, new_j, visited, path)) 
				return true;
			path.pop_back();
			visited[new_i][new_j] = false;
		}
		return false;
	}

	bool valid(int m, int n, int i, int j, vector<vector<bool>>& visited) {
		if (i < 1 || i > m || j < 1 || j > n) return false;
		return !visited[i][j];
	}
	
	void test() {
		string s; 
		solve(4,3,2,2);
	}
};

