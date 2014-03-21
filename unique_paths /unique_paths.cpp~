/*
思路：动态规划，设f(i,j)为到达grid[i][j]的路径数。
则f(i,j) = f(i,j-1) + f(i-1,j);
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int* dp = new int[n]; //注意，是int× 不是int。莫粗心！
        for(int i = 0; i < n; i++){ dp[i] = 1; }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[j] = dp[j-1] + dp[j];
            }
        }
        int result = dp[n-1];
        delete [] dp;
        return result;
    }
};
