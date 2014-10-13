/*
但是题目中要求，不要用这个O(n)解法，而是采用Divide & Conquer。这就暗示了，解法必然是二分。分析如下：

假设数组A[left, right]存在最大值区间[i, j](i>=left & j<=right)，以mid = (left + right)/2 分界，无非以下三种情况：

subarray A[i,..j] is
(1) Entirely in A[low,mid-1]
(2) Entirely in A[mid+1,high]
(3) Across mid
对于(1) and (2)，直接递归求解即可，对于(3)，则需要以min为中心，向左及向右扫描求最大值，
意味着在A[left, Mid]区间中找出A[i..mid], 而在A[mid+1, right]中找出A[mid+1..j]，两者加和即为(3)的解。
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
      int maxV = INT_MIN;
      return maxArray(A, 0, n-1, maxV);
    }

    int maxArray(int A[], int left, int right, int& maxV)
    {
      if(left>right)
         return INT_MIN;
       int mid = (left+right)/2;
       int lmax = maxArray(A, left, mid -1, maxV);
       int rmax = maxArray(A, mid + 1, right, maxV);
       maxV = max(maxV, lmax);
       maxV = max(maxV, rmax);
       int sum = 0, mlmax = 0;
       for(int i= mid -1; i>=left; i--)
       {
         sum += A[i];
         if(sum > mlmax)
           mlmax = sum;
       }
       sum = 0; int mrmax = 0;
       for(int i = mid +1; i<=right; i++)
       {
         sum += A[i];
         if(sum > mrmax)
           mrmax = sum;
       }
       maxV = max(maxV, mlmax + mrmax + A[mid]);
       return maxV;
    }
};
