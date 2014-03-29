/*
时间O(n^2),空间O(1) 会超时！
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
//    int Min(int a, int b){ return a < b ? a : b;}
    int ComputeCapacity(int A[], int len, int cur_posi)
    {
        int max_left_height = 0;
        int max_right_height = 0;
        for(int i = 0; i < cur_posi; i++)
        {
            if(A[i] > max_left_height)
            {
                max_left_height = A[i];
            }
        }
        for(int j = len-1; j > cur_posi; j--)
        {
            if(A[j] > max_right_height)
            {
                max_right_height = A[j];
            }
        }
        int sum = max(0,min(max_left_height, max_right_height)- A[cur_posi]);
        return sum;
    }
    int trap(int A[], int n) {
        int sum = 0;
        for(int i = 1; i < n-1; i++)
        {
            sum += ComputeCapacity(A, n, i);
        }
        return sum;
    }
};

void Test()
{
	//int A[] = {5,2,1,2,1,5};
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	//int A[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
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
