/*
思路：
i从0到blue index扫描，
遇到0，放在red index位置，red index后移；
遇到2，放在blue index位置，blue index前移；
遇到1，i后移。
扫描一遍得到排好序的数组。时间O(n)，空间O(1)，
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0;
        int blue = n-1;
        int i = 0;
        while(i < blue+1) //注意，不是 i < n;否则blue有可能回减到小于0。
        {
            if(A[i] == 0)
            {
                swap(A[i], A[red]);
                red++;
                i++;
                continue;
            }
            if(A[i] == 2)
            {
                swap(A[i], A[blue]);
                blue--;
                continue;
            }
            i++;
        }
    }
};
