#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    bool IsAlpha(char cur_char)
    {
        if((cur_char >='a' && cur_char <='z')||(cur_char >= 'A' && cur_char <= 'Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool IsNumeric(char cur_char)
    {
        if(cur_char >= '0' && cur_char <= '9')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool IsAlphaEqual(char a, char b)
    {
        if(a == b || abs(a-b) == 32)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isPalindrome(string s) {
        int s_len = s.size();
        if(s_len == 0)
        {
            return true;
        }
        int low = 0;
        int high = s_len -1;
        while(low < high)
        {
            while(!IsAlpha(s[low]) && !IsNumeric(s[low]) && low < high)
            {
                low ++;
            }
            while(!IsAlpha(s[high]) && !IsNumeric(s[high])  && high > low)
            {
                high--;
            }
            if(low == high)
            {
                return true;
            }
            else if((IsNumeric(s[low]) && IsNumeric(s[high]) && s[low] == s[high])
                    || (IsAlpha(s[low]) && IsAlpha(s[high]) && IsAlphaEqual(s[low], s[high])))
            {
                low++;
                high--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

void Test()
{
    string str("aa");
    Solution s;
    cout << s.isPalindrome(str) << endl;
}

int main()
{
    Test();
    return 0;
}
