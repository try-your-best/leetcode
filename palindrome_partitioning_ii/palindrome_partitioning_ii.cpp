/*
˼·����̬�滮
�� dp[i]Ϊ�ַ���0��i����С�Ļ��ķָ������
dp[i] = min(dp[j] +1) if 0<=j<i; str[j+1..i] ���ġ�

Ϊ�����ظ����㣬�Ի��ĵ��ж�ͬ���ö��顣
�ο�����:
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
					if (isPalind[j + 1][i])//����ú����б���ģ��������������ظ����㣡
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
