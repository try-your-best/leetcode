/*
˼·���Ӻ���ǰ�������顣move_index ��¼���ظ��������λ��
�ҵ���ǰ������ظ�λ����ǰ��i,��move_index���Ժ�����ݸ��Ƶ�i+1
*/
#include<iostream>
using namespace std;
class Solution {
public:
    void MoveData(int A[], int target_index, int move_index, int cur_len)
    {
        for(int i = move_index; i < cur_len; i++, target_index++) //ע�⣬target_indexҪ���ŵ���;
        {
            A[target_index] = A[i];
        }
    }
    int removeDuplicates(int A[], int n) {
        int move_index = n;
        int cur_len = n;
        for(int i = n-1; i >= 1; i--)
        {
            if(A[i] != A[i-1])
            {
                if(move_index == i + 1)
                {
                    move_index--;
                }
                else
                {
                    MoveData(A, i+1, move_index, cur_len);
                    cur_len -= move_index - 1 - i;//����ĳ���Ҫ��������
                    move_index = i;
                }
            }
        }
        if(move_index > 1)
        {
            MoveData(A, 1, move_index, cur_len);
            cur_len -= move_index - 1;
            move_index = 0;
        }
        return cur_len;
    }
};

void Print(int A[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Test()
{
	int A[] = {1,1,2,3};
	int len = sizeof(A)/sizeof(int);
	Solution s;
	int cur_len = s.removeDuplicates(A, len);
	cout << cur_len << endl;
        Print(A, cur_len);
}

int main()
{
	Test();
	return 0;
}

