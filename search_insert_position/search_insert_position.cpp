/*
思路：二分查找，一次A掉！
*/
class Solution {
public:
    int BinarySearch(int A[], int n, int target)
    {
        int low = 0;
        int high = n-1;
        while(low < high)
        {
            int mid = (low+high)/2;
            if(A[mid] == target)
            {
                return mid;
            }
            else if(A[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if(A[low] >= target)// low == high
        {
            return low;
        }
        else
        {
            return low+1;
        }
    }
    int searchInsert(int A[], int n, int target) {
        return BinarySearch(A, n, target);
    }
};
