/*
思路：KMP算法！
KMP算法的想法是，设法利用这个已知信息，不要把"搜索位置"移回已经比较过的位置，继续把它向后移，这样就提高了效率。
参考读物：http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
prefix_value[i] 表示长度为i的字符串的表值!
例子： ACADEACAC
*/

class Solution {
public:
    void ComputePrefix(const char *pattern, int prefix_value[]) //线性的计算表值！参考wiki
    {
        const int pattern_len = strlen(pattern);
        prefix_value[0] = -1;
        prefix_value[1] = 0;
        int cnd = 0;//cnd 表示上一字符串的最大公共前缀长度！
        int posi = 2;
        while(posi <= pattern_len)
        {
            if(pattern[posi-1] == pattern[cnd])
            {
                cnd = cnd + 1;
                prefix_value[posi] = cnd;
                posi++;
            }
            else if(cnd > 0)//可回退
            {
                cnd = prefix_value[cnd];
            }
            else
            {
                prefix_value[posi] = 0;
                posi++;
            }
        }
         
    }
    
    int KMP(const char* text, const char* pattern)
    {
        int text_len = strlen(text);
        int pattern_len = strlen(pattern);
        if(pattern_len == 0)// "",""
        {
            return 0;
        }
        if(text_len < pattern_len)//"", "a"
        {
            return -1;
        }
        int *prefix_value = new int[pattern_len+1]();//记得初始化！
        ComputePrefix(pattern, prefix_value);
        int last_prefix_value = 0;
        for(int i = 0; i < text_len; i++)
        {
            int text_index = i+last_prefix_value;
            int j = last_prefix_value;//已知匹配的位不用再次匹配！
            for(; j < pattern_len; j++)
            {
                if(text_index < text_len && text[text_index] == pattern[j])
                {
                    text_index++;
                }
                else
                {
                    break;
                }
            }
            if(j == pattern_len)
            {
                delete[] prefix_value;
                return i;
            }
            else if(j > 0)
            {
                 i += j-prefix_value[j]-1;//注意在此移动的位数要先减1,因为后面还有i++;
                 last_prefix_value = prefix_value[j];//记录最大公共长度，方便以后计算比较位！
            }
        }
        delete[] prefix_value;
        return -1;
    }
    char *strStr(char *haystack, char *needle) {
        int target_index = KMP(haystack, needle);
        if(target_index == -1)
        {
            return NULL;
        }
        else
        {
            return haystack+target_index;
        }
    }
};
