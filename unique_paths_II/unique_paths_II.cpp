/*
思路：跟题目unique_paths类似。
动态规划，设f(i,j)为到达obstacleGrid[i][j]的路径数。
obstacleGrid[i][j] == 1 时, f(i,j) = 0;
obstacleGrid[i][j] == 0 ,则 f(i,j) = f(i,j-1) + f(i-1,j); 
为了简洁处理边界条件，我们将f(i,j)设置为到达obstacleGrid[i-1][j-1]的路径数。
f(0,1) = 1; f(0,j) = 0; f(i,0) = 0;
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int *dp = new int[col+1];//为了处理边界条件，数组长度为col+1！
        for(int i = 0; i < col+1; i++){ dp[i] = 0; }
        dp[1] = 1;
        for(int i = 0; i < row; i++)
        {
            for(int j = 1; j < col + 1; j++)
            {
                 if(obstacleGrid[i][j-1])
                 {
                    dp[j] = 0;
                 }
                 else
                 {
                     dp[j] = dp[j-1] + dp[j];
                 }
            }
        }
        int result = dp[col];
        delete [] dp;
        return result;
    }
};
