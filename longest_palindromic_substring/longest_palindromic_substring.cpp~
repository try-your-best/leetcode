/*
思路：遍历字符串，以每个字符串为中心点展开对回文的检查。注意，回文可以是长度有单数，和偶数两种。
时间复杂度O(n^2)，空间复杂度O(1)
本体如果用动态规划的话，内存太大，不给过！
*/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    void CheckPalindrome(string str, int center, bool is_even, int &start, int &palindrome_len)
    {
        int str_len = str.length();
        int low = 0;
        int high = 0;
        if(is_even)
        {
            palindrome_len = 0;
            start = center;
            low = center;
            high = center+1;
        }
        else
        {
            palindrome_len = 1;
            start = center;
            low = center-1;
            high = center+1;
        }
        while(low >= 0 && high < str_len)
        {
            if(str[low] == str[high])
            {
                palindrome_len += 2;
                low--;
                high++;
            }
            else{ break; }
        }
        start = low+1; //注意！不是start = low,因为当退出循环时，当前的low是不符合条件的，必须加1才能作为回文的起点。
    }
    string longestPalindrome(string s) {
        int str_len = s.length();
        int max_start = 0;
        int max_palindrome_len = 0;
        int cur_start = 0;
        int cur_palindrome_len = 0;
        for(int i = 0; i < str_len; i++)
        {
            CheckPalindrome(s, i, true, cur_start, cur_palindrome_len);
            if(cur_palindrome_len > max_palindrome_len)
            {
                max_palindrome_len = cur_palindrome_len;
                max_start = cur_start;
            }
            CheckPalindrome(s, i, false, cur_start, cur_palindrome_len);
            if(cur_palindrome_len > max_palindrome_len)
            {
                max_palindrome_len = cur_palindrome_len;
                max_start = cur_start;
            }
        }
        return s.substr(max_start, max_palindrome_len);
    }
};

void Test()
{
	string str("a");
	Solution s;
	s.longestPalindrome(str);
}

int main()
{
	Test();
	return 0;
}
