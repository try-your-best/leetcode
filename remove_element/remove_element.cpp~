/*
思路：借用快排中分界的思想。将等于目标元素的值都移动到数组的尾端！
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = n;
        for(int j = n-1; j>=0; --j)
        {
            if(A[j] == elem)
            {
                swap(A[j], A[--i]);
            }
        }
        return i; //注意，最终i的值刚好就是新队列的长度！
    }
};
