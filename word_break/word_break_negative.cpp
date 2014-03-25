/*
思路：深搜,超时
时间复杂度 O(2^n),空间复杂度 O(n)
*/

class Solution {
public:
    bool DFS(string& str, int start, unordered_set<string> &dict)
    {
        int str_len = str.length();
        if(start == str_len)
        {
            return true;
        }
        for(int i = start; i < str_len; i++)
        {
            if(dict.count(str.substr(start,i-start+1)) != 0)
            {
                if(DFS(str, i+1, dict))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        return DFS(s, 0, dict);
    }
};
