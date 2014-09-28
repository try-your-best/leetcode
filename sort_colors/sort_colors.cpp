/*
思路：计数排序！
*/
class Solution {
public:
    void sortColors(int A[], int n) {
        vector<int> count(3);
        for(int i = 0; i < n; ++i)
        {
            count[A[i]]++;
        }
        int index = 0;
        for(int i =0; i < 3; ++i)
        {
            for(int j = 0; j < count[i]; ++j)
            {
                A[index] = i;
                index++;
            }
        }
    }
};
