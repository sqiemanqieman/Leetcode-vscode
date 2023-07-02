#pragma once

#define problem 13

#if problem == 13
#include "../header/47.全排列-ii.h"

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
#include "leetcode_239_max_sliding_window.h"
using Solution = MaxSlidingWindow;

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
