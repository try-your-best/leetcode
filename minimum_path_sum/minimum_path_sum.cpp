//典型的DP，一次A掉。

class Solution {
public:
    int Min(int a, int b){
        return a < b ? a : b; 
    }
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int* min_path_sum = new int[n]; //只需O(n)辅助空间。
        min_path_sum[0] = grid[0][0];
        //处理第一行
        for(int i = 1; i < n; i++)
        {   
            min_path_sum[i] = min_path_sum[i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++)
        {
            min_path_sum[0] = min_path_sum[0]+grid[i][0];//处理每行的第一个
            for(int j = 1; j < n; j++)
            {
                min_path_sum[j] = Min(min_path_sum[j-1], min_path_sum[j])+ grid[i][j];
            }
        }
        int min_sum = min_path_sum[n-1];
        delete [] min_path_sum;
        return min_sum;
    }
};
