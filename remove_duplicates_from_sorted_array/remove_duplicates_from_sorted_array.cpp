/*
思路:只有当A[i]与A[index]的值不同时，才将A[i]赋给A[index+1]。这样可以保证A[]没有重复元素。
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
        {
            return 0;
        }
        int index = 0;
        for(int i = 1; i < n; i++)
        {
            if(A[index] != A[i])
            {
                A[++index] = A[i];
            }
        }
        return index+1;
    }
};
