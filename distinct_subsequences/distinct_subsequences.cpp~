/*
题意：给出两个字符串S和T，求S的所有子串中与T相同的有多少个。
思路：动态规划。想不出来，参考答案的。
设 状 态 为 f (i, j), 表 示 T[0,j] 在 S[0,i] 里 出 现 的 次 数。 
若 S[i]!=T[j] 则 f (i, j) = f (i − 1, j);
若 S[i]==T[j],则可以使用 S[i],此时 f (i, j) = f (i − 1, j) + f (i − 1, j − 1)。
时间复杂度 O(m*n),空间复杂度 O(n)
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int s_len = S.length();
        int t_len = T.length();
        if(s_len < t_len)
            return 0;
		//为了简化对边界条件的处理。这里都假设字符串S和T的下标是从1开始的。
		//在S和T的下标0的位置插入一个与其它任意字符都不相等的字符。当然这只是概念上的
		//真实的字符串还是从下标为0开始的。
		//让f(0,0) = 1; f(0,j) = 0 当 j > 1; f(i,0) = 0 当 i > 1;
		int* dp = new int[t_len + 1]; //按照上面的理念，让dp的长度为 t_len + 1
        dp[0] = 1; 
        for(int i = 1; i < t_len+1; i++)
        {
            dp[i] = 0;
        }
        for(int i = 0; i < s_len; i++)
        {
            for(int j = t_len-1; j >= 0; j--)//要细心，不要收快写成 j++！！
            {
                if(S[i] != T[j])//字符串真实的下标从0开始。
                {
                    dp[j+1] = dp[j+1];
                }
                else
                {
                    dp[j+1] = dp[j+1] + dp[j];
                }
            }
        }
        int distinct_num = dp[t_len];
        delete[] dp;
        return distinct_num;
    }
};

void Test()
{
    Solution s;
    string str1("a");
    string str2("b");
    int result = s.numDistinct(str1, str2);
    cout << result << endl;
}

int main()
{
    Test();
    return 0;
}
