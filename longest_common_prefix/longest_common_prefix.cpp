/*
思路：首先找字符串的最短长度，每次扫每个字符串的对应字符！
特例
空字符串：返回空字符
只有一个字符串：直接返回该字符串
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int size = strs.size();
        string result;
        if(!size) return result;
        else if(size == 1)
        {
            return strs[0];
        }
        int minLen = INT_MAX;
        for(int i = 0; i < size; ++i)
        {
            int len = strs[i].size();
            minLen = min(minLen, len);
        }
        for(int i = 0; i < minLen; i++)
        {
            set<char> chars;//用set来判断，不能用异或，因为字符串树可能是奇数
            for(int j = 0; j < size; j++)
            {
                chars.insert(strs[j][i]);
            }
            if(chars.size() == 1)
            {
                result.push_back(strs[0][i]);
            }
            else
                break;
        }
        return result;
    }
};
