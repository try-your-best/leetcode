/*
思路：分别从字符串的两端遍历字符串，判断是否组成回文。
需要注意的是字母有大小写，所以把字母全部转为小写会让处理逻辑更简单。
尤其是函数还是通过值传递的！
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
    bool isPalindrome(string s) {//值传递！
        int s_len = s.size();
        if(s_len == 0)
        {
            return true;
        }
        int low = 0;
        int high = s_len -1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);//转为小写
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
