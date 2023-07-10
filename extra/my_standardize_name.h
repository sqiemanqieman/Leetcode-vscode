#pragma once

/*
 2023复旦计算机夏令营机考第一题

1.给你一个数字，加下来n行每行有两个字符串，每个字符串是一个人名，将人名修改为
首字母大写的格式。例如：
输入：
2
svsDZ DAVid
jONE bobe
输出：
Svsdz Davide
Jone Bobe
*/
#include "common.h"

class Solution {
public:
	void solve() {
		findParent();
	}

	void findParent() {
		int n;
		cin >> n;
		vector<string> names(n, "");
		while (cin.get() != '\n') continue;
		for (int i = 0; i < n; ++i) {
			string str;
			getline(cin, names[i]);
		}
		for (auto& i : names) {
			bool is_leading_chac = true;
			for (auto& j : i) {
				if (isblank(j)) {
					is_leading_chac = true;
				}
				else if (is_leading_chac) {
					is_leading_chac = false;
					j = toupper(j);
					continue;
				}
				else j = tolower(j);
			}
		}
		for (auto& i : names) {
			cout << i << endl;
		}
	}

	void test() {
		solve();
	}
};
