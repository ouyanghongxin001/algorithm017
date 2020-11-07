/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int m = s.size();
        vector<int> dp(m + 1, 1);
        for (int i = 2; i <= m; i ++){
            if(s[i - 1] == '0'){
                if(s[i - 2] == '1' || s[i - 2] == '2'){
                    dp[i] = dp[i - 2];
                }
                else{
                    return 0;
                }
            }
            else if(s[i - 2] == '1'){
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else if(s[i - 2] == '2' && s[i - 1] > '0' && s[i - 1] <= '6'){
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else{
                dp[i] = dp[i - 1];
            }

        }
        return dp[m];
    }
};
// @lc code=end

