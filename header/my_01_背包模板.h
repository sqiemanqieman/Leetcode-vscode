#include "common.h"

// 使用二维dp数组
void test() {
    vector<int> weight = { 1, 3, 4 };
    vector<int> value = { 15, 20, 30 };
    int bag_size = 4;
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bag_size + 1, 0));
    dp[0][0] = 0; // or 1 in some case.

    for (int i = 1; i <= weight.size(); ++i) { // start from 1
        for (int j = 0; j <= bag_size; ++j) { // start from 0
            if (weight[i-1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i-1]] + value[i]);
        }
    }
    cout << dp;
}


// 使用一维滚动dp数组 (更好)
void test1(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    dp[0] = 0; // or 1 in some case.
    for (int i = 0; i < weight.size(); i++) { // 遍历物品 start from 0
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量 start from back
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;