/*
思路：将输入的罗马数字转为10进制数。关键的前提是输入的字符串是有效的。
遍历字符串，取得当前字符的值，如果当前值比前一字符小，则直接加上该值，
否则，则要与前一字符组合，即当前值减去前一字符值。
*/

class Solution {
public:
    int mapToValue(char c)
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
    int romanToInt(string s) {
        int len = s.size();
        if(len == 0)
        {
            return 0;
        }
        int result = mapToValue(s[0]);
        for(int i = 1; i < len; i++)
        {
            if(mapToValue(s[i]) > mapToValue(s[i-1]))
            {
                result += mapToValue(s[i]) - 2 * mapToValue(s[i-1]);//注意，这里要减去的上一字符值的两倍，因为上一字符值已加到result中去了。
            }
            else
            {
                result +=  mapToValue(s[i]);
            }
        }
        return result;
    }
};
