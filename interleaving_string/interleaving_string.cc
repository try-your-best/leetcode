/*
思路：
参考leetcode详解
设状态 f[i][j],表示 s1[0,i] 和 s2[0,j],匹配 s3[0, i+j]。如果 s1 的最后一个字符等
于 s3 的最后一个字符,则 f[i][j]=f[i-1][j];如果 s2 的最后一个字符等于 s3 的最后一个字符,
则 f[i][j]=f[i][j-1]。因此状态转移方程如下:
f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j])|| (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_len = s1.size();
        int s2_len = s2.size();
        int s3_len = s3.size();
        if(s1_len + s2_len != s3_len)
        {
            return false;
        }
        vector<vector<bool> > dp(s1_len+1, vector<bool>(s2_len+1, true));//简洁的初始化！
        for(int i = 1; i <= s1_len; i++)
        {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];//边界处理
        }
        for(int i = 1; i <= s2_len; i++)
        {
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];//边界处理
        }
        for(int i = 1; i <= s1_len; i++)
        {
            for(int j = 1; j <= s2_len; j++)
            {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[s1_len][s2_len];
    }
};
