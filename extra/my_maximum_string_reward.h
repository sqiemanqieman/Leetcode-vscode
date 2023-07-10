#pragma once

/*
2023复旦计算机夏令营机考第五题

长为n的字符串，只有'.'和'#'两个字符,你需要把按一定的顺序把'.'换成'#',每次转换时,
你能获得的奖励为'.'右边相邻的'#'数目+'.'左边相邻的'#'数目+1, 求把所有'.'换成'#'
能得到的最大奖励。
输入：
4
....
输出：
10 (1+2+3+4)

输入：
6
.#.##.
输出
15 (按照3->1->6的顺序，获得的奖励为4+5+6)
*/

#include "common.h"
//#include <boost/bind/bind.hpp>
//#include <boost/bind/std_placeholders.hpp>
//#include <boost/function.hpp>
//#include <boost/lambda/if.hpp>

//bool f(int a, int b) { return a < b; }

// 贪心 正确性有待证明
class Solution {
public:
	void solve() {
		// Input
		int n;
		cin >> n;
		while (cin.get() != '\n') continue;
		string s;
		getline(cin, s);

		// Post-process input 
		list<int> l;
		l.push_back(0);
		int count = 0;
		for (auto& i : s) {
			if (i == '.') {
				if (count) l.push_back(count);
				l.push_back(0);
				count = 0;
			}
			else ++count;
		}
		if (count) l.push_back(count);
		l.push_back(0);

		// Core code
		list<int>::iterator pre, cur, next;
		int M = 0;
		int res = 0;
		do {
			pre = l.begin(); cur = pre; ++cur; next = cur; ++next;
			list<int>::iterator pos;
			while(next != l.end()){
				if (*cur == 0) {
					if (*pre + *next + 1 > M) {                                
						M = *pre + *next + 1;
						pos = cur;
					}
				}
				++pre; ++cur; ++next;
			}
			auto a = pos; auto b = pos; --a; ++b;
			*pos = M;
			res += M;
			if (*a) l.erase(a);
			if (*b) l.erase(b);
		} while (l.size() > 3);

		// Output
		cout << res;
	}

	void test() {
		solve();
	}
};