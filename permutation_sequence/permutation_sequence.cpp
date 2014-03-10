#include<iostream>
#include<string>

using namespace std;

class Solution {
private:
    void CopyString(const char* source, char* target)
    {
        while(*source != '\0')
        {
            *target = *source;
            target++;
            source++;
        }
        target = '\0';
    }
    void Swap(char& a, char& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void BuildPermutation(char* source_str, int len, int start, int& k, bool& is_found, char* target_str)
    {
        if(start == len-1)
        {
            k--;
            if(k == 0)
            {
                is_found = true;
                CopyString(source_str, target_str);
            }
            return;
        }
        for(int i = start; i < len && !is_found; i++)
        {
            Swap(source_str[start], source_str[i]);
            BuildPermutation(source_str, len, i+1, k, is_found, target_str);
            Swap(source_str[start], source_str[i]);
        }
    }
public:
    string getPermutation(int n, int k) {
        char* source_str = new char[n+1];
        for(int i = 0; i < n; i++)
        {
            source_str[i] = '0' + i + 1;
        }
        source_str[n] = '\0';
        char* target_str = new char[n+1];
        bool is_found = false;
        BuildPermutation(source_str, n, 0, k, is_found, target_str);
        string str(target_str);
        delete[] source_str;
        delete[] target_str;
        return str;
    }
};

void Test()
{
    Solution s;
    string str = s.getPermutation(1,1);
    cout << str << endl;
}

int main()
{
    Test();
    return 0;
}
