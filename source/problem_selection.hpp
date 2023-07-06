#pragma once
#define RUN_IN_LOCAL

#define problem 38

#if problem == 38
#include "../header/376.摆动序列.cpp"

#elif problem == 37
#include "../header/714.买卖股票的最佳时机含手续费.cpp"

#elif problem ==36
#include "../header/309.最佳买卖股票时机含冷冻期.cpp"

#elif problem == 35
#include "../header/188.买卖股票的最佳时机-iv.cpp"

#elif problem == 34
#include "../header/123.买卖股票的最佳时机-iii.cpp"

#elif problem == 33
#include "../header/122.买卖股票的最佳时机-ii.cpp"

#elif problem == 32
#include "../header/121.买卖股票的最佳时机.cpp"

#elif problem == 31
#include "../header/518.零钱兑换-ii.cpp"

#elif problem == 30
#include "../header/474.一和零.cpp"

#elif problem == 29
#include "../header/494.目标和.cpp"

#elif problem == 28
#include "../header/1049.最后一块石头的重量-ii.cpp"

#elif problem == 27
#include "../header/416.分割等和子集.cpp"

#elif problem == 26
#include "../header/84.柱状图中最大的矩形.cpp"

#elif problem ==25
#include "../header/503.下一个更大元素-ii.cpp"

#elif problem ==24
#include "../header/496.下一个更大元素-i.cpp"

#elif problem == 23
#include "../header/739.每日温度.cpp"

#elif problem == 22
#include "../header/42.接雨水.cpp"

#elif problem == 21
#include "../header/96.不同的二叉搜索树.cpp"

#elif problem == 20
#include "../header/343.整数拆分.cpp"

#elif problem == 19
#include "../header/63.不同路径-ii.cpp"

#elif problem == 18
#include "../header/62.不同路径.cpp"

#elif problem == 17
#include "../header/746.使用最小花费爬楼梯.cpp"

#elif problem == 16
#include "../header/37.解数独.cpp"

#elif problem == 15
#include "../header/51.n-皇后.cpp"

#elif problem == 14
#include "../header/332.重新安排行程.cpp"

#elif problem == 13
#include "../header/47.全排列-ii.cpp"

#elif problem ==12
#include "leetcode_90_subset_2.h"

#elif problem == 11
#include "my_binary_tree_reconstruction.h"

#elif problem == 10
#include "my_maximum_string_reward.h"

#elif problem == 9
#include "my_parent_value.h"
using Solution = ParentValue;

#elif problem == 8
#include "my_protect_solidier.h"

#elif problem == 7
#include "my_standardize_name.h"

#elif problem == 6
#include "leetcode_101_is_symmetric.h"

#elif problem == 5
#include "leetcode_347_top_k_frequent.h"
using Solution = TopKFrequent;

#elif problem == 4
#include "../header/239.滑动窗口最大值.cpp"

#elif problem == 3
#include "leetcode_459_repeated_substring_pattern.h"
using Solution = RepeatedSubstringPattern;

#elif problem == 2
#include "leetcode_28_KMP.h"
using Solution = KMP;

#elif problem == 1
#include "my_simple_calculator.h"
using Solution = SimpleCalculator;

#elif problem == 0
#include "leetcode_18_four_sum.h"
using Solution = FourSum;

#else 
#include "default_problem.hpp"

#endif // problem == ?
