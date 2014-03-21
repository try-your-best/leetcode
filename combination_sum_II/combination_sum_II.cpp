/*
思路：深搜+剪枝
题目的思路跟在有重复数的序列中生成组合数是一致的。但是为了剪枝，需要修改函数的形参。
一开始：
void BuildConbination(vector<int>& sorted_num, int select_len, int start, int target, vector<int>& intermediate, vector<vector<int> >& results)
对比 DFS(vector<int>& sorted_num, int start, int gap, vector<int>& intermediate, vector<vector<int> >& results)
将组合数的长度select_len改为与目标和的差值gap。

*/

class Solution {
public:
    void DFS(vector<int>& sorted_num, int start, int gap, vector<int>& intermediate, vector<vector<int> >& results)
    {
        if(gap == 0)
        {
            results.push_back(intermediate);
            return;
        }
        int duplicate_mark = -1;//所有候选值均为正数
        int num_len = sorted_num.size();
        for(int i = start; i < num_len; i++)
        {
            if(sorted_num[i] > gap){ break; } //剪枝
            if(sorted_num[i] != duplicate_mark)
            {
                duplicate_mark = sorted_num[i];
                intermediate.push_back(sorted_num[i]);
                DFS(sorted_num, i+1, gap-sorted_num[i], intermediate, results);
                intermediate.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> intermediate;
        vector<vector<int> > results;
        DFS(num, 0, target, intermediate, results);
        return results;
    }
};
