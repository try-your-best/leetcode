#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Solution {
private:
    int m_num_decodings;
public:
    void DFS(int start, string& str)
    {
        int str_len = str.length();
        if(start == str_len)
        {
            m_num_decodings++;
            return;
        }
        if(str[start] != '0')
        {
            DFS(start+1, str);
        }
        if(start+1 < str_len && atoi(str.substr(start,2).c_str()) <= 26)
        {
            DFS(start+2, str);
        }
    }
    int numDecodings(string s) {
        int str_len = s.length();
        m_num_decodings = 0;
        if(str_len == 0)
        {
            return m_num_decodings;
        }
        DFS(0, s);
        return m_num_decodings;
    }
};

void Test()
{
    string str = "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253";
    Solution s;
    cout << s.numDecodings(str) << endl; 
}

int main()
{
    Test();
    return 0;
}
