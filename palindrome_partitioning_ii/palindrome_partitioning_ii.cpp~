/*
思路：动态规划
设 dp[i]为字符串0到i的最小的回文分割次数。
dp[i] = min(dp[j] +1) if 0<=j<i; str[j+1..i] 回文。

为避免重复计算，对回文的判断同样用动归。
参考文章:
http://fisherlei.blogspot.jp/2013/03/leetcode-palindrome-partitioning-ii.html
*/

class Solution
{
public:
	int minCut(string s)
	{
		int size = s.size();
		if (size == 0)
		{
			return 0;
		}
		vector<int> dp(size, INT_MAX);
		vector<vector<bool> > isPalind(size, vector<bool>(size));
		for (int i = 0; i < size; ++i)
		{
			isPalind[i][i] = true;
		}
    for(int i = 1; i < size; ++i)
    {
    	for(int j = 0; j < size; ++j)
    	{
    		if(j+i < size)
    		{
    			if(s[j] == s[j+i] && ((i <= 2) || isPalind[j+1][j+i-1]))
    			{
    				isPalind[j][j+i] = true;
    			}
    		}
    	}
    }
		dp[0] = 0;
		for (int i = 1; i < size; ++i)
		{
			if (isPalind[0][i])
			{
				dp[i] = 0;
			}
			else
			{
				for (int j = 0; j < i; ++j)
				{
					if (isPalind[j + 1][i])//如果用函数判别回文，这会产生大量的重复计算！
					{
						if (dp[j] + 1 < dp[i])
						{
							dp[i] = dp[j] + 1;
						}
					}
				}
			}
		}
		return dp[size - 1];
	}
};
