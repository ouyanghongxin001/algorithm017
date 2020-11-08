/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
//我知道我写得很冗余。。。请大佬帮我优化
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int maxl = 0;
        int dp[m + 1][n + 1];
        for (int i = 0; i <= n; i ++)
            dp[0][i] = 0;
        for (int i = 0; i <= m; i ++)
            dp[i][0] = 0;
        for (int i = 1; i <= m; i ++){
            for (int j = 1; j <= n; j ++){
                if(matrix[i - 1][j - 1] == '1'){
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    maxl = dp[i][j] > maxl ? dp[i][j] : maxl;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxl * maxl;
    }
};
// @lc code=end

