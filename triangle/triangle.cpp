/*
思路：动态规划！！
对第i行的节点
dp[j] = min(dp[j], dp[j]) + triangle[i][j];
这里要处理的边界条件是每一行的尾和头节点。
对于末尾节点，使对应的dp[] 为INT_MAX;
对于头节点则单独处理。
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        vector<int> dp(triangle[row-1].size(), INT_MAX);
        dp[0] = triangle[0][0];
        for(int i = 1; i < row; ++i)
        {
            for(int j = triangle[i].size()-1; j > 0; --j)
            {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        int minSum = INT_MAX;
        for(int i = 0; i < triangle[row-1].size(); ++i)
        {
            minSum = min(minSum, dp[i]);
        }
        return minSum;
    }
};
