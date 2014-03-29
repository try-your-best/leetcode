/*
思路：深搜， 在深搜的过程中注意判断选中的字符串是否符合要求。
当选中的字符串长度为1,则该字符串一定有效，
如果长度为2,则注意其起始值不能为0,即出现'01'
如果长度为3,则注意其起始值不能为0，同时该值必须不大于255。
*/
#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    bool CheckValid(string &str)
    {
        int value= atoi(str.c_str());
        if(value <= 255)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void DFS(string &str, int start, int depth, string &intermediate,vector<string>& results)
    {
        int str_len = str.length();
        if(depth == 3)
        {
            int left_len = str_len - start;
            string left_str = str.substr(start, left_len);
            if(left_len == 1)
            {
                intermediate += left_str;//这里所加的字符会被上一层的erase清除!
                results.push_back(intermediate);
            }
            else if(left_len == 2 && str[start] != '0')
            {
                intermediate += left_str;//这里所加的字符会被上一层的erase清除!
                results.push_back(intermediate);
            }
            else if(left_len == 3 && str[start] != '0' && CheckValid(left_str))
            {
                intermediate += left_str;//这里所加的字符会被上一层的erase清除!
                results.push_back(intermediate);
            }
            return;
        }
        int max_left = 9 - depth * 3;//限制当前字符串可选的长度！
        int min_left = 3 - depth;
        if(str_len - start - 1 <= max_left) 
        {
            int cur_len = intermediate.length();
            intermediate+= str.substr(start, 1);
            intermediate+=".";
            DFS(str, start+1, depth+1, intermediate, results);
            intermediate.erase(cur_len,intermediate.length()-cur_len);
        }
        if(str[start] != '0')
        {
            if(str_len - start - 2 >= min_left && str_len - start - 2 <= max_left)  
            {
                int cur_len = intermediate.length();
                intermediate+= str.substr(start, 2);
                intermediate+=".";
                DFS(str, start+2, depth+1, intermediate, results);
                intermediate.erase(cur_len,intermediate.length()-cur_len);
            }
            if(str_len - start - 3 >= min_left)
            {
                string cur_str = str.substr(start, 3);
                if(CheckValid(cur_str))
                {
                    int cur_len = intermediate.length();
                    intermediate+=cur_str;
                    intermediate+=".";
                    DFS(str, start+3, depth+1, intermediate, results);
                    intermediate.erase(cur_len,intermediate.length()-cur_len);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string intermediate;
        vector<string> results;
        int str_len = s.length();
        if(str_len < 4 || str_len > 12)
        {
            return results;
        }
        DFS(s, 0, 0, intermediate, results);
        return results;
    }
};

void Test()
{
	string str("0000");
	Solution s;
	s.restoreIpAddresses(str);
}

int main()
{
	Test();
	return 0;
}
