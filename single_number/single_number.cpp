//思路:利用异或的性质： a ^ a = 0; 0 ^ a = a;
class Solution {
public:
    int singleNumber(int A[], int n) {
        for(int i = 1; i < n; i++)
        {
            A[i] ^= A[i-1];
        }
        return A[n-1];
    }
};
