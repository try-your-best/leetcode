/*
思路：
用位运算来实现排列，再用复杂度为O(n)的选择算法选择第k-1个。最后发现还不如用STL的sort快！那设计者果真大神！
最大是9个元素，一个元素4 bit，long long 类型可以装下所有状态。
*/
#include<iostream>
#include<vector>
#include<string>
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

    void Swap(long long& a, long long& b)
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
        mask = 15LL << (digit_index2 * 4);
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
    int Partition(vector<long long>& permu_values, int low, int high)
    {
        int i  = low -1;
        for(int j = low; j < high; j++)
        {
            if(permu_values[j] < permu_values[high])
            {
                i++;
                Swap(permu_values[i],permu_values[j]);                
            }
        }
        i++;
        Swap(permu_values[i],permu_values[high]);
        return i;
    }
    
    long long Select(vector<long long>& permu_values, int low, int high, int k_th)
    {
        if(low == high)
            return permu_values[low];
        int select_index = Partition(permu_values, low, high);
        int cur_th = select_index - low + 1;
        if(cur_th == k_th)
        {
            return permu_values[select_index]; 
        }
        else if(cur_th > k_th)
        {
            return Select(permu_values,low, select_index -1, k_th);
        }
        else
        {
            return Select(permu_values,select_index+1, high, k_th - cur_th);
        }
    }
public:
    string getPermutation(int n, int k) {
        long long val = CreateInialValue(n);
        vector<long long> permu_values;
        BuildPermutation(val, n, 0, permu_values);
        sort(permu_values.begin(), permu_values.end());
        char* str = new char[n + 1];
        //cout << "size:" << permu_values.size() << endl;
        //ConvertToString(permu_values[k-1], n, str);
        long long selected_value = Select(permu_values, 0, permu_values.size()-1, k); 
        ConvertToString(selected_value, n, str);
        string final_str(str);
        delete[] str;
        return final_str;
    }
};

//void Test()
//{
//    long long val = 0x1234;
//    int len = 4;
//    Swap(val, len, 0, 3);
//    char* str = new char[len+1];
//    ConvertToString(val, len, str);
//    cout << str << endl;
//    delete[] str;
//}

void Test2()
{
//    int len = 9;
//    Solution s;
//    //long long val = s.CreateInialValue(len);
//    char* str = new char[len+1];
//    long long val = 0x123456789;
//    s.ConvertToString(val, len, str);
//    cout << str << endl;
//    delete[] str;

//   int move = 4 * 8;
//   long long val = 0x100000000;
//   long long target_val = (15LL << move) & val;
//   cout << hex << target_val << endl;
}

void Test3()
{
    Solution s;
//    cout << s.getPermutation(3, 3) << endl;
    cout << s.getPermutation(9, 94626) << endl;
}

//void Test4()
//{
//    vector<long long> test;
//    test.push_back(1);
//    test.push_back(3);
//    test.push_back(2);
//    test.push_back(4);
//    Solution s;
//    long long val = s.Select(test, 0, test.size()-1, 4); 
//    cout << val << endl;
//}

int main()
{
    Test3();
    return 0;
}
