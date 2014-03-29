/*
思路：简单的排序，一次A掉！
*/
class Solution {
public:
    void Swap(int &a, int &b)
    {
        if(&a == &b)
        {
            return;
        }
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void BuildPermutation(vector<int> &num, int start, vector<vector<int> > &result)
    {
        int len = num.size();
        if(start == len)
        {
            result.push_back(num);
            return;
        }
        for(int i = start; i < len; i++)
        {
            Swap(num[start], num[i]);
            BuildPermutation(num, start+1, result);
            Swap(num[start], num[i]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        BuildPermutation(num, 0, result);
        return result;
    }
};
