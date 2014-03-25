#include<iostream>
#include<vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(A[j] >= (i - j))
                {
                    dp[i] = dp[i] > dp[j]+1 ? dp[j]+1 : dp[i];
                }
            }
        }
        return dp[n-1];
    }
};

void Test()
{
	int A[] = {1,2,3};
	int len = sizeof(A)/sizeof(int);
        cout << len << endl;
        Solution s;
	cout << s.jump(A, len) << endl;
}

int main()
{
	Test();
	return 0;
}
