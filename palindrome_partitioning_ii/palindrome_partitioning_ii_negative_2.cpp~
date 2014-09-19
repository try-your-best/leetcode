/*
重复求回文，超时！！
*/
class Solution {
public:
    bool isPalindrome(const string& str, int start, int end)
    {
        while(start < end)
        {
            if(str[start++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
        int size = s.size();
        if(size == 0)
        {
            return 0;
        }
        vector<int> dp(size, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < size; ++i)
        {
            if(isPalindrome(s, 0, i))
            {
                dp[i] = 0;
            }
            else
            {
                for(int j = 0; j < i; ++j)
                {
                    if(isPalindrome(s, j+1, i))
                    {
                        if(dp[j]+1 < dp[i])
                        {
                            dp[i] = dp[j] + 1;
                        }
                    }
                }
            }
        }
        return dp[size-1];
    }
};
