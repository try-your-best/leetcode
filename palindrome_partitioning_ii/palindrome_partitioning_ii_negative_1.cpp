/*
思路：搜索（回溯）+剪枝，会超时！
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> current;
    int minCut_;
    bool isPalindrome(const string& str, int start, int end)
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
        const int size = str.size();
        const int curCut = (int) current.size()-1;
        if(start == size)
        {
            if(curCut < minCut_)
            {
                minCut_= curCut;
            }
        }
        if(minCut_ <= curCut)
            return;
        for(int i = size-1; i >= start; --i)
        {
            if(isPalindrome(str, start, i))
            {
                current.push_back(str.substr(start, i-start+1));
                DFS(str, i+1);
                current.pop_back();
            }
        }
    }
    
    int minCut(string s) {
        minCut_ = 0x7fffffff;
        if(current.size())
        {
            current.clear();
        }
        DFS(s, 0);
        return minCut_;
    }
};

void test1()
{
	Solution s;
	int r =  s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi");
	cout << r << endl;
}

int main()
{
	test1();
	return 0;
}

