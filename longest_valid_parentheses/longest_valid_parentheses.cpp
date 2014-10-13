/*
这道题可以用一维动态规划逆向求解。假设输入括号表达式为String s，维护一个长度为s.length的一维数组dp[]，数组元素初始化为0。 
dp[i]表示以s[i]为开头字符，从s[i]到s[s.length - 1]最长的有效匹配括号子串长度。则存在如下关系：
dp[s.length - 1] = 0;
从i - 2 -> 0逆向求dp[]，并记录其最大值。若s[i] == '('，则在s中从i开始到s.length - 1计算s[i]的值。
这个计算分为两步，通过dp[i + 1]进行的（注意dp[i + 1]已经在上一步求解）：
1在s中寻找从i + 1开始的有效括号匹配子串长度，即dp[i + 1]，跳过这段有效的括号子串，查看下一个字符，
其下标为j = i + 1 + dp[i + 1]。若j没有越界，并且s[j] == ‘)’，则s[i ... j]为有效括号匹配，dp[i] =dp[i + 1] + 2。

2在求得了s[i ... j]的有效匹配长度之后，若j + 1没有越界，则dp[i]的值还要加上从j + 1开始的最长有效匹配，即dp[j + 1]。
参考：
http://blog.csdn.net/abcbc/article/details/8826782
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        vector<int> dp(size);
        int maxLen = 0; // must be 0, not INT_MIN
        for(int i = size-2; i >= 0; --i) // note --i, not ++i
        {
            if(s[i] == '(')
            {
                int j = i+1 + dp[i+1];
                if(j < size)
                {
                    if(s[j] == ')')
                    {
                        dp[i] = dp[i+1]+2;
                        if(j+1 < size)
                        {
                            dp[i] += dp[j+1];
                        }
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
