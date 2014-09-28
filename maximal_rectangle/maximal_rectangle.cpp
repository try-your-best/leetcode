/*
思路：求矩阵中1组成的最大正方形的面积。
首先是用height[i][j]保存第i行j列的柱子的高度。然后对于第i行去求直方图中的矩形的最大面积，即
Largest Rectangle in Histogram。这个解法太难想了，全靠网上大神指点！
最终的复杂度是O(n^2)
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(!row) return 0;
        int col = matrix[0].size();
        vector<vector<int> > height(row, vector<int>(col));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(matrix[i][j] == '0')
                {
                    height[i][j] == 0;
                }
                else
                {
                    if(i > 0)
                    {
                        height[i][j] = height[i-1][j]+1;
                    }
                    else
                    {
                        height[i][j] = 1;
                    }
                }
            }
        }
        int maxArea = 0;
        for(int i = 0; i < row; ++i)
        {
            maxArea = max(maxArea, largestRectangleArea(height[i]));
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int> &height) {
    vector<int> tmpHeight(height);
    tmpHeight.push_back(0);
    stack<int> indexs;
    int i = 0; 
    int maxArea = 0;
    while(i < tmpHeight.size())
    {
        if(indexs.empty() || tmpHeight[i] >= tmpHeight[indexs.top()])
        {
            indexs.push(i++);
        }
        else
        {
            int tmp = indexs.top();
            indexs.pop();
            maxArea = max(maxArea, tmpHeight[tmp] * (indexs.empty()? i : i - indexs.top() -1));
        }
    }
    return maxArea;
    }
};
