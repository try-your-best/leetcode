/*
思路：先二分查找，找到起点。如果找不到，直接退出。再利用找到的起点，二分查找终点。一次A掉！
*/
class Solution {
public:
    int BinarySearchStartPoint(int A[], int n, int target)
    {
        int low = 0;
        int high = n -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(A[mid] == target)
            {
                if(mid == 0 || A[mid-1] < target)//起点条件
                {
                    return mid;
                }
                else 
                {
                    high = mid-1;
                }
            }
            else if(A[mid] > target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return -1;
    }
    int BinarySearchEndPoint(int A[], int n, int start ,int target)
    {
        int low = start;
        int high = n -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(A[mid] == target)
            {
                if(mid == n-1 || A[mid+1] > target)//终点条件
                {
                    return mid;
                }
                else 
                {
                    low = mid+1;
                }
            }
            else if(A[mid] > target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        //return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        int start_point = BinarySearchStartPoint(A, n, target); 
        if(start_point == -1)
        {
            return vector<int>(2, -1);
        }
        int end_point = BinarySearchEndPoint(A, n, start_point, target);
        return vector<int>{start_point, end_point};
    }
};
