/*
˼·���ֱ���ַ��������˱����ַ������ж��Ƿ���ɻ��ġ�
��Ҫע�������ĸ�д�Сд�����԰���ĸȫ��תΪСд���ô����߼����򵥡�
�����Ǻ�������ͨ��ֵ���ݵģ�
*/

#include <algorithm>
#include <string> 
using namespace std;
class Solution {
public:
    bool IsAlphaOrNumeric(char cur_char)
    {
        if((cur_char >='a' && cur_char <='z')||(cur_char >= '0' && cur_char <= '9'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isPalindrome(string s) {//ֵ���ݣ�
        int s_len = s.size();
        if(s_len == 0)
        {
            return true;
        }
        int low = 0;
        int high = s_len -1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);//תΪСд
        while(low < high)
        {
            while(!IsAlphaOrNumeric(s[low]) && low < high)
            {
                low ++;
            }
            while(!IsAlphaOrNumeric(s[high])  && high > low)
            {
                high--;
            }
            if(low == high)
            {
                return true;
            }
            else if(s[low] == s[high])
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
