/*
经典的字符串翻转题目，就是要解决一些特定的需求
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

这道题关键是注意string的用法！
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
class Solution {
public:
    void CopyStr(char *source, char * dest)
    {
        while(*source != '\0')
        {
            *(dest++) = *(source++);
        }
        *dest ='\0';
    }
    void reverseWords(string &s) {
        if(s.size() == 0)
        {
            return;
        }
        int s_len = s.size();
        char* str = new char[s_len+1];
        s.copy(str, s_len);
	str[s_len] = '\0';
        //删除多余空格！
        //删除末尾空格
        int not_space = s_len-1;
        while(not_space >= 0 && str[not_space] == ' ')
        {
            not_space--;
        }
        if(not_space < s_len-1)
        {
            str[not_space+1] = '\0';
            s_len = not_space + 1;
        }
        //cout << s.size() << endl;
        //删除头部空格
        int space_begin = 0;
        while(space_begin < s_len && str[space_begin] == ' ')
        {
            space_begin++;
        }
        if(space_begin > 0)
        {
            CopyStr(str+space_begin, str);
            s_len = s_len - space_begin;
        }
        //删除中间多余空格
        space_begin = s_len-1;
        while(space_begin >= 0)
        {
            while(space_begin >= 0 && str[space_begin] != ' ')
            {
                space_begin--;
            }
            int space_end = space_begin -1;
            while(space_end >= 0 && str[space_end] == ' ')
            {
                space_end--;
            }
            if(space_begin - space_end >= 2)
            {
                CopyStr(str+space_begin+1, str+space_end+2); 
            }
            space_begin = space_end-1; 
        }
        s_len = strlen(str);
        //翻转字符串
        for(int i = 0; i < s_len/2; i++)
        {
            swap(str[i], str[s_len-1-i]);
        }
        int begin = 0;
        int end = 0;
        while(begin < s_len)
        {
            end = begin+1;
            while(end < s_len && str[end] != ' ')
            {
                end++;
            }
            int word_len = end - begin;//翻转字
            for(int i = 0; i < word_len/2; i++)
            {
                swap(str[begin+i], str[begin+word_len-1-i]);
            }
            begin = end+1;
        }
        s = str;
        delete[] str;
    }
};

void Test()
{
	string str("lak.kb c!gfbb' cgyxxrph!ai paim,izbj.tnkugjx.f!uhs!xgv vsx.ncydmsgeaenstgthzd'fv qssjheigf!xca!d ,tsvj!yni'csdnphtt cej.ngxy egnh oaxzxugnehorkqkt,");
	Solution s;
	s.reverseWords(str);
	cout << str << endl;
        cout << str.size() << endl;
}

int main()
{
	Test();
	return 0;
}

