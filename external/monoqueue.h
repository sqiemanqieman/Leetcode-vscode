#include "bits/stdc++.h"
using namespace std;


// 单调队列
class MonotoneQueue {
public:
    void pop(int value) {
        if (que.front() == value)
            que.pop_front();
    }

    void push(int value) {
        while (!que.empty() && value > que.back())
            que.pop_back();
        que.push_back(value);
    }

    int front() {
        return que.front();
    }
    deque<int> que; // 使用deque实现单调队列
};