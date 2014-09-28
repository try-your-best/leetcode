/*
看网上的神解释
大意是：如果柱体高度是上升的，则面积是持续增大的，这个时候继续压栈（压入的是柱体的下标）。
保持对当前柱体的高度大于栈顶柱体的高度。否则，则开始弹栈，并计算面积。直至当前柱体的
高度大于栈顶柱体的高度。这有点类似与求最大子序列和！
复杂度 O(n)
http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
*/

class Solution {
public:
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
