

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.length();
        bool* *dp = new bool*[str_len];
        for(int i = 0; i < str_len; i++)
        {
            dp[i] = new bool[str_len]();
        }
        int max_len = 0;
        int start = 0;
        for(int i = 0; i < str_len; i++)
        {
            dp[i][i] = true;
            for(int j = 0; j < i; j++)
            {
                if(s[j] == s[i] && (j+1 == i || dp[j+1][i-1]))
                {
                    dp[j][i] = true;
                    int cur_len = i - j + 1;
                    if(cur_len > max_len)
                    {
                        max_len = cur_len;
                        start = j;
                    }
                }
            }
        }
        for(int i = 0; i < str_len; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
        return s.substr(start, max_len);
    }
};

void Test()
{
   string str("1221");
   Solution s;
   cout << s.longestPalindrome(str) << endl;
}

int main()
{
    Test();
    return 0;
}
