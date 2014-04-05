/*
˼·�����ֲ�������㣬���Ըõ�Ϊ�ֽ磬���ֲ��ң��ҵ�Ŀ��Ԫ�أ���
���ַ�����ǰ����������û���ظ�Ԫ�أ�
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int RotatedIndex(int A[], int n)//ע�⣬���ֶ��ֲ��ҵ�ģʽ����ͨ�Ĳ�̫��ͬ��
    {
        if(n == 1)//ע�����������
        {
            return 0;
        }
        int low = 0; 
        int high = n - 1;
        int mid = low;//����������������򷵻�0;
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