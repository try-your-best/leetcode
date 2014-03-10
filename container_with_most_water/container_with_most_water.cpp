//思路：贪心算法，从最外的两条边选起，每次保留较长的边，较短的往里挪。
//暂时无法证明算法的正确性！求指教
class Solution {
int Min(int a, int b){ return a <= b? a : b; }
int Max(int a, int b){ return a >= b? a : b; }

public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size()-1;
        int max_area = -1;
        while(start < end)
        {
            int cur_height = Min(height[start], height[end]);            
            max_area = Max(max_area, cur_height*(end - start));
            if(height[start] <= height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return max_area;
    }
};
