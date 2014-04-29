/*
思路：参考 leetcode详解！
既然可以用记忆化搜索,这题也一定可以用动规。设状态为 f[n][i][j],表示长度为 n,起
点为 s1[i] 和起点为 s2[j] 两个字符串是否互为 scramble,则状态转移方程为
f[n][i][j]} = (f[k][i][j] && f[n-k][i+k][j+k])|| (f[k][i][j+n-k] && f[n-k][i+k][j])

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int str_len = s1.size();
        if(str_len != s2.size())
        {
            return false;
        }
        vector<vector<vector<bool> > > dp(str_len+1, vector<vector<bool> >(str_len, vector<bool>(str_len, false)));
        for(int i = 0; i < str_len; i++)
        {
            for(int j = 0; j < str_len; j++)
            {
                dp[1][i][j] = s1[i]== s2[j];
            }
        }
        for(int n = 1; n <= str_len; n++)
        {
            for(int i = 0; i+n <= str_len; i++)
            {
                for(int j = 0; j+n <= str_len; j++)
                {
                    for(int k = 1; k < n; k++)
                    {
                        if((dp[k][i][j] && dp[n-k][i+k][j+k]) || (dp[k][i][j+n-k] && dp[n-k][i+k][j]))
                        {
                            dp[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[str_len][0][0];
    }
};


void Test()
{
	Solution s;
	s.isScramble("a", "a");
}

int main()
{
	Test();
	return 0;
}
