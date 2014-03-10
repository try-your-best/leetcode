/*
思路：
遇到空格后再遇到单词就重新开始计算单词的长度。
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        if(s == NULL)
            return len;
        bool new_word = true;
        while(*s != '\0')
        {
            if(*s == ' ')
            {
                new_word = true;
            }
            else if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
            {
                if(new_word)
                {
                    new_word = false;
                    len = 1;
                }
                else
                {
                    len++;
                }
            }
            s++;
        }
        return len;
    }
};
