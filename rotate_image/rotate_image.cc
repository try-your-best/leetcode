/*
看参考答案
思路：
方案1：先沿着向右倾的对角线翻转，然后在沿着水平中线翻转。就可以顺时针翻转矩阵90度;
方案2：先沿着水平中线翻转，在沿着向右倾的对角线翻转。
时间复杂度 O(n^2),空间复杂度 O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int n = matrix.size();
        for(int i = 0; i < n-1; i++)
        {
            for(int j = 0; j < n - i; j++)
            {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);//沿这右倾的主对角线翻转！注意下标的变换！
            }
        }
        for(int i = 0; i < n/2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                swap(matrix[i][j], matrix[n-1-i][j]);//沿水平中线翻转！
            }
        }
    }
};
