/*
最长和子序列！
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(curSum < 0)
            {
                curSum = A[i];
            }
            else
            {
                curSum += A[i];
            }
            if(curSum > maxSum)
            {
                maxSum = curSum;
            }
        }
        return maxSum;
    }
};
