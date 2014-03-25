/*

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    void DFS(string& digits, int cur, string * keyboard, string& path, vector<string>& result)
    {
        if(cur == digits.length())
        {
            result.push_back(path);
            return;
        }
        string letters = keyboard[digits[cur]-'0'];
        int letters_len = letters.length();
        for(int i = 0; i < letters_len; i++)
        {
            path += letters[i];
            DFS(digits, cur+1, keyboard, path, result); //cur+1写成cur了，否则就可以一次A掉。
            path.erase(path.length()-1, 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        string keyboard[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        vector<string> result;
        DFS(digits, 0, keyboard, path, result);
        return result;
    }
};
void Test()
{
	string digits("2");
	Solution s;
	s.letterCombinations(digits);
}

int main()
{
	Test();
	return 0;
}
