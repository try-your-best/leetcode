/*
思路：用递归去模拟组合。
*/
class Solution {
private:
    void BuildCombination(int n, int k, int start, vector<int>& intermediate, vector<vector<int>>& combiantions)
    {
        if(k == 0)
        {
            combiantions.push_back(intermediate);
            return;
        }
        for(int i = start; i < n - (k - 1); i++)
        {
            intermediate.push_back(i+1);
            BuildCombination(n, k-1, i+1, intermediate, combiantions);
            intermediate.pop_back();
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> combiantions;
        if(n < 0 || k < 0 || k > n)
        {
            return combiantions;
        }
        vector<int> intermediate;
        BuildCombination(n, k, 0, intermediate, combiantions);
        return combiantions;
    }
};
