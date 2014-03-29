/*
思路：注意，这种思路有bug！
在柱子中寻找凸点，即先升序后降序。对边界值要特殊处理。
收集各个凸点，再递归计算面积。
面积计算公式：选左右两个凸点，如果两个凸点间的凸点均比他们矮，
则计算面积，否则以当前凸点为分界，递归计算。
*/
#include<iostream>
#include<vector>
using namespace std;

void Print(int A[], vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        cout << A[nums[i]] <<" ";
    }
    cout << endl;
}

class Solution {
public:
    int Min(int a, int b){ return a < b ? a : b;}
    int ComputeCapacity(int A[], int start, int end)
    {
        int width = (end - start -1);
        if(width <= 0)
        {
            return 0;
        }
        int valid_height = Min(A[start], A[end]);
        int sum = width * valid_height;
        for(int i = start+1; i < end; i++)
        {
            sum -= Min(A[i], valid_height);
        }
        return sum;
    }
    int CollectCapacity(int A[], vector<int>& compute_index, int start, int end)
    {
		if(compute_index.size() <= 1)
		{
			return 0;
		}
		int select_point = end;
        for(int i = start+1; i < end; i++)
        {
            if(A[compute_index[i]] <= A[compute_index[start]] && A[compute_index[i]] <= A[compute_index[end]])
            {
                continue;
            }
            else
            {
                select_point = i;
                break;
            }
        }
        cout <<"select: "<< A[compute_index[select_point]] << endl;
        if(select_point == end)
        {
            return ComputeCapacity(A, compute_index[start], compute_index[end]);
        }
        else
        {
            return CollectCapacity(A, compute_index, start, select_point) + CollectCapacity(A, compute_index, select_point, end);
        }
    }
    int trap(int A[], int n) {
        if(n <= 2)
        {
            return 0;
        }
        vector<int> compute_index;
        int index = 0;
        while(index < n -1 && A[index] <= A[index+1]){index++;}   //先找降
        compute_index.push_back(index);
	index++;
        while(index < n-1)
        {
            while(index < n-1 && A[index] >= A[index+1]){index++;}//找升
            if(index == n - 1)
            {
                break;//到末尾一直是降序
            }
            index++;
            while(index < n-1 && A[index] <= A[index+1]){index++;}//找降
            compute_index.push_back(index);
            index++;
        }
        Print(A, compute_index);
        int sum = CollectCapacity(A, compute_index, 0, compute_index.size()-1);
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
