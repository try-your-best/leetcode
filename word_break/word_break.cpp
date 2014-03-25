/*
思路：一开始想到的是用深搜。可是会超时，特别是类似"aaaaaaaaaab",dict = {a,aa,aaa}。
后来看答案，用动态规划。
设状态为 f (i),表示 s[0,i] 是否可以分词,则状态转移方程为
f (i) = any_of (f(j)&&s[j + 1, i] ∈ dict), 0 ≤ j < i
动规,时间复杂度 O(n^2),空间复杂度 O(n)
*/
#include<string>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) { //unordered_set<string> &dict
        vector<bool> dp(s.size()+1, false);
        int str_len = s.size();
        dp[0] = true;
        for(int i = 1; i <= str_len; i++)
        {
            for(int j = i-1; j >= 0; j--)//注意，不要把j--写成j++。已经犯过不少次这种低级错误了。从后往前计算，或从前往后都可以。
            {
                if(dp[j]&&(dict.count(s.substr(j,i-j))>0))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[str_len];
    }
};

void Test()
{
	string str("a");
	set<string> dict;
        Solution s;
	s.wordBreak(str, dict);
}

int main()
{
	Test();
	return 0;
}
