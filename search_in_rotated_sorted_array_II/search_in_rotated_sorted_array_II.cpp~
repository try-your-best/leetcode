/*
思路：允许数组出现重复元素！
在search_in_rotated_sorted_array的基础上，对于函数RotatedIndex（），当
A[low] == A[mid] && A[mid] == A[high]时，此时无法靠二分缩小范围，只能顺序查找逆转点！
*/

class Solution {
public:
    int FindIndexInOrder(int A[], int low, int high)
    {
        for(int i = low; i < high; i++)
        {
            if(A[i] > A[i+1])
            {
                return i+1;
            }
        }
        return low;
    }
    int RotatedIndex(int A[], int n)
    {
        if(n == 1)
        {
            return 0;
        }
        int low = 0;
        int high = n -1;
        int mid = low;
        while(A[low] >= A[high])
        {
            mid = (low+high)/2;
            if(A[low] == A[mid] && A[mid] == A[high])//顺序查找逆转点!
            {
                return FindIndexInOrder(A, low, high);
            }
            else if(low + 1 == high)
            {
                return high;
            }
            else if(A[low] <= A[mid])
            {
                low = mid;
            }
            else 
            {
                high = mid;
            }
        }
    }
    bool BinarySearch(int A[], int low, int high, int target)
    {
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(A[mid] == target)
            {
                return true;
            }
            else if(A[mid] < target)
            {
                low = mid + 1;
            }
            else 
            {
                high = mid - 1;
            }
        }
        return false;
    }
    bool search(int A[], int n, int target) {
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
