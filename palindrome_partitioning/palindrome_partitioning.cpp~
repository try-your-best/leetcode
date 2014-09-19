/*
思路：深度搜索,在字符串中划分子字符串，判断是否回文，是的话就找下一相邻的回文。
*/
class Solution {
public:
    vector<string> current;
    vector<vector<string>> result;
    bool isPalindrome(const string& str, int start, int end)//这样的处理可以兼容奇偶数！
    {
        while(start < end)
        {
            if(str[start++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }
    void DFS(const string& str, int start)
    {
        int size = str.size();
        if(start == size)
        {
            result.push_back(current);
            return;
        }
        for(int i = 0; i < size-start; ++i)
        {
            if(isPalindrome(str, start, start+i))
            {
                current.push_back(str.substr(start, i+1));
                DFS(str, start+i+1);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(current.size())
            current.clear();
        if(result.size())
            result.clear();
        DFS(s, 0);
        return result;
    }
};
