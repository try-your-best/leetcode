/*
思路：看trapping_rain_water.cpp
时间O(n),空间O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int *max_left_height = new int[n]();
        int *max_right_height = new int[n]();
        for(int i = 1; i < n; i++)
        {
           max_left_height[i] = max(max_left_height[i-1], A[i-1]);
           max_right_height[n-1-i] = max(max_right_height[n-i], A[n-i]);
        }
        int sum = 0;
        for(int i = 1; i < n-1; i++)
        {
            sum += max(min(max_left_height[i], max_right_height[i]) - A[i], 0);
        }
        delete[] max_left_height;
        delete[] max_right_height;
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
