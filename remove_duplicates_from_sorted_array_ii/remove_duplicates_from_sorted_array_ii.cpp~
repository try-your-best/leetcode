/*
思路：每次考虑当前节点与前一节点的值。设置标志位判断是否重复过。记得要修改数组的值，
重复超过两次的要删除。len用于记录最后数组的长度，也用于标示待删除点。

*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n) return 0;
        bool dup = false;
        int len = 1;
        for(int i = 1; i < n; ++i)
        {
            if(A[i] == A[i-1])
            {
                if(!dup)
                {
                     A[len] = A[i];
                    ++len;
                    dup = true;
                }
            }
            else
            {
                 A[len] = A[i];
                 ++len;
                 dup = false;
            }
        }
        return len;
    }
};
