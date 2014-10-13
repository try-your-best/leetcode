/*
������Ŀ��Ҫ�󣬲�Ҫ�����O(n)�ⷨ�����ǲ���Divide & Conquer����Ͱ�ʾ�ˣ��ⷨ��Ȼ�Ƕ��֡��������£�

��������A[left, right]�������ֵ����[i, j](i>=left & j<=right)����mid = (left + right)/2 �ֽ磬�޷��������������

subarray A[i,..j] is
(1) Entirely in A[low,mid-1]
(2) Entirely in A[mid+1,high]
(3) Across mid
����(1) and (2)��ֱ�ӵݹ���⼴�ɣ�����(3)������Ҫ��minΪ���ģ���������ɨ�������ֵ��
��ζ����A[left, Mid]�������ҳ�A[i..mid], ����A[mid+1, right]���ҳ�A[mid+1..j]�����߼Ӻͼ�Ϊ(3)�Ľ⡣
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
