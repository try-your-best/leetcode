#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void BuildConbination(vector<int>& sorted_num, int select_len, int start, int target, vector<int>& intermediate, vector<vector<int> >& results)
    {
        if(select_len == 0)
        {
            int inter_len = intermediate.size();
            int sum = 0;
            for(int i = 0; i < inter_len; i++)
            {
                sum += intermediate[i];
            }
            if(sum == target)
            {
                results.push_back(intermediate);
            }
            return;
        }
        int duplicate_mark = sorted_num[start];
        int num_len = sorted_num.size();
        for(int i = start; i < num_len; i++)
        {
            if(i > start && sorted_num[i] == duplicate_mark)
            {
                continue;
            }
            else
            {
                duplicate_mark = sorted_num[i];
                intermediate.push_back(sorted_num[i]);
                BuildConbination(sorted_num, select_len-1, i+1, target, intermediate, results);
                intermediate.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> intermediate;
        vector<vector<int> > results;
        int num_len = num.size();
        for(int select_len = 1; select_len <= num_len; select_len++)
        {
            BuildConbination(num, select_len, 0, target, intermediate, results);
        }
        return results;
    }
};

void Print(vector<vector<int> > results)
{
    int len1 = results.size();
    if(len1 == 0)
        return;
    for(int i = 0; i < len1; i++)
    {
        int len2 = results[i].size();
        for(int j =0; j < len2; j++)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

void Test()
{
    vector<int> num;
    num.push_back(10);
    num.push_back(1);
    num.push_back(2);
    num.push_back(7);
    num.push_back(6);
    num.push_back(1);
    num.push_back(5);
    Solution s;
    vector<vector<int> > result = s.combinationSum2(num, 8);
    Print(result);
}

int main()
{
    Test();
    return 0;
}
