//思路：深搜+剪枝
class Solution {
private:
void DFS(vector<int>& nums, int gap, vector<int>& intermediate, vector<vector<int>>& result)
{
    if(gap == 0)
    {
        result.push_back(intermediate);
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if( gap - nums[i] >= 0)//剪枝
        {
            if(intermediate.empty() || nums[i] >= intermediate.back())//剪枝
            {
                intermediate.push_back(nums[i]);
                DFS(nums, gap-nums[i], intermediate, result);
                intermediate.pop_back();
            }
        }
        else
        {
            break;
        }
    }
}
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> intermediate;
        vector<vector<int>> result;
        std::sort (candidates.begin(), candidates.end());  //注意，题目中没有说待选数组是升序的。
        DFS(candidates, target, intermediate, result);
        return result;
    }
};
