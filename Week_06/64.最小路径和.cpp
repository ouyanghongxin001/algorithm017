/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = m - 2; i >= 0; i --){
            grid[i][n - 1] += grid[i + 1][n - 1];
        }
        for (int i = n - 2; i >= 0; i --){
            grid[m - 1][i] += grid[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; i --){
            for (int j = n - 2; j >= 0; j --){
                grid[i][j] += min(grid[i + 1][j] , grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
};
// @lc code=end

