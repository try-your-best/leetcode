/*
˼·:ֻ�е�A[i]��A[index]��ֵ��ͬʱ���Ž�A[i]����A[index+1]���������Ա�֤A[]û���ظ�Ԫ�ء�
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