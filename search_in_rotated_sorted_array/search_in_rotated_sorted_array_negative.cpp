#include<iostream>
using namespace std;

class Solution {
public:
    int RotatedIndex(int A[], int n)
    {
        int low = 0; 
        int high = n - 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(mid == 0)
            {
                low = mid+1;
            }
            else if(A[mid] <= A[low])
            {
                if(A[mid] < A[mid-1])
                {
                    return mid;
                }
                else
                {
                    high = mid -1;
                }
            }
            else// if(A[mid] > A[low])
            {
                low = mid +1;
            }
        }
        return 0;
    }
    int BinarySearch(int A[], int low, int high, int target)
    {
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(A[mid] == target)
            {
                return mid;
            }
            else if(A[mid] > target)
            {
                high = mid -1;
            }
            else
            {
                low = mid +1;
            }
        }
        return -1;
    }
    int search(int A[], int n, int target) {
        int rotated_index = RotatedIndex(A, n);
        cout << rotated_index << endl;
        if(rotated_index == 0)
        {
            return BinarySearch(A, 0, n-1, target);
        }
        else
        {
             if(target > A[n-1])
             {
                 return BinarySearch(A, 0, rotated_index-1, target);
             }
             else
             {
                 return BinarySearch(A, rotated_index, n-1, target);
             }
        }
    }
};

void Test()
{
    int A[] = {4,5,6,7,0,1,2};
    int len = sizeof(A)/sizeof(int);
    Solution s;
    cout << s.search(A, len, 0) << endl;
}

int main()
{
    Test();
    return 0;
}
