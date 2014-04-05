/*
思路：动态规划，实在是很难想到用动归。纯看答案实现！
以 i 为根的树的个数等于左子树的个数乘以右子树的个数。具体的参考leetcode详解
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n+1; i++)
        {
            for(int k = 0; k < i; k++)
            {
                dp[i] += dp[k] * dp[i-1-k];
            }
        }
        return dp[n];
    }
};
