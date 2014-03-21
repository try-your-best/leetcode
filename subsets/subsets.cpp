/*
思路：用递归（深搜）模拟组合。
又太粗心了，未能一次A掉……
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void DFS(int num, int start, vector<int>& data, vector<int>& intermediate ,vector<vector<int> >& result)
    {
        if(num == 0)
        {
            result.push_back(intermediate);
            return; // 注意返回，否则回无限递归！
        }
        int len = data.size();
        for(int i = start; i < len - num + 1; i++)
        {
            intermediate.push_back(data[i]);
            DFS(num-1, i+1, data, intermediate, result);
            intermediate.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > results;
        vector<int> intermediate; 
        int len = S.size();
        sort(S.begin(), S.end()); // 记得排序，题目要求非递减
        for(int i = 0; i <= len; i++)
        {
            intermediate.clear();
            DFS(i, 0, S, intermediate, results);
        }
        return results;
    }
};

void Test()
{
    vector<int> data;
    data.push_back(0);
    Solution s;
    s.subsets(data);
//    vector<int> data;
//    data.clear();
//    data.clear();
//    data.clear();
}

int main()
{
    Test();
    return 0;
}
