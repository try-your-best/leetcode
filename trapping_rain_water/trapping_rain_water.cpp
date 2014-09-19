/*
思路：
对于每个柱子,找到其左右两边最高的柱子, 柱子i对应能容纳的面积就是:
max(min(max_left_height[i], max_right_height[i]) - A[i], 0),所以
1. 从左往右扫描一遍,对于每个柱子,求取左边最大值;
2. 从右往左扫描一遍,对于每个柱子,求最大右值;
3. 再扫描一遍,把每个柱子的面积并累加。
也可以,
1. 扫描一遍,找到最高的柱子,这个柱子将数组分为两半;
2. 处理左边一半;
3. 处理右边一半。
下面是采取第后者。时间O(n),空间O(1)
后者的总体思路和前者是一致的。先找最高的柱子，对左半部分，每根柱子右边最大值找到了，现在只要找左边最大值，
通过left_peak维护。同理，对右半部分，现在只要找其右边最大值，通过right_peak维护。

trapping_rain_water_1.cpp 则是采用前者，时间O(n),空间O(n);
trapping_rain_water_negative_2.cpp 时间O(n^2),空间O(n1);会超时！！
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int max_height_index = 0;
        int sum = 0;
        for(int i = 1; i < n; i++)
        {
            if(A[i] > A[max_height_index])
            {
               max_height_index = i; 
            }
        }
        for(int i = 0, left_peak = 0; i < max_height_index; i++)
        {
            if(left_peak > A[i])
            {
                sum += left_peak - A[i];
            }
            else
            {
                left_peak = A[i];
            }
        }
        for(int j = n-1, right_peak = 0; j > max_height_index; j--)
        {
            if(right_peak > A[j])
            {
                sum += right_peak - A[j];
            }
            else
            {
                right_peak = A[j];
            }
        }
        return sum;
    }
};

void Test()
{
	//int A[] = {5,2,1,2,1,5};
	//int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int A[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
	int len = sizeof(A)/sizeof(int);
	Solution s;
	cout << s.trap(A, len) << endl;
}

int main()
{
    Test();
    return 0;
}

/*
Input:	[6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3]
Output:	71
Expected:83
*/
