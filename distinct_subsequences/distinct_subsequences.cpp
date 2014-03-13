/*
���⣺���������ַ���S��T����S�������Ӵ�����T��ͬ���ж��ٸ���
˼·����̬�滮���벻�������ο��𰸵ġ�
�� ״ ̬ Ϊ f (i, j), �� ʾ T[0,j] �� S[0,i] �� �� �� �� �� ���� 
�� S[i]!=T[j] �� f (i, j) = f (i �6�1 1, j);
�� S[i]==T[j],�����ʹ�� S[i],��ʱ f (i, j) = f (i �6�1 1, j) + f (i �6�1 1, j �6�1 1)��
ʱ�临�Ӷ� O(m*n),�ռ临�Ӷ� O(n)
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int s_len = S.length();
        int t_len = T.length();
        if(s_len < t_len)
            return 0;
		//Ϊ�˼򻯶Ա߽������Ĵ������ﶼ�����ַ���S��T���±��Ǵ�1��ʼ�ġ�
		//��S��T���±�0��λ�ò���һ�������������ַ�������ȵ��ַ�����Ȼ��ֻ�Ǹ����ϵ�
		//��ʵ���ַ������Ǵ��±�Ϊ0��ʼ�ġ�
		//��f(0,0) = 1; f(0,j) = 0 �� j > 1; f(i,0) = 0 �� i > 1;
		int* dp = new int[t_len + 1]; //��������������dp�ĳ���Ϊ t_len + 1
        dp[0] = 1; 
        for(int i = 1; i < t_len+1; i++)
        {
            dp[i] = 0;
        }
        for(int i = 0; i < s_len; i++)
        {
            for(int j = t_len-1; j >= 0; j--)//Ҫϸ�ģ���Ҫ�տ�д�� j++����
            {
                if(S[i] != T[j])//�ַ�����ʵ���±��0��ʼ��
                {
                    dp[j+1] = dp[j+1];
                }
                else
                {
                    dp[j+1] = dp[j+1] + dp[j];
                }
            }
        }
        int distinct_num = dp[t_len];
        delete[] dp;
        return distinct_num;
    }
};

void Test()
{
    Solution s;
    string str1("a");
    string str2("b");
    int result = s.numDistinct(str1, str2);
    cout << result << endl;
}

int main()
{
    Test();
    return 0;
}
