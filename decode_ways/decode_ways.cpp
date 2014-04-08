/*
思路：第一直觉是深搜，然后就华丽丽的超时了。
然后就想到动规。work！
设dp[i] 为第长度为i的字符串的可解析的个数;
则总体的状态转移方程为
dp[i] = dp[i-1] + dp[i-2];
当然，在加dp[i-1]时，要判断s[i-1]是否符合要求！即不为0;
在加dp[i-2]时，要判断s[i-2,i-1]是否符合要求！就s[i-2]不为0,则两个字符组成的值属于(0,26];
*/
class Solution {
public:
    int numDecodings(string s) {
        int str_len = s.length();
        if(str_len == 0)
        {
            return 0;
        }
        vector<int> dp(str_len+1, 0);
        dp[0] = 1;//注意，dp[0]的初始值为1，不是0;
        if(s[0] != '0')
        {
            dp[1] = 1;
        }
        for(int i = 2; i < str_len+1; i++)
        {
            if(s[i-1] != '0')
            {
                dp[i] += dp[i-1];
            }
            int two_char_value = atoi(s.substr(i-2, 2).c_str());
            if(s[i-2] != '0' && two_char_value > 0 && two_char_value <= 26) //注意 "00"和"01"情况
            {
                dp[i] += dp[i-2];
            }
        }
        return dp[str_len];
    }
};
