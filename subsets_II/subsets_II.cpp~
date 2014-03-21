/*
思路：递归模拟组合。排序使序列非递减。因为数字有重复，
所以设置变量保留已选中数字，保证在递归中，当前层次选中的数字不再选。
*/

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
        int dup_mark = data[start];//保留信息，保证在当前层选中数字不再选！
        for(int i = start; i < len - num + 1; i++)
        {   
            if(i > start && data[i] == dup_mark)
            {
                continue;
            }
            else 
            {
                dup_mark = data[i];
            }
            intermediate.push_back(data[i]);
            DFS(num-1, i+1, data, intermediate, result);
            intermediate.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
