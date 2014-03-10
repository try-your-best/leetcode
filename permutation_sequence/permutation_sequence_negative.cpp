/*
˼·��
��λ������ʵ�����У��ٽ����к�Ԫ�ص�ֵ���бȽϣ�ѡ���k-1������ϧ���ǳ�ʱ�ˣ�����
�����9��Ԫ�أ�һ��Ԫ��4 bit��long long ���Ϳ���װ������״̬��
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    void Swap(int& a, int& b)
    {
        if(&a == &b)
            return;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void Swap(long long& val, int n, int index1, int index2)
    {
        int digit_index1 = n -1 - index1;
        int digit_index2 = n- 1 - index2;
        if(digit_index1 == digit_index2)
        {
            return;
        }
        else if(digit_index1 > digit_index2)
        {
            Swap(digit_index1, digit_index2);
        }
        long long mask = 15LL << (digit_index1 * 4);
        long long tmp1 = val & mask;
        mask = 15LL << (digit_index2 * 4); // 15��int�ͣ�15LL��long long�͡���λ��������Ľ������������ߵ�Ԫ�ؾ�����
        long long tmp2 = val & mask;
        val ^= tmp1;
        val ^= tmp2;
        val |= tmp1 << ((digit_index2 - digit_index1) * 4);
        val |= tmp2 >> ((digit_index2 - digit_index1) * 4);
    }
    
    void ConvertToString(long long val, int n, char* str)
    {
        for(int i = 0; i < n; i++)
        {
            int move_bit = (n-1-i) * 4;
            long long target_val = (15LL << move_bit) & val;
            str[i] = '0' + (target_val >> move_bit);
        }
        str[n] = '\0';
    }
    //��������
    void BuildPermutation(long long& val, int len, int start, vector<long long>& permu_values)
    {
        if(start == len -1)
        {
            permu_values.push_back(val);
            return;
        }
        for(int i = start; i < len; i++)
        {
            Swap(val, len, start, i);
            BuildPermutation(val, len, start+1, permu_values);
            Swap(val, len, start, i);
        }
    }
    //�����ʼ����
    long long CreateInialValue(int n)
    {
        long long val = 0;
        for(int i = 1; i <= n; i++)
        {
            long long bit_value = i;
            val |= bit_value << ((n - i) * 4);
        }
        return val;
    }
public:
    string getPermutation(int n, int k) {
        long long val = CreateInialValue(n);
        vector<long long> permu_values;
        BuildPermutation(val, n, 0, permu_values);
        sort(permu_values.begin(), permu_values.end());
        char* str = new char[n + 1];
        ConvertToString(permu_values[k-1], n, str);
        string final_str(str);
        delete[] str;
        return final_str;
    }
};

void Test3()
{
    Solution s;
//    cout << s.getPermutation(3, 3) << endl;
    cout << s.getPermutation(9, 94626) << endl;
}

int main()
{
    Test3();
    return 0;
}

