/*
会超时！！
*/

class Solution {
public:
    int minSum;
    int curSum;
    void DFS(vector<vector<int> > &triangle, int depth, int lastIndex)
    {
        if(triangle.size() == depth)
        {
            minSum = min(minSum, curSum);
            return;
        }
        for(int i = lastIndex; i <lastIndex+2; ++i) //注意，要组成路径必须是相邻的两个子节点！
        {
            curSum += triangle[depth][i];
            DFS(triangle, depth+1, i);
            curSum -= triangle[depth][i];
        }
    }
    int minimumTotal(vector<vector<int> > &triangle) {
        minSum = INT_MAX;
        curSum = triangle[0][0];
        DFS(triangle, 1, 0);
        return minSum;
    }
};
