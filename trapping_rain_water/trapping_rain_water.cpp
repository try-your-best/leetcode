/*
˼·��
����ÿ������,�ҵ�������������ߵ�����, ����i��Ӧ�����ɵ��������:
max(min(max_left_height[i], max_right_height[i]) - A[i], 0),����
1. ��������ɨ��һ��,����ÿ������,��ȡ������ֵ;
2. ��������ɨ��һ��,����ÿ������,�������ֵ;
3. ��ɨ��һ��,��ÿ�����ӵ�������ۼӡ�
Ҳ����,
1. ɨ��һ��,�ҵ���ߵ�����,������ӽ������Ϊ����;
2. �������һ��;
3. �����ұ�һ�롣
�����ǲ�ȡ�ں��ߡ�ʱ��O(n),�ռ�O(1)
���ߵ�����˼·��ǰ����һ�µġ�������ߵ����ӣ�����벿�֣�ÿ�������ұ����ֵ�ҵ��ˣ�����ֻҪ��������ֵ��
ͨ��left_peakά����ͬ�����Ұ벿�֣�����ֻҪ�����ұ����ֵ��ͨ��right_peakά����

trapping_rain_water_1.cpp ���ǲ���ǰ�ߣ�ʱ��O(n),�ռ�O(n);
trapping_rain_water_negative_2.cpp ʱ��O(n^2),�ռ�O(n1);�ᳬʱ����
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
