/*
思路：二分查找逆序点，再以该点为分界，二分查找，找到目标元素！！
这种方法的前提是数组中没有重复元素！
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int RotatedIndex(int A[], int n)//注意，这种二分查找的模式跟普通的不太相同！
    {
        if(n == 1)//注意该特例！！
        {
            return 0;
        }
        int low = 0; 
        int high = n - 1;
        int mid = low;//如果整个数组有序，则返回0;
        while(A[low] >= A[high])
        {
            if(low + 1 == high)
            {
                return high;
            }
            mid = (low+high)/2;
            if(A[mid] >= A[low])
            {
                low = mid;
            }
            else if(A[mid] <= A[high])
            {
                high = mid;
            }
        }
        return mid;
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
    int A[] = {1};
    int len = sizeof(A)/sizeof(int);
    Solution s;
    cout << s.search(A, len, 0) << endl;
}

int main()
{
    Test();
    return 0;
}
