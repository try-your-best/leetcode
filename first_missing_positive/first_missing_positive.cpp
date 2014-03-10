/*
思路：
题目要求是找到给定数组中第一个缺失的正数。
注意,0不是正数。
交换数组中元素的位置，将值为i的放在第i-1个位置。交换后再遍历数组，
如果第i-1个位置的值不是i，则i为缺失的值。
*/ 

class Solution {
private:
    void Swap(int& a ,int& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
public:
    int firstMissingPositive(int A[], int n) {
        int index = 0;
        while(index < n)
        {   // A[index] != A[A[index]-1] 为了防止类似 [1,1] 的情况，这样程序会进入死循环
            if(A[index] > 0 && A[index] <= n && A[index] != index + 1 && A[index] != A[A[index]-1])
            {
                Swap(A[index], A[A[index]-1]);
            }
            else
            {
                index++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(A[i] != i+1)
                return i+1;
        }
        return n+1;//注意，当数组中的值都在的时候，缺失值为n+1;
    }
};
