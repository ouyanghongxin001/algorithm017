/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
//没思路直接看了题解。。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> dp(26 , 0);
        int len = tasks.size();
        for(char c : tasks){
            dp[c - 'A']++;
        }
        sort(dp.rbegin(), dp.rend());
        int N = dp[0];
        int count = 1;
        while(count < 26 && dp[count] == dp[0])
            count++;
        return max(len, (N - 1) * (n + 1) + count);
    }
};
// @lc code=end

